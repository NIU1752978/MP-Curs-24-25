#ifndef JOC_H
#define JOC_H

#include <stdio.h>
#include "info_joc.hpp"

using namespace std;


class Joc 
{

public:
    Joc() {};
    
    bool actualitza(int mousePosX, int mousePosY, bool mouseStatus);
    
    
private:
    int m_fila;
    int m_columna;
};

#endif 
