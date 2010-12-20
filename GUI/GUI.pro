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
    eventwidget.cpp \
    newgroupdialog.cpp \
    invitetogroupdialog.cpp

HEADERS  += mainwindow.h \
    eventdelegate.h \
    signindialog.h \
    signupdialog.h \
    eventwidget.h \
    newgroupdialog.h \
    invitetogroupdialog.h

FORMS    += \
    mainwindow.ui \
    signindialog.ui \
    signupdialog.ui \
    eventwidget.ui \
    newgroupdialog.ui \
    invitetogroupdialog.ui

RESOURCES += \
    resources.qrc
