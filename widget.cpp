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
    int coin[] = {500, 100, 50, 10};
    int size = sizeof(coin)/sizeof(int);
    int remain = 0;
    QString msg = "";

    for(int i = 0; i < size; i++)
    {
        remain = int(money/coin[i]);
        if(remain > 0)
        {
            money %= coin[i];
            msg += QString::number(coin[i]) + "원 "+ QString::number(remain) + "개\n";
        }
    }

    changeMoney(0);
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec(); // dialog
    // no play
}

