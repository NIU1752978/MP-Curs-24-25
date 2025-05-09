#ifndef ASSIGNATURA_H
#define ASSIGNATURA_H
#include "estudiant.h"
#include "professor.h"

const int MAX_ESTUDIANTS = 50;

class Assignatura
{
public:
    Assignatura() : m_nom(""), m_nEstudiants(0) {};
    Assignatura(string nom) : m_nom(nom), m_nEstudiants(0) {};
    Assignatura(string nom, string nomProfessor, string mailProfessor, string despatx, int nEstudiants, string estudiants[MAX_ESTUDIANTS][2]);

    void afegeixEstudiant(string nom, string niu);
    bool afegeixNota(string niu, float nota);
    float calculaNotaMitjana(string niu);

    string getNomProfessor() { return m_professor.getNom(); }
    string getMailProfessor() { return m_professor.getMail(); }
    string getDespatxProfessor() { return m_professor.getDespatx(); }

private:
    string m_nom;
    Estudiant m_estudiant[MAX_ESTUDIANTS];
    Professor m_professor;
    int m_nEstudiants;
};

#endif