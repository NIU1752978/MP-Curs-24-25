#include "posicio.h"

string Posicio::toString() const
{
    string posicio = "a1";
    posicio[0] = 'a' + m_columna;
    posicio[1] = '1' + (N_FILES - 1) - m_fila;

    return posicio;
}

void Posicio::fromString(const string& posicio)
{
    m_fila = (N_FILES - 1) - (posicio[1] - '1');
    m_columna = posicio[0] - 'a';
}

ifstream& operator>>(ifstream& fitxer, Posicio& posicio)
{
    string posAux;
    fitxer >> posAux;
    posicio.fromString(posAux);
    return fitxer;
}
ofstream& operator<<(ofstream& fitxer, const Posicio& posicio)
{
    string posAux = posicio.toString();
    fitxer << posAux;
    return fitxer;
}
