#ifndef DATA_H
#define DATA_H
#include <iostream>

using namespace std;

const int N_MESOS = 12;

class Data
{
public:
    Data() : m_dia(-1), m_mes(-1), m_any(-1) { }
    Data(int dia, int mes, int any) : m_dia(dia), m_mes(mes), m_any(any) { }

    void setData(int dia, int mes, int any) { m_dia = dia; m_mes = mes; m_any = any; }
    void llegeix();

    int getDia() const { return m_dia; }
    int getMes() const { return m_mes; }
    int getAny() const { return m_any; }

    bool operator<(const Data& data) const;
    bool operator==(const Data& data) const;
    bool operator<=(const Data& data) const;
    bool operator>=(const Data& data) const;
    Data operator+(int nDies) const;
    Data operator++();
    void operator+=(int nDies);
    int operator-(const Data& data) const;
    Data operator-(int nDies) const;

private:
    int m_dia, m_mes, m_any;
};

istream& operator>>(istream& input, Data& data);
ostream& operator<<(ostream& output, const Data& data);

bool comprovaTermini(const Data& dataInicial, const Data& dataActual, int dies);


#endif