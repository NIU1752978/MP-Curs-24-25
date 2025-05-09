#include "escola.h"
#include <fstream>
using namespace std;

void Escola::inicialitzaProfessors(const string& nomFitxer)
{
    ifstream fitxer(nomFitxer);
    if (fitxer.is_open())
    {
        string nom, mail, despatx;
        while (!fitxer.eof())
        {
            fitxer >> nom >> mail >> despatx;

			if (nom != "")
			{
				m_professors[m_nProfessors].setNom(nom);
				m_professors[m_nProfessors].setMail(mail);
				m_professors[m_nProfessors].setDespatx(despatx);
				m_nProfessors++;
			}
        }
        fitxer.close();
    }
}

Assignatura* Escola::cercaAssignatura(const string& nomAssignatura)
{
    Assignatura* assignatura = nullptr;
    bool trobat = false;

    int i = 0;

    while (!trobat && (i < m_nAssignatures))
    {
        if (m_assignatures[i].getNom() == nomAssignatura)
        {
            trobat = true;
            assignatura = &m_assignatures[i];
        }
        else
        {
            i++;
        }
    }
    return assignatura;
}

Professor* Escola::cercaProfessor(const string& nomProfessor)
{
	Professor* professor = nullptr;
	bool trobat = false;
	int i = 0;

	while (!trobat && (i < m_nProfessors))
	{
		if (m_professors[i].getNom() == nomProfessor)
		{
			trobat = true;
			professor = &m_professors[i];
		}
		else
		{
			i++;
		}
	}
	return professor;
}

bool Escola::afegeixProfessorAssignatura(const string& nomAssignatura, const string& nomProfessor)
{
    bool afegit = false;
	Assignatura* assignatura = cercaAssignatura(nomAssignatura);
	Professor* professor = cercaProfessor(nomProfessor);

    if (assignatura != nullptr && professor != nullptr)
    {
        if (assignatura->getProfessor() == nullptr)
        {
            assignatura->setProfessor(professor);
            afegit = true;
        }
    }

    return afegit;
}

bool Escola::eliminaProfessorAssignatura(const string& nomAssignatura)
{
	bool eliminat = false;
	Assignatura* assignatura = cercaAssignatura(nomAssignatura);

    if (assignatura != nullptr && assignatura->getProfessor() != nullptr)
    {
		assignatura->setProfessor(nullptr);
		eliminat = true;
    }
	
    return eliminat;
}

void Escola::getAssignaturesProfessor(const string& nomProfessor, string assignatures[MAX_ASSIGNATURES], int& nAssignatures)
{
    nAssignatures = 0;
	Professor* professor = cercaProfessor(nomProfessor);

	if (professor != nullptr)
	{
		for (int i = 0; i < m_nAssignatures; i++)
		{
			if (m_assignatures[i].getProfessor() == professor)
			{
				assignatures[nAssignatures++] = m_assignatures[i].getNom();
			}
		}
	}
}

string Escola::getProfessorAssignatura(const string& nomAssignatura)
{
    string nomProfessor = "";
    Assignatura* assignatura = cercaAssignatura(nomAssignatura);

    if (assignatura != nullptr)
    {
        Professor* professor = assignatura->getProfessor();
        if (professor != nullptr)
        {
            nomProfessor = professor->getNom();
        }
    }

    return nomProfessor;
}

void Escola::inicialitzaAssignatures(const string& nomFitxer)
{
    ifstream fitxer(nomFitxer);
    if (fitxer.is_open())
    {
        string nomAssignatura;
        int nEstudiants;
        while (!fitxer.eof())
        {
            fitxer >> nomAssignatura >> nEstudiants;
            m_assignatures[m_nAssignatures] = Assignatura(nomAssignatura);

            for (int i = 0; i < nEstudiants; i++)
            {
                string nom, niu;
                fitxer >> nom >> niu;
                m_assignatures[m_nAssignatures].afegeixEstudiant(nom, niu);
            }
            m_nAssignatures++;
        }
        fitxer.close();
    }
}

