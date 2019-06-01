  #include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    showJudge=0;


    //testFile.setFileName("C:/Users/k/Desktop/qbank");
    testFile.setFileName("D:/WORK/QT/ReviewSystem/Reviewer/ReviewSystem/Qbank");
    testFile.open(QIODevice::ReadWrite| QIODevice::Text);
    QByteArray zone=testFile.readAll();

    dataBase=new unpacker(zone);
    dataBase->FirstSort();

    cursorofBP=-1;

    numOfFFdata=dataBase->ffblank.length();

    ui->setupUi(this);

    clickedCounter=0;

    numOfQ=-1;

    cursorAns=-1;

    ui->reminder->setHidden(true);

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

    bpline_x = 250;
    bpline_y = 370;
    bpline_w = 200;
    bpline_h = 50;

    bplabel_x = bpline_x -20;
    bplabel_y = bpline_y;
    bplabel_w = 30;
    bplabel_h = bpline_h;

    bpline[0].setGeometry(bpline_x, bpline_y, bpline_w, bpline_h);
    bpline[1].setGeometry(bpline_x, bpline_y + 10 + bpline_h, bpline_w, bpline_h);
    bpline[2].setGeometry(bpline_x, bpline_y + (10 + bpline_h)*2, bpline_w, bpline_h);
    bpline[3].setGeometry(bpline_x, bpline_y + (10 + bpline_h)*3, bpline_w, bpline_h);
    bpline[4].setGeometry(bpline_x, bpline_y + (10 + bpline_h)*4, bpline_w, bpline_h);
    bpline[5].setGeometry(bpline_x + 300, bpline_y, bpline_w, bpline_h);
    bpline[6].setGeometry(bpline_x + 300, bpline_y + 10 + bpline_h, bpline_w, bpline_h);
    bpline[7].setGeometry(bpline_x + 300, bpline_y + (10 + bpline_h)*2, bpline_w, bpline_h);
    bpline[8].setGeometry(bpline_x + 300, bpline_y + (10 + bpline_h)*3, bpline_w, bpline_h);
    bpline[9].setGeometry(bpline_x + 300, bpline_y + (10 + bpline_h)*4, bpline_w, bpline_h);

    //修改位置和大小

    bplabel[0].setGeometry(bplabel_x, bpline_y, bplabel_w, 20);
    bplabel[1].setGeometry(bplabel_x, bpline_y + 10 + bplabel_h, bplabel_w, bpline_h);
    bplabel[2].setGeometry(bplabel_x, bpline_y + (10 + bplabel_h)*2, bplabel_w, bpline_h);
    bplabel[3].setGeometry(bplabel_x, bpline_y + (10 + bplabel_h)*3, bplabel_w, bpline_h);
    bplabel[4].setGeometry(bplabel_x, bpline_y + (10 + bplabel_h)*4, bplabel_w, bpline_h);
    bplabel[5].setGeometry(bplabel_x + 300, bpline_y, bplabel_w, bpline_h);
    bplabel[6].setGeometry(bplabel_x + 300, bpline_y + 10 + bplabel_h, bplabel_w, bpline_h);
    bplabel[7].setGeometry(bplabel_x + 300, bpline_y + (10 + bplabel_h)*2, bplabel_w, bpline_h);
    bplabel[8].setGeometry(bplabel_x + 300, bpline_y + (10 + bplabel_h)*3, bplabel_w, bpline_h);
    bplabel[9].setGeometry(bplabel_x + 300, bpline_y + (10 + bplabel_h)*4, bplabel_w, bpline_h);

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


//    numofBPdata=0;
      numofBPdata=dataBase->bpQues.length();

//    for(int i=0;i<50;i++)
//    {
//        BPinfo[i].pointofQ=0;

//        for(int j=0;j<10;j++)
//        {
//            if(!dataBase->bpQues[i].point[j].isEmpty())
//                BPinfo[i].pointofQ++;
//        }

//        //qDebug()<<BPinfo[i].pointofQ<<"分点数量";

//        if(BPinfo[i].pointofQ)
//            numofBPdata++;
//    }

      for(int i=0;i<numofBPdata;i++)
          BPinfo[i].pointofQ=dataBase->bpQues.at(i).point.length();

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

void Widget::on_checkFFQuestionButton_clicked()
{
    if(cursorAns != -1 && numOfQ != -1)
    {


        //确认输入完成
        QString answer=ui->lineEdit->text();
        qDebug()<<dataBase->ffblank[cursorAns].sensitiveText.data();
        if(answer==dataBase->ffblank[cursorAns].sensitiveText)
        {

           ui->reminder->setHidden(false);
           ui->reminder->setText("correct!");


        }

        else
        {
            ui->reminder->setHidden(false);
            ui->reminder->setText("wrong!");

        }
        ui->checkFFQuestionButton->setText("检查");

    }


}



void Widget::on_nextFFQuestionButton_clicked()
{
    Jump2NextQuestion();
}

void Widget::Jump2NextQuestion()
{
    if(numOfQ<numOfFFdata-1)
        numOfQ++;
    else
        numOfQ=0;
    if(cursorAns<numOfFFdata-1)
        cursorAns++;
    else
        cursorAns=0;
    s_question = dataBase->ffblank[numOfQ].NsensitiveTextLF + "__________________" + dataBase->ffblank[numOfQ].NsensitiveTextRT;
    ui->ffquestionBrowser->setText(s_question);

    ui->lineEdit->clear();
}

void Widget::on_checkBPQuestionButton_clicked()
{

    if(cursorofBP != -1)
    {
        int judge=0;
        for(int i=0;i<BPinfo[cursorofBP].pointofQ;i++)
        {
            if(bpline[i].text()==dataBase->bpQues[cursorofBP].point[i])
            judge++;
        }
        if(judge==BPinfo[cursorofBP].pointofQ)

        {
            ui->reminderBP->setText("correct!");
        }

        else
        {
            ui->reminderBP->setText("wrong!");
        }


    }


}

void Widget::on_nextBPQuestionButton_clicked()
{
    if(cursorofBP != -1)
    {
        for(int i=0;i<BPinfo[cursorofBP].pointofQ;i++)
        {
            bpline[i].clear();
        }

    }

    if(cursorofBP<numofBPdata-1)
        cursorofBP++;
    else
        cursorofBP=0;


    //ui->Qhead->setText(dataBase->bpQues[cursorofBP].HEAD);
    ui->bqquestionBrowser->setText(dataBase->bpQues[cursorofBP].HEAD);

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


    //qDebug()<<"答案";
    for(int i=0;i<BPinfo[cursorofBP].pointofQ;i++)
        qDebug()<<dataBase->bpQues[cursorofBP].point[i].data();

    for(int i=0;i<BPinfo[cursorofBP].pointofQ;i++)
    {
        bpline[i].show();
        bplabel[i].show();
    }

}
