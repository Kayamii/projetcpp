#ifndef EXPERT_H
#define EXPERT_H

#include <QDialog>
#include"user.h"

namespace Ui {
class expert;
}

class expert : public QDialog
{
    Q_OBJECT

public:
    explicit expert(QWidget *parent = nullptr);
    ~expert();


private slots:
    void on_pushButton_2_clicked();
    void on_rech_textChanged(const QString &arg1);
    void on_tri_currentIndexChanged(const QString &arg1);
    void on_stats_clicked();
    void on_imp_clicked();


private:
    Ui::expert *ui;
    User U;
};

#endif // EXPERT_H
