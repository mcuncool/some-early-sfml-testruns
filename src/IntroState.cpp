#include "IntroState.h"

#include "GameObject.h"
#include "StateManager.h"



IntroState::IntroState(StateManager *argStateManager, sf::RenderWindow *argRenderWindow)
{

	m_pStateManager = argStateManager;
	m_pRenderWindow = argRenderWindow;

	

	go1 = new GameObject();

	sf::Texture *txt2 = new sf::Texture();
	//txt2->loadFromFile("start.png");
	
	/* Two dots ("..") point upwards in the hierarchy, to indicate the parent directory; one dot (".") represents the current directory itself. */
	
	txt1.loadFromFile("../more_pictures/Intro.png");
	/*if (!txt1.loadFromFile("image1.png"))
	{
		std::cout << "not loaded\n";
	}*/

	spr1.setTexture(txt1);

	//spr1.setTexture(*txt2);

	//Zugriff auf einen Member durch Pointer !
	go1->m_Sprite = &spr1;

	



}


IntroState::~IntroState()
{
	std::cout << "Intro state destroyed\n";
}


void IntroState::handleInput(sf::Event &argEvent)
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


void IntroState::processKeys(sf::Keyboard::Key argKeyCode, bool isPressed)
{
	//std::cout << argKeyCode << ((isPressed == true) ? " was pressed" : " was released") << "\n";
	if (argKeyCode == sf::Keyboard::Key::Return && isPressed)
	{

		requestClearState();
		requestPushState(StateDefinitions::MENU);
		
		//requestPushState();
		std::cout << "Pressed Enter\n";
	} 
	if (argKeyCode == sf::Keyboard::Key::Escape && isPressed)
	{
		m_pRenderWindow->close();
	}
	
}

//
void IntroState::update(sf::Time argtimeSinceLastUpdate)
{
	//Was kann man hier updaten?
}

void IntroState::render()
{
	//m_pRenderWindow->clear();
	//window.draw(shape);
	//std::cout << "DRAWING SHIT\n";
	//tmp_renderwindow->draw(go1->m_Sprite);
	m_pRenderWindow->draw(*go1->m_Sprite);

	/*m_pRenderWindow->display();*/

}
