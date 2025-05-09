#include "gestio_projecte.h"

void GestioProjecte::afegeixTasca(const string& nom, int duradaPrevista, const Data& dataActual, int nParticipants, 
    string participants[MAX_PARTICIPANTS])
{
    Data dataPrevista = dataActual + duradaPrevista;
    Tasca novaTasca(nom, duradaPrevista, participants, dataActual);
    novaTasca.setNParticipants(nParticipants);

    m_tasques[m_nTasques] = novaTasca;
    m_nTasques++;
}

void GestioProjecte::endarrereixTasca(const string& nom, int nDies)
{
    for (int i = 0; i < m_nTasques; i++)
    {
        if (m_tasques[i].getNom() == nom)
        {
            Data novaData;
            novaData = m_tasques[i].getDataPrevista() + nDies;
            m_tasques[i].setDataPrevista(novaData);
        }
    }
}

int GestioProjecte::completaTasca(const string& nom, const Data& dataActual)
{
    int diferencia = 0;

    for (int i = 0; i < m_nTasques; i++)
    {
        if (m_tasques[i].getNom() == nom)
        {
            m_tasques[i].setCompleta(true);
            m_tasques[i].setDataFinalitzacio(dataActual);

            diferencia = dataActual - m_tasques[i].getDataPrevista();
        }
    }
    return diferencia;
}

void GestioProjecte::tasquesPendents(const string& nom, const Data& dataActual, int nDies, int& nTasques, string tasques[])
{
    nTasques = 0;
    Data dataLimit;
    dataLimit = dataActual + nDies;

    for (int i = 0; i < m_nTasques ; i++)
    {
        if (!m_tasques[i].estaCompletada())
        {
            for (int j = 0; j < m_tasques[i].getNParticipants(); j++)
            {
                if (m_tasques[i].getParticipants()[j] == nom)
                {
                    if (dataActual <= m_tasques[i].getDataPrevista() && m_tasques[i].getDataPrevista() <= dataLimit)
                    {
                        tasques[nTasques++] = m_tasques[i].getNom();
                    }
                }
            }
        }
    }
}

void GestioProjecte::retardTasques(const Data& dataActual, int& nPersones, string persones[])
{
    nPersones = 0;

    for (int i = 0; i < m_nTasques; i++)
    {
        if (m_tasques[i].getDataPrevista() < dataActual && !m_tasques[i].estaCompletada())
        {
            for (int j = 0; j < m_tasques[i].getNParticipants(); j++)
            {
                string participant = m_tasques[i].getParticipants()[j];
                bool repetit = false;

                for (int k = 0; k < nPersones; k++)
                {
                    if (persones[k] == participant)
                    {
                        repetit = true;
                    }
                }

                if (!repetit && nPersones < MAX_PARTICIPANTS)
                {
                    persones[nPersones++] = participant;
                }
            }
        }
    }
}

void GestioProjecte::recuperaTasca(const string& nom, Data& dataPrevista, bool& completada, Data& dataFinal)
{
    for (int i = 0; i < m_nTasques; i++)
    {
        if (m_tasques[i].getNom() == nom)
        {
            dataPrevista = m_tasques[i].getDataPrevista();
            completada = m_tasques[i].estaCompletada();

            if (completada == true)
            {
                dataFinal = m_tasques[i].getDataFinalitzacio();
            }
        }
    }
}

