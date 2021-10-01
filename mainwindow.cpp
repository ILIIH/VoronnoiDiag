#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

mView->setRandSite();

}

void MainWindow::on_pushButton_2_clicked()

{
QString Filtr = "Text File (*.txt) ";
QString file_name = QFileDialog::getOpenFileName(this,"Open file","D://",Filtr);
ui->lineEdit_2->setText(file_name);
QFile Site(file_name);
QString site_string;

if ((Site.exists())&&(Site.open(QIODevice::ReadOnly))){site_string = Site.readAll();}
QPoint temp;
QString temp_stringx="";
QString temp_stringy="";
for(int i=0;site_string[i]!='\0';i++){

    if(site_string[i]=='('){
        int q=i+1; bool zapInsp =0;
        while(site_string[q]!=')'){
            if(site_string[q]==',')zapInsp=1;
            if(zapInsp==0&&site_string[q]!=','){
                temp_stringx+=site_string[q];

            }
            else if(site_string[q]!=','){
                temp_stringy+=site_string[q];

            }
q++;
        }
        temp.setX(temp_stringx.toInt());
        temp.setY(temp_stringy.toInt());
        mView->setSite(temp);
        mView->paintSite(temp);
i=q;
temp_stringx.clear();
temp_stringy.clear();
    }
}


}

void MainWindow::on_pushButton_5_clicked()
{
mView->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->comboBox->currentIndex()==0)ui->lineEdit->setText(mView->PaintPerebor(1));
    if(ui->comboBox->currentIndex()==1)ui->lineEdit->setText(mView->PaintPerebor(3));
    if(ui->comboBox->currentIndex()==2)ui->lineEdit->setText(mView->PaintPerebor(4));
    if(ui->comboBox->currentIndex()==3)ui->lineEdit->setText(mView->PaintPerebor(2));
    if(ui->comboBox->currentIndex()==4)ui->lineEdit->setText(mView->PaintPerebor(5));
}

void MainWindow::on_pushButton_4_clicked()
{
    QString Filtr = " Text File (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this,"Open file","D://",Filtr);
    ui->lineEdit_2->setText(file_name);
    QFile Site(file_name);
    QString site_string;

    if ((Site.exists())&&(Site.open(QIODevice::ReadOnly))){mView->Granici_Est=1;site_string = Site.readAll();}
    QPoint temp;
    QString temp_stringx="";
    QString temp_stringy="";
    for(int i=0;site_string[i]!='\0';i++){

        if(site_string[i]=='('){
            int q=i+1; bool zapInsp =0;
            while(site_string[q]!=')'){
                if(site_string[q]==',')zapInsp=1;
                if(zapInsp==0&&site_string[q]!=','){
                    temp_stringx+=site_string[q];

                }
                else if(site_string[q]!=','){
                    temp_stringy+=site_string[q];

                }
    q++;
            }
            temp.setX(temp_stringx.toInt());
            temp.setY(temp_stringy.toInt());
       mView->Granici.push_back(temp);
    i=q;
    temp_stringx.clear();
    temp_stringy.clear();
        }
    }
    mView->PaintGranici();
}
