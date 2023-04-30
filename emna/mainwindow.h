<<<<<<< HEAD
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <expert.h>
#include <QMainWindow>
#include <QtWidgets> //librairie a inclure

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

private:
    expert ex ;
    Ui::MainWindow *ui;
    QIntValidator* validator;
     int clic;
};
#endif // MAINWINDOW_H
=======
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <expert.h>
#include <QMainWindow>
#include <QtWidgets> //librairie a inclure

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

private:
    expert ex ;
    Ui::MainWindow *ui;
    QIntValidator* validator;
     int clic;
};
#endif // MAINWINDOW_H
>>>>>>> c8f612c71c066dc8965fe32616aa55601a129795
