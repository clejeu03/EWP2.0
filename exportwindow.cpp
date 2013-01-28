#include "exportwindow.h"
#include "ui_exportwindow.h"


exportWindow::exportWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exportWindow)
{
    ui->setupUi(this);
    connect(ui->btn_browse, SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
}


exportWindow::~exportWindow()
{
    delete ui;
}

void exportWindow::on_pushButton_clicked()
{
    QString directoryTarget = QFileDialog::getExistingDirectory(this,tr("Dossier d'exportation..."),"/home",QFileDialog::ShowDirsOnly);
}
