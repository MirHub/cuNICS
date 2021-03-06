#-------------------------------------------------
#
# Project created by QtCreator 2017-03-01T15:22:11
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TeamOOPS_cuNICS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    user.cpp \
    employee.cpp \
    payrollspecialist.cpp \
    bankinformation.cpp \
    date.cpp \
    phonenumber.cpp \
    address.cpp \
    salary.cpp \
    status.cpp \
    role.cpp \
    paystub.cpp \
    editemployeeinfocontrol.cpp \
    listemployeescontrol.cpp \
    applysalarydeductioncontrol.cpp \
    payrollgenerationtool.cpp \
    manageemployeesalarycontrol.cpp


HEADERS  += mainwindow.h \
    user.h \
    employee.h \
    payrollspecialist.h \
    bankinformation.h \
    date.h \
    phonenumber.h \
    address.h \
    salary.h \
    status.h \
    constants.h \
    role.h \
    paystub.h \
    editemployeeinfocontrol.h \
    listemployeescontrol.h \
    applysalarydeductioncontrol.h \
    payrollgenerationtool.h \
    manageemployeesalarycontrol.h

FORMS    += mainwindow.ui
