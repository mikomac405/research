#include "bt.h"

Bt::Bt(QObject *parent) : QObject(parent)
{
    setUpdate("Wait");
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent;
    discoveryAgent->setLowEnergyDiscoveryTimeout(5000);

    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &Bt::checkIfBand);
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &Bt::deviceScanFinished);
}

QString Bt::getUpdate()
{
    return m_message;
}


void Bt::startDeviceDiscovery()
{
    setUpdate("Scan");
    discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
}

void Bt::checkIfBand(const QBluetoothDeviceInfo &device){
    if(device.name() == "Mi Smart Band 4"){
        setUpdate(device.address().toString());
        bandInfo = device;
        bandFound = true;
    }
}

void Bt::deviceScanFinished(){
    setUpdate("Scan done");
    if(bandFound){
        enableConnection = true;
    }
}

void Bt::setUpdate(const QString &message)
{
    m_message = message;
    emit updateChanged();
}

void Bt::connectionEstablished(){
    setUpdate("Connected");
}

void Bt::connectionInterrupted(){
    setUpdate("Disconnected");
}

void Bt::connectionFailed(const QLowEnergyController::Error &error)
{
    setUpdate("Connection failed");
}

void Bt::socketReadyToRead(){
    setUpdate("Reading data");
}

void Bt::connectToBand(){
    setUpdate("Connecting to: " + bandInfo.address().toString());
    controller = QLowEnergyController::createCentral(bandInfo, this);
    controller->setRemoteAddressType(QLowEnergyController::PublicAddress);

    connect(controller, &QLowEnergyController::connected, this, &Bt::connectionEstablished);
    connect(controller, &QLowEnergyController::disconnected, this, &Bt::connectionInterrupted);
    connect(controller, QOverload<QLowEnergyController::Error>::of(&QLowEnergyController::error),
            this, &Bt::connectionFailed);

    controller->connectToDevice();
}

void Bt::getHeartRate()
{
    connect(controller, &QLowEnergyController::serviceDiscovered, this, &Bt::serviceDiscovered);
    controller->discoverServices();
}

void Bt::serviceDiscovered(const QBluetoothUuid &service)
{
    serviceString+=service.toString()+"\n";
    setUpdate(serviceString);
}
