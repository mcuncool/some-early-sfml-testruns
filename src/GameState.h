#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "World.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class StateManager;
class GameObject;
class IntroState;
class MenuState;
class GameState;


class GameState :
	public State
{
public:

	GameState(StateManager * argStateManager, sf::RenderWindow *argRenderWindow);
	virtual ~GameState();

	virtual void handleInput(sf::Event& argEvent);
	virtual void update(sf::Time argtimeSinceLastUpdate);
	virtual void render();

	void processKeys(sf::Keyboard::Key argKeyCode, bool isPressed);



	World *m_pGameWorld;

	

};

#endif

