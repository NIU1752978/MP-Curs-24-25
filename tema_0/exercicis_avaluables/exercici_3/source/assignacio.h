#include <string>
using namespace std;

const int MAX_ASSIGNATURES = 10;
const int MAX_ESTUDIANTS = 100;

struct Estudiant
{
	string nom;
	string preferencies[MAX_ASSIGNATURES];
	string assignatures[MAX_ASSIGNATURES];
	int creditsSuperats = 0;
	float notaMitjana;
	int nAssignaturesMatriculades = 0;
	int nAssignaturesPreferides;
};

struct Assignatura
{
	string nom;
	int maxMatriculats;
	int nAssignats = 0;
	string estudiantsAssignats[MAX_ESTUDIANTS];
};

struct Assignacio
{
	Assignatura assignatures[MAX_ASSIGNATURES];
	int nAssignatures;
	Estudiant estudiants[MAX_ESTUDIANTS];
	int nEstudiants = 0;
};

void inicialitza(Assignacio& dadesAssignacio, string nomAssignatures[MAX_ASSIGNATURES], int maxMatriculats[MAX_ASSIGNATURES], int nAssignatures);
void afegeixPreferenciesEstudiant(Assignacio& dadesAssignacio, std::string nomEstudiant, int nCreditsSuperats, float notaMitjana, int nAssignaturesAMatricular, int nAssignaturesPreferides, string assignaturesPreferides[MAX_ASSIGNATURES]);
void fesAssignacio(Assignacio& dadesAssignacio);
void assignaturesEstudiant(Assignacio& dadesAssignacio, string nomEstudiant, int& nAssignatures, string assignaturesAssignades[MAX_ASSIGNATURES]);
void estudiantsAssignatura(Assignacio& dadesAssignacio, string nomAssignatura, int& nEstudiants, string estudiantsAssignats[MAX_ESTUDIANTS]);
