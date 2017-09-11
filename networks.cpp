#include "networks.h"





networks::networks()
{
    pose_receiver = new QUdpSocket(this);
    mode_poster = new QUdpSocket(this);
    pose_receiver->bind(QHostAddress::LocalHost,18888);

    connect(pose_receiver,SIGNAL(readyRead()),this,SLOT(pose_recv()));
}


void networks::pose_recv(void){

    pose_receiver->readDatagram((char *)pose_data,sizeof(int) * 6);
    for(int i=0;i<6;i++)
    {
        qDebug() << pose_data[i];
    }
}
