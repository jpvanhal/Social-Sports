#-------------------------------------------------
#
# Project created by QtCreator 2010-11-27T08:59:56
#
#-------------------------------------------------

QT       += core gui

TARGET = GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    eventdelegate.cpp \
    signindialog.cpp \
    signupdialog.cpp

HEADERS  += mainwindow.h \
    eventdelegate.h \
    signindialog.h \
    signupdialog.h

FORMS    += \
    mainwindow.ui \
    create_group.ui \
    signindialog.ui \
    signupdialog.ui

RESOURCES += \
    icons.qrc
