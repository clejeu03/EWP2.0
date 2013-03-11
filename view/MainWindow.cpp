#include "MainWindow.h"
#include "Timelineview.h"

#include <QVBoxLayout>

MainWindow::MainWindow(){

    QWidget *container = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout();
    TimelineView *timelineView = new TimelineView();
    layout->addWidget(timelineView);
    container->setLayout(layout);
    container->setMinimumHeight(380);
    container->setMinimumWidth(1050);
    setCentralWidget(container);
}
