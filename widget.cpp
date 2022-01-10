#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin)
{
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 100);
}

void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbReset_clicked()
{
    int coin500 = 0;
    int coin100 = 0;
    int coin50 = 0;
    int coin10 = 0;

    coin500 = money/500;
    money %= 500;
    coin100 = money/100;
    money %= 100;
    coin50 = money/50;
    money %= 50;
    coin10 = money/10;
    money %= 10;

    QString msg;
    msg = "500원 "+ QString::number(coin500) + "개, ";
    msg += "100원 "+ QString::number(coin100) + "개, ";
    msg += "50원 "+ QString::number(coin50) + "개, ";
    msg += "10원 "+ QString::number(coin10) + "개";

    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();

    changeMoney(0); // return

}

