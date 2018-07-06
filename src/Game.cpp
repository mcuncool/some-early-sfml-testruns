#include "Game.h"
#include "GameObject.h"
#include "MenuState.h"
#include "IntroState.h"
#include "GameState.h"
#include "StateManager.h"
#include <iostream>

#include <SFML/Graphics.hpp>

Game::Game()
{

	sf::VideoMode actualMode = sf::VideoMode::getDesktopMode();
	//m_pRenderWindow = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Castle Defender 1");// , sf::Style::Fullscreen);
	m_pRenderWindow = new sf::RenderWindow(actualMode, "Castle Defender 1");

	m_pStateManager = new StateManager(m_pRenderWindow);

	
	
	m_pStateManager->pushGameState(StateDefinitions::States::INTRO);


	

	/* das ist Initialisierung der Variablen, der Clocks und sowas */
	/* Zeigt, wie oft es gerendert werden sollte
	unzwar 1 mal in 16 millisekunden, für 60 fps*/
	m_renderTimeRate = sf::milliseconds(16); 

	m_updateTime = sf::Time::Zero; // ?

	m_renderTimeThreshold = sf::milliseconds(0);
	fps = 0;

	m_gameFont.loadFromFile("arial.ttf");

	m_fpsCounter.setFont(m_gameFont);
	m_fpsCounter.setCharacterSize(15);
	//m_fpsCounter.setColor(sf::Color::Red); //Statischer element der Klasee Color

	m_updateTimeString.setFont(m_gameFont);
	m_updateTimeString.setCharacterSize(15);
	m_updateTimeString.setPosition(0, 20);

	m_mt1String.setFont(m_gameFont);
	m_mt1String.setCharacterSize(15);
	m_mt1String.setPosition(0, 40);

	m_fpsTime = sf::milliseconds(1000);
	m_timeUntilFpsUpdate = sf::Time::Zero;

	clk.restart();


}


Game::~Game()
{
}

bool Game::init()
{
	return true;
}

void Game::handleInput()
{
	sf::Event event;
	while (m_pRenderWindow->pollEvent(event))
	{
		//Ob es geschlossen wird, kann ich gleich hier abfragen?
		switch (event.type)
		{
		case sf::Event::Closed:
			m_pRenderWindow->close();
			break;
		}
		m_pStateManager->handleInput(event);
	}
}

void Game::update(sf::Time argUpdateTime)
{
	//clock.restart();
	/* Update die States die im StateManager abgelegt sind */
	m_pStateManager->update(argUpdateTime);
		
}

void Game::render()
{
	/* Säubere Bildschirm */
	m_pRenderWindow->clear();

	/* Dann fordere State Manager auf, seine States zu zeichnen */
	m_pStateManager->render(); //draw State before drawing additional Information


	//Zeichne zusätzliche Informationen oben drauf
	m_pRenderWindow->draw(m_fpsCounter);
	m_pRenderWindow->draw(m_updateTimeString);
	m_pRenderWindow->draw(m_mt1String);
	//Zeig was du gezeichnet hast
	m_pRenderWindow->display();
}



void Game::run()
{
	clk.restart(); //gameclock
	m_updateClock.restart(); //updateclock

	while (m_pRenderWindow->isOpen())
	{
		
		handleInput(); //HANDLE INPUT

		m_renderTimeThreshold += clk.restart();
	
		
		
		m_updateTime = m_updateClock.restart();

		
		m_updateTimeString.setString("time since last update ms: " + std::to_string(m_updateTime.asMilliseconds()));

		//Das erzeugt LAG ! das muss aber so :)
		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 1000; j++)
			{
				;//tu nix, das ist um update zu Bremsen !
			}
		}

		//Updated wird so schnell wie möglich, ist das gut?
		update(m_updateTime); //UPDATE HIER, zeit noch nicht so wichtig


		//WENN DIE ZEIT FÜR EIN RENDER GEKOMMEN IST - zum Zeichnen
		if (m_renderTimeThreshold >= m_renderTimeRate)
		{
			render();
			m_timeUntilFpsUpdate += m_renderTimeThreshold;
			fps++;

			m_renderTimeThreshold = sf::Time::Zero;

			if (m_timeUntilFpsUpdate >= m_fpsTime) //BERECHNE FRAMES PRO SEKUNDE
			{
				m_fpsCounter.setString("fps : " + std::to_string(fps));
				m_timeUntilFpsUpdate = sf::Time::Zero;
				fps = 0;
			}

		}
		

		m_mt1String.setString("game tickrate ms: " + std::to_string(m_renderTimeThreshold.asMilliseconds()));
		
		
		
	}

}