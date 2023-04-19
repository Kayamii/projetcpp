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
    QString ch;
    QString m;//mail
    explicit verification(QWidget *parent = nullptr);
    ~verification();

private slots:
    void on_pushButton_clicked();

private:
    Ui::verification *ui;
};

#endif // VERIFICATION_H
