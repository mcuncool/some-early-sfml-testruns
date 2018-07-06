#ifndef INTROSTATE_H
#define INTROSTATE_H


#include "State.h"
#include "SFML/Graphics.hpp"

class GameObject;

class StateManager;

class IntroState :
	public State
{
public:

	IntroState(StateManager * argStateManager, sf::RenderWindow *argRenderWindow);
	virtual ~IntroState();

	virtual void handleInput(sf::Event& argEvent);
	//argtimeSinceLastUpdate Skol'ko proshlo  s poslednego obnovlenija
	//Wie viel Zeit es seit dem letzten Update vergangen ist
	virtual void update(sf::Time argtimeSinceLastUpdate);
	virtual void render();


	void processKeys(sf::Keyboard::Key argKeyCode, bool isPressed);


	sf::Texture txt1;
	sf::Sprite spr1;

	

	GameObject *go1;

};

#endif // !INTROSTATE_H