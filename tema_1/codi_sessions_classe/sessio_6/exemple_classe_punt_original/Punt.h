#ifndef PUNT_H
#define PUNT_H

const int MAX_DIMENSIONS = 10;

class Punt
{
public:
   void llegeix();
    void mostra();
    float distancia(Punt &p);
	Punt suma(Punt& p);
private:
    float m_coordenades[MAX_DIMENSIONS];
    int m_nDimensions;
};

#endif
