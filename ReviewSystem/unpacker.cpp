#include "unpacker.h"

//typedef struct{
//    QByteArray goalData;
//    QByteArray leftdata;
//}xResult;

unpacker::unpacker(QByteArray qbank)
{
    //len=0;
    //ffblank=new FFRY[len];
    debugNUM=0;
    lenOfBP=0;
    lenOfFF=0;
    numOfPoint=0;
    FORsignNUM=0;
    SORsignNUM=0;
    //file=new QFile;
    /*qbank.open(QIODevice::ReadWrite| QIODevice::Text)*/;
    stack= qbank;
    qDebug()<<stack.data();
    while(stack.indexOf("\n")!=(-1))
    stack=stack.remove(stack.indexOf("\n"),1);
    //qDebug()<<"file text";
//    qbank.close();
}

unpacker::~unpacker()
{
    //delete ffblank;

    //delete file;
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

void unpacker::FirstSort()
{

    QByteArray reader=stack;


    QByteArray MAOdata = Intercept(reader,"MAO","MAO").goalData;
    //qDebug()<<MAOdata.data()<<"withoutMAO";
    SeccondSort(MAOdata);


}

void unpacker::SeccondSort(QByteArray resorteddata)
{
//    QByteArray ALLSIGN;
//    for(int FORsignNUM=31;FORsignNUM<70;FORsignNUM++)
//    {
//        QByteArray sign="FOR FOR";
//                        sign.insert(sign.length(),QString("%1")
//                                         .arg(FORsignNUM));
//                        sign.insert(3,QString("%1")
//                                    .arg(FORsignNUM));
//                        //qDebug()<<sign;
//                        ALLSIGN.append(sign);
//    }
//    qDebug()<<ALLSIGN;

    //test area
    QByteArray restData=resorteddata;
    while(restData.indexOf("FOR")!=(-1))
    {
        QByteArray FORsign="FOR";
                        FORsign.insert(FORsign.length(),QString("%1")
                                         .arg(FORsignNUM));
        //qDebug()<< FORsign;
      xResult Result=Intercept(restData,FORsign,FORsign);


      QByteArray FORgoal=Result.goalData;

      if(FORgoal.indexOf("SENSI")!=(-1)&&FORgoal.indexOf("TIVE")!=(-1))
      {
          FFRY FFresult =sensitiveSort(FORgoal);
          if(!FFresult.allSentence.isEmpty())
          {
//             ffblank[lenOfFF]=FFresult;
//             lenOfFF++;
              ffblank.append(FFresult);
          }

      }
      if(FORgoal.indexOf("SOR")!=(-1))
      {
//          bpQues[lenOfBP]= pointQ(FORgoal);
//          lenOfBP++;
          bpQues.append(pointQ(FORgoal));
      }

      FORsignNUM++;

      restData=Result.leftdata;

    }

    //test area
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

    QByteArray restData=SecSortedData;

    QByteArray head=SecSortedData.left(SecSortedData.indexOf("SOR0"));
    rowBP.HEAD=head;

    //test area
    while(restData.indexOf("SOR")!=(-1))
    {
        QByteArray SORsign="SOR";
                        SORsign.insert(SORsign.length(),QString("%1")
                                         .arg(SORsignNUM));
        //qDebug()<< SORsign;

        xResult sorResult=Intercept(restData,SORsign,SORsign);

        QByteArray GOALinPoint=sorResult.goalData;
        //qDebug()<<"begin";
        //qDebug()<<"end";
//        rowBP.point[numOfPoint]=GOALinPoint;
        rowBP.point.append(GOALinPoint);

        //qDebug()<<debugNUM;
        debugNUM++;
        numOfPoint++;
        SORsignNUM++;

        restData=sorResult.leftdata;
    }
    for(int i=0;i<numOfPoint;i++)
    //qDebug()<<rowBP.point[i].data();
    //test area

    SORsignNUM=0;
    numOfPoint=0;
    return rowBP;
}
