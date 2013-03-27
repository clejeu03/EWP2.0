#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MdiChild;
QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QMdiArea;
class QMdiSubWindow;
class QSignalMapper;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
   void newProject();
   void openProject();
   void importFile();
   void exportFile();
   void save();
   void saveAs();
   /*void showChutier();
   void showOutils();
   void showMoniteur();
   void showTimeline();
   void showConception();*/
   void about();
   void updateMenu();
   void updateWindowMenu();
   void setActiveSubWindow(QWidget *window);
   void loadStyles();

private:
   void createMenu();
   void createStatusBar();
   void createToolBar();
   void createActions();
   void readSettings();
   void writeSettings();
   MdiChild *activeMdiChild();
   QMdiSubWindow *findMdiChild(const QString &fileName);

   QMdiArea *m_mdiArea;
   QSignalMapper *m_windowMapper;

    QMenu *fileMenu;
    QMenu *scriptMenu;
    QMenu *playerMenu;
    QMenu *processMenu;
    QMenu *windowMenu;
    QMenu *helpMenu;
    QAction *m_newAct;
    QAction *m_openAct;
    QAction *m_saveAct;
    QAction *m_saveAsAct;
    QAction *m_quitAct;
    QAction *m_importAct;
    QAction *m_exportAct;
    QAction *m_applyScriptAct;
    QAction *m_suppressScriptAct;
    QAction *m_playLastClipAct;
    QAction *m_renderAct;
    QAction *m_displayToolAct;
    QAction *m_displayPlayerAct;
    QAction *m_displayTimelineAct;
    QAction *m_displayConceptionWindowAct;
    QAction *m_displayRealisationAct;
    QAction *m_aboutAct;
    QAction *m_closeAct;
    QAction *m_closeAllAct;
    QAction *m_tileAct;
    QAction *m_cascadeAct;
    QAction *m_separatorAct;

};

#endif // MAINWINDOW_H
