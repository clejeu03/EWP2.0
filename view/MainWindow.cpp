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


    createMenu();
    createStatusBar();

    QWidget *container = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout();

    /*Drawing the Timeline View*/
    TimelineView *timelineView = new TimelineView(timeline);

    layout->addWidget(timelineView);
    container->setLayout(layout);
    container->setMinimumHeight(600);
    container->setMinimumWidth(1250);
    setCentralWidget(container);
    setUnifiedTitleAndToolBarOnMac(true);
}

void MainWindow::createMenu()
{
    /*------ INSTANCIATION ACTIONS ------*/

    m_new = new QAction("Nouveau...", this);
    m_new->setShortcut(QKeySequence::New);
    m_open = new QAction("Ouvrir...", this);
    m_open->setShortcut(QKeySequence::Open);
    m_save = new QAction("Enregistrer",this);
    m_save->setShortcut(QKeySequence::Save);
    m_saveAs = new QAction("Enregistrer sous...",this);
    m_saveAs->setShortcut(QKeySequence::SaveAs);
    m_import = new QAction("Importer...",this);
    m_export = new QAction("Exporter...", this);
    m_quit = new QAction("Quitter", this);
    m_quit->setShortcut(QKeySequence::Quit);


    m_applyScript = new QAction("Appliquer un script...", this);
    m_suppressScript = new QAction("Supprimer les scripts appliqués", this);

    m_playLastClip = new QAction("Lire le dernier clip importé", this);
    m_render = new QAction("Lancer le rendu", this);

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

    file = new QMenu("&Fichier");
    script = new QMenu("&Script");
    player = new QMenu("&Lecteur");
    process = new QMenu("&Process");
    display = new QMenu("&Affichage");
    help = new QMenu("&Help");

    QMenuBar *menu = menuBar();

    menu->addMenu(file);
    menu->addMenu(script);
    menu->addMenu(player);
    menu->addMenu(process);
    menu->addMenu(display);
    menu->addMenu(help);

    file->addAction(m_new);
    file->addAction(m_open);
    file->addSeparator();
    file->addAction(m_save);
    file->addAction(m_saveAs);
    file->addSeparator();
    file->addAction(m_import);
    file->addAction(m_export);
    file->addSeparator();
    file->addAction(m_quit);

    script->addAction(m_applyScript);
    script->addAction(m_suppressScript);

    player->addAction(m_playLastClip);
    process->addAction(m_render);

    /*help->addAction(m_showHelp);
    help->addSeparator();
    help->addAction(m_showWebsite);
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

    connect(m_new, SIGNAL(triggered()), this, SLOT(newProject()));
    connect(m_open, SIGNAL(triggered()), this, SLOT(openProject()));
    connect(m_save, SIGNAL(triggered()), this, SLOT(save()));
    connect(m_saveAs, SIGNAL(triggered()), this, SLOT(saveUnder()));
    connect(m_import, SIGNAL(triggered()), this, SLOT(openFile()));
    //connect(m_Exporter, SIGNAL(triggered()), this, SLOT(displayExportWindow()));
    connect(m_quit,SIGNAL(triggered()),qApp, SLOT(quit()));

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

void MainWindow::saveUnder()
{
    //QString projectname = QFileDialog::getSaveFileName(this,tr("Enregistrer sous..."),"/home");
}

void MainWindow::openFile()
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

