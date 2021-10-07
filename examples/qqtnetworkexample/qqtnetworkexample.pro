#-------------------------------------------------
#
# Project created by QtCreator 2017-10-17T21:33:06
#
#-------------------------------------------------
#include QQt's header (add QQt header to includepath)
include(../../src/qqt_header.pri)

#CONFIG += BUILD_SRC
contains (CONFIG, BUILD_SRC) {
    #if you want to build src but not link QQt in this project
    #include(../../src/qqt.pri)
} else {
    #if you want to link QQt library
    include(../qqt_library.pri)
}

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qqtnetworkexample
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


QT += core gui network sql xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport serialport bluetooth
greaterThan(QT_MAJOR_VERSION, 4): DEFINES += __QT5__

INCLUDEPATH +=  $$PWD

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qqtcloudprotocol.cpp \
    qqtlanprotocol.cpp \
    qqtnetworkmessage.cpp \
    qqtserialmessage.cpp \
    qqtuserserialprotocol.cpp

HEADERS += \
        mainwindow.h \
    qqtcloudprotocol.h \
    qqtlanprotocol.h \
    qqtnetworkmessage.h \
    qqtserialmessage.h \
    qqtuserserialprotocol.h

FORMS += \
        mainwindow.ui

CONFIG += mobility
MOBILITY = 

