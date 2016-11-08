#ifndef ELITELOGCONVERT_H
#define ELITELOGCONVERT_H

#include <QMainWindow>

namespace Ui {
class EliteLogConvert;
}

class EliteLogConvert : public QMainWindow
{
	Q_OBJECT

public:
	explicit EliteLogConvert(QWidget *parent = 0);
	~EliteLogConvert();

private slots:
	void on_actionOpen_EliteLog_log_triggered();

private:
	Ui::EliteLogConvert *ui;
};

#endif // ELITELOGCONVERT_H
