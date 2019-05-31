  #include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    showJudge=0;


    testFile.setFileName("C:/Users/k/Desktop/qbank");
    testFile.open(QIODevice::ReadWrite| QIODevice::Text);
    QByteArray zone=testFile.readAll();

    dataBase=new unpacker(zone);
    dataBase->FirstSort();


   cursorofBP=0;

    numOfFFdata=0;
    for(int i=0;i<200;i++)
    {
        if(!dataBase->ffblank[i].allSentence.isEmpty())
            numOfFFdata++;
    }
    //qDebug()<<numOfFFdata;


    ui->setupUi(this);

    clickedCounter=0;

    numOfQ=0;

    cursorAns=0;

    ui->reminder->setHidden(true);
    //ui->reminder->setFont();


    ui->head->setText(dataBase->ffblank[numOfQ].NsensitiveTextLF);
    ui->end->setText(dataBase->ffblank[numOfQ].NsensitiveTextRT);

    bpline[0].setParent(this);
    bpline[1].setParent(this);
    bpline[2].setParent(this);
    bpline[3].setParent(this);
    bpline[4].setParent(this);
    bpline[5].setParent(this);
    bpline[6].setParent(this);
    bpline[7].setParent(this);
    bpline[8].setParent(this);
    bpline[9].setParent(this);

    bplabel[0].setParent(this);
    bplabel[1].setParent(this);
    bplabel[2].setParent(this);
    bplabel[3].setParent(this);
    bplabel[4].setParent(this);
    bplabel[5].setParent(this);
    bplabel[6].setParent(this);
    bplabel[7].setParent(this);
    bplabel[8].setParent(this);
    bplabel[9].setParent(this);



    for(int i=0;i<10;i++)
    {
         QByteArray numberOflabel="";
        numberOflabel.insert(numberOflabel.length(),QString("%1")
                         .arg(i+1));
      bplabel[i].setText(numberOflabel);
    }



    bpline[0].setGeometry(300,370,113,21);
    bpline[1].setGeometry(299,400,113,21);
    bpline[2].setGeometry(299,440,113,21);
    bpline[3].setGeometry(299,470,113,21);
    bpline[4].setGeometry(300,510,113,21);
    bpline[5].setGeometry(540,370,113,21);
    bpline[6].setGeometry(539,400,113,21);
    bpline[7].setGeometry(539,440,113,21);
    bpline[8].setGeometry(539,470,113,21);
    bpline[9].setGeometry(539,510,113,21);

    //修改位置和大小

    bplabel[0].setGeometry(231,370,61,20);
    bplabel[1].setGeometry(230,400,61,20);
    bplabel[2].setGeometry(230,440,61,20);
    bplabel[3].setGeometry(230,470,61,20);
    bplabel[4].setGeometry(230,510,61,20);
    bplabel[5].setGeometry(471,370,61,20);
    bplabel[6].setGeometry(470,400,61,20);
    bplabel[7].setGeometry(470,440,61,20);
    bplabel[8].setGeometry(470,470,61,20);
    bplabel[9].setGeometry(470,510,61,20);

    bpline[0].setHidden(true);
    bpline[1].setHidden(true);
    bpline[2].setHidden(true);
    bpline[3].setHidden(true);
    bpline[4].setHidden(true);
    bpline[5].setHidden(true);
    bpline[6].setHidden(true);
    bpline[7].setHidden(true);
    bpline[8].setHidden(true);
    bpline[9].setHidden(true);

    bplabel[0].setHidden(true);
    bplabel[1].setHidden(true);
    bplabel[2].setHidden(true);
    bplabel[3].setHidden(true);
    bplabel[4].setHidden(true);
    bplabel[5].setHidden(true);
    bplabel[6].setHidden(true);
    bplabel[7].setHidden(true);
    bplabel[8].setHidden(true);
    bplabel[9].setHidden(true);


    numofBPdata=0;
    for(int i=0;i<50;i++)
    {
        BPinfo[i].pointofQ=0;

        for(int j=0;j<10;j++)
        {
            if(!dataBase->bpQues[i].point[j].isEmpty())
                BPinfo[i].pointofQ++;
        }

        //qDebug()<<BPinfo[i].pointofQ<<"分点数量";

        if(BPinfo[i].pointofQ)
            numofBPdata++;
    }

    //qDebug()<<numofBPdata<<"题目数量";
    //qDebug()<<zone.data()<<"题目数量";


    if(testFile.isOpen())
        testFile.close();
}

Widget::~Widget()
{
    //delete testFile;
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

void Widget::on_pushButton_2_clicked()
{
    bpline[0].setHidden(true);
    bpline[1].setHidden(true);
    bpline[2].setHidden(true);
    bpline[3].setHidden(true);
    bpline[4].setHidden(true);
    bpline[5].setHidden(true);
    bpline[6].setHidden(true);
    bpline[7].setHidden(true);
    bpline[8].setHidden(true);
    bpline[9].setHidden(true);

    bplabel[0].setHidden(true);
    bplabel[1].setHidden(true);
    bplabel[2].setHidden(true);
    bplabel[3].setHidden(true);
    bplabel[4].setHidden(true);
    bplabel[5].setHidden(true);
    bplabel[6].setHidden(true);
    bplabel[7].setHidden(true);
    bplabel[8].setHidden(true);
    bplabel[9].setHidden(true);

    ui->pushButton_2->setText("确认输入");

    if(!showJudge)
    {
        ui->Qhead->setText(dataBase->bpQues[cursorofBP].HEAD);
        for(int i=0;i<BPinfo[cursorofBP].pointofQ;i++)
        {
            bpline[i].show();
            //qDebug()<<"i am in here";
            bplabel[i].show();
        }
        showJudge=1;

    }
    //qDebug()<<"答案";
    for(int i=0;i<BPinfo[cursorofBP].pointofQ;i++)
    qDebug()<<dataBase->bpQues[cursorofBP].point[i].data();
    //qDebug()<<"答案";


    int judge=0;
    for(int i=0;i<BPinfo[cursorofBP].pointofQ;i++)
    {
        if(bpline[i].text()==dataBase->bpQues[cursorofBP].point[i])
            judge++;
    }
    if(judge==BPinfo[cursorofBP].pointofQ)

    {
        ui->reminderBP->setText("correct!");

        for(int i=0;i<BPinfo[cursorofBP].pointofQ;i++)
        {
            bpline[i].clear();
        }

        if(cursorofBP<numofBPdata-1)
            cursorofBP++;
        else
            cursorofBP=0;

        ui->Qhead->setText(dataBase->bpQues[cursorofBP].HEAD);

        for(int i=0;i<BPinfo[cursorofBP].pointofQ;i++)
        {
            bpline[i].show();
            bplabel[i].show();
        }


    }

    else
    {
        for(int i=0;i<BPinfo[cursorofBP].pointofQ;i++)
        {
            bpline[i].show();
            bplabel[i].show();
        }

        ui->reminderBP->setText("wrong!");
    }


}
