#ifndef DASHBOARD_E_H
#define DASHBOARD_E_H
#include <seance.h>
#include <equipement.h>
#include <adherent.h>
#include <expert.h>
#include <user.h>
#include <QMainWindow>
#include <string>
#include <QSystemTrayIcon>
using namespace std;
#include <QDialog>



namespace Ui {
class dashboard_e;
}

class dashboard_e : public QDialog
{
    Q_OBJECT

public:
    explicit dashboard_e(QWidget *parent = nullptr);
    ~dashboard_e();
private slots:
void alwayscheck();







    void on_tri_2_clicked();

    //void on_trier_clicked();

   // void on_recherche_clicked();

    void on_rechetxt_cursorPositionChanged();


    void on_pdf_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_pushButton_clicked();



    void on_pushButton_2_clicked();



    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);



    void on_idimage_cursorPositionChanged(int arg1, int arg2);


    void on_Tri_clicked();

    void on_PDF_button_clicked();

    void on_liner_2_cursorPositionChanged(int arg1, int arg2);

    void on_qr_clicked();





    void on_comboBox_2_currentTextChanged(const QString &arg1);



    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();



    void on_id_2_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_11_clicked();




    void on_pushButton_19_clicked();

    void on_pushButton_13_clicked();


    void on_tri_currentIndexChanged(const QString &arg1);

    void on_stats_2_clicked();

    void on_imp_clicked();

    void on_pb_ajouter_clicked();

    void on_ajouter_5_clicked();

private:
    Ui::dashboard_e *ui;
    Seance ss;
    Equipements Etmp;
    Adherent Etmp1;
    expert ex;
    User U;
};

#endif // DASHBOARD_E_H
