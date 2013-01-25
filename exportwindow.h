#ifndef EXPORTWINDOW_H
#define EXPORTWINDOW_H

#include <QDialog>
#include <iostream>
#include <QDebug>
#include <QMutex>
#include <QFileDialog>

namespace Ui {
class exportWindow;
}

class exportWindow : public QDialog
{
    Q_OBJECT
    
public:
    static exportWindow* Instance();
    static void drop();
    //~exportWindow();
protected:
    explicit exportWindow(QWidget *parent = 0);
    
private slots:
    void on_pushButton_clicked();

private:
    static exportWindow* _instance;
    Ui::exportWindow *ui;
};

#endif // EXPORTWINDOW_H
