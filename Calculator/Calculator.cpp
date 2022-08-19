#include "Calculator.h"

double firstnum;
bool userIsTypingSecondnum = false;
Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connectSignalSlot();
}

Calculator::~Calculator()
{}

void Calculator::connectSignalSlot()
{
    // 设置连接

    connect(ui.pushButton_0, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui.pushButton_1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui.pushButton_2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui.pushButton_3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui.pushButton_4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui.pushButton_5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui.pushButton_6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui.pushButton_7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui.pushButton_8, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui.pushButton_9, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui.pushButton_decimal, SIGNAL(released()), this, SLOT(on_pushButton_Decimal()));
    connect(ui.pushButton_PosNage, SIGNAL(released()), this,SLOT(unary_operation_pressed()));
    connect(ui.pushButton_clear, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
	connect(ui.pushButton_precent, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
	connect(ui.pushButton_add, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui.pushButton_equal, SIGNAL(released()), this, SLOT(equal_pressed()));
    connect(ui.pushButton_subtraction, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui.pushButton_multiplication, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui.pushButton_devide, SIGNAL(released()), this, SLOT(binary_operation_pressed()));

    ui.pushButton_add->setCheckable(true);
    ui.pushButton_subtraction->setCheckable(true);
    ui.pushButton_multiplication->setCheckable(true);
    ui.pushButton_devide->setCheckable(true);
}

// 按下数字键
void Calculator::digit_pressed()
{
    QPushButton *button = (QPushButton *)sender();
    QString newLabel;
    double labelnum;
    if ((ui.pushButton_add->isChecked() || ui.pushButton_subtraction->isChecked() ||
        ui.pushButton_multiplication->isChecked() || ui.pushButton_devide->isChecked())&&(!userIsTypingSecondnum))
    {
        labelnum = button->text().toDouble();
        userIsTypingSecondnum = true;
        newLabel = QString::number(labelnum, 'g', 15);
    }
    else
    {
        if (ui.label->text().contains(".")&&button->text() == "0")
        {
            newLabel = ui.label->text() + button->text();
        }
        else
        {
            labelnum = (ui.label->text() + button->text()).toDouble();
            newLabel = QString::number(labelnum, 'g', 15);
        }
    }
    
    
    ui.label->setText(newLabel);
}


void Calculator::on_pushButton_Decimal()
{
    ui.label->setText(ui.label->text() + ".");
}

void Calculator::unary_operation_pressed()
{
    QPushButton* button = (QPushButton*) sender();
    double labelnum;
    QString newlabel;

    if (button->text() == "+/-")
    {
        labelnum = ui.label->text().toDouble();
        labelnum = labelnum * -1;
        newlabel = QString::number(labelnum, 'g', 15);
        ui.label->setText(newlabel);
    }
    if (button->text() == "C")
    {
        newlabel = "0";
        ui.label->setText(newlabel);
        ui.pushButton_add->setChecked(false);
        ui.pushButton_subtraction->setChecked(false);
        ui.pushButton_multiplication->setChecked(false);
        ui.pushButton_devide->setChecked(false);
        userIsTypingSecondnum = false;
    }
    if (button->text() == "%")
    {
		labelnum = ui.label->text().toDouble();
		labelnum = labelnum * 0.01;
		newlabel = QString::number(labelnum, 'g', 15);
		ui.label->setText(newlabel);
    }
}

void Calculator::binary_operation_pressed()
{
    QPushButton* button = (QPushButton*)sender();
    firstnum = ui.label->text().toDouble();
    button->setChecked(true);
    
}

void Calculator::equal_pressed()
{
    double labelnum, secondnum;
    QString newlabel;
    secondnum = ui.label->text().toDouble();

    if (ui.pushButton_add->isChecked())
    {
        labelnum = firstnum + secondnum;
        newlabel = QString::number(labelnum, 'g', 15);
        ui.label->setText(newlabel);
        ui.pushButton_add->setChecked(false);
    }
	else if (ui.pushButton_subtraction->isChecked())
	{
        labelnum = firstnum - secondnum;
		newlabel = QString::number(labelnum, 'g', 15);
		ui.label->setText(newlabel);
		ui.pushButton_subtraction->setChecked(false);
	}
	else if (ui.pushButton_multiplication->isChecked())
	{
        labelnum = firstnum * secondnum;
		newlabel = QString::number(labelnum, 'g', 15);
		ui.label->setText(newlabel);
		ui.pushButton_multiplication->setChecked(false);
	}
	else if (ui.pushButton_devide->isChecked())
	{
        labelnum = firstnum / secondnum;
		newlabel = QString::number(labelnum, 'g', 15);
		ui.label->setText(newlabel);
		ui.pushButton_devide->setChecked(false);
	}

    userIsTypingSecondnum = false;
}
