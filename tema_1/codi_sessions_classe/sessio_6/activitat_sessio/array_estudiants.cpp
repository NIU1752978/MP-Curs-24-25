#include "estudiant.h"

const int MAX_ESTUDIANTS = 10;

void afegeixEstudiant(Estudiant estudiants[], int nEstudiants, string nom, string niu)
{
	estudiants[nEstudiants].inicialitza(nom, niu);
	nEstudiants++;
}

bool afegeixNota(Estudiant estudiants[], int nEstudiants, string niu, float nota)
{
	bool afegir_nota = false;
	int i = 0;

	for (int i = 0; i < nEstudiants; i++)
	{
		if (estudiants[i].getNiu() == niu)
		{
			afegir_nota = estudiants[i].afegeixNota(nota);
		}
	}
	return afegir_nota;
}

float calculaNotaMitjana(Estudiant estudiants[], int nEstudiants, string niu)
{
	float mitjana = -1;

	for (int i = 0; i < nEstudiants; i++)
	{
		if (estudiants[i].getNiu() == niu)
		{
			mitjana = estudiants[i].calculaNotaMitjana();
		}
	}

	return mitjana;
}
