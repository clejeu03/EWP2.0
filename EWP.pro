#-------------------------------------------------
#
# Project created by QtCreator 2013-01-14T10:31:32
#
#-------------------------------------------------

QT       += core gui
QT += multimedia multimediawidgets
QT += network sql
QT += declarative
QT += quick qml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EWP
TEMPLATE = app


SOURCES += \
    core/VideoUtils.cpp \
    core/Timeline.cpp \
    core/ProjectManager.cpp \
    core/Project.cpp \
    core/Path.cpp \
    view/infoconception.cpp \
    view/exportwindow.cpp \
    view/Timelineview.cpp \
    view/MainWindow.cpp \
    view/MdiChild.cpp \
    view/BinView.cpp \
    main.cpp

HEADERS  += \
    core/VideoUtils.h \
    core/Video.h \
    core/Timeline.h \
    core/ProjectManager.h \
    core/Project.h \
    core/Path.h \
    core/Mouse.h \
    core/Drawable.h \
    core/Camera.h \
    core/Brush.h \
    view/infoconception.h \
    view/exportwindow.h \
    view/Timelineview.h \
    view/MainWindow.h \
    view/MdiChild.h \
    view/BinView.h

FORMS    += \
    view/infoconception.ui \
    view/exportwindow.ui

#INCLUDEPATH += /usr/include/opencv /usr/include/opencv2
#LIBS += -Lopencv -Lopencv2

INCLUDEPATH += -l/usr/include/opencv -l/usr/include/opencv2
LIBS += -lopencv_core
LIBS += -lopencv_highgui

RESOURCES += \
    view/resources/viewResources.qrc

OTHER_FILES += \
    view/styles/style.css \
    view/styles/toolbar.css

