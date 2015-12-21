#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_addPcBtn_clicked();

    void on_addPerfBtn_clicked();

    void on_calcBtn_clicked();

    void on_perfEdit_returnPressed();

    void on_subPcBtn_clicked();

    void on_clrPcListBtn_clicked();

    void on_subPerfBtn_clicked();

    void on_clrPcBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
