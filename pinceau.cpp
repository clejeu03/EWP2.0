#include "pinceau.h"

Pinceau::Pinceau(QWidget *parent):QWidget(parent)
{
    QFont font;
    font.setBold(true);
    font.setPointSize(16);

    PLabel = new QLabel("Pinceau", this);
    PLabel->setFont(font);
    PLabel->setAlignment(Qt::AlignTop);

    //a enlever par la suite
    PLabel->resize(300,200);
}

Pinceau::~Pinceau()
{

}
