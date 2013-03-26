#include "BinView.h"
#include "core/Project.h"
#include "core/ProjectManager.h"

#include <QtWidgets>
#include <QDebug>

BinView::BinView(ProjectManager *projectManager, QWidget *parent):QWidget(parent)
{
    m_projectManager = projectManager;
    //DisplayMode(DEFAULT);
}


void BinView::update(){

    QList<Project*> openList = m_projectManager->getProjects();
    if(!openList.isEmpty()){
        m_toolBox = new QToolBox;
        m_toolBox->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored));
        m_toolBox->setMinimumWidth(150);
        m_toolBox->setMaximumWidth(200);
        m_toolBox->setMaximumHeight(300);

        QHBoxLayout *lay = new QHBoxLayout(this);



        for(int i = 0; i<openList.size(); ++i){
            QListWidget *widgetList = new QListWidget;
            for(int j = 0; j<openList[i]->getVideoListSize();++j){
                 widgetList->addItem(openList[i]->getVideoList()[j]->getCompleteName());
            }

            QGridLayout *layout = new QGridLayout;
            layout->addWidget(widgetList, 0, 0);

            QWidget *widget = new QWidget;
            widget->setLayout(layout);

            m_toolBox->addItem(widget, openList[i]->getProjectName());
        }

        lay->addWidget(m_toolBox);
        setLayout(lay);
        showMaximized();
    }
}

