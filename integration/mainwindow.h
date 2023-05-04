#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <seance.h>
#include <equipement.h>
#include <adherent.h>
#include <expert.h>
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

    void on_pushButton_clicked();

    void on_btnAjouterEquip_clicked();

    void on_btnModifierEquip_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);



    void on_idimage_cursorPositionChanged(int arg1, int arg2);

    void on_pb_ajouter_clicked();

    void on_deleteb2_clicked();

    void on_Tri_clicked();

    void on_PDF_button_clicked();

    void on_liner_2_cursorPositionChanged(int arg1, int arg2);

    void on_qr_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pushButton_5_clicked();

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_supp_clicked();

    void on_id_2_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_11_clicked();

    void on_tabWidget_2_currentChanged(int index);

private:
    Ui::MainWindow *ui;

   Seance ss;
   Equipements Etmp;
   Adherent Etmp1;
   expert ex;


};

#endif // MAINWINDOW_H
