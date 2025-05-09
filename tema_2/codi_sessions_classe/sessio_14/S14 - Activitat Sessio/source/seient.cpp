#include "seient.h"

Seient::Seient()
{
	m_codi = "";
	m_passatger = nullptr;
}

Seient::Seient(const string& codi)
{
	m_codi = codi;
	m_passatger = nullptr;
}

Seient::~Seient()
{
	if (m_passatger != nullptr)
	{
		delete m_passatger;
	}
}

bool Seient::assignaPassatger(const string& dni, const string& nom)
{
	bool assignat = false;

	if (m_passatger == nullptr)
	{
		m_passatger = new Passatger(dni, nom);
		assignat = true;
	}

	return assignat;
}

bool Seient::eliminaPassatger()
{
	bool eliminat = false;

	if (m_passatger != nullptr)
	{
		delete m_passatger;
		m_passatger = nullptr;
		eliminat = true;
	}
	

	return eliminat;
}