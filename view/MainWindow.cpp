#include "MainWindow.h"
#include "Timelineview.h"
#include "core/Video.h"
#include "core/Timeline.h"

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

    m_mdiArea = new QMdiArea;
    setCentralWidget(mdiArea);
    connect(mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),
            this, SLOT(updateMenus()));
    windowMapper = new QSignalMapper(this);
    connect(windowMapper, SIGNAL(mapped(QWidget*)),
            this, SLOT(setActiveSubWindow(QWidget*)));

    createActions();
    createMenu();
    createStatusBar();
    updateMenu();

    readSettings();

    setWindowTitle(tr("EWP 2.0"));
    setUnifiedTitleAndToolBarOnMac(true);

    /*Drawing the Timeline View
    TimelineView *timelineView = new TimelineView(timeline);

    QMdiSubWindow *subWindow1 = new QMdiSubWindow;
    subWindow1->setWidget(timelineView);
    subWindow1->resize(900, 400);
    subWindow1->setAttribute(Qt::WA_DeleteOnClose);
    mdiArea->addSubWindow(subWindow1);
    setCentralWidget(mdiArea);
    setUnifiedTitleAndToolBarOnMac(true);*/
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    mdiArea->closeAllSubWindows();
    if (mdiArea->currentSubWindow()) {
        event->ignore();
    } else {
        writeSettings();
        event->accept();
    }
}

void MainWindow::createMenu()
{
    /*------ INSTANCIATION ACTIONS ------*/

    m_newAct = new QAction("Nouveau...", this);
    m_newAct->setShortcut(QKeySequence::New);
    m_openAct = new QAction("Ouvrir...", this);
    m_openAct->setShortcut(QKeySequence::Open);
    m_saveAct = new QAction("Enregistrer",this);
    m_saveAct->setShortcut(QKeySequence::Save);
    m_saveAsAct = new QAction("Enregistrer sous...",this);
    m_saveAsAct->setShortcut(QKeySequence::SaveAs);
    m_importAct = new QAction("Importer...",this);
    m_exportAct = new QAction("Exporter...", this);
    m_quitAct = new QAction("Quitter", this);
    m_quitAct->setShortcut(QKeySequence::Quit);


    m_applyScriptAct = new QAction("Appliquer un script...", this);
    m_suppressScriptAct = new QAction("Supprimer les scripts appliqués", this);

    m_playLastClipAct = new QAction("Lire le dernier clip importé", this);
    m_renderAct = new QAction("Lancer le rendu", this);

    /*m_afficherChutier = new QAction("Chutier", this);
    m_afficherChutier->setCheckable(true);
    m_afficherChutier->setChecked(true);
    m_afficherOutils = new QAction("Outil", this);
    m_afficherOutils->setCheckable(true);
    m_afficherOutils->setChecked(true);
    m_afficherMoniteur = new QAction("Moniteur", this);
    m_afficherMoniteur->setCheckable(true);
    m_afficherMoniteur->setChecked(true);
    m_afficherTimeline = new QAction("Timeline", this);
    m_afficherTimeline->setCheckable(true);
    m_afficherTimeline->setChecked(true);

    m_afficherConception = new QAction("Conception",this);
    m_afficherRealisation = new QAction("Réalisation",this);
    m_voirSite = new QAction("http://electronicwallpaper.com",this);*/

    /*------ INSTANCIATION ITEMS MENU ------*/

    fileMenu = new QMenu("&Fichier");
    scriptMenu = new QMenu("&Script");
    playerMenu = new QMenu("&Lecteur");
    processMenu = new QMenu("&Process");
    displayMenu = new QMenu("&Affichage");
    helpMenu = new QMenu("&Help");

    QMenuBar *menu = menuBar();

    menu->addMenu(fileMenu);
    menu->addMenu(scriptMenu);
    menu->addMenu(playerMenu);
    menu->addMenu(processMenu);
    menu->addMenu(displayMenu);
    menu->addMenu(helpMenu);

    fileMenu->addAction(m_newAct);
    fileMenu->addAction(m_openAct);
    fileMenu->addSeparator();
    fileMenu->addAction(m_saveAct);
    fileMenu->addAction(m_saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(m_importAct);
    fileMenu->addAction(m_exportAct);
    fileMenu->addSeparator();
    fileMenu->addAction(m_quitAct);

    scriptMenu->addAction(m_applyScriptAct);
    scriptMenu->addAction(m_suppressScriptAct);

    playerMenu->addAction(m_playLastClipAct);
    processMenu->addAction(m_renderAct);

    /*help->addAction(m_showHelp);
    help->addSeparator();
    help->addAction(m_about);
    help->addAction(m_showCredits);*/

    /*affichage->addAction(m_afficherChutier);
    affichage->addAction(m_afficherOutils);
    affichage->addAction(m_afficherMoniteur);
    affichage->addAction(m_afficherTimeline);

    credits->addAction(m_afficherConception);
    credits->addAction(m_afficherRealisation);
    credits->addSeparator();
    credits->addAction(m_voirSite);*/

    /*------ CONNEXIONS ACTIONS ------*/

    connect(m_newAct, SIGNAL(triggered()), this, SLOT(newProject()));
    connect(m_openAct, SIGNAL(triggered()), this, SLOT(openProject()));
    connect(m_saveAct, SIGNAL(triggered()), this, SLOT(save()));
    connect(m_saveAsAct, SIGNAL(triggered()), this, SLOT(saveUnder()));
    connect(m_importAct, SIGNAL(triggered()), this, SLOT(importFile()));
    //connect(m_Exporter, SIGNAL(triggered()), this, SLOT(displayExportWindow()));
    connect(m_quitAct,SIGNAL(triggered()),qApp, SLOT(quit()));

    /*
connect(m_appliquerScript, SIGNAL(triggered()), this, SLOT());
connect(m_supprimerScript, SIGNAL(triggered()), this, SLOT());
*/

    /*connect(m_afficherChutier,SIGNAL(triggered()),this, SLOT(showChutier()));
    connect(m_afficherOutils,SIGNAL(triggered()),this, SLOT(showOutils()));
    connect(m_afficherMoniteur,SIGNAL(triggered()),this, SLOT(showMoniteur()));
    connect(m_afficherTimeline,SIGNAL(triggered()),this, SLOT(showTimeline()));*/

    /*connect(m_lireDernierClip, SIGNAL(triggered()), this, SLOT());
connect(m_lancerRendu, SIGNAL(triggered()), this, SLOT());*/

    //connect(m_afficherConception, SIGNAL(triggered()), this, SLOT(showConception()));
  /* connect(m_afficherRealisation, SIGNAL(triggered()), this, SLOT());*/
    //connect(m_voirSite, SIGNAL(triggered()), this, SLOT(visitWebsite()));

}

void MainWindow::updateMenus()
{
    bool hasMdiChild = (activeMdiChild() != 0);
    m_saveAct->setEnabled(hasMdiChild);
    m_saveAsAct->setEnabled(hasMdiChild);
    m_closeAct->setEnabled(hasMdiChild);
    m_closeAllAct->setEnabled(hasMdiChild);
    m_tileAct->setEnabled(hasMdiChild);
    m_cascadeAct->setEnabled(hasMdiChild);
    m_importAct->setEnabled(hasMdiChild);
    m_exportAct->setEnabled(hasMdiChild);
    m_renderAct->setEnabled(hasMdiChild);
    m_playLastClipAct->setEnabled(hasMdiChild);
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

    QList<QMdiSubWindow *> windows = mdiArea->subWindowList();
    separatorAct->setVisible(!windows.isEmpty());

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
        connect(action, SIGNAL(triggered()), windowMapper, SLOT(map()));
        windowMapper->setMapping(action, windows.at(i));
    }
}

MdiChild *MainWindow::createMdiChild()
{
    MdiChild *child = new MdiChild;
    mdiArea->addSubWindow(child);
    return child;
}

void MainWindow::createActions()
{
    //Modèle si ajout d'icones --> saveAct = new QAction(QIcon(":/images/save.png"), tr("&Save"), this);

    m_newAct = new QAction(tr("&Nouveau Projet"), this);
    m_newAct->setShortcuts(QKeySequence::New);
    m_newAct->setStatusTip(tr("Créer un nouveau projet pour travailler"));
    connect(m_newAct, SIGNAL(triggered()), this, SLOT(newProject());

    m_openAct = new QAction(tr("&Ouvrir un projet..."), this);
    m_openAct->setShortcuts(QKeySequence::Open);
    m_openAct->setStatusTip(tr("Ouvrir un projet existant"));
    connect(m_openAct, SIGNAL(triggered()), this, SLOT(openProject());

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
*/

    m_importAct = new QAction(tr("&Importer"), this);
    m_importAct->setStatusTip(tr("Importer une vidéo dans le projet courant"));
    connect(m_importAct, SIGNAL(triggered()), qApp, SLOT(importFile()));

    m_exportAct = new QAction(tr("&Exporter"), this);
    m_exportAct->setStatusTip(tr("Importer une vidéo dans le projet courant"));
    connect(m_exportAct, SIGNAL(triggered()), qApp, SLOT(exportFile()));

    m_closeAct = new QAction(tr("&Fermer"), this);
    m_closeAct->setStatusTip(tr("Fermer la fenetre active"));
    connect(m_closeAct, SIGNAL(triggered()),
            mdiArea, SLOT(closeActiveSubWindow()));

    m_closeAllAct = new QAction(tr("Fermer &tout"), this);
    m_closeAllAct->setStatusTip(tr("Fermer toutes les fenetres"));
    connect(m_closeAllAct, SIGNAL(triggered()),
            mdiArea, SLOT(closeAllSubWindows()));

    m_tileAct = new QAction(tr("&Mosaique"), this);
    m_tileAct->setStatusTip(tr("Organise les fenetres en mosaique"));
    connect(m_tileAct, SIGNAL(triggered()), mdiArea, SLOT(tileSubWindows()));

    m_cascadeAct = new QAction(tr("&Cascade"), this);
    m_cascadeAct->setStatusTip(tr("Organise les fenetres en cascade"));
    connect(m_cascadeAct, SIGNAL(triggered()), mdiArea, SLOT(cascadeSubWindows()));

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
    std::cout<<"New Project"<<std::endl;
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
}*/

}

