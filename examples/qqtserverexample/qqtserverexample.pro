#-------------------------------------------------
#
# Project created by QtCreator 2018-04-22T12:57:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qqtserverexample
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qqtserverprotocolmanager.cpp \
    qqtserver2protocolmanager.cpp

HEADERS += \
        mainwindow.h \
    qqtserverprotocolmanager.h \
    qqtserver2protocolmanager.h

FORMS += \
        mainwindow.ui

#qmake_pre/post_link will work after source changed but not pro pri changed.
system("touch main.cpp")

#-------------------------------------------------
#link qqt library
#if you link a library to your app, on android you must select the running kit to the app, not LibQQt e.g.
#user can modify any infomation under this annotation
#-------------------------------------------------
include(../../src/app_base_manager.pri)
