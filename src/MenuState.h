#ifndef  MENUSTATE_H
#define MENUSTATE_H


#include "State.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class GameObject;

class StateManager;

class MenuState :
	public State
{
public:

	MenuState(StateManager *argStateManager, sf::RenderWindow *argRenderWindow);
	virtual ~MenuState();

	virtual void handleInput(sf::Event& argEvent);
	virtual void update(sf::Time argtimeSinceLastUpdate);
	virtual void render();

	void processKeys(sf::Keyboard::Key argKeyCode, bool isPressed);


	sf::Texture txt1;
	sf::Sprite spr1;

	GameObject *go1;
	

};

#endif // ! MENUSTATE_H_

