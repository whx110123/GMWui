#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCloseEvent>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	init_form();
	mytree = new QTreeWidget( ui->frame);
	QVBoxLayout *myLayout = new QVBoxLayout(ui->frame);
	myLayout->setContentsMargins(0,0,0,0);
	myLayout->addWidget(mytree);
	mytree->show();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::init_form()
{
	getpic = new FunGetPicDlg(this);
	readSettings();
}

int MainWindow::maybeSave()
{
	return QMessageBox::question(this,"问题对话框","是否保存窗口状态","保存","不保存","取消");
}

void MainWindow::readSettings()
{
	QString name = qApp->applicationName() + ".ini";
	QSettings settings(name, QSettings::IniFormat);
	settings.beginGroup("MainWindow");
	restoreGeometry(settings.value("geometry").toByteArray());
	restoreState(settings.value("windowState").toByteArray());
//	QStringList tmplst = settings.value("tableState").toString().split(' ');
//	tmplst.removeAll("");
//	for (int i = 0; i <ui->treeWidget_2->columnCount() && i<tmplst.size();i++)
//	{
//		ui->treeWidget_2->setColumnWidth(i,tmplst.value(i).toInt());
//	}
	settings.endGroup();
}

void MainWindow::writeSettings()
{
	QString name = qApp->applicationName() + ".ini";
	QSettings settings(name, QSettings::IniFormat);
	settings.beginGroup("MainWindow");
	settings.setValue("geometry", saveGeometry());
	settings.setValue("windowState", saveState());

//	QString tmp;
//	for (int i = 0; i <ui->treeWidget_2->columnCount();i++)
//	{
//		tmp += QString::number(ui->treeWidget_2->columnWidth(i))+" ";
//	}
//	settings.setValue("tableState", tmp);
	//		settings.setValue("splitterState", myDataViewWidget->saveState());
	settings.endGroup();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
//	int ret = maybeSave();
//	if (ret == 0)
//	{
		writeSettings();		//保存界面状态
		event->accept();
//	}
//	else if( ret == 1)
//	{
//		event->accept();
//	}
//	else
//	{
//		event->ignore();
//	}

}

void MainWindow::on_actGetPng_triggered()
{
	getpic->show();
}
