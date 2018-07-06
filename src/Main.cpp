#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"
#include "Game.h"
#include "MenuState.h"

int main()
{
	//sf::RenderWindow window(sf::VideoMode(800, 640), "SFML works!");


	

	//int *pa;
	//int b = 11;
	//pa = &b;
	//std::cout << pa << " " << *pa; //dereferenzierung

	
	
	Game *g = new Game();

	g->run();

	return 0;
}