#ifndef SQLCONVERTER_H
#define SQLCONVERTER_H

#include <QDateTime>
#include <QSqlDatabase>

class SqlConverter
{
public:
	SqlConverter();

	bool addSystem(const QString& name, QDateTime& date);
	void closeDB();

private:
	QSqlDatabase db;
};

#endif // SQLCONVERTER_H
