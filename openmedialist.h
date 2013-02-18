#ifndef OPENMEDIALIST_H
#define OPENMEDIALIST_H

#include <QDialog>

namespace Ui {
class openMediaList;
}

class openMediaList : public QDialog
{
    Q_OBJECT
public:
    explicit openMediaList(QWidget *parent = 0);
    ~openMediaList();
    
signals:
    
public slots:

private:
    Ui::openMediaList *ui;
    
};

#endif
