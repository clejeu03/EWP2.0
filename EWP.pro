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


SOURCES += main.cpp \
    exportwindow.cpp \
    infoconception.cpp \
    Project.cpp \
    ProjectManager.cpp \
    Timeline.cpp \
    VideoUtils.cpp \
    Mouse.cpp \
    Camera.cpp \
    Path.cpp \
    core/VideoUtils.cpp \
    core/Timeline.cpp \
    core/ProjectManager.cpp \
    core/Project.cpp \
    core/Path.cpp \
    core/Mouse.cpp \
    core/main.cpp \
    core/Camera.cpp \
    view/infoconception.cpp \
    view/exportwindow.cpp

HEADERS  += \
    exportwindow.h \
    infoconception.h \
    Video.h \
    Project.h \
    ProjectManager.h \
    VideoUtils.h \
    Timeline.h \
    Drawable.h \
    Brush.h \
    Mouse.h \
    Camera.h \
    Path.h \
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
    view/exportwindow.h

FORMS    += \
    exportwindow.ui \
    infoconception.ui \
    openMediaList.ui \
    view/infoconception.ui \
    view/exportwindow.ui

#INCLUDEPATH += /usr/include/opencv /usr/include/opencv2
#LIBS += -Lopencv -Lopencv2

INCLUDEPATH += -l/usr/include/opencv -l/usr/include/opencv2
LIBS += -lopencv_core
LIBS += -lopencv_highgui


OTHER_FILES += player/playerStyleSheet.css \
    view/resources/Slider.qml \
    view/resources/interface.qml \
    view/resources/highlight.qml \
    view/resources/dynamic.qml \
    view/resources/app.qml \
    view/resources/play.png \
    view/resources/play.jpeg \
    view/resources/exit_hovered.png \
    view/resources/exit_clicked.png \
    view/resources/exit.png \
    view/resources/draw.png \
    view/resources/blue-23.png \
    view/resources/blue-16.png \
    view/resources/blue-10.png \
    view/resources/blue-02.png

RESOURCES += \
    timeline.qrc \
    view/timeline.qrc
