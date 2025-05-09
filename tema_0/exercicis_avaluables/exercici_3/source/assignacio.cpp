#include "assignacio.h"

// Inicialitzem les dades de les assignatures
void inicialitza(Assignacio& dadesAssignacio, string nomAssignatures[MAX_ASSIGNATURES], int maxMatriculats[MAX_ASSIGNATURES], int nAssignatures)
{
    dadesAssignacio.nAssignatures = nAssignatures; // numero assignatures que assignem

    for (int i = 0; i < nAssignatures; i++)
    {
        dadesAssignacio.assignatures[i].nom = nomAssignatures[i];
        dadesAssignacio.assignatures[i].maxMatriculats = maxMatriculats[i];
        dadesAssignacio.assignatures[i].nAssignats = 0;
    }

    dadesAssignacio.nEstudiants = 0;
}

// afegim les preferencies dun estudiant
void afegeixPreferenciesEstudiant(Assignacio& dadesAssignacio, string nomEstudiant, int nCreditsSuperats, float notaMitjana, int nAssignaturesAMatricular, int nAssignaturesPreferides, string assignaturesPreferides[MAX_ASSIGNATURES])
{
    Estudiant& estudiant = dadesAssignacio.estudiants[dadesAssignacio.nEstudiants]; // agafem la posicio de lestudiant actual
    estudiant.nom = nomEstudiant;
    estudiant.creditsSuperats = nCreditsSuperats;
    estudiant.notaMitjana = notaMitjana;
    estudiant.nAssignaturesPreferides = nAssignaturesPreferides;

    for (int i = 0; i < nAssignaturesPreferides; i++)
    {
        estudiant.preferencies[i] = assignaturesPreferides[i]; // guardem les preferencies
    }

    estudiant.nAssignaturesMatriculades = nAssignaturesAMatricular;

    dadesAssignacio.nEstudiants++;
}

// ordenem els estudiants per credits superats i nota mitjana
void fesAssignacio(Assignacio& dadesAssignacio)
{
    for (int i = 0; i < dadesAssignacio.nEstudiants - 1; i++)
    {
        int pos_max = i;
        for (int j = i + 1; j < dadesAssignacio.nEstudiants; j++)
        {
            if (dadesAssignacio.estudiants[j].creditsSuperats > dadesAssignacio.estudiants[pos_max].creditsSuperats ||
                (dadesAssignacio.estudiants[j].creditsSuperats == dadesAssignacio.estudiants[pos_max].creditsSuperats &&
                    dadesAssignacio.estudiants[j].notaMitjana > dadesAssignacio.estudiants[pos_max].notaMitjana))
            {
                pos_max = j;
            }
        }
        // Intercanvi manual
        Estudiant temp = dadesAssignacio.estudiants[i];
        dadesAssignacio.estudiants[i] = dadesAssignacio.estudiants[pos_max];
        dadesAssignacio.estudiants[pos_max] = temp;
    }

    // Assignacio assignatures
    for (int i = 0; i < dadesAssignacio.nEstudiants; i++)
    {
        Estudiant& estudiant = dadesAssignacio.estudiants[i];
        int assignats = 0;

        for (int j = 0; j < estudiant.nAssignaturesPreferides && assignats < estudiant.nAssignaturesMatriculades; j++)
        {
            for (int k = 0; k < dadesAssignacio.nAssignatures; k++)
            {
                if (dadesAssignacio.assignatures[k].nom == estudiant.preferencies[j] &&
                    dadesAssignacio.assignatures[k].nAssignats < dadesAssignacio.assignatures[k].maxMatriculats)
                {
                    estudiant.assignatures[assignats] = estudiant.preferencies[j];
                    dadesAssignacio.assignatures[k].estudiantsAssignats[dadesAssignacio.assignatures[k].nAssignats] = estudiant.nom;
                    dadesAssignacio.assignatures[k].nAssignats++;
                    assignats++;
                }
            }
        }

        estudiant.nAssignaturesMatriculades = assignats;
    }
}

// retornem les assignatures dun estudiant concret
void assignaturesEstudiant(Assignacio& dadesAssignacio, string nomEstudiant, int& nAssignatures, string assignaturesAssignades[MAX_ASSIGNATURES])
{
    nAssignatures = 0;

    for (int i = 0; i < dadesAssignacio.nEstudiants; i++)
    {
        if (dadesAssignacio.estudiants[i].nom == nomEstudiant)
        {
            nAssignatures = dadesAssignacio.estudiants[i].nAssignaturesMatriculades; // guardem el nombre dassignatures

            for (int j = 0; j < nAssignatures; j++)
            {
                assignaturesAssignades[j] = dadesAssignacio.estudiants[i].assignatures[j]; // copiem les assignatures assignades
            }
        }
    }
}

// retornem els estudiants matriculats en una assignatura concreta
void estudiantsAssignatura(Assignacio& dadesAssignacio, string nomAssignatura, int& nEstudiants, string estudiantsAssignats[MAX_ESTUDIANTS])
{
    nEstudiants = 0;
    bool trobat = false;

    for (int i = 0; i < dadesAssignacio.nAssignatures && !trobat; i++)
    {
        if (dadesAssignacio.assignatures[i].nom == nomAssignatura)
        {
            nEstudiants = dadesAssignacio.assignatures[i].nAssignats;

            for (int j = 0; j < nEstudiants; j++)
            {
                estudiantsAssignats[j] = dadesAssignacio.assignatures[i].estudiantsAssignats[j];
            }

            trobat = true; // indiquem que ja hem trobat lassignatura
        }
    }
}