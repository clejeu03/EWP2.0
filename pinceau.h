#ifndef PINCEAU_H
#define PINCEAU_H

#include <QWidget>
#include <QLabel>

class Pinceau : public QWidget
{
    Q_OBJECT
    private:
        QLabel *PLabel;
    public:
        Pinceau(QWidget *parent=0);
        virtual ~Pinceau();
};

#endif // PINCEAU_H
