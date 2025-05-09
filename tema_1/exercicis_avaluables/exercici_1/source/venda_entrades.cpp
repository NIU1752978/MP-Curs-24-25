#include "venda_entrades.h"
#include <iostream>

using namespace std;

// Constructor classe VendaEntrades. Inicialitza num. seients i espectacles disponibles.
VendaEntrades::VendaEntrades(int nSeients) : m_nSeients(nSeients), m_nEspectacles(0) {}

// Afegeix un espectacle a la llista disponibles, si no se supera el limit maxim.
void VendaEntrades::afegeixEspectacle(const string& nom, const string& dia, float preu)
{
    if (m_nEspectacles < MAX_ESPECTACLES)
    {
        m_espectacle[m_nEspectacles] = Espectacle(nom, dia, preu, m_nSeients);
        m_nEspectacles++;
    }
}

// Compra entrades per a un espectacle en un dia determinat.
// Retorna COMPRA_OK --> compra correcta.
// ERROR_ESPECTACLE --> espectacle no existeix.
// ERROR_SEIENTS --> no hi ha seients disponibles.
EstatCompra VendaEntrades::compraEntrades(const string& nom, string& dia, int nEntrades, float& preu, int seients[MAX_SEIENTS_COMPRA])
{
    EstatCompra resultat = ERROR_ESPECTACLE;  // Inicialitzem amb l'error per defecte

    int i = 0;
    while (i < m_nEspectacles)
    {
        if (m_espectacle[i].getNom() == nom && m_espectacle[i].getDia() == dia)
        {
            bool descompteAdjacents = true;

            if (m_espectacle[i].assignarSeients(nEntrades, seients, descompteAdjacents))
            {
                preu = m_espectacle[i].getPreu() * nEntrades;

                float percentatgeDescompte = 0.0;
                if (!descompteAdjacents) percentatgeDescompte += 0.10; // 10% de descompte
                if (nEntrades > 5) percentatgeDescompte += 0.05; // 5% de descompte

                preu *= (1.0 - percentatgeDescompte);
                resultat = COMPRA_OK;
            }
            else
            {
                resultat = ERROR_SEIENTS;
            }

            i = m_nEspectacles;
        }
        else
        {
            i++;
        }
    }
    return resultat;
}

// Anula la compra dentrades dun espectacle en un dia determinat.
// Retorna COMPRA_OK --> anulacio correcta
// ERROR_ESPECTACLE ---> espectacle no existeix
// ERROR_SEIENTS --> algun dels seients a anular no estava reservat.
EstatCompra VendaEntrades::anulaCompra(const string& nom, const string& dia, int nEntrades, int seients[MAX_SEIENTS_COMPRA])
{
    EstatCompra resultat = ERROR_ESPECTACLE;
    int i = 0;

    while (i < m_nEspectacles)
    {
        if (m_espectacle[i].getNom() == nom && m_espectacle[i].getDia() == dia)
        {
            bool hiHaNoReservats = false;

            if (m_espectacle[i].alliberarSeients(nEntrades, seients, hiHaNoReservats))
            {
                resultat = hiHaNoReservats ? ERROR_SEIENTS : COMPRA_OK;
            }

            i = m_nEspectacles;
        }
        else
        {
            i++;
        }
    }

    return resultat;
}

// Retorna lestat docupacio dels seients dun espectacle en un dia determinat.
void VendaEntrades::recuperaOcupacio(const string& nom, const string& dia, bool ocupacioSeients[MAX_SEIENTS])
{
    int i = 0;
    while (i < m_nEspectacles)
    {
        if (m_espectacle[i].getNom() == nom && m_espectacle[i].getDia() == dia)
        {
            m_espectacle[i].obtenirOcupacio(ocupacioSeients);
            i = m_nEspectacles;
        }
        else
        {
            i++;
        }
    }
}
