#-------------------------------------------------
#
# Project created by QtCreator 2015-03-24T14:38:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RF
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        terminal.cpp \
        persona.cpp \
        donante.cpp \
        maleante.cpp \
    addplace.cpp

HEADERS  += mainwindow.h \
        terminal.h \
        persona.h \
        donante.h \
        maleante.h \
    addplace.h

FORMS    += mainwindow.ui \
    terminal.ui \
    addplace.ui
