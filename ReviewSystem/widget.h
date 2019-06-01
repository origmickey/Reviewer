#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "unpacker.h"
#include "QThread"
#include "QLineEdit"
#include "QLabel"

typedef struct pointinfo{
    int pointofQ;
}Pinfo;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QFile  testFile;


private slots:


    void on_checkFFQuestionButton_clicked();

    void on_nextFFQuestionButton_clicked();

    void on_checkBPQuestionButton_clicked();

    void on_nextBPQuestionButton_clicked();

private:
    Ui::Widget *ui;

    int clickedCounter;

    unpacker * dataBase;

    int numOfQ;

    int numOfFFdata;

    int cursorAns;

    int numofBPdata;

    Pinfo BPinfo[50];

    int cursorofBP;

    QLineEdit bpline[10];

    QLabel    bplabel[10];

    int showJudge;

    QString s_question;

    int bpline_x;
    int bpline_y;
    int bpline_w;
    int bpline_h;

    int bplabel_x;
    int bplabel_y;
    int bplabel_w;
    int bplabel_h;


    void Jump2NextQuestion();






};

#endif // WIDGET_H
