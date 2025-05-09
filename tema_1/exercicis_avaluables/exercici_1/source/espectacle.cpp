#include "espectacle.h"

// Constructor classe Espectacle. Inicialitza nom, dia, preu i nTotal seients.
// marca seients disponibles (false).
Espectacle::Espectacle(const string& nom, const string& dia, float preu, int totalSeients) : m_nom(nom), m_dia(dia), m_preu(preu), m_totalSeients(totalSeients)
{
    for (int i = 0; i < MAX_SEIENTS; i++)
    {
        m_seients[i] = false;
    }
}

// Assigna els seients a una compra si nhi ha prou de lliures.
// Retorna true --> assignats, false --> no assigants.
// seients no consecutius --> no descompte.
bool Espectacle::assignarSeients(int nEntrades, int seientsAssignats[MAX_SEIENTS_COMPRA], bool& descompteAdjacents)
{
    descompteAdjacents = true;
    bool resultat = false;
    int seientsLliures = 0;

    // Comprovem si hi ha prou seients lliures en total
    int i = 0;
    while (i < m_totalSeients) 
    {
        if (!m_seients[i]) 
        {
            seientsLliures++;
        }
        i++;
    }

    if (seientsLliures >= nEntrades) 
    {
        // Busquem seients consecutius
        i = 0;
        while (i <= m_totalSeients - nEntrades && !resultat) 
        {
            bool disponibles = true;
            int j = 0;
            while (j < nEntrades) 
            {
                if (m_seients[i + j]) 
                {
                    disponibles = false;
                }
                j++;
            }

            if (disponibles) 
            {
                j = 0;
                while (j < nEntrades) 
                {
                    m_seients[i + j] = true;
                    seientsAssignats[j] = i + j + 1;
                    j++;
                }
                resultat = true;
            }
            i++;
        }

        // Si no hi ha seients consecutius, assignem els primers lliures
        if (!resultat) 
        {
            descompteAdjacents = false;
            int assignats = 0;
            i = 0;
            while (i < m_totalSeients) 
            {
                if (!m_seients[i]) 
                {
                    m_seients[i] = true;
                    seientsAssignats[assignats] = i + 1;
                    assignats++;

                    if (assignats == nEntrades) 
                    {
                        resultat = true;
                        i = m_totalSeients;
                    }
                }
                i++;
            }
        }
    }

    return resultat;
}

// Allibera els seients especificats per a una anulacio de compra.
// Retorna true --> seient reservat i alliberat.
// hiHaNoReservats = true --> seients no reservat.
bool Espectacle::alliberarSeients(int nEntrades, const int seients[MAX_SEIENTS_COMPRA], bool& hiHaNoReservats)
{
    bool algunReservat = false;
    hiHaNoReservats = false;

    for (int i = 0; i < nEntrades; i++) {
        int index = seients[i] - 1;

        if (index >= 0 && index < m_totalSeients)
        {
            if (m_seients[index])
            { // Seient estava reservat
                m_seients[index] = false;
                algunReservat = true;
            }
            else
            { // Seient no estava reservat
                hiHaNoReservats = true;
            }
        }
    }

    return algunReservat;
}

// ocupacio de tots els seients.
void Espectacle::obtenirOcupacio(bool ocupacio[MAX_SEIENTS])
{
    int i = 0;
    while (i < m_totalSeients) 
    {
        ocupacio[i] = m_seients[i];
        i = i + 1;
    }
}

