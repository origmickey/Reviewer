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


    void on_pushButton_clicked();



    void switchQ(void);

    void on_pushButton_2_clicked();

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






};

#endif // WIDGET_H
