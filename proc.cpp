#include "proc.h"

Proc::Proc()
{

}

int Proc::getNum1() const
{
    return num1;
}

void Proc::setNum1(int value)
{
    num1 = value;
}

int Proc::getNum2() const
{
    return num2;
}

void Proc::setNum2(int value)
{
    num2 = value;
}

char Proc::getOperator() const
{
    return oper;
}

void Proc::setOperator(char value)
{
    oper = value;
}

int Proc::getId() const
{
    return id;
}

void Proc::setId(int value)
{
    id = value;
}

int Proc::getEstTime() const
{
    return estTime;
}

void Proc::setEstTime(int value)
{
    estTime = value;
}

int Proc::getResult() const
{
    return result;
}

void Proc::setResult(int value)
{
    result = value;
}

int Proc::getTTtime() const
{
    return tTtime;
}

void Proc::setTTtime(int value)
{
    tTtime = value;
}

int Proc::getTiempoLlegada() const
{
    return tiempoLlegada;
}

void Proc::setTiempoLlegada(int value)
{
    tiempoLlegada = value;
}

int Proc::getTiempoFinal() const
{
    return tiempoFinal;
}

void Proc::setTiempoFinal(int value)
{
    tiempoFinal = value;
}

int Proc::getTiempoRespuesta() const
{
    return tiempoRespuesta;
}

void Proc::setTiempoRespuesta(int value)
{
    tiempoRespuesta = value;
}

int Proc::getTiempoEspera() const
{
    return tiempoEspera;
}

void Proc::setTiempoEspera(int value)
{
    tiempoEspera = value;
}

int Proc::getTiemrpoServicio() const
{
    return tiemrpoServicio;
}

void Proc::setTiemrpoServicio(int value)
{
    tiemrpoServicio = value;
}

bool Proc::getVezPrim() const
{
    return vezPrim;
}

void Proc::setVezPrim(bool value)
{
    vezPrim = value;
}

int Proc::getTiempoRetorno() const
{
    return tiempoRetorno;
}

void Proc::setTiempoRetorno(int value)
{
    tiempoRetorno = value;
}

bool Proc::getBlock() const
{
    return block;
}

void Proc::setBlock(bool value)
{
    block = value;
}

bool Proc::getError() const
{
    return error;
}

void Proc::setError(bool value)
{
    error = value;
}

int Proc::getContBlock() const
{
    return contBlock;
}

void Proc::setContBlock(int value)
{
    contBlock = value;
}

bool Proc::getExecuted() const
{
    return executed;
}

void Proc::setExecuted(bool value)
{
    executed = value;
}
