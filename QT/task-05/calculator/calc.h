#ifndef CALC_H
#define CALC_H

#include <QObject>

class Calc : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double result READ result NOTIFY resultChanged)
public:
    explicit Calc(QObject *parent = nullptr);
    double result() const;

    Q_INVOKABLE void calculate(double a, double b, QString op);

signals:
    void resultChanged();

private:
    double m_result = 0;
};



#endif // CALC_H
