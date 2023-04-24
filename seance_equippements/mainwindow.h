#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <seance.h>
#include <QMainWindow>
#include <string>
#include <QSystemTrayIcon>
using namespace std;

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
void alwayscheck();

    void on_ajouter_5_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_tableView_activated(const QModelIndex &index);




    void on_tri_2_clicked();

    //void on_trier_clicked();

   // void on_recherche_clicked();

    void on_rechetxt_cursorPositionChanged();


    void on_pdf_clicked();

    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::MainWindow *ui;
   Seance ss;
};

#endif // MAINWINDOW_H
