#pragma once
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include <iostream>

class World
{
public:
	World(sf::RenderWindow *argPtrRenderWindow);
	~World();


	/* ist innerhalb des GameStates und 
	initialisiert 
	verwaltet 
	zeichnet 
	die Layer und sowas */



	
	void update(sf::Time argtimeSinceLastUpdate);
	void render();

	//void loadTextures();
	//void buildScene();


	sf::RenderWindow *m_pWindow;
	
		
	GameObject *go1; //dient momentan als Background
	sf::Texture txt1;
	sf::Sprite spr1;

	/* das muss geändert werden !
	dient als Player */
	GameObject *player;
	sf::Texture txt2;
	sf::Sprite spr2;

	/* das hier wird ausgelagert !*/
	/* es sind alles states die mit dem Spieler Objekt zu tun haben 
	(dem Objekt den der Spieler steuert */

	bool m_isMovingUp;
	bool m_isMovingDown;
	bool m_isMovingLeft;
	bool m_isMovingRight;

	//test Dinge, subject to change
	bool m_isTurningLeft;
	bool m_isTurningRight;


	std::vector<GameObject*> gameObjects;//to be filled with game objects

	std::vector<sf::Sprite*> layerOne; //ein vector von länge 0
	std::vector<sf::Sprite*> layerTwo; //repräsentieren den Boden und statics wie z.B. Bäume

	/* das in eine eigene Klasse auslagern */



};

