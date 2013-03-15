#include "MainWindow.h"
#include "Timelineview.h"
#include "core/Video.h"
#include "core/Timeline.h"

#include <QDebug>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QApplication>

MainWindow::MainWindow(){

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

    /*Drawing the Timeline View*/
    QWidget *container = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout();
    initMenu();
    TimelineView *timelineView = new TimelineView(timeline);

    layout->addWidget(timelineView);
    container->setLayout(layout);
    container->setMinimumHeight(400);
    container->setMinimumWidth(1050);
    setCentralWidget(container);
}

void MainWindow::initMenu()
{
    /*------ INSTANCIATION ACTIONS ------*/

    m_Nouveau = new QAction("Nouveau...", this);
    m_Nouveau->setShortcut(QKeySequence::New);
    m_Ouvrir = new QAction("Ouvrir...", this);
    m_Ouvrir->setShortcut(QKeySequence::Open);
    m_Enregistrer = new QAction("Enregistrer",this);
    m_Enregistrer->setShortcut(QKeySequence::Save);
    m_EnregistrerSous = new QAction("Enregistrer sous...",this);
    m_EnregistrerSous->setShortcut(QKeySequence::SaveAs);
    m_Importer = new QAction("Importer...",this);
    m_Exporter = new QAction("Exporter...", this);
    m_Quitter = new QAction("Quitter", this);
    m_Quitter->setShortcut(QKeySequence::Quit);


    m_appliquerScript = new QAction("Appliquer un script...", this);
    m_supprimerScript = new QAction("Supprimer les scripts appliqués", this);

    m_lireDernierClip = new QAction("Lire le dernier clip importé", this);
    m_lancerRendu = new QAction("Lancer le rendu", this);

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

    QMenu *fichier = new QMenu("&Fichier");
    QMenu *script = new QMenu("&Script");
    QMenu *lecteur = new QMenu("&Lecteur");
    QMenu *process = new QMenu("&Process");
    QMenu *affichage = new QMenu("&Affichage");
    QMenu *credits = new QMenu("&Crédits");

    QMenuBar *menu = menuBar();

    menu->addMenu(fichier);
    menu->addMenu(script);
    menu->addMenu(lecteur);
    menu->addMenu(process);
    menu->addMenu(affichage);
    menu->addMenu(credits);

    fichier->addAction(m_Nouveau);
    fichier->addAction(m_Ouvrir);
    fichier->addSeparator();
    fichier->addAction(m_Enregistrer);
    fichier->addAction(m_EnregistrerSous);
    fichier->addSeparator();
    fichier->addAction(m_Importer);
    fichier->addAction(m_Exporter);
    fichier->addSeparator();
    fichier->addAction(m_Quitter);

    script->addAction(m_appliquerScript);
    script->addAction(m_supprimerScript);

    lecteur->addAction(m_lireDernierClip);
    process->addAction(m_lancerRendu);

    /*affichage->addAction(m_afficherChutier);
    affichage->addAction(m_afficherOutils);
    affichage->addAction(m_afficherMoniteur);
    affichage->addAction(m_afficherTimeline);

    credits->addAction(m_afficherConception);
    credits->addAction(m_afficherRealisation);
    credits->addSeparator();
    credits->addAction(m_voirSite);*/

    /*------ CONNEXIONS ACTIONS ------*/

    connect(m_Nouveau, SIGNAL(triggered()), this, SLOT(newProject()));
    connect(m_Ouvrir, SIGNAL(triggered()), this, SLOT(openProject()));
    connect(m_Enregistrer, SIGNAL(triggered()), this, SLOT(save()));
    connect(m_EnregistrerSous, SIGNAL(triggered()), this, SLOT(saveUnder()));
    connect(m_Importer, SIGNAL(triggered()), this, SLOT(openFile()));
    //connect(m_Exporter, SIGNAL(triggered()), this, SLOT(displayExportWindow()));
    connect(m_Quitter,SIGNAL(triggered()),qApp, SLOT(quit()));

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

