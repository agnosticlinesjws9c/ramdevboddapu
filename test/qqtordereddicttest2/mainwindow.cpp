#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qqtcore.h>
#include <qqtdictionary.h>

//#define QDictionary QQtDictionary
typedef QQtDictionary QDictionary;


// BAD EXPORT FOUND [MSVC2015]
#include <qqtordereddictionary.h>

//#include <qqtordereddictionary.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pline() << "aaa";
    QDictionary d1;
    d1["b"] = 'b';
    pline() << d1;

    //QQtOrderedDictionary d2;
    //d2["b"] = 'b';
    //d2["a"] = 'a';
}

MainWindow::~MainWindow()
{
    delete ui;
}
