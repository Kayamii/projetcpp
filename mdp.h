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
    explicit mdp(QWidget *parent = nullptr);
    ~mdp();

private:
    Ui::mdp *ui;
};

#endif // MDP_H
