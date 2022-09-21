#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

#define PI 3.14159265

QString operandName1 = "";
QString operandName2 = "";

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

void MainWindow::on_button_answer_clicked()
{
    bool ok1;
    bool ok2;
    double firstNumber = ui->lineEdit->text().toDouble(&ok1);
    double secondNumber = ui->lineEdit_2->text().toDouble(&ok2);
    QString outputText = "";
    QString division;


    if (ui->lineEdit->text() != "inf" and ui->lineEdit->text() != "nan" and ui->lineEdit_2->text() != "inf" and ui->lineEdit_2->text() != "nan")
    {
        if(ok1) // Проверка 1 операнда для вычислений с одним операндом
        {
            ui->label_percent->setText("");
            if (ui->button_sin->isChecked())
            {
                outputText.setNum(round(sin(firstNumber * PI / 180)*10000000)/10000000);
            }

            else if (ui->button_cos->isChecked())
            {
                outputText.setNum(round(cos(firstNumber * PI / 180)*10000000)/10000000);
            }

            else if (ui->button_tg->isChecked())
            {
                outputText.setNum(round(tan(firstNumber * PI / 180)*10000000)/10000000);
            }

            else if (ui->button_ctg->isChecked())
            {
                outputText.setNum(round(1/tan(firstNumber * PI / 180)*10000000)/10000000);
            }

            else if (ui->button_arccos->isChecked())
            {
                outputText.setNum(acos(firstNumber) * 180 / PI);
            }

            else if (ui->button_arcsin->isChecked())
            {
                outputText.setNum(asin(firstNumber) * 180 / PI);
            }

            else if(ok2) // Проверка 2 операнда для операций с двумя операндами
            {
                if (ui->button_plus->isChecked())
                {
                    outputText.setNum(firstNumber + secondNumber);
                }

                else if (ui->button_mins->isChecked())
                {
                    outputText.setNum(firstNumber - secondNumber);
                }

                else if (ui->button_multi->isChecked())
                {
                    outputText.setNum(firstNumber * secondNumber);
                }

                else if (ui->button_divide->isChecked())
                {
                    if (secondNumber != 0) // Проверка для деления на ноль
                    {
                        outputText.setNum(firstNumber / secondNumber);
                        division.setNum(fmod(firstNumber, secondNumber));
                        ui->label_percent->setText(division);
                    }

                    else
                        outputText = "Нельзя делить на ноль!";
                }

                else if (ui->button_upper->isChecked())
                {
                    outputText.setNum(pow(firstNumber, secondNumber));
                }

                else if (ui->button_dupper->isChecked())
                {
                    if (firstNumber >= 0) // Проверка на знак под корнем
                        outputText.setNum(pow(firstNumber, 1/secondNumber));

                    else
                        outputText = "Не завезли комплексные числа, пока...";
                }
            }

            else // Ошибка если нет 2 операнда или там слово
                outputText = "Ошибка во 2 операнде";
        }
        else // Ошибка если нет 1 операнда или там слово
            outputText = "Ошибка в 1 операнде";
        ui->label_resultAnswer->setText(outputText);
    }
    else
    {
       ui->label_resultAnswer->setText("inf и nan Низя");
    }
}

void MainWindow::on_button_sin_toggled(bool checked)
{
    if (checked)
    {
        operandName1 = "Тригонометрический операнд";
        ui->label_op1_text->setText(operandName1);
        ui->lineEdit_2->setVisible(false);
        ui->label_op2_text->setVisible(false);
    }

    else
    {
        ui->lineEdit_2->setVisible(true);
        ui->label_op2_text->setVisible(true);
    }
}

void MainWindow::on_button_arcsin_toggled(bool checked)
{
    if (checked)
    {
        operandName1 = "Тригонометрический операнд";
        ui->label_op1_text->setText(operandName1);
        ui->lineEdit_2->setVisible(false);
        ui->label_op2_text->setVisible(false);
    }

    else
    {
        ui->lineEdit_2->setVisible(true);
        ui->label_op2_text->setVisible(true);
    }
}

void MainWindow::on_button_cos_toggled(bool checked)
{
    if (checked)
    {
        operandName1 = "Тригонометрический операнд";
        ui->label_op1_text->setText(operandName1);
        ui->lineEdit_2->setVisible(false);
        ui->label_op2_text->setVisible(false);
    }

    else
    {
        operandName1 = "Тригонометрический операнд";
        ui->label_op1_text->setText(operandName1);
        ui->lineEdit_2->setVisible(true);
        ui->label_op2_text->setVisible(true);
    }
}

void MainWindow::on_button_arccos_toggled(bool checked)
{
    if (checked)
    {
        operandName1 = "Тригонометрический операнд";
        ui->label_op1_text->setText(operandName1);
        ui->lineEdit_2->setVisible(false);
        ui->label_op2_text->setVisible(false);
    }

    else
    {
        ui->lineEdit_2->setVisible(true);
        ui->label_op2_text->setVisible(true);
    }
}

void MainWindow::on_button_tg_toggled(bool checked)
{
    if (checked)
    {
        operandName1 = "Тригонометрический операнд";
        ui->label_op1_text->setText(operandName1);
        ui->lineEdit_2->setVisible(false);
        ui->label_op2_text->setVisible(false);
    }

    else
    {
        ui->lineEdit_2->setVisible(true);
        ui->label_op2_text->setVisible(true);
    }
}

void MainWindow::on_button_ctg_toggled(bool checked)
{
    if (checked)
    {
        operandName1 = "Тригонометрический операнд";
        ui->label_op1_text->setText(operandName1);
        ui->lineEdit_2->setVisible(false);
        ui->label_op2_text->setVisible(false);
    }

    else
    {
        ui->lineEdit_2->setVisible(true);
        ui->label_op2_text->setVisible(true);
    }
}

void MainWindow::on_button_plus_clicked()
{
    operandName1 = "Слагаемое 1";
    operandName2 = "Слагаемое 2";
    ui->label_op1_text->setText(operandName1);
    ui->label_op2_text->setText(operandName2);
}

void MainWindow::on_button_multi_clicked()
{
    operandName1 = "Число для умножения 1";
    operandName2 = "Число для умножения 2";
    ui->label_op1_text->setText(operandName1);
    ui->label_op2_text->setText(operandName2);
}

void MainWindow::on_button_mins_clicked()
{
    operandName1 = "Число для разницы 1";
    operandName2 = "Число для разницы 2";
    ui->label_op1_text->setText(operandName1);
    ui->label_op2_text->setText(operandName2);
}

void MainWindow::on_button_divide_clicked()
{
    operandName1 = "Числитель";
    operandName2 = "Знаменатель";
    ui->label_op1_text->setText(operandName1);
    ui->label_op2_text->setText(operandName2);
}

void MainWindow::on_button_upper_clicked()
{
    operandName1 = "Число в сетепнь";
    operandName2 = "Степень";
    ui->label_op1_text->setText(operandName1);
    ui->label_op2_text->setText(operandName2);
}

void MainWindow::on_button_dupper_clicked()
{
    operandName1 = "Число в корень 1";
    operandName2 = "Степень корня 2";
    ui->label_op1_text->setText(operandName1);
    ui->label_op2_text->setText(operandName2);
}
