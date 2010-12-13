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
    eventdelegate.cpp

HEADERS  += mainwindow.h \
    eventdelegate.h

FORMS    += mainwindow.ui \
    Sign_in_window.ui \
    new_user_registration.ui \
    main.ui \
    create_group.ui

RESOURCES += \
    icons.qrc
