#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <expert.h>
#include <string>
#include <QMainWindow>
#include <QtWidgets> //librairie a inclure
#include <QSqlRecord>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_pushButton_clicked();
    void testInt(QString);
    void testIntt(QString );
    void checkInputt(QString text);

    void checkInput(QString);

    void on_pushButton_clicked();

    void on_supp_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_id_2_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    //void on_pushButton_7_clicked();

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    expert ex ;
    Ui::MainWindow *ui;
    QIntValidator* validator;
     int clic;
};
#endif // MAINWINDOW_H
