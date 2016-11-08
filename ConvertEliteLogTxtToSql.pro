#-------------------------------------------------
#
# Project created by QtCreator 2016-11-06T12:31:32
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ConvertEliteLogTxtToSql
TEMPLATE = app


SOURCES += main.cpp\
        elitelogconvert.cpp \
    sqlconverter.cpp

HEADERS  += elitelogconvert.h \
    sqlconverter.h

FORMS    += elitelogconvert.ui
