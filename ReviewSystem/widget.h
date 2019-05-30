#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "unpacker.h"
#include "QThread"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:


    void on_pushButton_clicked();



    void switchQ(void);

private:
    Ui::Widget *ui;

    int clickedCounter;

    unpacker * dataBase;

    int numOfQ;

    int numOfFFdata;
    int numOfBPdata;

    int cursorAns;
};

#endif // WIDGET_H
