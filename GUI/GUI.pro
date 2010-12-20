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
    signupdialog.cpp \
    eventwidget.cpp

HEADERS  += mainwindow.h \
    eventdelegate.h \
    signindialog.h \
    signupdialog.h \
    eventwidget.h

FORMS    += \
    mainwindow.ui \
    create_group.ui \
    signindialog.ui \
    signupdialog.ui \
    eventwidget.ui

RESOURCES += \
    resources.qrc
