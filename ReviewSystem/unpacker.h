#ifndef UNPACKER
#define UNPACKER
//调用填空题使用结构体数组ffblank,一个元素为一题
#include <QFile>
#include "qdebug.h"
#include "qlist.h"

typedef struct data{
    QByteArray goalData;
    QByteArray leftdata;
    QByteArray allData;
    QByteArray NSLF;
    QByteArray NSRT;
}xResult ;

typedef struct FFRYdata{
    QByteArray allSentence;
    QByteArray sensitiveText;
    QByteArray NsensitiveTextLF;
    QByteArray NsensitiveTextRT;
}FFRY;

typedef struct BPRYdata{
    QByteArray allSentence;
    QByteArray HEAD;
    QList<QByteArray> point;
    //QByteArray point[10];
}BPRY;

class unpacker
{
public:
    unpacker(QByteArray qbank);
    ~unpacker();


    xResult Intercept(QByteArray rowdata, QString cutter, QString cutter2);

    void FirstSort(void);

    void SeccondSort(QByteArray resorteddata);

    FFRY sensitiveSort(QByteArray NSTSdata);

    //BPRY pointQ(QByteArray SecSortedData);
    BPRY pointQ(QByteArray SecSortedData);
    QFile file;
    int lenOfFF;
    int lenOfBP;
    int numOfPoint;
//    FFRY * ffblank;
    QList<FFRY> ffblank;
    QList<BPRY> bpQues;

//    FFRY  ffblank[200];
//    BPRY  bpQues[50];

    int FORsignNUM;
    int SORsignNUM;

    int debugNUM;

    QByteArray stack;

};




#endif // UNPACKER

