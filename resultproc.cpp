#include "resultproc.h"
#include "ui_resultproc.h"

resultProc::resultProc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::resultProc)
{
    ui->setupUi(this);
}

resultProc::~resultProc()
{
    delete ui;
}

void resultProc::setResultProc(Proc P)
{
    ui->ID_Lb->setNum(P.getId());
    ui->TMax_Lb->setNum(P.getEstTime());
    ui->OP_Lb->setText(QString::number(P.getNum1()) + P.getOperator() + QString::number(P.getNum2()));
    if(P.getError()){
        ui->Res_Lb->setText("Error");
    }
    else {
        ui->Res_Lb->setNum(P.getResult());
    }
    ui->TLleg_Lb->setNum(P.getTiempoLlegada());
    ui->TFin_Lb->setNum(P.getTiempoFinal());
    ui->TRet_Lb->setNum(P.getTiempoRetorno());
    ui->TRes_Lb->setNum(P.getTiempoRespuesta());
    ui->TEsp_Lb->setNum(P.getTiempoEspera());
    ui->TServ_Lb->setNum(P.getTiemrpoServicio());
}
