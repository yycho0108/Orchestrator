#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "orchestrate.h"

#include <QListWidget>
#include <QTableWidget>
#include <QList>
#include <QMessageBox>

#include <sstream>
#include <iostream>

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

bool warnEmpty(){
    QMessageBox mBox;
    mBox.setText("A Field value is Null.");
    mBox.setInformativeText("Continue anyway?");
    mBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    mBox.setDefaultButton(QMessageBox::No);
    if(mBox.exec() == QMessageBox::Yes){
        return true;
    }
    return false;
}

void MainWindow::on_addPcBtn_clicked()
{
    auto title = ui->titleEdit->text();
    auto comp = ui->compEdit->text();
    if(title.size()==0 || comp.size()==0){
        if(!warnEmpty())
            return;
    }

    std::stringstream s;
    for(int i=0;i<ui->perfList->count();++i)
        s << ui->perfList->item(i)->text().toUtf8().constData() << ';';
    auto r = ui->pcTable->rowCount();
    ui->pcTable->setRowCount(r+1);
    ui->pcTable->setItem(r,0,new QTableWidgetItem(title));
    ui->pcTable->setItem(r,1,new QTableWidgetItem(comp));
    ui->pcTable->setItem(r,2,new QTableWidgetItem(QString::fromStdString(s.str())));
    ui->titleEdit->clear();
    ui->compEdit->clear();
    ui->perfList->clear();
}

void MainWindow::on_addPerfBtn_clicked()
{
    auto perf = ui->perfEdit->text();
    if(perf.size() == 0 && !warnEmpty()){
        return;
    }
    ui->perfList->addItem(perf);
    ui->perfEdit->clear();
}

std::list<std::string> split(std::string&& s){
    std::stringstream ss(s);
    std::string item;
    std::list<std::string> l;
    while(std::getline(ss,item,';')){
        l.push_back(item);
    }
    return l;
}

void MainWindow::on_calcBtn_clicked()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->resCombo->clear();
    Orchestrator o;
    for(int i=0;i<ui->pcTable->rowCount();++i){
        auto comp = ui->pcTable->item(i,0)->text().toStdString();
        auto l = split(ui->pcTable->item(i,2)->text().toStdString());
        o.push(comp, l);
    }
    auto pcs = o.orchestrate();
    for(auto p : pcs){
        ui->resCombo->addItem(QString::fromStdString(p));
    }
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_perfEdit_returnPressed()
{
    on_addPerfBtn_clicked();
}

void MainWindow::on_subPcBtn_clicked()
{
    ui->pcTable->removeRow(ui->pcTable->currentRow());
}



void MainWindow::on_clrPcListBtn_clicked()
{
    ui->pcTable->clear();
    ui->pcTable->setRowCount(0);
}

void MainWindow::on_subPerfBtn_clicked()
{
    delete ui->perfList->takeItem(ui->perfList->currentRow());
}

void MainWindow::on_clrPcBtn_clicked()
{
    ui->compEdit->clear();
    ui->titleEdit->clear();
    ui->perfEdit->clear();
    ui->perfList->clear();

}
