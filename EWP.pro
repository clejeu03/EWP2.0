#-------------------------------------------------
#
# Project created by QtCreator 2013-01-14T10:31:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EWP
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    chutier.cpp \
    moniteur.cpp \
    timeline.cpp

HEADERS  += \
    mainwindow.h \
    chutier.h \
    moniteur.h \
    timeline.h

FORMS    +=

INCLUDEPATH += -l/usr/include/opencv -l/usr/include/opencv2
LIBS += -Lopencv -Lopencv2
