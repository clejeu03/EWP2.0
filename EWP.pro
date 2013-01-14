#-------------------------------------------------
#
# Project created by QtCreator 2013-01-14T10:31:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EWP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/include/opencv2/opencv.hpp
LIBS += -L usr/include/opencv2/opencv.hpp
