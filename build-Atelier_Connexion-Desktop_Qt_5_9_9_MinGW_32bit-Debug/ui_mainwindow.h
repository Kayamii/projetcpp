/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Ajouter;
    QLabel *label;
    QPushButton *btnAjouterEquip;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLineEdit *ID_EQU;
    QLabel *label_6;
    QLineEdit *nomEquip;
    QLabel *label_7;
    QLineEdit *quantite;
    QLabel *label_8;
    QLineEdit *DUREE_VIE;
    QLabel *label_9;
    QLineEdit *prixEquip;
    QLineEdit *idSeance;
    QLabel *label_12;
    QPushButton *pushButton_3;
    QLabel *imageLabel;
    QLabel *imageLabel_2;
    QWidget *tab_2;
    QLabel *label_2;
    QPushButton *suppEquip;
    QLineEdit *lineEdit_IDS;
    QLabel *label_10;
    QWidget *tab_3;
    QLabel *label_3;
    QPushButton *btnModifierEquip;
    QLabel *label_11;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_13;
    QLineEdit *ID_EQU_2;
    QLabel *label_14;
    QLineEdit *nomEquip_2;
    QLabel *label_15;
    QLineEdit *quantite_2;
    QLabel *label_16;
    QLineEdit *DUREE_VIE_2;
    QLabel *label_17;
    QLineEdit *prixEquip_2;
    QLabel *label_18;
    QLineEdit *idSeance_2;
    QWidget *tab_4;
    QLabel *label_4;
    QTableView *tableView;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_19;
    QPushButton *pushButton_2;
    QWidget *tab;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *statlayout;
    QWidget *tab_5;
    QTableView *tableView_2;
    QLabel *imageimage;
    QLineEdit *idimage;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1272, 795);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1251, 741));
        Ajouter = new QWidget();
        Ajouter->setObjectName(QStringLiteral("Ajouter"));
        label = new QLabel(Ajouter);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, -60, 1121, 681));
        label->setPixmap(QPixmap(QString::fromUtf8("../331802584_421204743538946_1674189878202346939_n.png")));
        btnAjouterEquip = new QPushButton(Ajouter);
        btnAjouterEquip->setObjectName(QStringLiteral("btnAjouterEquip"));
        btnAjouterEquip->setGeometry(QRect(410, 460, 161, 51));
        btnAjouterEquip->setStyleSheet(QLatin1String("QPushButton\n"
"\n"
"{\n"
"	background-color: rgb(72, 78, 86);\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius:20px;\n"
"    border-color: beige;\n"
"    \n"
"font: 81 10pt \"Rockwell Extra Bold\";\n"
"    padding: 6px;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover\n"
"\n"
"{\n"
"	background-color: rgb(106, 227, 231);\n"
"	color: rgb(0, 0, 0);\n"
"	gridline-color: rgb(94, 118, 255);\n"
"}\n"
"\n"
"QPushButton:pressed"));
        formLayoutWidget = new QWidget(Ajouter);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(250, 220, 521, 171));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        ID_EQU = new QLineEdit(formLayoutWidget);
        ID_EQU->setObjectName(QStringLiteral("ID_EQU"));

        formLayout->setWidget(0, QFormLayout::FieldRole, ID_EQU);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        nomEquip = new QLineEdit(formLayoutWidget);
        nomEquip->setObjectName(QStringLiteral("nomEquip"));

        formLayout->setWidget(1, QFormLayout::FieldRole, nomEquip);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        quantite = new QLineEdit(formLayoutWidget);
        quantite->setObjectName(QStringLiteral("quantite"));

        formLayout->setWidget(2, QFormLayout::FieldRole, quantite);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_8);

        DUREE_VIE = new QLineEdit(formLayoutWidget);
        DUREE_VIE->setObjectName(QStringLiteral("DUREE_VIE"));

        formLayout->setWidget(3, QFormLayout::FieldRole, DUREE_VIE);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_9);

        prixEquip = new QLineEdit(formLayoutWidget);
        prixEquip->setObjectName(QStringLiteral("prixEquip"));

        formLayout->setWidget(4, QFormLayout::FieldRole, prixEquip);

        idSeance = new QLineEdit(formLayoutWidget);
        idSeance->setObjectName(QStringLiteral("idSeance"));

        formLayout->setWidget(5, QFormLayout::FieldRole, idSeance);

        label_12 = new QLabel(formLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_12);

        pushButton_3 = new QPushButton(Ajouter);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(260, 410, 131, 28));
        imageLabel = new QLabel(Ajouter);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setGeometry(QRect(470, 120, 221, 51));
        imageLabel_2 = new QLabel(Ajouter);
        imageLabel_2->setObjectName(QStringLiteral("imageLabel_2"));
        imageLabel_2->setGeometry(QRect(450, 70, 251, 71));
        tabWidget->addTab(Ajouter, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, -60, 1121, 681));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../331802584_421204743538946_1674189878202346939_n.png")));
        suppEquip = new QPushButton(tab_2);
        suppEquip->setObjectName(QStringLiteral("suppEquip"));
        suppEquip->setGeometry(QRect(440, 320, 151, 51));
        suppEquip->setStyleSheet(QLatin1String("QPushButton\n"
"\n"
"{\n"
"	background-color: rgb(72, 78, 86);\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius:20px;\n"
"    border-color: beige;\n"
"    \n"
"font: 81 10pt \"Rockwell Extra Bold\";\n"
"    padding: 6px;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover\n"
"\n"
"{\n"
"	background-color: rgb(106, 227, 231);\n"
"	color: rgb(0, 0, 0);\n"
"	gridline-color: rgb(94, 118, 255);\n"
"}\n"
"\n"
"QPushButton:pressed"));
        lineEdit_IDS = new QLineEdit(tab_2);
        lineEdit_IDS->setObjectName(QStringLiteral("lineEdit_IDS"));
        lineEdit_IDS->setGeometry(QRect(330, 240, 371, 51));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(330, 190, 401, 20));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, -60, 1121, 681));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../331802584_421204743538946_1674189878202346939_n.png")));
        btnModifierEquip = new QPushButton(tab_3);
        btnModifierEquip->setObjectName(QStringLiteral("btnModifierEquip"));
        btnModifierEquip->setGeometry(QRect(420, 320, 151, 51));
        btnModifierEquip->setStyleSheet(QLatin1String("QPushButton\n"
"\n"
"{\n"
"	background-color: rgb(72, 78, 86);\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius:20px;\n"
"    border-color: beige;\n"
"    \n"
"font: 81 10pt \"Rockwell Extra Bold\";\n"
"    padding: 6px;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover\n"
"\n"
"{\n"
"	background-color: rgb(106, 227, 231);\n"
"	color: rgb(0, 0, 0);\n"
"	gridline-color: rgb(94, 118, 255);\n"
"}\n"
"\n"
"QPushButton:pressed"));
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(320, 80, 391, 20));
        formLayoutWidget_2 = new QWidget(tab_3);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(220, 140, 521, 171));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(formLayoutWidget_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_13);

        ID_EQU_2 = new QLineEdit(formLayoutWidget_2);
        ID_EQU_2->setObjectName(QStringLiteral("ID_EQU_2"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, ID_EQU_2);

        label_14 = new QLabel(formLayoutWidget_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_14);

        nomEquip_2 = new QLineEdit(formLayoutWidget_2);
        nomEquip_2->setObjectName(QStringLiteral("nomEquip_2"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, nomEquip_2);

        label_15 = new QLabel(formLayoutWidget_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_15);

        quantite_2 = new QLineEdit(formLayoutWidget_2);
        quantite_2->setObjectName(QStringLiteral("quantite_2"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, quantite_2);

        label_16 = new QLabel(formLayoutWidget_2);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_16);

        DUREE_VIE_2 = new QLineEdit(formLayoutWidget_2);
        DUREE_VIE_2->setObjectName(QStringLiteral("DUREE_VIE_2"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, DUREE_VIE_2);

        label_17 = new QLabel(formLayoutWidget_2);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_17);

        prixEquip_2 = new QLineEdit(formLayoutWidget_2);
        prixEquip_2->setObjectName(QStringLiteral("prixEquip_2"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, prixEquip_2);

        label_18 = new QLabel(formLayoutWidget_2);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_18);

        idSeance_2 = new QLineEdit(formLayoutWidget_2);
        idSeance_2->setObjectName(QStringLiteral("idSeance_2"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, idSeance_2);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, -60, 1121, 681));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../331802584_421204743538946_1674189878202346939_n.png")));
        tableView = new QTableView(tab_4);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 110, 961, 331));
        lineEdit = new QLineEdit(tab_4);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(830, 60, 113, 22));
        pushButton = new QPushButton(tab_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 460, 231, 41));
        label_19 = new QLabel(tab_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(860, 40, 56, 16));
        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 460, 181, 41));
        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 10, 1251, 681));
        statlayout = new QHBoxLayout(horizontalLayoutWidget);
        statlayout->setSpacing(6);
        statlayout->setContentsMargins(11, 11, 11, 11);
        statlayout->setObjectName(QStringLiteral("statlayout"));
        statlayout->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tableView_2 = new QTableView(tab_5);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(40, 50, 751, 201));
        imageimage = new QLabel(tab_5);
        imageimage->setObjectName(QStringLiteral("imageimage"));
        imageimage->setGeometry(QRect(830, 30, 281, 241));
        idimage = new QLineEdit(tab_5);
        idimage->setObjectName(QStringLiteral("idimage"));
        idimage->setGeometry(QRect(60, 290, 113, 22));
        tabWidget->addTab(tab_5, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1272, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des equipements", Q_NULLPTR));
        label->setText(QString());
        btnAjouterEquip->setText(QApplication::translate("MainWindow", "Ajouter ", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "ID_EQUIPEMENT ", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "NOM EQUIPEMENT", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "QUANTITE", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "DUREE DE VIE", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "PRIX", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "ID_SEANCE", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Inserer image ", Q_NULLPTR));
        imageLabel->setText(QString());
        imageLabel_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Ajouter), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        label_2->setText(QString());
        suppEquip->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "ENTREZ L'IDENTIFIANT DE L'EQUIPEMENT POUR SUPPRIMER:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        label_3->setText(QString());
        btnModifierEquip->setText(QApplication::translate("MainWindow", "Modifier ", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "ENTREZ L'IDENTIFIANT DE L'EQUIPEMENT POUR MODIFIER:", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "ID_EQUIPEMENT ", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "NOM EQUIPEMENT", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "QUANTITE", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "DUREE DE VIE", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "PRIX", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "ID_SEANCE", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
        label_4->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "TRIER PAR ORDRE ALPHABETIQUE", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "CONVERTIR EN PDF", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "stat", Q_NULLPTR));
        imageimage->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "image_display", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
