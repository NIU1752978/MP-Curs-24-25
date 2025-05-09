#include "gestio_aules.h"
#include <iostream>
#include <fstream>

using namespace std;

GestioAules::GestioAules()
{
	m_nAules = 0;
	m_nAssignatures = 0;
}

void GestioAules::inicialitzaAules(const string& nomFitxer)
{
	// Inicialitza les aules llegint dun fitxer
	ifstream fitxer(nomFitxer);

	if (fitxer.is_open())
	{
		string codiAula;
		int capacitat, nReserves;

		while (fitxer >> codiAula >> capacitat >> nReserves)
		{
			if (m_nAules < MAX_AULES)
			{
				m_aules[m_nAules].setCodiAula(codiAula);
				m_aules[m_nAules].setCapacitat(capacitat);

				for (int i = 0; i < nReserves; i++)
				{
					string diaSetmana;
					int horaInici, horaFinal, setmanaInici, setmanaFinal;

					fitxer >> diaSetmana >> horaInici >> horaFinal >> setmanaInici >> setmanaFinal;
					Reserva reserva(diaSetmana, horaInici, horaFinal, setmanaInici, setmanaFinal);
					m_aules[m_nAules].afegirReserva(reserva);
				}

				m_nAules++;
			}
		}
		fitxer.close();
	}
}

void GestioAules::inicialitzaAssignatures(const string& nomFitxer)
{
	// Inicialitza les assignatures llegint dun fitxer
	ifstream fitxer(nomFitxer);

	if (fitxer.is_open())
	{
		string codiAssignatura;
		int nEstudiantsMatriculats;
		string diaSetmana;
		int horaInici, horaFinal, setmanaInici, setmanaFinal;

		while (fitxer >> codiAssignatura >> nEstudiantsMatriculats >> diaSetmana >> horaInici >> horaFinal >> setmanaInici >> setmanaFinal)
		{
			if (m_nAssignatures < MAX_ASSIGNATURES)
			{
				m_assignatures[m_nAssignatures].setCodiAssignatura(codiAssignatura);
				m_assignatures[m_nAssignatures].setNReserves(nEstudiantsMatriculats);
				m_assignatures[m_nAssignatures].setDiaSetmana(diaSetmana);
				m_assignatures[m_nAssignatures].setHoraInici(horaInici);
				m_assignatures[m_nAssignatures].setHoraFinal(horaFinal);
				m_assignatures[m_nAssignatures].setSetmanaInici(setmanaInici);
				m_assignatures[m_nAssignatures].setSetmanaFinal(setmanaFinal);
				m_assignatures[m_nAssignatures].setCodiAula("");
				m_nAssignatures++;
			}
		}
		fitxer.close();
	}
}

string GestioAules::assignaAula(const string& codiAssignatura)
{
	// Assigna una aula a una assignatura
	string codiAula = "";
	int idxAssignatura = -1;

	for (int i = 0; i < m_nAssignatures && idxAssignatura == -1; i++)
	{
		if (m_assignatures[i].getCodiAssignatura() == codiAssignatura)
			idxAssignatura = i;
	}

	if (idxAssignatura != -1)
	{
		Reserva novaReserva(
			m_assignatures[idxAssignatura].getDiaSetmana(),
			m_assignatures[idxAssignatura].getHoraInici(),
			m_assignatures[idxAssignatura].getHoraFinal(),
			m_assignatures[idxAssignatura].getSetmanaInici(),
			m_assignatures[idxAssignatura].getSetmanaFinal()
		);

		int millorIndex = -1;
		int millorCapacitat = 999999;

		for (int i = 0; i < m_nAules; i++)
		{
			int capacitat = m_aules[i].getCapacitat();

			if (capacitat >= m_assignatures[idxAssignatura].getNReserves() && m_aules[i].noSolapaReserva(novaReserva))
			{
				if (capacitat < millorCapacitat)
				{
					millorCapacitat = capacitat;
					millorIndex = i;
				}
			}
		}

		if (millorIndex != -1)
		{
			if (m_aules[millorIndex].afegirReserva(novaReserva))
			{
				codiAula = m_aules[millorIndex].getCodiAula();
				m_assignatures[idxAssignatura].setCodiAula(codiAula);
			}
		}
	}

	return codiAula;
}

bool GestioAules::eliminaReserva(const string& codiAssignatura)
{
	// Elimina la reserva duna assignatura
	bool eliminada = false;

	for (int i = 0; i < m_nAssignatures && !eliminada; i++)
	{
		if (m_assignatures[i].getCodiAssignatura() == codiAssignatura)
		{
			string codiAula = m_assignatures[i].getCodiAula();

			for (int j = 0; j < m_nAules && !eliminada; j++)
			{
				if (m_aules[j].getCodiAula() == codiAula)
				{
					Reserva reserva(
						m_assignatures[i].getDiaSetmana(),
						m_assignatures[i].getHoraInici(),
						m_assignatures[i].getHoraFinal(),
						m_assignatures[i].getSetmanaInici(),
						m_assignatures[i].getSetmanaFinal());

					if (m_aules[j].anularReserva(reserva))
					{
						eliminada = true;
						m_assignatures[i].setCodiAula("");
					}
				}
			}
		}
	}
	return eliminada;
}

string GestioAules::aulaAssignatura(const string& codiAssignatura)
{
	// Retorna el codi de laula assignada a una assignatura
	string codiAula = "";

	for (int i = 0; i < m_nAssignatures; i++)
	{
		if (m_assignatures[i].getCodiAssignatura() == codiAssignatura)
		{
			codiAula = m_assignatures[i].getCodiAula();
		}
	}

	return codiAula;
}

void GestioAules::assignaturesAula(const string& codiAula, int& nAssignatures, string assignatures[])
{
	// Retorna les assignatures assignades a una aula
	nAssignatures = 0;

	for (int i = 0; i < m_nAssignatures; i++)
	{
		if (m_assignatures[i].getCodiAula() == codiAula)
		{
			assignatures[nAssignatures] = m_assignatures[i].getCodiAssignatura();
			nAssignatures++;
		}
	}
}

void GestioAules::reservesAula(const string& codiAula, const string& nomFitxer)
{
	// Escriu les reserves duna aula a un fitxer
	ofstream fitxer(nomFitxer);

	if (fitxer.is_open())
	{
		for (int i = 0; i < m_nAules; i++)
		{
			if (m_aules[i].getCodiAula() == codiAula)
			{
				int nReserves = m_aules[i].getNReserves();
				for (int j = 0; j < nReserves; j++)
				{
					Reserva reserva = m_aules[i].getReserva(j);
					fitxer << reserva.getDiaSetmana() << " "
						<< reserva.getHoraInici() << " "
						<< reserva.getHoraFinal() << " "
						<< reserva.getSetmanaInici() << " "
						<< reserva.getSetmanaFinal() << endl;
				}
			}
		}
		fitxer.close();
	}
}
