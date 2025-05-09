#ifndef ESPECTACLE_H
#define ESPECTACLE_H

#include <string>
using namespace std;

const int MAX_SEIENTS_COMPRA = 10;
const int MAX_SEIENTS = 20;

class Espectacle
{
public:
    Espectacle() {}
    Espectacle(const string& nom, const string& dia, float preu, int totalSeients);

    bool assignarSeients(int nEntrades, int seientsAssignats[MAX_SEIENTS_COMPRA], bool& descompteAdjacents);
    bool alliberarSeients(int nEntrades, const int seients[MAX_SEIENTS_COMPRA], bool& hiHaNoReservats);
    void obtenirOcupacio(bool ocupacio[MAX_SEIENTS]);

    const string& getNom() const { return m_nom; }
    const string& getDia() const { return m_dia; }
    float getPreu() const { return m_preu; }
		
private:
    string m_nom;
    string m_dia;
    float m_preu;
    int m_totalSeients;
    bool m_seients[MAX_SEIENTS] = { false };
};

#endif
