#-------------------------------------------------
#
# Project created by QtCreator 2013-06-15T10:18:19
#
#-------------------------------------------------

QT       += core gui
QT       += network
INCLUDEPATH += ../apcomptec

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIClient
TEMPLATE = app


SOURCES += main.cpp\
    newfiledialog.cpp \
    loginwindow.cpp \
    datadialog.cpp \
    clientmain.cpp \
    client.cpp

HEADERS  += newfiledialog.h \
    loginwindow.h \
    datadialog.h \
    clientmain.h \
    client.h

FORMS    += newfiledialog.ui \
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
    Resource.qrc
