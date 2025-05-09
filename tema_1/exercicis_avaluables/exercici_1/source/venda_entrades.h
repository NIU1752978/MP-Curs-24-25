#ifndef VENDA_ENTRADES_H
#define VENDA_ENTRADES_H

#include <string>
#include "espectacle.h"

using namespace std;

const int MAX_ESPECTACLES = 5;

typedef enum
{
	COMPRA_OK,
	ERROR_ESPECTACLE,
	ERROR_SEIENTS
}EstatCompra;

class VendaEntrades
{
public:
	
	VendaEntrades(int nSeients);

	void afegeixEspectacle(const string& nom, const string& dia, float preu);
	EstatCompra compraEntrades(const string& nom, string& dia, int nEntrades, float& preu, int seients[MAX_SEIENTS_COMPRA]);
    EstatCompra anulaCompra(const string& nom, const string& dia, int nEntrades, int seients[MAX_SEIENTS_COMPRA]);
    void recuperaOcupacio(const string& nom, const string& dia, bool ocupacioSeients[MAX_SEIENTS]);

private:
	int m_nSeients;
	Espectacle m_espectacle[MAX_ESPECTACLES];
	int m_nEspectacles;
};


#endif