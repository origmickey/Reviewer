#ifndef UNPACKER
#define UNPACKER
//调用填空题使用结构体数组ffblank,一个元素为一题
#include <QFile>
#include "qdebug.h"

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
    QByteArray point[6];
}BPRY;

class unpacker
{
public:
    unpacker(QFile * qbank);
    ~unpacker();


    xResult Intercept(QByteArray rowdata, QString cutter, QString cutter2);

    FirstSort(void);

    SeccondSort(QByteArray resorteddata);

    FFRY sensitiveSort(QByteArray NSTSdata);

    //BPRY pointQ(QByteArray SecSortedData);
    BPRY pointQ(QByteArray SecSortedData);
    QFile *file;

//    FFRY * ffblank;
    FFRY  ffblank[5];
    BPRY  bpQues;

};




#endif // UNPACKER

