#include "MainWindow.h"
#include "MdiChild.h"
#include "Timelineview.h"
#include "core/Video.h"
#include "core/Timeline.h"
#include "BinView.h"

#include <QtWidgets>
#include <QDebug>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QMenu>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QApplication>
#include <QMdiArea>
#include <QMdiSubWindow>


MainWindow::MainWindow(){


    m_mdiArea = new QMdiArea;
    setCentralWidget(m_mdiArea);
    connect(m_mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),
            this, SLOT(updateMenu()));
    m_windowMapper = new QSignalMapper(this);
    connect(m_windowMapper, SIGNAL(mapped(QWidget*)),
            this, SLOT(setActiveSubWindow(QWidget*)));

    loadStyles();

    createActions();
    createMenu();
    createToolBar();
    createStatusBar();
    updateMenu();

    readSettings();

    setWindowTitle(tr("EWP 2.0"));
    setUnifiedTitleAndToolBarOnMac(true);


}

void MainWindow::loadStyles(){
    QFile File("../EWP2.0/view/styles/style.css");
    if(!File.open(QFile::ReadOnly)){
        qDebug() << "EWP : couldn't open the stylesheet file";
    }
    QString StyleSheet = QLatin1String(File.readAll());
    setStyleSheet(StyleSheet);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    m_mdiArea->closeAllSubWindows();
    if (m_mdiArea->currentSubWindow()) {
        event->ignore();
    } else {
        writeSettings();
        event->accept();
    }
}

void MainWindow::createMenu()
{
    fileMenu = menuBar()->addMenu(tr("&Fichier"));
    fileMenu->addAction(m_newAct);
    fileMenu->addAction(m_openAct);
    fileMenu->addAction(m_saveAct);
    fileMenu->addAction(m_saveAsAct);
    fileMenu->addSeparator();
    /*fileMenu->addAction(m_importAct);
    fileMenu->addAction(m_exportAct);*/
    fileMenu->addAction(m_quitAct);

    scriptMenu = menuBar()->addMenu(tr("&Script"));
    /*scriptMenu->addAction(m_applyScriptAct);
    scriptMenu->addAction(m_suppressScriptAct);*/

    playerMenu = menuBar()->addMenu(tr("&Player"));
    //playerMenu->addAction(m_playLastClipAct);

    processMenu = menuBar()->addMenu(tr("&Process"));
    //processMenu->addAction(m_renderAct);

    windowMenu = menuBar()->addMenu(tr("&Window"));
    updateWindowMenu();
    connect(windowMenu, SIGNAL(aboutToShow()), this, SLOT(updateWindowMenu()));

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(m_aboutAct);
}

void MainWindow::createToolBar(){
    QDockWidget *dock = new QDockWidget(this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);

    QWidget *toolBox = new QWidget;
    QGridLayout *grid = new QGridLayout;

    QPushButton *newProjectButton = new QPushButton(tr("Nouveau"));
    connect(newProjectButton, SIGNAL(clicked()), this, SLOT(newProject()));
    grid->addWidget(newProjectButton, 0, 0);

    QPushButton *openProjectButton = new QPushButton(tr("Ouvrir"));
    connect(openProjectButton, SIGNAL(clicked()), this, SLOT(openProject()));
    grid->addWidget(openProjectButton, 0, 1);

    QPushButton *importButton = new QPushButton(tr("Importer"));
    connect(importButton, SIGNAL(clicked()), this, SLOT(importFile()));
    grid->addWidget(importButton, 0, 2);

    toolBox->setLayout(grid);


    dock->setWidget(toolBox);
    dock->setFeatures(QDockWidget::NoDockWidgetFeatures);
    dock->setMaximumHeight(100);
    dock->setMinimumHeight(50);
    dock->setMinimumWidth(200);
    dock->setMaximumWidth(400);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
}

void MainWindow::updateMenu()
{
    bool hasMdiChild = (activeMdiChild() != 0);
    m_saveAct->setEnabled(hasMdiChild);
    m_saveAsAct->setEnabled(hasMdiChild);
    m_closeAct->setEnabled(hasMdiChild);
    m_closeAllAct->setEnabled(hasMdiChild);
    m_tileAct->setEnabled(hasMdiChild);
    m_cascadeAct->setEnabled(hasMdiChild);
    /*m_importAct->setEnabled(hasMdiChild);
    m_exportAct->setEnabled(hasMdiChild);
    m_renderAct->setEnabled(hasMdiChild);
    m_playLastClipAct->setEnabled(hasMdiChild);*/
    m_separatorAct->setVisible(hasMdiChild);
}

void MainWindow::updateWindowMenu(){

    windowMenu->clear();
    windowMenu->addAction(m_closeAct);
    windowMenu->addAction(m_closeAllAct);
    windowMenu->addSeparator();
    windowMenu->addAction(m_tileAct);
    windowMenu->addAction(m_cascadeAct);
    windowMenu->addAction(m_separatorAct);

    QList<QMdiSubWindow *> windows = m_mdiArea->subWindowList();
    m_separatorAct->setVisible(!windows.isEmpty());

    for (int i = 0; i < windows.size(); ++i) {
        MdiChild *child = qobject_cast<MdiChild *>(windows.at(i)->widget());

        QString text;
        if (i < 9) {
            text = tr("&%1 %2").arg(i + 1)
                               .arg(child->userFriendlyCurrentFile());
        } else {
            text = tr("%1 %2").arg(i + 1)
                              .arg(child->userFriendlyCurrentFile());
        }
        QAction *action  = windowMenu->addAction(text);
        action->setCheckable(true);
        action ->setChecked(child == activeMdiChild());
        connect(action, SIGNAL(triggered()), m_windowMapper, SLOT(map()));
        m_windowMapper->setMapping(action, windows.at(i));
    }
}

void MainWindow::readSettings()
{
    QSettings settings("QtProject", "MDI Example");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();
    move(pos);
    resize(size);
}

void MainWindow::writeSettings()
{
    QSettings settings("QtProject", "MDI Example");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}

MdiChild *MainWindow::activeMdiChild()
{
    if (QMdiSubWindow *activeSubWindow = m_mdiArea->activeSubWindow())
        return qobject_cast<MdiChild *>(activeSubWindow->widget());
    return 0;
}

QMdiSubWindow *MainWindow::findMdiChild(const QString &fileName)
{
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();

    foreach (QMdiSubWindow *window, m_mdiArea->subWindowList()) {
        MdiChild *mdiChild = qobject_cast<MdiChild *>(window->widget());
        if (mdiChild->currentFile() == canonicalFilePath)
            return window;
    }
    return 0;
}


void MainWindow::setActiveSubWindow(QWidget *window)
{
    if (!window)
        return;
    m_mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(window));
}

void MainWindow::createActions()
{
    //Modèle si ajout d'icones --> saveAct = new QAction(QIcon(":/images/save.png"), tr("&Save"), this);

    m_newAct = new QAction(tr("&Nouveau Projet"), this);
    m_newAct->setShortcuts(QKeySequence::New);
    m_newAct->setStatusTip(tr("Créer un nouveau projet"));
    connect(m_newAct, SIGNAL(triggered()), this, SLOT(newProject()));

    m_openAct = new QAction(tr("&Ouvrir un projet..."), this);
    m_openAct->setShortcuts(QKeySequence::Open);
    m_openAct->setStatusTip(tr("Ouvrir un projet existant"));
    connect(m_openAct, SIGNAL(triggered()), this, SLOT(openProject()));

    m_saveAct = new QAction(tr("&Sauvegarder"), this);
    m_saveAct->setShortcuts(QKeySequence::Save);
    m_saveAct->setStatusTip(tr("Sauvegarder le projet courant"));
    connect(m_saveAct, SIGNAL(triggered()), this, SLOT(save()));

    m_saveAsAct = new QAction(tr("S&auvegarder Sous..."), this);
    m_saveAsAct->setShortcuts(QKeySequence::SaveAs);
    m_saveAsAct->setStatusTip(tr("Sauvegarder le projet sous un nouveau nom"));
    connect(m_saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

    m_quitAct = new QAction(tr("&Quitter"), this);
    m_quitAct->setShortcuts(QKeySequence::Quit);
    m_quitAct->setStatusTip(tr("Quitter l'application"));
    connect(m_quitAct, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

/*
    m_applyScriptAct = new QAction(tr("Appliquer..."), this);
    m_applyScriptAct->setStatusTip(tr("Appliquer un script"));
    connect(m_applyScriptAct, SIGNAL(triggered()), qApp, SLOT(applyScript()));

    m_suppressScriptAct = new QAction(tr("Enlever"), this);
    m_suppressScriptAct->setStatusTip(tr("Annuler l'appliquation d'un script"));
    connect(m_suppressScriptAct, SIGNAL(triggered()), qApp, SLOT(suppressScript()));

    m_playLastClipAct = new QAction(tr("&Lire"), this);
    m_playLastClipAct->setShortcuts(QKeySequence::Play);
    m_playLastClipAct->setStatusTip(tr("Lire dans le player le dernier fichier vidéo importé"));
    connect(m_playLastClip, SIGNAL(triggered()), qApp, SLOT(play()));

    m_renderAct = new QAction(tr("&Rendu"), this);
    m_renderAct->setStatusTip(tr("Lancer le rendu"));
    connect(m_renderAct, SIGNAL(triggered()), qApp, SLOT(render()));


    m_importAct = new QAction(tr("&Importer"), this);
    m_importAct->setStatusTip(tr("Importer une vidéo dans le projet courant"));
    connect(m_importAct, SIGNAL(triggered()), qApp, SLOT(importFile()));

    m_exportAct = new QAction(tr("&Exporter"), this);
    m_exportAct->setStatusTip(tr("Importer une vidéo dans le projet courant"));
    connect(m_exportAct, SIGNAL(triggered()), qApp, SLOT(exportFile()));
*/
    m_closeAct = new QAction(tr("&Fermer"), this);
    m_closeAct->setStatusTip(tr("Fermer la fenetre active"));
    connect(m_closeAct, SIGNAL(triggered()),
            m_mdiArea, SLOT(closeActiveSubWindow()));

    m_closeAllAct = new QAction(tr("Fermer &tout"), this);
    m_closeAllAct->setStatusTip(tr("Fermer toutes les fenetres"));
    connect(m_closeAllAct, SIGNAL(triggered()),
            m_mdiArea, SLOT(closeAllSubWindows()));

    m_tileAct = new QAction(tr("&Mosaique"), this);
    m_tileAct->setStatusTip(tr("Organise les fenetres en mosaique"));
    connect(m_tileAct, SIGNAL(triggered()), m_mdiArea, SLOT(tileSubWindows()));

    m_cascadeAct = new QAction(tr("&Cascade"), this);
    m_cascadeAct->setStatusTip(tr("Organise les fenetres en cascade"));
    connect(m_cascadeAct, SIGNAL(triggered()), m_mdiArea, SLOT(cascadeSubWindows()));

    m_separatorAct = new QAction(this);
    m_separatorAct->setSeparator(true);

    m_aboutAct = new QAction(tr("&About"), this);
    m_aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(m_aboutAct, SIGNAL(triggered()), this, SLOT(about()));

}

void MainWindow::createStatusBar(){
    statusBar()->showMessage(tr("Ready"));
}


void MainWindow::newProject()
{
    QDockWidget *dock = new QDockWidget(this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);

    //!! TO DO : A changer avec BinView !!
    /****===============TESTS=======================*****/
    Video *video1 = new Video("/home/cecilia/Vidéos/bunny.mp4");
    Video *video2 = new Video("/home/cecilia/Vidéos/ludovik.mp4");

    QMap<int, Video*> sourceMap;
    sourceMap[0]= video1;
    sourceMap[1] = video2;
    Timeline *timeline = new Timeline(sourceMap);

    qDebug() << "__________CREATION__________";
    qDebug() << "drawing status : " << timeline->getDrawingStatus();
    qDebug() << "list size : " << timeline->getVideoList();
    qDebug() << "keys : " << timeline->getVideoList().uniqueKeys();

    //timeline.addVideo(video1);
    //timeline.addVideo(video2);

    qDebug() << "__________ADDING__________";
    qDebug() << "list size : " << timeline->getListSize();
    qDebug() << "keys : " << timeline->getVideoList().uniqueKeys();
    qDebug() << "adding 2 videos : " << timeline->getVideoList().value(0)->getCompleteName();
    qDebug() << "adding 2 videos : " << timeline->getVideoList().value(1)->getCompleteName();

    /****============================================*****/

    /*Drawing the Timeline View*/
    TimelineView *timelineView = new TimelineView(timeline);
    QDockWidget *dockTimeline = new QDockWidget(this);
    dockTimeline->setAllowedAreas(Qt::BottomDockWidgetArea | Qt::RightDockWidgetArea);
    dockTimeline->setWidget(timelineView);
    dockTimeline->setMinimumHeight(400);
    dockTimeline->setMinimumWidth(600);

    ProjectManager *projectManager = new ProjectManager();
    projectManager->newProject("/home/cecilia/Vidéos/", "Porjet1");
    projectManager->newProject("/home/cecilia/Vidéos/", "ProjetPlop2");
    projectManager->getProjects()[0]->importVideo("/home/cecilia/Vidéos/bunny.mp4");
    projectManager->getProjects()[0]->importVideo("/home/cecilia/Vidéos/ludovik.mp4");
    projectManager->getProjects()[1]->importVideo("/home/cecilia/Vidéos/bunny.mp4");
    projectManager->getProjects()[1]->importVideo("/home/cecilia/Vidéos/ludovik.mp4");

    BinView *binView = new BinView(projectManager);
    binView->update();
    dock->setWidget(binView);
    dock->setMaximumHeight(500);
    dock->setMinimumHeight(100);
    dock->setMinimumWidth(200);
    dock->setMaximumWidth(400);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
    addDockWidget(Qt::RightDockWidgetArea, dockTimeline);
}


void MainWindow::openProject()
{

    /*QString projectname = QFileDialog::getOpenFileName(this, "Ouvrir le fichier", "/home/");

    //AJOUTER LES FILTRES DE RESTRICTION

    if(projectname.isEmpty())
    {
        std::cout << "Aucun fichier n'a été sélectionné" << std::endl;
    }*/
}

void MainWindow::save()
{
    //lors de l'ouverture d'un projet, enregistrer le dossier de travail dans une variable.
    //si variable vide, rediriger vers Enregistrer sous...
    std::cout << "enregistrer" << std::endl;
}

void MainWindow::saveAs()
{
    //QString projectname = QFileDialog::getSaveFileName(this,tr("Enregistrer sous..."),"/home");
}

void MainWindow::importFile()
{
    /*
    //Charger une vidéo
    QStringList filters;
    filters << "Video files (*.mp4 *.avi *.mov)";

    QFileDialog dialog(this);
    dialog.setNameFilters(filters);
    dialog.setViewMode(QFileDialog::Detail);

    if(dialog.exec()){

         //afficher le nom de la vidéo et son type
        QString filePath = dialog.selectedFiles().first();

        m_vecPath.push_back(filePath);
        //std::cout<<"file :" << filePath.toStdString() <<std::endl;
         QString fileName = dialog.selectedFiles().first();
         fileName.remove(0, ( fileName.lastIndexOf("/")+1) );

         QList<QString> list;
         list.append(fileName);
         chutier->Add(list);

         //afficher le poid de la vidéo
         QFileInfo fileWeight(dialog.selectedFiles().first());
         qint64 size = 0;
         size = fileWeight.size()/1000000.;
         QString Size = QString::number(size, 10);

         QList<QString> listW;
         listW.append(Size);
         if(!listW.isEmpty())
         chutier->Weight(listW);

         //afficher un lien vers le moniteur +lecture accélérée ou retour en arrière

         QPixmap iconImage("/resources/play.jpeg");
         QIcon icon(iconImage.scaled(QSize(5,5)));
         QListWidgetItem butt = QListWidgetItem(icon, "Play");
         std::cout<<"creation_du_bouton"<<std::endl;
         chutier->Play(&butt);
         connect(butt.listWidget(), SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(launchVideo(QListWidgetItem*)) );

        QModelIndex button;
        int i;
        for(i=0;i<listW.size();++i){
            button = listW[i];
            if(QAbstractItemView::doubleClicked(button)){
                if(point = ){
                    QMediaPlayer mediaPlayer;
                    mediaPlayer.setMedia(QUrl::fromLocalFile(fileName));
                    QAbstractButton *playButton;
                    playButton->setEnabled(true);
                    VideoPlayer(filePath);
                }
            }
        }
    }*/
}

void MainWindow::exportFile(){

}

void MainWindow::about(){

}


