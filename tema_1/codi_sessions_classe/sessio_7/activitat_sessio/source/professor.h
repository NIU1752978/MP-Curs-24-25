#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
using namespace std;

class Professor
{
public:
	Professor() : m_nom(""), m_mail(""), m_despatx("") {}
	Professor(string nom, string mail, string despatx) : m_nom(nom), m_mail(mail), m_despatx(despatx) {}
	~Professor() {}

	string getNom() { return m_nom; }
	string getMail() { return m_mail; }
	string getDespatx() { return m_despatx; }

	void setNom(string nom) { m_nom = nom; }
	void setMail(string mail) { m_mail = mail; }
	void setDespatx(string despatx) { m_despatx = despatx; }
private:
	string m_nom;
	string m_mail;
	string m_despatx;
};


#endif

