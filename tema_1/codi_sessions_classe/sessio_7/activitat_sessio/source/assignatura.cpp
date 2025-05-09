#include "assignatura.h"

Assignatura::Assignatura(string nom, string nomProfessor, string mailProfessor, string despatx, int nEstudiants, string estudiants[MAX_ESTUDIANTS][2]) : m_professor(nomProfessor, mailProfessor, despatx), m_nom(nom), m_nEstudiants(nEstudiants)
{
	for (int i = 0; i < m_nEstudiants; i++)
	{
		m_estudiant[i].inicialitza(estudiants[i][0], estudiants[i][1]);
	}

}

void Assignatura::afegeixEstudiant(string nom, string niu)
{
	if (m_nEstudiants < MAX_ESTUDIANTS)
	{
		m_estudiant[m_nEstudiants].inicialitza(nom, niu);
		m_nEstudiants++;
	}
}

bool Assignatura::afegeixNota(string niu, float nota)
{
	bool trobat = false;

	for (int i = 0; i < m_nEstudiants; i++)
	{
		if (m_estudiant[i].getNiu() == niu)
		{
			trobat = m_estudiant[i].afegeixNota(nota);
		}
	}

	return trobat;
}

float Assignatura::calculaNotaMitjana(string niu)
{
	float notaMitjana = -1;

	for (int i = 0; i < m_nEstudiants; i++)
	{
		if (m_estudiant[i].getNiu() == niu)
		{
			notaMitjana = m_estudiant[i].calculaNotaMitjana();
		}
	}

	return notaMitjana;
}
