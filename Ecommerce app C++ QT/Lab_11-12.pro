#-------------------------------------------------
#
# Project created by QtCreator 2018-06-04T20:55:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lab_11-12
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Controller.cpp \
    Phone.cpp \
    PhoneValidator.cpp \
    Repository.cpp \
    RepositoryException.cpp \
    UI.cpp \
    Utilities.cpp \
    adminhud.cpp \
    add.cpp \
    update.cpp \
    customerhud.cpp

HEADERS += \
        mainwindow.h \
    ../Temp/Controller.h \
    ../Temp/Phone.h \
    ../Temp/PhoneValidator.h \
    ../Temp/Repository.h \
    ../Temp/RepositoryException.h \
    ../Temp/UI.h \
    Controller.h \
    Phone.h \
    PhoneValidator.h \
    Repository.h \
    RepositoryException.h \
    UI.h \
    Utilities.h \
    adminhud.h \
    add.h \
    update.h \
    customerhud.h

FORMS += \
        mainwindow.ui \
    adminhud.ui \
    add.ui \
    update.ui \
    customerhud.ui

DISTFILES += \
    phones_CSV \
    phones_HTML \
    cart_HTML \
    cart_CSV
