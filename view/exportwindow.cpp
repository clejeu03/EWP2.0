#include "exportwindow.h"
#include "ui_exportwindow.h"


exportWindow::exportWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exportWindow)
{
    ui->setupUi(this);
    connect(ui->btn_browse, SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->btn_control, SIGNAL(accepted()), this, SLOT(action_valider()));
    connect(ui->btn_control, SIGNAL(rejected()), this, SLOT(action_annuler()));
}


exportWindow::~exportWindow()
{
    delete ui;
}

void exportWindow::on_pushButton_clicked()
{
   QString directoryTarget = QFileDialog::getExistingDirectory(this,tr("Dossier d'exportation..."),"/home",QFileDialog::ShowDirsOnly);

}

void exportWindow::action_valider()
{
    std::cout << "Valider" << std::endl;
}


void exportWindow::action_annuler()
{
    std::cout << "Annuler" << std::endl;
}
