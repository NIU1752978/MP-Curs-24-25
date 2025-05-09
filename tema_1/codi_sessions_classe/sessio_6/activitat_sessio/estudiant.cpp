#include "estudiant.h"
#include "array_estudiants.h"

void Estudiant::inicialitza(string nom, string niu)
{
	m_nom = nom;
	m_niu = niu;
	m_nNotes = 0;
}
bool Estudiant:: afegeixNota(float nota)
{
	bool afegir_nota = false;

	if (m_nNotes < 5)
	{
		m_notes[m_nNotes] = nota;
		m_nNotes++;
		afegir_nota = true;
	}

	return afegir_nota;
}
float Estudiant::calculaNotaMitjana() 
{
	float mitjana = -1;

	if (m_nNotes > 0)
	{
		float suma = 0;

		for (int i = 0; i < m_nNotes; i++)
		{
			suma = suma + m_notes[i];
		}

		mitjana = suma / m_nNotes;
	}

	return mitjana;
}
