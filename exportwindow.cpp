#include "exportwindow.h"
#include "ui_exportwindow.h"

exportWindow* exportWindow::_instance = 0;

exportWindow* exportWindow::Instance()
{
    static QMutex mutex;
    if (!_instance)
    {
        mutex.lock();

        if (!_instance)
            _instance = new exportWindow;

        mutex.unlock();
    }

    return _instance;

}

void exportWindow::drop()
{
    static QMutex mutex;
    mutex.lock();
    delete _instance;
    _instance = 0;
    mutex.unlock();
}

exportWindow::exportWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exportWindow)
{
    ui->setupUi(this);
    connect(ui->btn_browse, SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
}

/*
exportWindow::~exportWindow()
{
    delete ui;
}*/

void exportWindow::on_pushButton_clicked()
{
    QString directoryTarget = QFileDialog::getExistingDirectory(this,tr("Dossier d'exportation..."),"/home",QFileDialog::ShowDirsOnly);
}
