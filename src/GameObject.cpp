#pragma once
#include "GameObject.h"
#include <iostream>


GameObject::GameObject()
{

}


GameObject::~GameObject()
{
}

/* ich will dass alle Game Objects dem Player folgen ! */
void GameObject::update()
{
	
	if (whatAmI == GameObjectType::ENEMY)
	{
		std::cout << "I am an enemy and looking for the Player(update)\n";
		/* wo kriege ich die Koordinaten des Spielers her? */
		x += 0.1f;
		y += 0.1f; 
	}
}

void GameObject::draw(sf::RenderWindow *argPtrRenderWindow)
{
	sf::Vector2i vec(x, y);
	//Besser wäre es, das Zentrum des SPrites zu finden und damit zu arbeiten
	m_Sprite->setPosition(x, y); //geht das besser? ja, setPosition und alignSpriteOrigin
	argPtrRenderWindow->draw(*m_Sprite);
}

/* value call */
void GameObject::setPosition(float argx, float argy)
{
	x = argx;
	y = argy;
}


void GameObject::giveMeMyCoodinates()
{
	std::cout << "Player x : " << x << " y : " << y << "\n";

}

sf::Vector2f GameObject::getPosition()
{
	sf::Vector2f myPosition;
	myPosition.x = x;
	myPosition.y = y;
	return myPosition;
}

bool GameObject::hitTest(GameObject *objectOne, GameObject *objectTwo)
{
	return false;
}

void GameObject::setSprite(sf::Sprite *argPtrSprite)
{
	m_Sprite = argPtrSprite;
	alignSpriteOrigin();
	
}

void GameObject::alignSpriteOrigin()
{
	sf::FloatRect bounds = m_Sprite->getLocalBounds();
	m_Sprite->setOrigin(bounds.width / 2.f, bounds.height / 2.f);

}

void GameObject::setVelocity(float argx, float argy)
{
	m_velocity.x = argx;
	m_velocity.y = argy;
}

void GameObject::setVelocity(sf::Vector2f argVelVec)
{
	m_velocity = argVelVec;
}



sf::Vector2f GameObject::getVelocity()
{
	//kopie des Wertes
	return m_velocity;
}