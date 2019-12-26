#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileInfoList>
#include <QPluginLoader>
#include <QDebug>
#include <QMessageBox>
#include "cvplugininterface.h"

#define PLUGINS_SUBFOLDER "/plugins/"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QDir filterDir(qApp->applicationDirPath() + PLUGINS_SUBFOLDER);
    QFileInfoList filters = filterDir.entryInfoList(QDir::NoDotAndDotDot |
                                                    QDir::Files,QDir::Name);
    foreach (QFileInfo filter, filters)
    {
     if(QLibrary::isLibrary(filter.absoluteFilePath()))
     {
         // 调用DLL
         QPluginLoader pluginLoader(filter.absoluteFilePath(),this);
         if(dynamic_cast<CvPluginInterface*>(pluginLoader.instance()))
         {
             ui->listWidget->addItem(filter.fileName());
             qDebug()<<dynamic_cast<CvPluginInterface*>(pluginLoader.instance())->description();
         }
         else
         {
             QMessageBox::warning(this,tr("Warning"),
                     QString(tr("Make sure only plugins"
                                " exist in plugins folder.<br>"
                                "%1 is not a plugin."))
                                  .arg(filter.fileName()));
         }
     }



    }
}
