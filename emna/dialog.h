<<<<<<< HEAD
#ifndef DIALOG_H
#define DIALOG_H
#include <expert.h>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void setexpert(expert e);

    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
=======
#ifndef DIALOG_H
#define DIALOG_H
#include <expert.h>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void setexpert(expert e);

    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
>>>>>>> c8f612c71c066dc8965fe32616aa55601a129795
