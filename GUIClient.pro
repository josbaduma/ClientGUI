#-------------------------------------------------
#
# Project created by QtCreator 2013-06-15T10:18:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    newfiledialog.cpp \
    loginwindow.cpp \
    datadialog.cpp \
    clientmain.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    newfiledialog.h \
    loginwindow.h \
    datadialog.h \
    clientmain.h \
    client.h

FORMS    += mainwindow.ui \
    newfiledialog.ui \
    loginwindow.ui \
    datadialog.ui \
    clientmain.ui

OTHER_FILES += \
    ProtocoloV1.0.pdf \
    lunapic_13545596828390_1.gif \
    logoTEC_gd.png \
    gif-video-63169.jpg \
    Electric Avennue.wav

RESOURCES += \
    Resources.qrc
