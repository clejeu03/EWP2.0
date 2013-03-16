#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        MainWindow();

    public slots:

    private:
        QMenu *file;
        QMenu *script;
        QMenu *player;
        QMenu *process;
        QMenu *display;
        QMenu *help;
        QToolBar *fileToolBar;
        QToolBar *editToolBar;
        QAction *m_quit;
        QAction *m_new;
        QAction *m_open;
        QAction *m_save;
        QAction *m_saveAs;
        QAction *m_import;
        QAction *m_export;
        QAction *m_applyScript;
        QAction *m_suppressScript;
        QAction *m_playLastClip;
        QAction *m_render;
        QAction *m_displayBin;
        QAction *m_displayTool;
        QAction *m_displayPlayer;
        QAction *m_displayTimeline;
        QAction *m_displayConceptionWindow;
        QAction *m_displayRealisation;
        QAction *m_showWebsite;
        QAction *m_showHelp;
        QAction *m_showCredits;

        void createMenu();
        void createToolBars();
        void createStatusBar();

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
