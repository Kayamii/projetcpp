#ifndef DIALOG_MDP_H
#define DIALOG_MDP_H

#include <QDialog>

namespace Ui {
class Dialog_mdp;
}

class Dialog_mdp : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_mdp(QWidget *parent = nullptr);
    ~Dialog_mdp();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog_mdp *ui;
};

#endif // DIALOG_MDP_H
