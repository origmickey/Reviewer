  #include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    QFile testFile;
    testFile.setFileName("C:/Users/k/Desktop/qbank");


    dataBase=new unpacker(&testFile);
    dataBase->FirstSort();

    ui->setupUi(this);

    clickedCounter=0;

    ui->lineEdit->setReadOnly(true);
    ui->reminder->setHidden(true);
}

Widget::~Widget()
{
    delete dataBase;
    delete ui;

}

void Widget::on_pushButton_clicked()
{qDebug()<<dataBase->ffblank[0].sensitiveText.data();
    clickedCounter++;
    if(clickedCounter%2)
    {
        //输入
        ui->lineEdit->setReadOnly(false);
        ui->pushButton->setText("确认");
    }
    else if(clickedCounter)
    {
        ui->lineEdit->setReadOnly(true);
        //确认输入完成
        QString answer=ui->lineEdit->text();
        if(answer==dataBase->ffblank[0].sensitiveText)
        {
           ui->reminder->setHidden(false);
           ui->reminder->setText("correct!");
        }

        else
        {
            ui->reminder->setHidden(false);
            ui->reminder->setText("wrong!,正确答案是：帝国主义和无产阶级革命");

        }
        ui->pushButton->setText("点击输入");
    }
}
