#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();



public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private:
    Ui::login *ui;
};

#endif // LOGIN_H








