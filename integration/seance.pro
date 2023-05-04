#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql
QT+= sql
QT += svg
QT += printsupport
QT       += core gui charts
QT +=serialport

QT       += core gui sql printsupport

QT += core gui multimedia multimediawidgets


QT       += core gui sql serialport


QT += svg
QT       += core gui sql axcontainer printsupport network serialport multimedia multimediawidgets charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = seances
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QT+= sql
QT+= charts
CONFIG += c++11

SOURCES += \
    adherent.cpp \
    createaccount.cpp \
    dashboard.cpp \
    dashboard_e.cpp \
    dialog.cpp \
    dialog_mdp.cpp \
    employe.cpp \
    equipements.cpp \
    expert.cpp \
    login.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    mdp.cpp \
    qrcode.cpp \
    qrcodegeneratordemo.cpp \
    qrcodegeneratorworker.cpp \
    qrwidget.cpp \
    seance.cpp \
    user.cpp \
    verification.cpp

HEADERS += \
    adherent.h \
    createaccount.h \
    dashboard.h \
    dashboard_e.h \
    dialog.h \
    dialog_mdp.h \
    employe.h \
    equipement.h \
    expert.h \
    login.h \
        mainwindow.h \
    connection.h \
    mdp.h \
    qrcode.h \
    qrwidget.h \
    qtcodegeneratorworker.h \
    seance.h \
    user.h \
    verification.h

FORMS += \
        createaccount.ui \
        dashboard.ui \
        dashboard_e.ui \
        dialog.ui \
        dialog_mdp.ui \
        employe.ui \
        login.ui \
        mainwindow.ui \
        mdp.ui \
        user.ui \
        verification.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
