#ifndef DIALOG_MDP_H
#define DIALOG_MDP_H

#include <QDialog>

namespace Ui {
class dialog_mdp;
}

class dialog_mdp : public QDialog
{
    Q_OBJECT

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

public:
    explicit dialog_mdp(QWidget *parent = nullptr);
    ~dialog_mdp();

private:
    Ui::dialog_mdp *ui;
};

#endif // DIALOG_MDP_H



