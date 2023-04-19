#ifndef MDP_H
#define MDP_H

#include <QDialog>

namespace Ui {
class mdp;
}

class mdp : public QDialog
{
    Q_OBJECT

public:
    QString mm;
    explicit mdp(QWidget *parent = nullptr);
    ~mdp();

private slots:
    void on_pushButton_clicked();

private:
    Ui::mdp *ui;
};

#endif // MDP_H
