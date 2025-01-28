#this configration need Qt Creator set default build directory
#%{CurrentProject:Name}/%{Qt:Version}/%{CurrentKit:FileSystemName}/%{CurrentBuild:Name}")}

#这里暂时使用QSYS - FileSystemName这样的决定格式。
#如果QtCreator把编译器名称、FileSystemName传递过来就好了。
#或者QtCreator把Qt SDK目录名传过来也好。
#或者QtCreator自动生成QSYS描述符、FileSystemName，并且传递过来，也好。
#哎，但是现在没有，无奈之下，用户设定QSYS。

#FileSystemName的终极状态是编译器_目标系统名，比如gcc_macOS, clang_macOS这样。

#当工程编译目标相同,可是编译配置的Qt版本不同的时候,这个机制有一点点缺点,
#使用相同的中间编译目录吗? 很明显,这不合理?No,这很合理.Qt版本变化,引起链接库变化,但是,还是Qt,依然是Qt.程序中应当注意使用的Qt库(Qt4和Qt5库名字不太一样)和版本(版本号不一样,源代码会有点小区别,需要注意兼容性).
#比如桌面 gcc_64的Qt4 和 gcc_64的Qt5,不合适使用相同的中间编译目录,可是他们的FileSystemName都是Linux64,导致中间编译目录相同.
#为此,做出改进? No,用户请注意电脑上用Qt5开发就不要用Qt4,如果使用Qt4,请换电脑进行开发.(或者全部rebuild?其实Qt的版本之间引起的差异,如果不大,混用没什么问题,Qt库只能使用一个版本的)
#整体而言,Qt版本变化,引发的编译会比较多源文件.建议使用不同电脑开发.

#原理
#Qt Creator kit页的FileSystemName Creator自己用,忘记了传给qmake.(存储于Qt Creator配置区域)
#工程构建和配置页(存储于.pro.userxxx)里的环境变量QSYS给qmake用.
#如果用户在pro里面设置QMAKE.KIT QMAKE.SYSNAME,Qt Creator从qmake里读也挺好的.

#You need define a env variable QSYS=XX
#target arch type
#注释
#config += xxx qmake用配置开关
#$$(XXX) 环境变量XXX
#$${XXX} qmake用变量XXX
#XXX = AAA 给qmake用变量XXX赋值
#DEFINES += XXX 源代码用宏 和上边的XXX可以重名,但是是两回事,不干扰.

QSYS_PRIVATE = $$(QSYS)
#源文件内平台小差异
#QSYS -> 源文件宏
#Embedded __EMBEDDED_LINUX__
#MIPS __MIPS_LINUX__
#ARM __ARM_LINUX__
#Linux __LINUX__
#LINUX64 __LINUX64__
#Win32 __WIN32__
#Win64 __WIN64__
#macOS __DARWIN__
#Android __ANDROID__
#AndroidX86 __ANDROIDX86__
equals(QSYS_PRIVATE, Embedded) {
    #embedded common macro
    DEFINES += __EMBEDDED_LINUX__
} else:equals(QSYS_PRIVATE, Arm32) {
    DEFINES += __EMBEDDED_LINUX__
    #arm32 private
    DEFINES += __ARM_LINUX__
} else:equals(QSYS_PRIVATE, Mips32) {
    DEFINES += __EMBEDDED_LINUX__
    #mips32 private
    DEFINES += __MIPS_LINUX__
} else:equals(QSYS_PRIVATE, Linux) {
    DEFINES += __LINUX__
} else:equals(QSYS_PRIVATE, LINUX64) {
    DEFINES += __LINUX64__
} else:equals(QSYS_PRIVATE, Win32) {
    DEFINES += __WIN32__
} else:equals(QSYS_PRIVATE, Win64) {
    DEFINES += __WIN64__
} else:equals(QSYS_PRIVATE, macOS) {
    DEFINES += __DARWIN__
} else:equals(QSYS_PRIVATE, iOS) {
    DEFINES += __IOS__
} else:equals(QSYS_PRIVATE, iOSSimulator) {
    DEFINES += __IOS__
    #TODO:no qcustomplot word printer process
} else:equals(QSYS_PRIVATE, Android) {
    DEFINES += __ANDROID__
} else:equals(QSYS_PRIVATE, AndroidX86) {
    DEFINES += __ANDROID__
    DEFINES += __ANDROIDX86__ #可能废弃
}

#QMAKESPEC_NAME = $${QMAKESPEC}
#QMAKESPEC_NAME ~= s@^/.*/([^/]+)/?@\1@g
#QMAKESPECS = $${QMAKESPEC}
#QMAKESPECS ~= s:/[^/]*$::p
#message (used spec: $$QMAKESPEC_NAME at here: $$QMAKESPECS )
#equals(QMAKESPEC_NAME, Embedded) {
#    #embedded common macro
#    DEFINES += __EMBEDDED_LINUX__
#} else:equals(QMAKESPEC_NAME, *arm*) {
#    DEFINES += __EMBEDDED_LINUX__
#    #arm32 private
#    DEFINES += __ARM_LINUX__
#} else:equals(QMAKESPEC_NAME, *mips*) {
#    QT += multimedia
#    DEFINES += __EMBEDDED_LINUX__
#    #mips32 private
#    DEFINES += __MIPS_LINUX__
#} else:equals(QMAKESPEC_NAME, linux-g++-32) {
#    DEFINES += __LINUX__
#} else:equals(QMAKESPEC_NAME, linux-g++) {
#    DEFINES += __LINUX64__
#} else:equals(QMAKESPEC_NAME, win32-*) {
#    DEFINES += __WIN32__
#} else:equals(QMAKESPEC_NAME, win64-*) {
#    DEFINES += __WIN64__
#} else:equals(QMAKESPEC_NAME, macx-ios-*) {
#    DEFINES += __IOS__
#} else:equals(QMAKESPEC_NAME, iOSSimulator) {
#    DEFINES += __IOS__
#} else:equals(QMAKESPEC_NAME, macx-*) {
#    DEFINES += __DARWIN__
#} else:equals(QMAKESPEC_NAME, android-*) {
#    DEFINES += __ANDROID__
#} else:equals(QMAKESPEC_NAME, AndroidX86) {
#    DEFINES += __ANDROID__
#    #todo:no qcustomplot word printer
#}

#################################################################
##variables
#################################################################
CONFIG(debug, debug|profile|release):BUILD=Debug
CONFIG(profile, debug|profile|release):BUILD=Profile
CONFIG(release, debug|profile|release):BUILD=Release
equals(QSYS_PRIVATE, Embedded) {
    SYSNAME = Embedded
} else:equals(QSYS_PRIVATE, Arm32) {
    SYSNAME = Arm32
} else:equals(QSYS_PRIVATE, Mips32) {
    SYSNAME = Mips32
} else:equals(QSYS_PRIVATE, Linux) {
    SYSNAME = Linux
} else:equals(QSYS_PRIVATE, LINUX64) {
    SYSNAME = Linux64
} else:equals(QSYS_PRIVATE, Win32) {
    SYSNAME = Windows
} else:equals(QSYS_PRIVATE, Win64) {
    SYSNAME = Win64
} else:equals(QSYS_PRIVATE, macOS) {
    SYSNAME = MacOS
} else:equals(QSYS_PRIVATE, iOS) {
    SYSNAME = iOS
} else:equals(QSYS_PRIVATE, iOSSimulator) {
    SYSNAME = iOS-simulator
} else:equals(QSYS_PRIVATE, Android) {
    SYSNAME = Android
} else:equals(QSYS_PRIVATE, AndroidX86) {
    SYSNAME = Android_x86
}

#if you dont modify Qt Creator default build directory, you may need mod this path variable.
#link operation all will need this variable
QSYS_STD_DIR = $${QT_VERSION}/$${SYSNAME}/$${BUILD}

message(qqt_qkit.pri)
message(Build $${TARGET} to $${QSYS_PRIVATE} \(QSYS=$${QSYS_PRIVATE} is configed in project build page.\) )
message(Build $${TARGET} at $${QSYS_STD_DIR} \(Qt Kit page FileSystem Name=$${SYSNAME}\) )
message(Build $${TARGET} on $${QMAKE_HOST.os} \(Operating System=$${QMAKE_HOST.os}\) )
isEmpty(QSYS_PRIVATE) : message(Build $${TARGET} Qt Kit page FileSystem Name is decided by env variable QSYS. Please set it. )

isEmpty(QSYS_PRIVATE) {
    message(env variable QSYS is required!)
    message(pleace check qqt_qkit.pri)
    error("error occured, please check build output panel.")
}
