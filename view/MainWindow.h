#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        MainWindow();
        void initMenu();

    public slots:

    private:
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
        /*void showChutier();
        void showOutils();
        void showMoniteur();
        void showTimeline();
        void showConception();
        void visitWebsite();*/
};

#endif // MAINWINDOW_H
