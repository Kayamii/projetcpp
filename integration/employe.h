#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QDialog>
#include"user.h"

namespace Ui {
class employe;
}

class employe : public QDialog
{
    Q_OBJECT

public:
    explicit employe(QWidget *parent = nullptr);
    ~employe();

private slots:
    void on_pushButton_2_clicked();
    void on_rech_textChanged(const QString &arg1);
    void on_tri_currentIndexChanged(const QString &arg1);
    void on_stats_clicked();
    void on_imp_clicked();

private:
    Ui::employe *ui;
    User U;
};

#endif // EMPLOYE_H
