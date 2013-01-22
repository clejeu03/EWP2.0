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

void Pinceau::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QBrush background(QLinearGradient());

    painter.setBrush(background);
    painter.drawRoundedRect(0,0,300,15,5,5,Qt::AbsoluteSize);

}
