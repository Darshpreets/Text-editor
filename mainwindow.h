#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtCore>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

    void on_actionPaste_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionSave_triggered();

    void on_actionSaveas_triggered();

    void on_actionSaveAs_triggered();

private:
    Ui::MainWindow *ui;
    QString mFilename;
};

#endif // MAINWINDOW_H
