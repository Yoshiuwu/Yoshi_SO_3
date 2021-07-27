#ifndef PROC_H
#define PROC_H
#include <QString>

class Proc
{
public:
    Proc();

    int getNum1() const;
    void setNum1(int value);

    int getNum2() const;
    void setNum2(int value);

    char getOperator() const;
    void setOperator(char value);

    int getId() const;
    void setId(int value);

    int getEstTime() const;
    void setEstTime(int value);

    int getResult() const;
    void setResult(int value);


    int getTTtime() const;
    void setTTtime(int value);

    int getTiempoLlegada() const;
    void setTiempoLlegada(int value);

    int getTiempoFinal() const;
    void setTiempoFinal(int value);

    int getTiempoRespuesta() const;
    void setTiempoRespuesta(int value);

    int getTiempoEspera() const;
    void setTiempoEspera(int value);

    int getTiemrpoServicio() const;
    void setTiemrpoServicio(int value);

    bool getVezPrim() const;
    void setVezPrim(bool value);

    int getTiempoRetorno() const;
    void setTiempoRetorno(int value);

    bool getBlock() const;
    void setBlock(bool value);

    bool getError() const;
    void setError(bool value);

    int getContBlock() const;
    void setContBlock(int value);

    bool getExecuted() const;
    void setExecuted(bool value);

private:

    int num1;
    int num2;
    char oper;
    int id;
    int estTime;
    int result;
    int tTtime;
    int tiempoLlegada;
    int tiempoFinal;
    int tiempoRespuesta;
    int tiempoEspera;
    int tiemrpoServicio;
    int tiempoRetorno;
    bool vezPrim;
    bool block;
    bool error;
    int contBlock;
    bool executed;
};

#endif // PROC_H
