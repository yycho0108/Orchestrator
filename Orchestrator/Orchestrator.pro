#-------------------------------------------------
#
# Project created by QtCreator 2015-12-21T00:38:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Orchestrator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    orchestrate.cpp

HEADERS  += mainwindow.h \
    orchestrate.h

FORMS    += mainwindow.ui

CONFIG += c++11
