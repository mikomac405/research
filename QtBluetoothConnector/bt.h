#ifndef BT_H
#define BT_H

#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QLowEnergyController>
#include <QBluetoothSocket>

class Bt : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString update READ getUpdate WRITE setUpdate NOTIFY updateChanged)
public:
    explicit Bt(QObject *parent = nullptr);
    QString getUpdate();

public slots:
    void startDeviceDiscovery();
    void connectToBand();
    void getHeartRate();

private slots:
    void serviceDiscovered(const QBluetoothUuid &service);
    void checkIfBand(const QBluetoothDeviceInfo &device);
    void deviceScanFinished();
    void connectionEstablished();
    void connectionInterrupted();
    void connectionFailed(const QLowEnergyController::Error &error);
    void socketReadyToRead();

Q_SIGNALS:
    void updateChanged();

private:
    void setUpdate(const QString &message);

    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QBluetoothSocket *socket;
    QLowEnergyController *controller = nullptr;
    QString m_message;
    QBluetoothDeviceInfo bandInfo;
    QBluetoothAddress bandAddress;
    QString serviceString = "";
    bool bandFound = false;
    bool enableConnection = false;
};

#endif // BT_H
