#include "reserva.h"

void Reserva::inicialitza(const string& dia, int horaInici, int horaFinal, int setmanaInici, int setmanaFinal)
{
	m_diaSetmana = dia;
	m_horaInici = horaInici;
	m_horaFinal = horaFinal;
	m_nSetmanaInici = setmanaInici;
	m_nSetmanaFinal = setmanaFinal;
}

bool Reserva::compatibleAmb(const Reserva& reserva) const
{
	// Comprova si dues reserves són compatibles
	bool compatible = true;

	bool mateixDia = m_diaSetmana == reserva.m_diaSetmana;
	bool solapenHores = m_horaInici < reserva.m_horaFinal && m_horaFinal > reserva.m_horaInici;
	bool solapenSetmanes = m_nSetmanaFinal >= reserva.m_nSetmanaInici && m_nSetmanaInici <= reserva.m_nSetmanaFinal;

	if (mateixDia && solapenHores && solapenSetmanes)
	{
		compatible = false;
	}

	return compatible;
}

bool Reserva::operator==(const Reserva& reserva) const
{
	// Comprova si dues reserves son iguals
	bool igual = false;

	if (m_diaSetmana == reserva.m_diaSetmana &&
		m_horaInici == reserva.m_horaInici &&
		m_horaFinal == reserva.m_horaFinal &&
		m_nSetmanaInici == reserva.m_nSetmanaInici &&
		m_nSetmanaFinal == reserva.m_nSetmanaFinal)
	{
		igual = true;
	}
	return igual;
}
