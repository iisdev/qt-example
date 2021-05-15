#include "dialog.h"
#include "./ui_dialog.h"



Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    oper = 1;

    ui ->radioButton_pl->setChecked(true); // set radio-button ON

    QObject::connect(this, SIGNAL(opertion_signal(int)), this, SLOT(operation_slot(int)));

    QObject::connect(ui->radioButton_pl, SIGNAL(clicked()), this, SLOT(plus_slot()));
    QObject::connect(ui->radioButton_min, SIGNAL(clicked()), this, SLOT(minus_slot()));
    QObject::connect(ui->radioButton_mul, SIGNAL(clicked()), this, SLOT(mul_slot()));
    QObject::connect(ui->radioButton_div, SIGNAL(clicked()), this, SLOT(div_slot()));

    QObject::connect(ui->pushButton_calc, SIGNAL(clicked()), this, SLOT(calc_slot()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::calc_slot() {
    double A, B, R = 0.;

    A = ui->lineEdit_A->text().toDouble(); // convert text from line to double
    B = ui->lineEdit_B->text().toDouble();

    switch (oper)
    {
        case 1: R = A+B; break;
        case 2: R = A-B; break;
        case 3: R = A*B; break;
        case 4: R = A/B; break;
    }

    ui->label->setText("Result: " + QString::number(R)); // show result
}

void Dialog::oper_slot(int o)
{
    oper = o;
}

void Dialog::plus_slot()
{
    emit oper_slot(1);
}
void Dialog::minus_slot()
{
    emit oper_slot(2);
}
void Dialog::mul_slot()
{
    emit oper_slot(3);
}
void Dialog::div_slot()
{
    emit oper_slot(4);
}



