#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include <QtGui>
#include <QDesktopServices>
#include <iostream>
#include <QToolButton>

#include "chutier.h"
#include "moniteur.h"
#include "timeline.h"
#include "pinceau.h"
#include "exportwindow.h"
#include "infoconception.h"

class mainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        mainWindow();
        virtual ~mainWindow();

        void initMenu();
        void displayChutier();
        void displayPinceau();
        void displayMoniteur();
        void displayTimeline();
    public slots:
        void updateTimelineAction(bool a);
        void updatePinceauAction(bool a);
        void updateMoniteurAction(bool a);
        void updateChutierAction(bool a);
        void displayExportWindow();
    private :
        Chutier *chutier;
        Pinceau *pinceau;
        Moniteur *moniteur;
        Timeline *timeline;
        QWidget *centralWidget;
        exportWindow *ui_exportWindow;
        infoConception *ui_aboutConception;

        QHBoxLayout *mainLayout;
        QVBoxLayout *vLayout;
        QVBoxLayout *rightVLayout;
        QHBoxLayout *hLayout;


        QSplitter *HSplitter;
        QSplitter *VSplitter;
        QSplitter *subRightSplitter;


        QAction *m_Quitter;
        QAction *m_Nouveau;
        QAction *m_Ouvrir;
        QAction *m_Enregistrer;
        QAction *m_EnregistrerSous;
        QAction *m_Importer;
        QAction *m_Exporter;
        QAction *m_appliquerScript;
        QAction *m_supprimerScript;
        QAction *m_lireDernierClip;
        QAction *m_lancerRendu;
        QAction *m_afficherChutier;
        QAction *m_afficherOutils;
        QAction *m_afficherMoniteur;
        QAction *m_afficherTimeline;
        QAction *m_afficherConception;
        QAction *m_afficherRealisation;
        QAction *m_voirSite;

     private slots:
        void newProject();
        void openProject();
        void openFile();
        void save();
        void saveUnder();
        void showChutier();
        void showOutils();
        void showMoniteur();
        void showTimeline();
        void showConception();
        void visitWebsite();

};

#endif // MAINWINDOW_H
