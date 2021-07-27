#ifndef BLOCKEDPROC_H
#define BLOCKEDPROC_H

#include <QWidget>

namespace Ui {
class blockedProc;
}

class blockedProc : public QWidget
{
    Q_OBJECT

public:
    explicit blockedProc(QWidget *parent = nullptr);
    ~blockedProc();
    void setBlockedProc(const int id, const int cont);

private:
    Ui::blockedProc *ui;

};

#endif // BLOCKEDPROC_H
