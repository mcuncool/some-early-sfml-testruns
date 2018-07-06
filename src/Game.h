#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class StateManager;


class Game
{
public:
	Game();
	~Game();

	bool init();
	void run();


	void handleInput();
	void update(sf::Time argUpdateTime);
	void render();


	sf::RenderWindow *m_pRenderWindow;
	StateManager *m_pStateManager;


	bool m_isRunning;





	//wie oftupdate gecallt werden soll
	sf::Clock clk; 
	sf::Clock m_updateClock; //yz
	sf::Time m_renderTimeThreshold; //Hier wird die Zeiz zum rendern addiert 
	
	sf::Time m_renderTimeRate;
	sf::Text m_updateTimeString;
	sf::Text m_mt1String; //time since last update

	sf::Time m_updateTime; //time since last update


	sf::Time m_timeUntilFpsUpdate; //1 mal pro sekunde updaten
	sf::Time m_fpsTime; //1 sekunde
	sf::Text m_fpsCounter;
	int fps;

	sf::Font m_gameFont;


};

#endif

