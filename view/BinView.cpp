#include "BinView.h"
#include "core/ProjectManager.h"


BinView::BinView(ProjectManager *projectManager, QWidget *parent):QWidget(parent)
{
    m_projectManager = projectManager;
    m_stackedWidget = new QStackedWidget;
}

void BinView::update(){
    QList<QString> openList = m_projectManager->getOpenProjectsList();
    if(!openList.isEmpty()){

        for(int i = 0; i<openList.size() ; ++i){
            m_projectManager->openProject(openList[i]);
// TO DO : récupérer un "projet" renvoyé directement par le "projectManager"
//afin d'avoir accès à tout ce qu'il contient
            m_stackedWidget->addWidget(projectTab);
        }
    }
}
