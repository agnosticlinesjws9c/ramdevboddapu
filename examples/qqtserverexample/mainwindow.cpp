#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow ( QWidget* parent ) :
    QMainWindow ( parent ),
    ui ( new Ui::MainWindow )
{
    ui->setupUi ( this );
    pm0 = QQtServerInstance ( this );
    //pm0 = QQtServer2Instance(this);
    connect ( pm0, SIGNAL ( notifyToBusinessLevel ( const QQtProtocol*, const QQtMessage* ) ),
              this, SLOT ( recvANotify ( const QQtProtocol*, const QQtMessage* ) ) );

    //QQtServer2ConnectionInstance ( this );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recvANotify ( const QQtProtocol* protocol, const QQtMessage* message )
{
    QQtServerProtocol* p = ( QQtServerProtocol* ) protocol;
    QQtServerMessage* m = ( QQtServerMessage* ) message;

    pline() << QString ( m->getAData() );

    switch ( m->getACmd() )
    {
        case 0x01:
        {
            if ( QString ( m->getAData() ).contains ( "hello" ) )
                p->sendB1Command();
            else
                p->sendB10Command();
            break;
        }
        default:
            break;
    }
}
