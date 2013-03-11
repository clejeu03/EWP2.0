#include "infoconception.h"
#include "ui_infoconception.h"


infoConception::infoConception(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoConception)
{
    ui->setupUi(this);
    connect(ui->btn_close, SIGNAL(clicked()),this,SLOT(accept()));
}


infoConception::~infoConception()
{
    delete ui;
}


