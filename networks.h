#ifndef NETWORKS_H
#define NETWORKS_H

#include <QObject>
#include<QHostAddress>
#include <QUdpSocket>
#include<QDebug>
#include<QByteArray>

class networks : public QObject
{
public:
    networks();

    QUdpSocket * pose_receiver;
    QUdpSocket * mode_poster;

    int pose_data[6];
public slots:
    void pose_recv(void);
};

#endif // NETWORKS_H
