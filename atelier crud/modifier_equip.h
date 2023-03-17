#ifndef MODIFIER_EQUIP_H
#define MODIFIER_EQUIP_H

#include <QDialog>

namespace Ui {
class Modifier_equip;
}

class Modifier_equip : public QDialog
{
    Q_OBJECT

public:
    explicit Modifier_equip(QWidget *parent = nullptr);
    ~Modifier_equip();

private:
    Ui::Modifier_equip *ui;
};

#endif // MODIFIER_EQUIP_H
