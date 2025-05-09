#include "estudiant.h"

Estudiant::Estudiant(const string& niu, const string& nom, int nAssignatures)
{
	m_NIU = niu;
	m_nom = nom;
	m_maxAssignatures = nAssignatures;
	m_assignatures = new string[m_maxAssignatures];	
	m_nAssignatures = 0;
}

Estudiant::~Estudiant()
{
	if (m_assignatures != nullptr)
	{
		delete[] m_assignatures;
	}
}

Estudiant& Estudiant::operator=(const Estudiant& e)
{
	if (this != &e)
	{
		m_nom = e.m_nom;
		m_NIU = e.m_NIU;
		m_maxAssignatures = e.m_maxAssignatures;
		m_nAssignatures = e.m_nAssignatures;

		if (m_assignatures != nullptr)
		{
			delete[] m_assignatures;
		}
		if (e.m_assignatures != nullptr)
		{
			m_assignatures = new string[m_maxAssignatures];

			for (int i = 0; i < m_nAssignatures; i++)
			{
				m_assignatures[i] = e.m_assignatures[i];
			}
		}
		else
		{
			m_assignatures = nullptr;
		}
	}

	return *this;
}

void Estudiant::allibera()
{

}

void Estudiant::afegeixAssignatura(const string& assignatura)
{ 
	if (m_assignatures != nullptr)
	{
		m_assignatures[m_nAssignatures++] = assignatura;
	}
}

string Estudiant::getAssignatura(int posicio) const
{
	if (m_assignatures != nullptr)
		return m_assignatures[posicio];
	else return "";
}


