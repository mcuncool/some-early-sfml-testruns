#ifndef STATE_H
#define STATE_H

/* Basisklasse für Alle States */
#include <iostream>
#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "StateDefinitions.h"


class StateManager;

class State
{
public:
	State();
	State(StateManager *argpStateManager, sf::RenderWindow *argpRenderWindow);
	virtual ~State();
	
	/* diese werden in allen abgeleiteten Klassen gleich ausfallen */
	void requestPushState(StateDefinitions::States argStateToPush);
	void requestPopState();
	void requestClearState();

	

	/* pure virtuals MÜSSENin abgeleiteten Klassen überladen werden */
	virtual void handleInput(sf::Event& argEvent) = 0;
	virtual void update(sf::Time argtimeSinceLastUpdate) = 0;
	//Wenn die Funktion in der abgeleiteten Klasse nicht
	//die selbe Signatur hat, bleibt diese Funktion pure virtual und macht die Klasse zu einer
	//abstract Klasse
	virtual void render() = 0;

	StateManager *m_pStateManager;
	sf::RenderWindow *m_pRenderWindow;

	

};

#endif
