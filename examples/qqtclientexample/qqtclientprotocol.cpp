#include "qqtclientprotocol.h"

QDebug& operator << ( QDebug& dbg, const QQtClientMessage& msg )
{
    //这里打印一下，报文里面到底有什么信息，
    //一般到这里的，都是被解析好的message。

    dbg.nospace() << "{" << hex << msg.getBSize() << "}";
    return dbg.space();
}

QQtClientProtocol* QQtClientConnectionInstance ( QObject* parent )
{
    static QQtClientProtocol* p0 = NULL;
    static QQtTcpClient* s0 = NULL;
    if ( !p0 && !s0 )
    {
        p0 = new QQtClientProtocol ( parent );

        s0 = new QQtTcpClient ( parent );
        s0->installProtocol ( p0 );
        QStringList ip;
        ip << "192.168.0.100";
        s0->setServerIPAddress ( ip );
        s0->setServerPort ( 8001 );

        s0->sendConnectToHost();

    }

    return p0;
}


QQtClientProtocol* QQtClientUdpConnectionInstance ( QObject* parent )
{
    static QQtClientProtocol* p0 = NULL;
    static QQtUdpClient* s0 = NULL;
    if ( !p0 && !s0 )
    {
        p0 = new QQtClientProtocol ( parent );

        s0 = new QQtUdpClient ( parent );
        s0->installProtocol ( p0 );
        QStringList ip;
        ip << "192.168.0.100";
        s0->setServer ( ip[0], 8001 );
        //我接收服务器消息，所以需要绑定本地端口
        s0->bind ( QHostAddress::Any, 8500 );
    }

    return p0;
}
