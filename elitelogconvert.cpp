#include "elitelogconvert.h"
#include "ui_elitelogconvert.h"

#include <QDateTime>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include "sqlconverter.h"

EliteLogConvert::EliteLogConvert(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::EliteLogConvert)
{
	ui->setupUi(this);
}

EliteLogConvert::~EliteLogConvert()
{
	delete ui;
}

// file -> open elitelog menu
void EliteLogConvert::on_actionOpen_EliteLog_log_triggered()
{
	// browse to elitelog.log file
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open EliteLog log file"), "",
		tr("Elitelog (*.log);;All Files (*)"));

	QFile CmdrLog(fileName);

	// open our file name (elitelog.log)
	if (!CmdrLog.open(QIODevice::ReadOnly))
	{
		QMessageBox::information(this, tr("Unable to open your personal LOG file for reading"),
		CmdrLog.errorString().append("\n\nUnable to open your personal LOG text file for reading, something is wrong, dude..."));
		return;
	}

	QString line;
	QStringList tempsystem;
	QTextStream in(&CmdrLog);

	// open sql file
	SqlConverter Sqlc;

	// read line by line
	while (!in.atEnd())
	{
		line = in.readLine();
		tempsystem = line.split(",");

		// convert *string* UTC time to QDateTime
		QDateTime date = QDateTime::fromString(tempsystem[1], Qt::ISODate);

		// send to our sql database
		Sqlc.addSystem(tempsystem[0], date);
	}
	CmdrLog.close();
	Sqlc.closeDB();

	ui->textEdit->append(fileName + " converted to pmc_elitelog.db, all done!");
}
