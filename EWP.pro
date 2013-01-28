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
<<<<<<< HEAD
    exportwindow.cpp \
    videoplayer.cpp
=======
    player/QOpenCVWidget.cpp \
    player/Player.cpp \
    exportwindow.cpp \
    infoconception.cpp
>>>>>>> 3cdce1526b4e85c54cc9d8df307a32fa151e0e9b

HEADERS  += \
    mainwindow.h \
    chutier.h \
    moniteur.h \
    timeline.h \
    pinceau.h \
<<<<<<< HEAD
    exportwindow.h \
    videoplayer.h
=======
    player/QOpenCVWidget.h \
    player/Player.h \
    exportwindow.h \
    infoconception.h
>>>>>>> 3cdce1526b4e85c54cc9d8df307a32fa151e0e9b

FORMS    += \
    exportwindow.ui \
    infoconception.ui

#INCLUDEPATH += /usr/include/opencv /usr/include/opencv2
#LIBS += -Lopencv -Lopencv2

INCLUDEPATH += -l/usr/include/opencv -l/usr/include/opencv2
LIBS += -lopencv_core
LIBS += -lopencv_highgui


OTHER_FILES += player/playerStyleSheet.css
