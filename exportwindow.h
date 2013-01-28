#ifndef EXPORTWINDOW_H
#define EXPORTWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QFileDialog>

namespace Ui {
class exportWindow;
}

class exportWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit exportWindow(QWidget *parent = 0);
    ~exportWindow();
private slots:
    void on_pushButton_clicked();
private:
    Ui::exportWindow *ui;
};

#endif // EXPORTWINDOW_H
