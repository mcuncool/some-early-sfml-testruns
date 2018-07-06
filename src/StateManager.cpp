#include "StateManager.h"
#include "IntroState.h"
#include "MenuState.h"
#include "GameState.h"
#include "State.h"

StateManager::StateManager()
{
	
}

StateManager::StateManager(sf::RenderWindow *argpWindow)
{
	m_pWindow = argpWindow;

}


StateManager::~StateManager()
{
	std::cout << "STATE MANAGER DESTROYED !\n";
}



void StateManager::pushGameState(StateDefinitions::States argStateToPush)
{
	auto it = initializedStates.find(argStateToPush); //wenn key nicht da ist, wird it auf end gesetzt
	if (it == initializedStates.end()) //Value zum Key wurde nicht gefunden
	{
		std::cout << "STATE NOT FOUND IN INITIALIZED STATES\n";
		initializedStates[argStateToPush] = createState(argStateToPush);
		m_GameStateVector.push_back(createState(argStateToPush));
	}
	else
	{
		std::cout << "STATE WAS FOUND AND NO NEW STATES WILL B CREATED\n";
		m_GameStateVector.push_back(initializedStates[argStateToPush]);
	}
	std::cout << initializedStates.size() << "\n";

}



void StateManager::popGameState()
{
	m_GameStateVector.pop_back();
}

void StateManager::clearStates()
{
	//for (auto x : m_GameStateVector)
	//{
	//	
	//	//delete x; //Ugh memory leak
	//}
	m_GameStateVector.clear();
}

void StateManager::handleInput(sf::Event& argEvent)
{
	//m_GameStateVector.back()->handleInput(argEvent);
	/*switch (argEvent.type)
	{
		case sf::Event::Closed:
			m_pWindow->close();
			break;
	}*/
	m_GameStateVector.back()->handleInput(argEvent);

	applyPendingActions();

}

void StateManager::update(sf::Time argtimeSinceLastUpdate)
{
	m_GameStateVector.back()->update(argtimeSinceLastUpdate);
	
}

void StateManager::render()
{
	m_GameStateVector.back()->render();
}

void StateManager::applyPendingActions()
{
	for (auto aChange : changesToApply)
	{
		switch (aChange.pendingAction)
		{
			case ActionDefinitions::Actions::PUSH:
				std::cout << "Pushing new State\n";
				pushGameState(aChange.stateID);
				break;
			case ActionDefinitions::Actions::POP:
				popGameState();
				std::cout << "Popping last State\n";
				break;
			case ActionDefinitions::Actions::CLEAR:
				clearStates();
				std::cout << "Clearing State Vector\n";
				break;
		}
	}
	changesToApply.clear();

}

/* wird als Teil von applyPendingActions aufgerufen */
State* StateManager::createState(StateDefinitions::States argStateToCreate)
{	
	switch (argStateToCreate)
	{
	case StateDefinitions::INTRO:
		return new IntroState(this, m_pWindow);
		break;
	case StateDefinitions::MENU:
		return new MenuState(this, m_pWindow);
		break;
	case StateDefinitions::GAME:
		return new GameState(this, m_pWindow);
		break;
	default:
		break;
	}

	return new IntroState(this, m_pWindow);
}


//sf::RenderWindow* StateManager::getRenderWindow()
//{
//
//
//	return m_pWindow;
//}