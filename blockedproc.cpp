#include "blockedproc.h"
#include "ui_blockedproc.h"

blockedProc::blockedProc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::blockedProc)
{
    ui->setupUi(this);
}

blockedProc::~blockedProc()
{
    delete ui;
}

void blockedProc::setBlockedProc(const int id, const int cont)
{
    ui->ID_LB->setText("ID: " + QString::number(id));
    ui->Cont_LB->setText("Contador: " + QString::number(cont));
}
