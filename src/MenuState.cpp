#include "MenuState.h"

#include "GameObject.h"



MenuState::MenuState(StateManager *argStateManager, sf::RenderWindow *argRenderWindow)
{
	m_pStateManager = argStateManager;
	m_pRenderWindow = argRenderWindow;

	go1 = new GameObject();

	sf::Texture *txt2 = new sf::Texture();

	txt1.loadFromFile("../more_pictures/Menu.png");

	spr1.setTexture(txt1);

	go1->m_Sprite = &spr1;



}

MenuState::~MenuState()
{
	std::cout << "Menu state destroyed\n";
}


void MenuState::handleInput(sf::Event& argEvent)
{
	switch (argEvent.type)
	{
	case sf::Event::KeyPressed:
		processKeys(argEvent.key.code, true);
		break;
	case sf::Event::KeyReleased:
		processKeys(argEvent.key.code, false);
		break;
	case sf::Event::MouseMoved:
		break;
	case sf::Event::MouseButtonPressed:
		//std::cout << "State Intro Mouse button  pressed\n";
		break;
	case sf::Event::MouseButtonReleased:
		//std::cout << "State Intro Mouse Button released\n";
		break;
	}
}

/* wenn ich eine Taste !DRÜCKE! - mach was in Abhängigkeit vom TastenCode */
void MenuState::processKeys(sf::Keyboard::Key argKeyCode, bool isPressed)
{
	/* also eher wenn die TASTE + GEDRÜCK wird */
	if (argKeyCode == sf::Keyboard::Key::Return && isPressed)
	{
		m_pStateManager->clearStates();
		m_pStateManager->pushGameState(StateDefinitions::GAME);
		std::cout << "Going to the Game\n";
	}
	if (argKeyCode == sf::Keyboard::Key::Escape && isPressed)
	{
		std::cout << "Return to Intro\n";
		requestClearState();
		requestPushState(StateDefinitions::INTRO);
	}
}

void MenuState::update(sf::Time argtimeSinceLastUpdate)
{
}

void MenuState::render()
{
	m_pRenderWindow->draw(*go1->m_Sprite);
}

