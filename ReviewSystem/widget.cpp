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

    numOfFFdata=0;
    for(int i=0;i<200;i++)
    {
        if(!dataBase->ffblank[i].allSentence.isEmpty())
            numOfFFdata++;
    }
    qDebug()<<numOfFFdata;

    ui->setupUi(this);

    clickedCounter=0;

    numOfQ=0;

    cursorAns=0;

    ui->reminder->setHidden(true);
    //ui->reminder->setFont();

    ui->head->setText(dataBase->ffblank[numOfQ].NsensitiveTextLF);
    ui->end->setText(dataBase->ffblank[numOfQ].NsensitiveTextRT);
}

Widget::~Widget()
{
    delete dataBase;
    delete ui;

}

void Widget::on_pushButton_clicked()
{


        //确认输入完成
        QString answer=ui->lineEdit->text();
        qDebug()<<dataBase->ffblank[cursorAns].sensitiveText.data();
        if(answer==dataBase->ffblank[cursorAns].sensitiveText)
        {
           ui->reminder->setHidden(false);
           ui->reminder->setText("correct!");

           if(numOfQ<numOfFFdata-1)
               numOfQ++;
           else
               numOfQ=0;
           switchQ();
           if(cursorAns<numOfFFdata-1)
           cursorAns++;
           else
               cursorAns=0;
           ui->lineEdit->clear();
        }

        else
        {
            ui->reminder->setHidden(false);
            ui->reminder->setText("wrong!");

        }
        ui->pushButton->setText("点击输入");


}


void Widget::switchQ()
{
    ui->head->setText(dataBase->ffblank[numOfQ].NsensitiveTextLF);
    ui->end->setText(dataBase->ffblank[numOfQ].NsensitiveTextRT);
}
