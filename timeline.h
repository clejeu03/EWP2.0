#ifndef TIMELINE_H
#define TIMELINE_H

#include <QWidget>
#include <QLabel>
#include <QListWidget>

class Timeline : public QWidget
{
    Q_OBJECT
    private :
        QLabel *TLabel;
        QListWidget *clipList;
    public:
        Timeline(QWidget *parent=0);
        virtual ~Timeline();
};

#endif // TIMELINE_H

