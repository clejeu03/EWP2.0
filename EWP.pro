#-------------------------------------------------
#
# Project created by QtCreator 2013-01-14T10:31:32
#
#-------------------------------------------------

QT       += core gui
QT += multimedia multimediawidgets
QT += network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EWP
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    chutier.cpp \
    moniteur.cpp \
    timeline.cpp \
    pinceau.cpp \
    exportwindow.cpp \
    videoplayer.cpp \
    infoconception.cpp

HEADERS  += \
    mainwindow.h \
    chutier.h \
    moniteur.h \
    timeline.h \
    pinceau.h \
    exportwindow.h \
    videoplayer.h \
    infoconception.h

FORMS    += \
    exportwindow.ui \
    infoconception.ui

#INCLUDEPATH += /usr/include/opencv /usr/include/opencv2
#LIBS += -Lopencv -Lopencv2

INCLUDEPATH += -l/usr/include/opencv -l/usr/include/opencv2
LIBS += -lopencv_core
LIBS += -lopencv_highgui


OTHER_FILES += player/playerStyleSheet.css
