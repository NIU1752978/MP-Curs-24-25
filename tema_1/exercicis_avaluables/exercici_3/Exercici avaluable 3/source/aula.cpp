#include "aula.h"

bool Aula::existeixReserva(const Reserva& reserva) const
{
	// Comprova si una reserva ja existeix a laula
	bool trobat = false;
	int i = 0;

	while (i < m_nReserves && !trobat)
	{
		if (m_reserves[i] == reserva)
		{
			trobat = true;
		}

		i++;
	}

	return trobat;
}

bool Aula::afegirReserva(const Reserva& reserva)
{
	// Comprova si una reserva es pot afegir a laula
	bool afegida = false;
	int i = 0;

	if (!existeixReserva(reserva) && m_nReserves < MAX_RESERVES)
	{
		bool compatible = true;

		while (i < m_nReserves && compatible)
		{
			if (!m_reserves[i].compatibleAmb(reserva))
			{
				compatible = false;
			}

			i++;
		}

		if (compatible)
		{
			m_reserves[m_nReserves] = reserva;
			m_nReserves++;
			afegida = true;
		}
	}

	return afegida;
}

bool Aula::anularReserva(const Reserva& reserva)
{
	// Comprova si una reserva es pot anular
	bool anulada = false;
	int i = 0;

	while (i < m_nReserves && !anulada)
	{
		if (m_reserves[i] == reserva)
		{
			anulada = true;
			int j = i;

			while (j < m_nReserves - 1)
			{
				m_reserves[j] = m_reserves[j + 1];
				j++;
			}
			m_nReserves--;
		}
		else
		{
			i++;
		}
	}

	return anulada;
}

bool Aula::noSolapaReserva(const Reserva& reserva) const
{
	// Comprova si una reserva no solapa amb les reserves existents
	bool compatible = true;
	int i = 0;

	while (i < m_nReserves && compatible)
	{
		if (!m_reserves[i].compatibleAmb(reserva))
		{
			compatible = false;
		}

		i++;
	}

	return compatible;
}
