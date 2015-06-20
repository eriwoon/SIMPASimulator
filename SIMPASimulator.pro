#-------------------------------------------------
#
# Project created by QtCreator 2015-06-17T20:45:10
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SIMPASimulator
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    chttpprocess.cpp

HEADERS  += dialog.h \
    chttpprocess.h

FORMS    += dialog.ui
