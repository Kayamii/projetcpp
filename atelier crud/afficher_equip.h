#ifndef AFFICHER_EQUIP_H
#define AFFICHER_EQUIP_H

#include <QDialog>

namespace Ui {
class Afficher_equip;
}

class Afficher_equip : public QDialog
{
    Q_OBJECT

public:
    explicit Afficher_equip(QWidget *parent = nullptr);
    ~Afficher_equip();

private:
    Ui::Afficher_equip *ui;
};

#endif // AFFICHER_EQUIP_H
