#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    ui->stackedWidget->setCurrentIndex(0);
}

//Slots
void MainWindow::on_noProcLE_textChanged(const QString &arg1)
{
    if(arg1.toInt() > 0){
        ui->noProcePB->setEnabled(true);
    }
    else {
        ui->noProcePB->setEnabled(false);
    }
}

void MainWindow::on_noProcePB_clicked()
{
    contProc = ui->noProcLE->text().toInt();
    setProce(contProc);
    ui->stackedWidget->setCurrentIndex(1);
    contProc -= 5;
    if(contProc < 0){
        contProc = 0;
    }

}

void MainWindow::on_startPB_clicked()
{
    startProc();
    ui->startPB->setEnabled(false);
}

void MainWindow::on_btnFinish_clicked()
{

    printResult();
    ui->stackedWidget->setCurrentIndex(2);
}
//Functions

void MainWindow::setProce(const int &totalProc)
{
    srand(time(NULL));
    for (int i(0); i < totalProc; ++i) {
        Proc p;
        int op = rand() % 5;
        switch (op) {
            case 0:
                p.setOperator('+');
            break;

            case 1:
                p.setOperator('-');
            break;

            case 2:
                p.setOperator('*');
            break;

            case 3:
                p.setOperator('/');
            break;

            case 4:
                p.setOperator('%');
            break;
         }
        p.setNum1(rand() % 100);
        if(op == 3 || op == 4){
            p.setNum2(rand() % 99 + 1);
        }
        else {
            p.setNum2(rand() % 99 + 1);
        }
        p.setId(i + 1);
        p.setEstTime(rand() % 10 + 6);
        p.setResult(0);
        p.setTTtime(0);
        p.setTiempoLlegada(0);
        p.setTiempoEspera(0);
        p.setTiempoFinal(0);
        p.setTiempoRetorno(0);
        p.setTiempoRespuesta(0);
        p.setTiemrpoServicio(0);
        p.setVezPrim(false);
        p.setBlock(false);
        p.setError(false);
        p.setContBlock(5);
        p.setExecuted(false);

        procList.push_back(p);
    }
}

void MainWindow::startProc()
{
    int memoryTop = 0,contBlock = 0;
    ui->globalCountLB->setText("Contador: " + QString::number(contGlob));
    for(int i(0); i < procList.size(); ++i){
        QLayoutItem* child;
        while((child = ui->pendingProcGL->takeAt(0)) != 0){
            delete child->widget();
        }
        int aux = 0;
        int column = 0;
        for(int j(i); j < procList.size(); ++j){
            if(procList.at(j).getBlock() == true){
                blockedProc* bProc = new blockedProc();
                bProc->setBlockedProc(procList.at(j).getId(), procList.at(j).getContBlock());
                ui->blocked_GL->addWidget(bProc, 0, column, Qt::AlignLeft);
                ++column;
            }
            else{
                unfinishedProc* pendProc = new unfinishedProc();
                pendProc->setFormat(procList.at(j).getId(), procList.at(j).getEstTime(), procList.at(j).getTTtime());
                ui->pendingProcGL->addWidget(pendProc);
                if(procList.at(j).getVezPrim() == false){
                    procList[j].setTiempoLlegada(contGlob);
                    procList[j].setVezPrim(true);
                }
            }
            memoryTop = j + 1;
            ++aux;
            if(aux == 5){
                break;
            }
        }
        ui->unfinishedBatchLB->setText("Procesos pendientes: " + QString::number(contProc));

        if(contBlock < 5 && contBlock < (procList.size() - i)){
            child = ui->pendingProcGL->takeAt(0);
            delete child->widget();
            if(procList.at(i).getExecuted() == false){
                procList[i].setTiempoRespuesta(contGlob - procList.at(i).getTiempoLlegada());
                procList[i].setExecuted(true);
            }

            int tr = procList.at(i).getEstTime() - procList.at(i).getTTtime();

            ui->onIdLB->setNum(procList.at(i).getId());
            ui->onOperatorLB->setText(QString::number(procList.at(i).getNum1()) + procList.at(i).getOperator() + QString::number(procList.at(i).getNum2()));
            ui->onEstimatedTimeLB->setNum(procList.at(i).getEstTime());
            ui->onPassTimeLB->setNum(procList.at(i).getTTtime());
            ui->onRestTimeB->setNum(tr);

            for (int n (procList.at(i).getTTtime()); n < procList.at(i).getEstTime(); ++n) {
                delay(1);
                procList[i].setTTtime(procList.at(i).getTTtime() + 1);
                ui->onPassTimeLB->setNum(procList.at(i).getTTtime());
                ui->onRestTimeB->setNum(--tr);

                ++contGlob;
                ui->globalCountLB->setText("Contador: " + QString::number(contGlob));

                for(int k(i); k < memoryTop; ++k) {
                    if(procList.at(k).getBlock()){
                        procList[k].setContBlock(procList.at(k).getContBlock() - 1);
                        if(procList.at(k).getContBlock()== 0){
                            procList[k].setContBlock(5);
                            procList[k].setBlock(false);
                            unfinishedProc* unfProc = new unfinishedProc();
                            unfProc->setFormat(procList.at(k).getId(), procList.at(k).getEstTime(), procList.at(k).getTTtime());
                            ui->pendingProcGL->addWidget(unfProc);
                            --contBlock;
                        }
                    }
                }

                while ((child = ui->blocked_GL->takeAt(0)) != 0) {
                    delete child->widget();
                }
                int col = 0;
                for (int k(i); k < memoryTop; ++k) {
                    if(procList.at(k).getBlock()){
                        blockedProc* bProc = new blockedProc();
                        bProc->setBlockedProc(procList.at(k).getId(), procList.at(k).getContBlock());
                        ui->blocked_GL->addWidget(bProc, 0, col, Qt::AlignLeft);
                        ++col;
                    }
                }

                if(interruption)
                    break;
                if(error)
                    break;
                if(pause){
                    do{
                        for (; ; ) {
                            delay(1);
                            if(continua)
                                break;
                        }
                    }while(!continua);
                    pause = false;
                    continua = false;
                }
            }

            ui->onIdLB->setText("");
            ui->onOperatorLB->setText("");
            ui->onEstimatedTimeLB->setText("");
            ui->onPassTimeLB->setText("");
            ui->onRestTimeB->setText("");

            if(!interruption){
                finishedProc* finproc = new finishedProc();
                if (!error){
                    procList[i].setResult(resolProc(procList.at(i).getNum1(), procList.at(i).getNum2(), procList.at(i).getOperator()));
                    finproc->setFormat(procList.at(i).getId(), QString::number(procList.at(i).getNum1()) + procList.at(i).getOperator() + QString::number(procList.at(i).getNum2()),
                                       QString::number(procList.at(i).getResult()));
                }
                else {
                    finproc->setFormat(procList.at(i).getId(), QString::number(procList.at(i).getNum1()) + procList.at(i).getOperator() + QString::number(procList.at(i).getNum2()),
                                       "Error");
                    error = false;
                    procList[i].setError(true);
                }

                procList[i].setTiempoFinal(contGlob);
                procList[i].setTiempoRetorno(procList.at(i).getTiempoFinal() - procList.at(i).getTiempoLlegada());
                procList[i].setTiemrpoServicio(procList.at(i).getTTtime());
                procList[i].setTiempoEspera(procList.at(i).getTiempoRetorno() - procList.at(i).getTiemrpoServicio());

                ui->finishedProcGL->addWidget(finproc);
                if(contProc > 0){
                    --contProc;
                }
            }
            else{
                procList[i].setBlock(true);
                procList.insert(memoryTop, procList.at(i));
                interruption = false;
                procList.removeAt(i);
                --i;
                ++contBlock;
            }
        }
        else {
            ui->onIdLB->setText("NULL");
            ui->onOperatorLB->setText("NULL");
            ui->onEstimatedTimeLB->setText("NULL");
            ui->onPassTimeLB->setText("NULL");
            ui->onRestTimeB->setText("NULL");

            delay(1);
            ++contGlob;
            ui->globalCountLB->setText("Contador: " + QString::number((contGlob)));

            for(int k(i); k < memoryTop; ++k) {
                procList[k].setContBlock(procList.at(k).getContBlock() - 1);
                if(procList.at(k).getContBlock() == 0){
                    procList[k].setContBlock(5);
                    procList[k].setBlock(false);
                    unfinishedProc* unfProc = new unfinishedProc();
                    unfProc->setFormat(procList.at(k).getId(), procList.at(k).getEstTime(), procList.at(k).getTTtime());
                    ui->pendingProcGL->addWidget(unfProc);
                    --contBlock;
                }

            }
            while ((child = ui->blocked_GL->takeAt(0)) != 0) {
                delete child->widget();
            }
            int col = 0;
            for (int k(i); k < memoryTop; ++k) {
                if(procList.at(k).getBlock()){
                    blockedProc* bProc = new blockedProc();
                    bProc->setBlockedProc(procList.at(k).getId(), procList.at(k).getContBlock());
                    ui->blocked_GL->addWidget(bProc, 0, col, Qt::AlignLeft);
                    ++col;
                }
            }
            --i;
        }

    }
    ui->btnFinish->setEnabled(true);
}

void MainWindow::delay(const int &seg)
{
    QTime betweenTime = QTime::currentTime().addSecs(seg);
    while (QTime::currentTime() < betweenTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

int MainWindow::resolProc(const int &num1, const int &num2, const char op)
{
    int result;
    switch (op) {
        case '+':
            result = num1 + num2;
        break;

        case '-':
            result = num1 - num2;
        break;

        case '*':
            result = num1 * num2;
        break;

        case '/':
            result = num1 / num2;
        break;

        case '%':
            result = num1 % num2;
        break;
    }
    return result;
}

void MainWindow::printResult()
{
    for(int i(0); i < procList.size(); ++i){
        resultProc* resProc = new resultProc;
        resProc->setResultProc(procList.at(i));
        ui->resultGL->addWidget(resProc, i/3, i%3,Qt::AlignCenter);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

   if(ui->stackedWidget->currentIndex() == 1){
       if(event->key() == Qt::Key_I && pause == false)
          interruption = true;
       if(event->key() == Qt::Key_E && pause == false)
          error = true;
       if(event->key() == Qt::Key_P && pause == false)
          pause = true;
       if(event->key() == Qt::Key_C && pause == true)
          continua = true;
   }
}


