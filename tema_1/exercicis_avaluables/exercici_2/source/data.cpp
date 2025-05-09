#include "data.h"
#include <iostream>

using namespace std;

void Data::llegeix()
{
	int dia, mes, any;

	cout << "Entra el dia: ";
	cin >> m_dia;
	cout << "Entra el mes: ";
	cin >> m_mes;
	cout << "Entra l'any: ";
	cin >> m_any;
}

bool Data::operator<(const Data& data) const
{
	return ((m_any < data.m_any) ||
		((m_any == data.m_any) && (m_mes < data.m_mes)) ||
		((m_any == data.m_any) && (m_mes == data.m_mes) && (m_dia < data.m_dia)));
}

bool Data::operator==(const Data& data) const
{
	return (m_any == data.getAny() && m_mes == data.getMes() && m_dia == data.getDia());
}

bool Data::operator<=(const Data& data) const
{
	return (m_any < data.getAny() ||
		(m_any == data.getAny() && m_mes < data.getMes()) ||
		(m_any == data.getAny() && m_mes == data.getMes() && m_dia < data.getDia()) ||
		(m_any == data.getAny() && m_mes == data.getMes() && m_dia == data.getDia()));
}

Data Data::operator+(int nDies) const
{
	Data dataNova;

	dataNova.m_dia = m_dia;
	dataNova.m_mes = m_mes;
	dataNova.m_any = m_any;

	int diesAlMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (dataNova.m_any % 4 == 0 && dataNova.m_any % 100 != 0 || dataNova.m_any % 400 == 0) //any de traspas
	{
		diesAlMes[1] = 29;
	}

	while (nDies > 0)
	{
		if (dataNova.m_dia + nDies <= diesAlMes[dataNova.m_mes - 1])
		{
			dataNova.m_dia += nDies;
			nDies = 0;
		}
		else
		{
			nDies -= (diesAlMes[dataNova.m_mes - 1] - dataNova.m_dia + 1);
			dataNova.m_dia = 1;
			dataNova.m_mes++;

			if (dataNova.m_mes > 12)
			{
				dataNova.m_mes = 1;
				dataNova.m_any++; 
			}

			if ((dataNova.m_any % 4 == 0 && dataNova.m_any % 100 != 0) || (dataNova.m_any % 400 == 0))
			{
				diesAlMes[1] = 29;
			}
			else
			{
				diesAlMes[1] = 28;
			}
		}
	}

	return dataNova;
}

Data Data::operator++()
{
	m_dia++;

	int diesAlMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (m_any % 4 == 0 && m_any % 100 != 0 || m_any % 400 == 0) //any de traspas
	{
		diesAlMes[1] = 29;
	}

	if (m_dia > diesAlMes[m_mes - 1])
	{
		m_dia = 1;
		m_mes = m_mes + 1;

		if (m_mes > 12)
		{
			m_mes = 1;
			m_any = m_any + 1;
		}
	}

	return Data();
}

void Data::operator+=(int nDies)
{
	m_dia+= nDies;

	int diesAlMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (m_any % 4 == 0 && m_any % 100 != 0 || m_any % 400 == 0) //any de traspas
	{
		diesAlMes[1] = 29;
	}

	while (m_dia > diesAlMes[m_mes - 1])
	{
		m_dia = m_dia - diesAlMes[m_mes - 1];
		m_mes = m_mes + 1;

		if (m_mes > 12)
		{
			m_mes = 1;
			m_any = m_any + 1;
		}

		if (m_any % 4 == 0 && m_any % 100 != 0 || m_any % 400 == 0)
		{
			diesAlMes[1] = 29;
		}
		else
		{
			diesAlMes[1] = 28;
		}
	}
}

int Data::operator-(const Data& data) const
{
	int diesDif;
	int diesData1 = 0, diesData2 = 0, mesosData1, mesosData2, anysData1, anysData2;

	int diesAlMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	//fem Data1

	for (int i = 0; i < m_any; i++)
	{
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) //any de traspas
		{
			diesData1 = diesData1 + 366;
		}
		else
		{
			diesData1 = diesData1 + 365;
		}
	}

	if (m_any % 4 == 0 && m_any % 100 != 0 || m_any % 400 == 0)
	{
		diesAlMes[1] = 29;
	}

	for (int i = 0; i < m_mes - 1; i++)
	{
		diesData1 = diesData1 + diesAlMes[i];
	}

	diesData1 = diesData1 + m_dia;

	diesAlMes[1] = 28;

	//comencem amb Data2

	for (int i = 0; i < data.getAny(); i++)
	{
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) //any de traspas
		{
			diesData2 = diesData2 + 366;
		}
		else
		{
			diesData2 = diesData2 + 365;
		}
	}

	if (data.getAny() % 4 == 0 && data.getAny() % 100 != 0 || data.getAny() % 400 == 0)
	{
		diesAlMes[1] = 29;
	}

	for (int i = 0; i < data.getMes() - 1; i++)
	{
		diesData2 = diesData2 + diesAlMes[i];
	}

	diesData2 = diesData2 + data.getDia();

	//dies diferncia

	diesDif = diesData2 - diesData1;

	return diesDif;
}

Data Data::operator-(int nDies) const
{
	Data resultat(m_dia, m_mes, m_any);

	while (nDies > 0)
	{
		int diesMes;
		switch (resultat.m_mes)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			diesMes = 31;
			break;
		case 4: case 6: case 9: case 11:
			diesMes = 30;
			break;
		case 2:
			if ((resultat.m_any % 4 == 0 && resultat.m_any % 100 != 0) || (resultat.m_any % 400 == 0))
			{
				diesMes = 29;
			}
			else
			{
				diesMes = 28;
			}
			break;
		}

		if (nDies < resultat.m_dia)
		{
			resultat.m_dia -= nDies;
			nDies = 0;
		}
		else
		{
			nDies -= resultat.m_dia;
			resultat.m_mes--;

			if (resultat.m_mes == 0)
			{
				resultat.m_mes = 12;
				resultat.m_any--;
			}

			if (resultat.m_mes == 1 || resultat.m_mes == 3 || resultat.m_mes == 5 ||
				resultat.m_mes == 7 || resultat.m_mes == 8 || resultat.m_mes == 10 || resultat.m_mes == 12)
			{
				resultat.m_dia = 31;
			}
			else if (resultat.m_mes == 4 || resultat.m_mes == 6 || resultat.m_mes == 9 || resultat.m_mes == 11)
			{
				resultat.m_dia = 30;
			}
			else
			{
				if ((resultat.m_any % 4 == 0 && resultat.m_any % 100 != 0) || (resultat.m_any % 400 == 0))
				{
					resultat.m_dia = 29;
				}
				else
				{
					resultat.m_dia = 28;
				}
			}
		}
	}

	return resultat;
}

istream& operator>>(istream& input, Data& data)
{
	int dia, mes, any;

	cout << "Entra data (dia mes any): ";
	input >> dia >> mes >> any;

	data.setData(dia, mes, any);
	return input;
}

ostream& operator<<(ostream& output, const Data& data)
{
	if (data.getDia() < 10)
	{
		output << "0";
	}
	output << data.getDia() << "/";

	if (data.getMes() < 10)
	{
		output << "0";
	}
	output << data.getMes() << "/";

	output << data.getAny();

	return output;
}

bool comprovaTermini(const Data& dataInicial, const Data& dataActual, int dies)
{
	bool menorIgual = false;
	Data dataFinal = dataInicial + dies;

	if (dataActual <= dataFinal)
	{
		menorIgual = true;
	}

	return menorIgual;
}
