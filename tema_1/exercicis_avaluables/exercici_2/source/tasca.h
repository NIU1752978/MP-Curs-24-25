#ifndef TASCA_H
#define TASCA_H 

#include <string>
#include "data.h"

using namespace std;

const int MAX_PARTICIPANTS = 10;

class Tasca
{
public:
	Tasca() : m_nom(""), m_duradaPrevista(0), m_nParticipants(0), m_completada(false) {}
	Tasca(const string& nom, int duradaPrevista, const string participants[MAX_PARTICIPANTS], const Data& dataActual) : m_nom(nom), m_duradaPrevista(duradaPrevista), m_dataPrevista(dataActual + duradaPrevista), m_nParticipants(0), m_completada(false) {}

	string getNom() { return m_nom; }
	int getDuradaPrevista() { return m_duradaPrevista; }
	Data getDataPrevista() { return m_dataPrevista; }
	Data getDataFinalitzacio() { return m_dataFinalitzacio; }
	string* getParticipants() { return m_Participants; }
	int getNParticipants() { return m_nParticipants; }
	bool estaCompletada() { return m_completada; }

	void setNom(const string& nom) {};
	void setDuradaPrevista(int duradaPrevista) {};
	void setDataPrevista(Data& dataPrevista) {};
	void setCompleta(bool completa) {};
	void setNParticipants(int nParticipants) {};
	void setDataFinalitzacio(Data dataFinalitzacio) {};

private:
	string m_nom;
	int m_duradaPrevista;
	Data m_dataPrevista;
	Data m_dataFinalitzacio;
	string m_Participants[MAX_PARTICIPANTS];
	int m_nParticipants;
	bool m_completada;
};

#endif