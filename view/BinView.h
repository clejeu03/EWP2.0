#ifndef BINVIEW_H
#define BINVIEW_H

#include <QWidget>
#include <QStackedWidget>
#include <core/ProjectManager.h>

class ProjectManager;

class BinView : public QWidget
{
    Q_OBJECT
public:
    BinView(ProjectManager *projectManager, QWidget *parent = 0);
    void update();

private:
    ProjectManager *m_projectManager;
    QStackedWidget *m_stackedWidget;
    enum DisplayMode {
        DEFAULT, //affiche une image, le nom de la vidéo sans extension
        DETAIL, //Afiche le nom et l'extension + le poids de la vidéo
        COMPLETE //Affiche une image, le nom avec extension et le poids
    };
};

#endif // BINVIEW_H
