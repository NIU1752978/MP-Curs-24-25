#pragma once
#include "Punt.h"
#include <cmath>
#include <iostream>
using namespace std;

void Punt::llegeix()
{
	cout << "Introdueix la dimensió del punt: ";
	cin >> m_nDimensions;

	for (int i = 0; i < m_nDimensions; i++)
	{
		cout << "Introdueix les coordenades del punt: ";
		cin >> m_coordenades[i];
	}
  
}

void Punt::mostra()
{
	for (int i = 0; i < m_nDimensions; i++)
	{
		cout << "(" << m_coordenades[i] << ")";
	}
}

float Punt::distancia(Punt &p)
{
	for (int i = 0; i < m_nDimensions; i++)
	{
		float diferencia = distancia + m_coordenades[i]
	}
    float distancia = (m_x * m_x) + (m_y * m_y);
    return sqrt(distancia);
}

Punt Punt::suma(Punt& p)
{
	Punt pSuma;
	pSuma.m_x = m_x + p.m_x;
	pSuma.m_y = m_y + p.m_y;
	return pSuma;
}
