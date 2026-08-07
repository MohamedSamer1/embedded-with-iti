#include "calc.h"

Calc::Calc(QObject *parent)
    : QObject{parent}
{}

void Calc::calculate(double a, double b, QString op)
{
    if(op == "+") {
        m_result = a + b;
    }

    else if(op == "-") {
        m_result = a - b;
    }

    else if(op == "*") {
        m_result = a * b;
    }

    else if(op == "/")
    {
        if(b == 0){
            m_result = 0;
        }
        else {
            m_result = a / b;
        }
    }

    emit resultChanged();
}

double Calc::result() const
{
    return m_result;
}