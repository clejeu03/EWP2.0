#ifndef BINVIEW_H
#define BINVIEW_H

#include <QWidget>
#include <QToolBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <core/ProjectManager.h>
#include <QAbstractButton>

class ProjectManager;

class BinView : public QWidget
{
    Q_OBJECT
public:
    BinView(ProjectManager *projectManager, QWidget *parent = 0);
    void update();

private:
    ProjectManager *m_projectManager;
    QToolBox *m_toolBox;
    QPushButton *but1;
    QPushButton *but2;
    QPushButton *but3;

    enum DisplayMode {
        DEFAULT, //affiche une image, le nom de la vidéo sans extension
        DETAIL, //Afiche le nom et l'extension + le poids de la vidéo
        COMPLETE //Affiche une image, le nom avec extension et le poids
    };
};

#endif // BINVIEW_H
