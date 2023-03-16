#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <seance.h>
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


    void on_ajouter_5_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_tableView_activated(const QModelIndex &index);




private:
    Ui::MainWindow *ui;
   Seance ss;
};

#endif // MAINWINDOW_H
