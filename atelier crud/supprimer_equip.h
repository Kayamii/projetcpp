#ifndef SUPPRIMER_EQUIP_H
#define SUPPRIMER_EQUIP_H

#include <QDialog>

namespace Ui {
class Supprimer_equip;
}

class Supprimer_equip : public QDialog
{
    Q_OBJECT

public:
    explicit Supprimer_equip(QWidget *parent = nullptr);
    ~Supprimer_equip();

private:
    Ui::Supprimer_equip *ui;
};

#endif // SUPPRIMER_EQUIP_H
