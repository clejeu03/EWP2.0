#include "openmedialist.h"
#include "ui_openMediaList.h"

openMediaList::openMediaList(QWidget *parent) :
    QDialog(parent),
  ui(new Ui::openMediaList)
{
    ui->setupUi(this);

}
openMediaList::~openMediaList(){
    delete ui;
}
