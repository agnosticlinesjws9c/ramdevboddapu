#include "usernode5protocol.h"

QDebug& operator << ( QDebug& dbg, const UserNode5Message& msg )
{
    //这里打印一下，报文里面到底有什么信息，
    //一般到这里的，都是被解析好的message。

    dbg.nospace() << "{" << hex << msg.size() << "}";
    return dbg.space();
}

UserNode5Protocol* UserNode5ConnectionInstance ( QObject* parent )
{
    static UserNode5Protocol* p0 = NULL;
    static QQtTcpServer* s0 = NULL;
    if ( !p0 && !s0 )
    {
        p0 = new UserNode5Protocol ( parent );

        s0 = new QQtTcpServer ( parent );
        s0->installProtocol ( p0 );
        s0->listen ( QHostAddress::Any, 8000 );

    }

    return p0;
}
