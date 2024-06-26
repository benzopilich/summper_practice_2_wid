#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sources.cpp"
#include <QString>
int Index;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->text1->hide();
    ui->text2->hide();
    ui->text3->hide();
    ui->pushButton->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_activated(int index)
{
    if(index==1)
    {
        ui->text1->setVisible(true);
        ui->pushButton->setVisible(true);
        Index=1;
    }
    if(index==2)
    {
        ui->text1->setVisible(true);
        ui->text2->setVisible(true);
        ui->pushButton->setVisible(true);
        Index=2;
    }
    if(index==3)
    {
        ui->text1->setVisible(true);
        ui->text2->setVisible(true);
        ui->text3->setVisible(true);
        ui->pushButton->setVisible(true);
        Index=3;
    }
}
void MainWindow::on_pushButton_clicked()
{
    if(Index==1)
    {
        int a=ui->text1->text().toInt();
        Prime pr;
        if(pr.isPrime(a))
        {
            ui->label1->setText("Prime");
        }
        else
        {
            vector<unsigned>res;
            res=pr.Factorization(a);
           QString TEXt1;
            TEXt1+="Составное";
            TEXt1+=" ";
            for(int i=0;i<res.size();i++)
            {
                TEXt1+=QString::number(res[i]);
                TEXt1+=" ";
            }
            ui->label1->setText(TEXt1);
        }
    }
    if(Index==2)
    {
        double x=ui->text1->text().toDouble();
        taylor t;
        double eps=ui->text2->text().toDouble();
        double res=t.series(x,eps);
        QString s;
        s+=QString::number(res);
        ui->label1->setText(s);
    }
    if(Index==3)
    {
        double a=ui->text1->text().toDouble();
        double b=ui->text3->text().toDouble();
        double c=ui->text2->text().toDouble();
        Roots t;
        vector<double>res;
        res=t.Disc(a,b,c);
        QString TEXt1;
        for(int i=0;i<res.size();i++)
        {
            TEXt1+=QString::number(res[i]);
            TEXt1+=" ";
        }
        ui->label1->setText(TEXt1);
    }
}

