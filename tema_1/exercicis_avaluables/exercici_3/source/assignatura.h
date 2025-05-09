#ifndef ASSIGNATURA_H
#define ASSIGNATURA_H

#include "reserva.h"
#include <string>
using namespace std;

class Assignatura
{
public:
	Assignatura() : m_codiAssignatura(""), m_nEstudiantsMatriculats(0), m_diaSetmana(""), m_horaInici(0), m_horaFinal(0), m_nSetmanaInici(0), m_nSetmanaFinal(0), m_codiAula("") {}
	Assignatura(const string& codi, int nEstudiantsMatriculats, const string& diaSetmana, int horaInici, int horaFinal, int nSetmanaInici, int nSetmanaFinal)
		: m_codiAssignatura(codi), m_nEstudiantsMatriculats(nEstudiantsMatriculats), m_diaSetmana(diaSetmana), m_horaInici(horaInici), m_horaFinal(horaFinal), m_nSetmanaInici(nSetmanaInici), m_nSetmanaFinal(nSetmanaFinal), m_codiAula("") {
	}

	void setCodiAssignatura(const string& codiAssignatura) { m_codiAssignatura = codiAssignatura; }
	void setNReserves(int nReserves) { m_nEstudiantsMatriculats = nReserves; }
	void setDiaSetmana(const string& diaSetmana) { m_diaSetmana = diaSetmana; }
	void setHoraInici(int horaInici) { m_horaInici = horaInici; }
	void setHoraFinal(int horaFinal) { m_horaFinal = horaFinal; }
	void setSetmanaInici(int setmanaInici) { m_nSetmanaInici = setmanaInici; }
	void setSetmanaFinal(int setmanaFinal) { m_nSetmanaFinal = setmanaFinal; }
	void setCodiAula(const string& codiAula) { m_codiAula = codiAula; }
	string getCodiAssignatura() const { return m_codiAssignatura; }
	int getNEstudiantsMatriculats() const { return m_nEstudiantsMatriculats; }
	string getDiaSetmana() const { return m_diaSetmana; }
	int getHoraInici() const { return m_horaInici; }
	int getHoraFinal() const { return m_horaFinal; }
	int getSetmanaInici() const { return m_nSetmanaInici; }
	int getSetmanaFinal() const { return m_nSetmanaFinal; }
	string getCodiAula() const { return m_codiAula; }
	int getNReserves() const { return m_nEstudiantsMatriculats; }

private:
	string m_codiAssignatura; 
	int m_nEstudiantsMatriculats;
	string m_diaSetmana;
	int m_horaInici;
	int m_horaFinal;
	int m_nSetmanaInici;
	int m_nSetmanaFinal;
	string m_codiAula;
};

#endif