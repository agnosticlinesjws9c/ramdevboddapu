#here is all your app common defination and configration
#change these path on your computer
message(Link QQt to $${TARGET} $${QKIT_} \
    at $${QT_VERSION} $${SYSNAME} $${BUILD} \
    on $${QMAKE_HOST.os})

equals(QMAKE_HOST.os, Darwin) {
    BUILDROOT = /Users/abel/Develop/c0-buildstation
} else: equals(QMAKE_HOST.os, Linux) {
    BUILDROOT = /home/abel/Develop/c0-buildstation
} else: equals(QMAKE_HOST.os, Windows) {
    BUILDROOT = C:/Users/Administrator/Develop/c0-build
}

QQT_OUT_PWD = QQt/$${QT_VERSION}/$${SYSNAME}/$${BUILD}/src
QQT_OUT_BIN = $${QQT_OUT_PWD}/$${DESTDIR}
QQT_LIB_PWD = $$BUILDROOT/$$QQT_OUT_BIN
#message (QQt Build: $$QQT_LIB_PWD)

contains(DEFINES, __DARWIN__) {
    lessThan(QT_MAJOR_VERSION, 5):{
        LIBS += -L$${QQT_LIB_PWD}
        LIBS += -l QQt
    } else {
        LIBS += -F$${QQT_LIB_PWD}
        LIBS += -framework QQt
    }
} else {
    LIBS += -L$${QQT_LIB_PWD}
    LIBS += -l QQt
}

############
##install
############
#CONFIG += can_install
can_install:equals(QKIT_, EMBEDDED) {
    target.path = /Application
    INSTALLS += target
} else: unix {
    equals(QKIT_, macOS) {
        target.path = /Applications
        INSTALLS += target
    }
}

#not good to use, some function error
#CONFIG += qmake_deploy
qmake_deploy:equals(QKIT_, macOS) {
    QQT_MAJOR_VERSION = 1
    QMAKE_POST_LINK += install_name_tool -change QQt.framework/Versions/$${QQT_MAJOR_VERSION}/QQt \
         @rpath/QQt.framework/Versions/$${QQT_MAJOR_VERSION}/QQt \
         bin/$${TARGET}.app/Contents/MacOS/$$TARGET &
    QMAKE_POST_LINK += cp -fr ../../src/bin/QQt.framework \
            bin/$${TARGET}.app/Contents/Frameworks &
    QMAKE_POST_LINK += macdeployqt bin/$${TARGET}.app -qmldir=$$PWD -verbose=1
}

############
##config defination
############
equals(QKIT_, macOS) {
    CONFIG += app_bundle
}
equals(QKIT_, Android) {
    CONFIG += mobility
    MOBILITY =
    #DISTFILES += \
    #    android/AndroidManifest.xml

    #ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
}

