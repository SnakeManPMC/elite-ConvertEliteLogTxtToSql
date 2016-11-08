#include "sqlconverter.h"

#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>

SqlConverter::SqlConverter()
{
	QString path = "pmc_elitelog.db";
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(path);
	db.open();

	if (!db.open())
	{
		qDebug() << "Error: connection with database fail";
	}
	else
	{
		qDebug() << "Database: connection ok";
	}
}


bool SqlConverter::addSystem(const QString& name, QDateTime& date)
{
	bool success = false;

	QSqlQuery query;
	query.prepare("INSERT INTO pmcsystem (systemName, time, systemNote) VALUES (:name, :time, :systemNote)");
	query.bindValue(":name", name);
	query.bindValue(":time", date);
	query.bindValue(":systemNote", "");
	if(query.exec())
	{
		success = true;
	}
	else
	{
		qDebug() << "addSystem error:  " << query.lastError();
	}

	return success;
}


void SqlConverter::closeDB()
{
	db.close();
}
