#-------------------------------------------------
#
# Project created by QtCreator 2017-02-22T11:09:24
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Simulator
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


SOURCES += main.cpp\
        mainwindow.cpp\
        sender.cpp \
        receiver.cpp \
    room.cpp \
    blinds.cpp \
    window.cpp \
    grass.cpp \
    door.cpp \
    house.cpp \
    sun.cpp \
    light.cpp


HEADERS  += mainwindow.h\
        sender.h \
        receiver.h \
    room.h \
    blinds.h \
    window.h \
    grass.h \
    door.h \
    house.h \
    sun.h \
    light.h


FORMS    += mainwindow.ui
