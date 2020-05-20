#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QTreeWidget>
#include "fungetpicdlg.h"
namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	void init_form();
	void init_config();
	int maybeSave();
	void readSettings();
	void writeSettings();
protected:
	void closeEvent(QCloseEvent *event);

private slots:

	void on_actGetPng_triggered();

private:
	Ui::MainWindow *ui;
	QTreeWidget *mytree;
	FunGetPicDlg *getpic;
};

#endif // MAINWINDOW_H
