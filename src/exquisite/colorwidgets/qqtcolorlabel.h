#ifndef QQTCOLORLABEL_H
#define QQTCOLORLABEL_H

#include <QLabel>
#include <QRgb>

#include <qqt-local.h>
#include <qqtcore.h>

class QQTSHARED_EXPORT QQtColorLabel : public QLabel
{
    Q_OBJECT
public:
    explicit QQtColorLabel ( QWidget* parent = nullptr );
    virtual ~QQtColorLabel() {}

    void setColor ( const QRgb& rgb );

    QRgb getColor();
signals:

public slots:

private:
    QRgb mRgb;
};

#endif // QQTCOLORLABEL_H
