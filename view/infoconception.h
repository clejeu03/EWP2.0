#ifndef INFOCONCEPTION_H
#define INFOCONCEPTION_H

#include <QDialog>

namespace Ui {
class infoConception;
}

class infoConception : public QDialog
{
    Q_OBJECT
public:
    explicit infoConception(QWidget *parent = 0);
    ~infoConception();
private:
    Ui::infoConception *ui;
};

#endif // INFOCONCEPTION_H
