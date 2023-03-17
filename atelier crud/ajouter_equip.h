#ifndef AJOUTER_EQUIP_H
#define AJOUTER_EQUIP_H

#include <QDialog>

namespace Ui {
class Ajouter_equip;
}

class Ajouter_equip : public QDialog
{
    Q_OBJECT

public:
    explicit Ajouter_equip(QWidget *parent = nullptr);
    ~Ajouter_equip();

private slots:
    void on_btnSave_clicked();

private:
    Ui::Ajouter_equip *ui;
};

#endif // AJOUTER_EQUIP_H
