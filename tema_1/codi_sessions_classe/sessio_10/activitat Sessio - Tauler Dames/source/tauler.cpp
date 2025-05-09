#include "tauler.h"	

void inicialitzaTauler(char tauler[N_FILES][N_COLUMNES])
{
	for (int i = 0; i < N_FILES; i++)
	{
		for (int j = 0; j < N_COLUMNES; j++)
		{
			tauler[i][j] = ' ';
		}
	}
}

void llegeixTauler(const string& nomFitxer, char tauler[N_FILES][N_COLUMNES])
{
	ifstream fitxer;
	fitxer.open(nomFitxer);
	
	if (fitxer.is_open())
	{
		inicialitzaTauler(tauler);

		char figura;
		Posicio posicio;
		
		while (fitxer >> figura)
		{
			fitxer >> posicio;
			tauler[posicio.getFila()][posicio.getColumna()] = figura;
		}
	}
	
	fitxer.close();
}

void escriuTauler(const string& nomFitxer, char tauler[N_FILES][N_COLUMNES])
{
	ofstream fitxer;
	fitxer.open(nomFitxer);
	
	if (fitxer.is_open())
	{
		for (int i = 0; i < N_FILES; i++)
		{
			for (int j = 0; j < N_COLUMNES; j++)
			{
				if (tauler[i][j] != ' ')
				{
					char columna = 'a' + j;
					char fila = '1' + (N_FILES - 1 - i);

					fitxer << tauler[i][j] << " " << columna << fila << "\n";
				}
			}
		}
		fitxer.close();
	}
}
