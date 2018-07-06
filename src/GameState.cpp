#include "GameObject.h"
#include "GameState.h"
#include "MenuState.h"
#include "IntroState.h"


GameState::GameState(StateManager * argStateManager, sf::RenderWindow *argRenderWindow)
{
	m_pStateManager = argStateManager;
	m_pRenderWindow = argRenderWindow;

	m_pGameWorld = new World(argRenderWindow);

	



}


GameState::~GameState()
{
	;
}

void GameState::handleInput(sf::Event & argEvent)
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
		//std::cout << "Mouse moved\n";
		break;
	case sf::Event::MouseButtonPressed:
		std::cout << "State Menu Mouse button  pressed\n";
		break;
	case sf::Event::MouseButtonReleased:
		std::cout << "State Menu Mouse Button released\n";
		break;
	}
}

void GameState::processKeys(sf::Keyboard::Key argKeyCode, bool isPressed)
{
	if (argKeyCode == sf::Keyboard::Key::W)
	{	
			m_pGameWorld->m_isMovingUp = isPressed;
	} 
	if (argKeyCode == sf::Keyboard::Key::S) //else if gelöscht, wieso else? wennich 2 tasten drck?
	{
			m_pGameWorld->m_isMovingDown = isPressed;
	}
	if (argKeyCode == sf::Keyboard::Key::A) //&& isPressed
	{
			m_pGameWorld->m_isMovingLeft = isPressed;
	}
	if (argKeyCode == sf::Keyboard::Key::D)
	{
			m_pGameWorld->m_isMovingRight = isPressed;
	}
	if (argKeyCode == sf::Keyboard::Key::Left)
	{
		m_pGameWorld->m_isTurningLeft = isPressed;
	}
	if (argKeyCode == sf::Keyboard::Key::Right)
	{
		m_pGameWorld->m_isTurningRight = isPressed;
	}

}

void GameState::update(sf::Time argtimeSinceLastUpdate)
{
	
	m_pGameWorld->update(argtimeSinceLastUpdate);
	

}

void GameState::render()
{
	//Alle Objekte bei sich in den Collections zeichnen !
	/* die Welt soll sich selber zeichnen */
	//m_pRenderWindow->draw(*go1->m_Sprite);

	m_pGameWorld->render();
	
	//m_pRenderWindow->draw(*player->m_Sprite);

	//m_pGameWorld->player->draw(m_pRenderWindow);
}

