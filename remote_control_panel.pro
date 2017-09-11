#-------------------------------------------------
#
# Project created by QtCreator 2017-08-29T16:50:19
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = remote_control_panel
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    networks.cpp

HEADERS  += mainwindow.h \
    networks.h

FORMS    += mainwindow.ui
