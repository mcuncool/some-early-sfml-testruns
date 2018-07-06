#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>

#include "StateDefinitions.h"
#include "ActionDefinitions.h"

class State;
class MenuState;
class IntroState;
class GameState;

class StateManager
{
public:
	StateManager();
	StateManager(sf::RenderWindow *argpWindow);
	~StateManager();


	

	/* das ding vielleicht auslagern ? */
	struct PendingChange
	{
		ActionDefinitions::Actions pendingAction;
		StateDefinitions::States stateID;
	};


	void pushGameState(StateDefinitions::States argStateToPush);
	void popGameState();
	void clearStates();


	virtual void handleInput(sf::Event& argEvent);
	virtual void update(sf::Time argtimeSinceLastUpdate);
	//virtual void render();
	virtual void render();

	
	void applyPendingActions();

	
	State* createState(StateDefinitions::States argStateToCreate);


	//sf::RenderWindow* getRenderWindow();


	//State *m_pCurrentGameState;
	sf::RenderWindow *m_pWindow; //gibt den an die einzelnen States weiter zum sich selber Zeichnen 

	std::vector<State*> m_GameStateVector;
	//States vorbereiten und beim Aufruf EINMALIG laden, dann die Zustände behalten;
	//Momentan nö - bei jedem change neues State Laden, memory leak?
	std::vector<PendingChange> changesToApply;

	std::map<StateDefinitions::States, State*> initializedStates;



	IntroState *i1;
	MenuState *m1;




};

#endif // !STATEMANAGER_H