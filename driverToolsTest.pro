QT += core network xml quick serialport widgets

CONFIG += c++11
CONFIG -= debug_and_release

TARGET = DriverTools
#RC_FILE = $$PWD/res/app.rc
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_NO_VERSION_TAGGING
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

buildDir = $$PWD/build/gcc-x86_64

DESTDIR = $$buildDir/bin
MOC_DIR = $$buildDir/temp
RCC_DIR = $$buildDir/temp
OBJECTS_DIR = $$buildDir/temp
UI_DIR = $$PWD/uimain

SOURCES += \
        main.cpp \
        src/arincComm429.cpp \
        src/buscomm.cpp \
        src/callc.cpp \
        src/diocomm.cpp \
        src/rs232comm.cpp \
        src/rs422comm.cpp \
        src/threadtask.cpp \
        src/uartfunc.cpp

RESOURCES += qml.qrc

TRANSLATIONS += \
    driverToolsTest_zh_CN.ts

HEADERS += \
    src/arincComm429.h \
    src/buscomm.h \
    src/callc.h \
    src/diocomm.h \
    src/drv_global.h \
    src/rs232comm.h \
    src/rs422comm.h \
    src/threadtask.h \
    src/uartfunc.h

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = $$buildDir/temp

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH = $$buildDir/temp

INCLUDEPATH += $$PWD/src/drv_202110151323 $$PWD/3rd/libcomm-pre.v0/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/src/drv_202110151323/release/ -ldrv
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/src/drv_202110151323/debug/ -ldrv
else:unix: LIBS += -L$$PWD/3rd/drv_202110151323 -ldrv -L$$PWD/3rd/libcomm-pre.v0/lib -lmauto

DEPENDPATH += $$PWD/src/drv_202110151323

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

DriverTools.files = $$PWD/3rd/drv_202110151323/*

DriverTools.path=$${DESTDIR}
INSTALLS += DriverTools


