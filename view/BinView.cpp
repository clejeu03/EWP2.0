#include "BinView.h"
#include "core/Project.h"
#include "core/ProjectManager.h"

#include <QtWidgets>
#include <QDebug>

BinView::BinView(ProjectManager *projectManager, QWidget *parent):QWidget(parent)
{
    m_projectManager = projectManager;
    m_stackedWidget = new QStackedWidget;
    //DisplayMode(DEFAULT);
}

void BinView::update(){

    QList<Project*> openList = m_projectManager->getProjects();
    if(!openList.isEmpty()){
        for(int i = 0; i<openList.size() ; ++i){
            openList[i]->getProjectName();
            openList[i]->getVideoList();



            QButtonGroup *buttonGroup = new QButtonGroup(this);
            buttonGroup->setExclusive(false);
            QGridLayout *layout = new QGridLayout;
            layout->addWidget(new QPushButton(tr("Video1")), 0, 0);
            layout->addWidget(new QPushButton(tr("Video2")),0, 1);
            layout->addWidget(new QPushButton(tr("Vidéo3")), 1, 0);

            QToolButton *textButton = new QToolButton;
            textButton->setCheckable(true);
            buttonGroup->addButton(textButton);
            textButton->setIcon(QIcon(QPixmap(":/images/textpointer.png")));
            textButton->setIconSize(QSize(50, 50));
            QGridLayout *textLayout = new QGridLayout;
            textLayout->addWidget(textButton, 0, 0, Qt::AlignHCenter);
            textLayout->addWidget(new QLabel(tr("Text")), 1, 0, Qt::AlignCenter);
            QWidget *textWidget = new QWidget;
            textWidget->setLayout(textLayout);
            layout->addWidget(textWidget, 1, 1);

            layout->setRowStretch(3, 10);
            layout->setColumnStretch(2, 10);

            QWidget *itemWidget = new QWidget;
            itemWidget->setLayout(layout);

            QGridLayout *backgroundLayout = new QGridLayout;
            backgroundLayout->addWidget(new QPushButton(tr("Blue Grid")), 0, 0);
            backgroundLayout->addWidget(new QPushButton(tr("White Grid")), 0, 1);
            backgroundLayout->addWidget(new QPushButton(tr("Gray Grid")), 1, 0);
            backgroundLayout->addWidget(new QPushButton(tr("No Grid")), 1, 1);

            backgroundLayout->setRowStretch(2, 10);
            backgroundLayout->setColumnStretch(2, 10);

            QWidget *backgroundWidget = new QWidget;
            backgroundWidget->setLayout(backgroundLayout);

            /*QToolBox *toolBox = new QToolBox;
            toolBox->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored));
            toolBox->setMinimumWidth(itemWidget->sizeHint().width());
            toolBox->addItem(itemWidget, tr("Basic Flowchart Shapes"));
            toolBox->addItem(backgroundWidget, tr("Backgrounds"));*/


            m_stackedWidget = new QStackedWidget;
            m_stackedWidget->setMinimumWidth(itemWidget->sizeHint().width());
            m_stackedWidget->addWidget(itemWidget);
            m_stackedWidget->addWidget(backgroundWidget);

                QVBoxLayout *vlayout = new QVBoxLayout;
                vlayout->addWidget(m_stackedWidget);
                setLayout(vlayout);
            qDebug() << "upadating !" ;
        }
    }
}

