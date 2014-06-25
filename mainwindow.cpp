#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 this->setCentralWidget(ui->textEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    mFilename="Darsh.txt";
       ui->textEdit->setPlainText("darshpreets.wordpress.com");
}

void MainWindow::on_actionOpen_triggered()
{

   QString file = QFileDialog::getOpenFileName(this,"Open a File ");
   if ( !file.isEmpty())
   {
       QFile sFile(file);
       if(sFile.open(QFile::ReadOnly | QFile::Text ))
       {
           QTextStream in(&sFile);
           QString text =in.readAll();
           sFile.close();

           ui->textEdit->setPlainText(text);
       }
   }
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}



void MainWindow::on_actionSave_triggered()
{
    QFile sFile(mFilename);
        if(sFile.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream out(&sFile);

            out<<ui->textEdit->toPlainText();

            sFile.flush();
            sFile.close();
        }

}

void MainWindow::on_actionSaveAs_triggered()
{
    QString file = QFileDialog::getSaveFileName(this,"Open a File");

        if(!file.isEmpty())
        {
            mFilename=file;
            on_actionSave_triggered();
        }

}
