#ifndef VERIFICATION_H
#define VERIFICATION_H

#include <QDialog>

namespace Ui {
class verification;
}

class verification : public QDialog
{
    Q_OBJECT

public:
    explicit verification(QWidget *parent = nullptr);
    ~verification();

private:
    Ui::verification *ui;
};

#endif // VERIFICATION_H
