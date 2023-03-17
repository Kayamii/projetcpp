#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QTabWidget>
#include <QMainWindow>
#include"equipements.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_btnAjouterEquip_clicked();



    /*void on_btnReload_clicked();

    void on_btnModifierEquip_clicked();*/

   /* void on_pushButton_2_clicked();*/

    void on_suppEquip_clicked();

    void on_btnModifierEquip_clicked();

private:
    Ui::MainWindow *ui;

    Equipements Etmp;

};

#endif // MAINWINDOW_H
