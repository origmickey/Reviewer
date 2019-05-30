#include "unpacker.h"

//typedef struct{
//    QByteArray goalData;
//    QByteArray leftdata;
//}xResult;

unpacker::unpacker(QFile * qbank)
{
    //len=0;
    //ffblank=new FFRY[len];
    file=qbank;
    file->open(QIODevice::ReadWrite| QIODevice::Text);
    //qDebug()<<file->readAll().data();
    //qDebug()<<"file text";
    file->close();
}

unpacker::~unpacker()
{
    //delete ffblank;
    file->close();
}

xResult unpacker::Intercept(QByteArray rowdata,QString cutter1,QString cutter2)
{
    long firstHead=rowdata.indexOf(cutter1);
    QByteArray withoutHead=rowdata.right(rowdata.length()-firstHead-cutter1.length());

    long firstEnd=withoutHead.indexOf(cutter2);

    QByteArray goal=withoutHead.left(firstEnd);


    QByteArray leftover=withoutHead.right(withoutHead.length()-firstEnd-cutter2.length());


    QByteArray BFallText=rowdata.remove(firstHead,cutter1.length());
//    qDebug()<<BFallText.data()<<"BFallText";
//    qDebug()<<BFallText.indexOf("TIVE");
//    qDebug()<<rowdata.indexOf(cutter2);
//    qDebug()<<cutter1.length();
    QByteArray allText=BFallText.remove(BFallText.indexOf(cutter2),cutter2.length());


    //qDebug()<<allText.data()<<"alltext";

    QByteArray NSleft=rowdata.left(firstHead);
    QByteArray NSright=rowdata.right(rowdata.length()-rowdata.indexOf(cutter2)-cutter2.length());
   // qDebug()<<NSleft.data()<<"NSleft";
   // qDebug()<<NSright.data()<<"NSright";


    xResult result;
    result.goalData=goal;
    result.leftdata=leftover;
    result.allData=allText;
    result.NSLF=NSleft;
    result.NSRT=NSright;

    return result;
}

unpacker::FirstSort()
{
    if(!file->isOpen())
        file->open(QIODevice::ReadWrite| QIODevice::Text);
    QByteArray reader=file->readAll();



    QByteArray MAOdata = Intercept(reader,"MAO","MAO").goalData;
    //qDebug()<<MAOdata.data()<<"withoutMAO";
    SeccondSort(MAOdata);


}

unpacker::SeccondSort(QByteArray resorteddata)
{
    xResult oneResult=Intercept(resorteddata,"ONE","ONE");

    QByteArray firstofM=oneResult.goalData;

    //qDebug()<<firstofM.data()<<"first";

    if(firstofM.indexOf("SENSI")!=(-1)&&firstofM.indexOf("TIVE")!=(-1))
    {
        FFRY FFresult =sensitiveSort(firstofM);
        if(!FFresult.allSentence.isEmpty())
            ffblank[0]=FFresult;
    }
    if(firstofM.indexOf("YI")!=(-1))
        bpQues= pointQ(firstofM);



    QByteArray twoRowData=oneResult.leftdata;



    xResult twoResult=Intercept(twoRowData,"TWO","TWO");

    QByteArray secondtofM=twoResult.goalData;

    //qDebug()<<secondtofM.data()<<"second";

    //qDebug()<<secondtofM.indexOf("SENSI");

    if(secondtofM.indexOf("SENSI")!=(-1)&&secondtofM.indexOf("TIVE")!=(-1))
    {
        FFRY FFresult =sensitiveSort(secondtofM);
        //qDebug()<<"FFresult.allSentence.data()";
        if(!FFresult.allSentence.isEmpty())
            ffblank[1]=FFresult;
    }

    if(secondtofM.indexOf("YI")!=(-1))
        bpQues= pointQ(secondtofM);

    QByteArray threeRowData=twoResult.leftdata;



    xResult threeResult=Intercept(threeRowData,"THREE","THREE");

    QByteArray thirdtofM=threeResult.goalData;

    //qDebug()<<thirdtofM.data()<<"third";

    if(thirdtofM.indexOf("SENSI")!=(-1)&&thirdtofM.indexOf("TIVE")!=(-1))
    {
        FFRY FFresult =sensitiveSort(thirdtofM);
        if(!FFresult.allSentence.isEmpty())
            ffblank[2]=FFresult;
    }

    if(thirdtofM.indexOf("YI")!=(-1))
        bpQues= pointQ(thirdtofM);

    QByteArray fourRowData=threeResult.leftdata;



    xResult fourResult=Intercept(fourRowData,"FOUR","FOUR");

    QByteArray fourthtofM=fourResult.goalData;

    //qDebug()<<fourthtofM.data()<<"fourth";

    if(fourthtofM.indexOf("SENSI")!=(-1)&&fourthtofM.indexOf("TIVE")!=(-1))
    {
        FFRY FFresult =sensitiveSort(fourthtofM);
        if(!FFresult.allSentence.isEmpty())
            ffblank[3]=FFresult;
    }
    if(fourthtofM.indexOf("YI")!=(-1))
        bpQues= pointQ(fourthtofM);


    QByteArray fiveRowData=fourResult.leftdata;



    xResult fiveResult=Intercept(fiveRowData,"FIVE","FIVE");

    QByteArray fivethtofM=fiveResult.goalData;


    //qDebug()<<fivethtofM.data()<<"five";

    if(fivethtofM.indexOf("SENSI")!=(-1)&&fivethtofM.indexOf("TIVE")!=(-1))
    {
        FFRY FFresult =sensitiveSort(fivethtofM);
        if(!FFresult.allSentence.isEmpty())
            ffblank[4]=FFresult;
    }
    if(fivethtofM.indexOf("YI")!=(-1))
        bpQues= pointQ(fivethtofM);

}

FFRY unpacker::sensitiveSort(QByteArray NSTSdata)
{
    //qDebug()<<NSTSdata.data()<<"NSTSDATA!!!";
    FFRY rowFF;

    xResult sensitiveResult=Intercept(NSTSdata,"SENSI","TIVE");

    rowFF.sensitiveText=sensitiveResult.goalData;

    //qDebug()<<rowFF.sensitiveText.data()<<"sensitive";

    rowFF.allSentence=sensitiveResult.allData;

    //qDebug()<<sensitiveResult.allData.data()<<"allSentence";

    rowFF.NsensitiveTextLF=sensitiveResult.NSLF;
    rowFF.NsensitiveTextRT=sensitiveResult.NSRT;

    //qDebug()<<sensitiveResult.NSLF.data()<<"NSLF";
    //qDebug()<<sensitiveResult.NSRT.data()<<"NSRT";

    //len++;

    return rowFF;

}

 BPRY unpacker::pointQ(QByteArray SecSortedData)
{
    BPRY rowBP;

    QByteArray head=SecSortedData.left(SecSortedData.indexOf("YI"));
    rowBP.HEAD=head;

    xResult yiResult=Intercept(SecSortedData,"YI","YI");

    QByteArray firstPoint=yiResult.goalData;
    rowBP.point[0]=firstPoint;

    QByteArray erRowData=yiResult.leftdata;



    xResult erResult=Intercept(erRowData,"ER","ER");

    QByteArray secondPoint=erResult.goalData;
    rowBP.point[1]=secondPoint;

    QByteArray sanRowData=erResult.leftdata;


    xResult sanResult=Intercept(sanRowData,"SAN","SAN");

    QByteArray thirdPoint=sanResult.goalData;
    rowBP.point[2]=thirdPoint;

    QByteArray siRowData=sanResult.leftdata;


    xResult siResult=Intercept(siRowData,"SI","SI");

    QByteArray fourthPoint=siResult.goalData;
    rowBP.point[3]=fourthPoint;

    QByteArray wuRowData=siResult.leftdata;


    xResult wuResult=Intercept(wuRowData,"WU","WU");

    QByteArray fifthPoint=wuResult.goalData;
    rowBP.point[4]=fifthPoint;

    QByteArray liuRowData=wuResult.leftdata;

    xResult liuResult=Intercept(liuRowData,"LIU","LIU");

    QByteArray sixthPoint=liuResult.goalData;
    rowBP.point[5]=sixthPoint;


    return rowBP;
}
