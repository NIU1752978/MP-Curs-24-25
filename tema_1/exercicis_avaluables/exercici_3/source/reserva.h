#ifndef RESERVA_H
#define RESERVA_H

#include <string>
#include <fstream>
using namespace std;

class Reserva
{
public:
    Reserva() : m_diaSetmana(""), m_horaInici(0), m_horaFinal(0), m_nSetmanaInici(0), m_nSetmanaFinal(0) {}
    Reserva(const string& dia, int horaInici, int horaFinal, int setmanaInici, int setmanaFinal) : m_diaSetmana(dia), m_horaInici(horaInici), m_horaFinal(horaFinal),
        m_nSetmanaInici(setmanaInici), m_nSetmanaFinal(setmanaFinal) {}

    void inicialitza(const string& dia, int horaInici, int horaFinal, int setmanaInici, int setmanaFinal);

    string getDiaSetmana() const { return m_diaSetmana; }
    int getHoraInici() const { return m_horaInici; }
    int getHoraFinal() const { return m_horaFinal; }
    int getSetmanaInici() const { return m_nSetmanaInici; }
    int getSetmanaFinal() const { return m_nSetmanaFinal; }

    bool compatibleAmb(const Reserva& altra) const;
    bool operator==(const Reserva& altra) const;

private:
    string m_diaSetmana;
    int m_horaInici, m_horaFinal;
    int m_nSetmanaInici, m_nSetmanaFinal;
};

#endif
