#ifndef RESULTPROC_H
#define RESULTPROC_H

#include <QWidget>
#include "proc.h"

namespace Ui {
class resultProc;
}

class resultProc : public QWidget
{
    Q_OBJECT

public:
    explicit resultProc(QWidget *parent = nullptr);
    ~resultProc();
    void setResultProc(Proc P);

private:
    Ui::resultProc *ui;
};

#endif // RESULTPROC_H
