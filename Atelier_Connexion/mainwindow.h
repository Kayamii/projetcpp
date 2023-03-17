#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "adherent.h"

#include <QMainWindow>

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
    void on_pb_ajouter_clicked();



    void on_supprimer_clicked();

    void on_pb_ajouter_2_clicked();

private:
    Ui::MainWindow *ui;
    Adherent Etmp;
};

#endif // MAINWINDOW_H
