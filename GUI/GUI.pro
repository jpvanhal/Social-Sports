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
    signindialog.cpp

HEADERS  += mainwindow.h \
    eventdelegate.h \
    signindialog.h

FORMS    += \
    Sign_in_window.ui \
    new_user_registration.ui \
    mainwindow.ui \
    create_group.ui \
    signindialog.ui

RESOURCES += \
    icons.qrc
