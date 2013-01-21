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
#include <iostream>

#include "chutier.h"
#include "moniteur.h"

class mainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        mainWindow();
        virtual ~mainWindow();

        void initMenu();
        void displayChutier();
        void displayMoniteur();

    private :
        Chutier *chutier;
        Moniteur *moniteur;
        QWidget *centralWidget;
        QHBoxLayout *mainLayout;
        QVBoxLayout *mainVLayout;
        QVBoxLayout *vLayout;
        QVBoxLayout *rightVLayout;
        QHBoxLayout *hLayout;
        QSplitter *HSplitter;
        QSplitter *VSplitter;

        QAction *m_Quitter;
        QAction *m_Nouveau;
        QAction *m_Ouvrir;
        QAction *m_Enregistrer;
        QAction *m_EnregistrerSous;
        QAction *m_Exporter;
        QAction *m_ouvrirScript;
        QAction *m_Executer;
        QAction *m_fermerScript;
        QAction *m_appliquerScript;
        QAction *m_afficherChutier;
        QAction *m_afficherOutils;
        QAction *m_afficherTimeline;
        QAction *m_afficherConception;
        QAction *m_afficherRealisation;
        QAction *m_voirSite;

     private slots:
        void newProject();
        void openProject();
        void save();
        void saveUnder();
        void showChutier();
        void showOutils();
        void showTimeline();

};

#endif // MAINWINDOW_H
