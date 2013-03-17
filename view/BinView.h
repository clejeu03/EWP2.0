#ifndef BINVIEW_H
#define BINVIEW_H

#include <QWidget>
#include <QStackedWidget>

class ProjectManager;

class BinView : public QWidget
{
    Q_OBJECT
public:
    BinView(ProjectManager * projectManager, QWidget *parent = 0);
    void update();
private:
    ProjectManager *m_projectManager;
    QStackedWidget *m_stackedWidget;
};

#endif // BINVIEW_H
