#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "adherent.h"
#include "arduino.h"

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





    void on_pb_ajouter_2_clicked();











    void on_PDF_clicked();

    void on_sort_clicked();

    void on_qr_clicked();


    void on_deleteb2_clicked();

    void on_rechercher_2_clicked();

    void on_Tri_clicked();

    void on_PDF_button_clicked();



    void on_liner_2_cursorPositionChanged(int arg1, int arg2);

    void on_on_clicked();

    void on_off_clicked();

    void on_l2_clicked();

    void on_l2_2_clicked();




private:
    Ui::MainWindow *ui;
    Adherent Etmp;
    arduino A;

};

#endif // MAINWINDOW_H
