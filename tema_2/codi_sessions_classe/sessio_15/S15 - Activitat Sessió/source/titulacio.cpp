#include "titulacio.h"



void Titulacio::afegeixEstudiant(const string& niu, const string& nom)
{
	m_estudiants[m_nEstudiants] = Estudiant(niu, nom, m_nMaxAssignatures);
	m_nEstudiants++;
}

bool Titulacio::eliminaEstudiant(const string& niu)
{
	bool trobat = false;
	int i = 0;

	while (i < m_nMaxAssignatures && !trobat)
	{
		if ()
		{

		}
		else
		{
			i++;
		}
	}

}

bool Titulacio::consultaEstudiant(const string& niu, Estudiant& e)
{
	bool trobat = false;
	int i = 0;
	while ((i < m_nEstudiants) && !trobat)
	{
		if (niu == m_estudiants[i].getNiu())
			trobat = true;
		else
		{
			i++;
		}
	}
	if (trobat)
	  e = m_estudiants[i];
	return trobat;
}
