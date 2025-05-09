#ifndef AULA_H
#define AULA_H
#include "reserva.h"
#include <string>
using namespace std;

const int MAX_RESERVES = 500;

class Aula
{
public:
	Aula() : m_nReserves(0), m_capacitat(0), m_codiAula("") {}
	Aula(const string& codiAula, int capacitat) : m_codiAula(codiAula), m_capacitat(capacitat), m_nReserves(0) {}

	bool afegirReserva(const Reserva& novaReserva);
	bool anularReserva(const Reserva& reserva);
	bool noSolapaReserva(const Reserva& novaReserva) const;

	string getCodiAula() const { return m_codiAula; }
	void setCodiAula(const string& codiAula) { m_codiAula = codiAula; }
	int getCapacitat() const { return m_capacitat; }
	void setCapacitat(int capacitat) { m_capacitat = capacitat; }
	int getNReserves() const { return m_nReserves; }
	Reserva getReserva(int index) const { return m_reserves[index]; }

private:
	Reserva m_reserves[MAX_RESERVES];
	int m_nReserves;
	int m_capacitat;
	string m_codiAula;

	bool existeixReserva(const Reserva& reserva) const;
};

#endif
