//
//  CurrentGame.cpp
//  LearnChess
//
//  Created by Enric Vergara on 21/2/22.
//

#include "joc.hpp"
#include <iostream>
#include <fstream>
#include "GraphicManager.h"



bool Joc::actualitza(int mousePosX, int mousePosY, bool mouseStatus) 
{
	//TODO 1: Interactuar amb la crida per dibuixar gr�fics (sprites).
	// 	      Dibuixar a pantalla el fons i el gr�fic amb el tauler buit.
	//------------------------------------------------------------------

	//TODO 1.1 Afegir l'include de GraphicManager --> #include "GraphicManager.h"
	//TODO 1.2 Fer la crida de dibuixar un sprite --> GraphicManager::getInstance()->drawSprite(image, posX, posY);
	//	    Per comen�ar podem cridar el drawSprite amb els params --> 
	//          (GRAFIC_FONS,0,0) i 
	//          (GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER)


	//TODO 1.3: Dibuixar a pantalla el gr�fic amb el tauler i una fitxa blanca a la posici� (fila, columna ) del tauler

	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER);

	if ((mouseStatus) && (mousePosX >= (POS_X_TAULER + CASELLA_INICIAL_X)) &&
		(mousePosY >= POS_Y_TAULER + CASELLA_INICIAL_Y) &&
		(mousePosX <= (POS_X_TAULER + CASELLA_INICIAL_X + AMPLADA_CASELLA * NUM_COLS_TAULER)) &&
		(mousePosY <= (POS_Y_TAULER + CASELLA_INICIAL_Y + ALCADA_CASELLA * NUM_FILES_TAULER)))

	{
		m_fila = (mousePosY - (POS_Y_TAULER + CASELLA_INICIAL_Y)) / ALCADA_CASELLA;
		m_columna = (mousePosX - (POS_X_TAULER + CASELLA_INICIAL_X)) / AMPLADA_CASELLA;
	}
	int posX = POS_X_TAULER + CASELLA_INICIAL_X + m_columna * AMPLADA_CASELLA;
	int posY = POS_Y_TAULER + CASELLA_INICIAL_Y + m_fila * ALCADA_CASELLA;
	GraphicManager::getInstance()->drawSprite(GRAFIC_FITXA_BLANCA, posX, posY);

	int posTextX = POS_X_TAULER;
	int posTextY = POS_Y_TAULER + (ALCADA_CASELLA * NUM_FILES_TAULER) + 120;
	std::string msg = "PosX: " + to_string(mousePosX) + ", PosY: " + to_string(mousePosY);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, posTextX, posTextY, 0.8, msg);

	//TODO 2: Interactuar amb el ratol�.
	//------------------------------------------------------------------
	//TODO 2.1: Dibuixar la fitxa blanca al tauler nom�s si estem pressionant el bot� del ratol�

	

    //TODO 2.2: Dibuixar la fitxa blanca al tauler nom�s si estem pressionant el bot� del ratol� i el ratol�
    // est� dins del l�mits del tauler

 

    //TODO 2.3: Dibuixar la fitxa blanca al tauler nom�s si estem pressionant el bot� del ratol� i el ratol�
    // est� dins del l�mits del tauler. Dibuixa la fitxa a la casella on est� el ratol�



    //TODO 2.4: Dibuixar la fitxa blanca a la casella on cliquem al ratol�. La fitxa s'ha de mantenir dibuixada
    // a la casella quan deixem de clicar amb el ratol�. Quan cliquem a una altra casella, la fitxa canvia de posici�
    // a la nova casella

        
        
    // TODO 3: Imprimir text per pantalla
    //------------------------------------------
    // TODO 3.1: Mostrar la posici� actual del ratol� a sota del tauler



	return false;
}




