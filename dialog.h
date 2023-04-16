#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"user.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_rech_textChanged(const QString &arg1);

    void on_tri_currentIndexChanged(const QString &arg1);

    void on_stats_clicked();

    void on_imp_clicked();

    void on_pushButton_4_clicked();


private:
    Ui::Dialog *ui;
    User U;
};

#endif // DIALOG_H
