#include "widget.h"
#include <QApplication>
#include "unpacker.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QFile testFile;
    testFile.setFileName("C:/Users/k/Desktop/qbank");
    unpacker testUnpacker(&testFile);
    testUnpacker.FirstSort();

    for(int i=0;i<5;i++)
    {
        qDebug()<<testUnpacker.ffblank[i].allSentence.data();
        qDebug()<<testUnpacker.ffblank[i].sensitiveText.data();
        qDebug()<<testUnpacker.ffblank[i].NsensitiveTextLF.data();
        qDebug()<<testUnpacker.ffblank[i].NsensitiveTextRT.data();
    }

    for(int i=0;i<6;i++)
    {
      qDebug()<<testUnpacker.bpQues.point[i].data();
    }

    w.show();

    return a.exec();
}
