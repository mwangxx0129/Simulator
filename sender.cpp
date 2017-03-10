#include <QUdpSocket>
#include "sender.h"

Sender::Sender(quint16 p)
    :port(p)
{
    udpSocket = new QUdpSocket();
    TEST_messageNo = 1;
}

//"1,2,3"
void Sender::broadcastDatagram(QString message)
{
    //Encode
    QByteArray datagram;
    datagram.append(message);

    //Send
    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress::LocalHost, port);
    //Count message only for test
    TEST_messageNo++;
}
