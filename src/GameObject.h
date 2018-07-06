#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include "GameObjectType.h"
#include "GameObjectStates.h"

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();


	void setPosition(float argx, float argy);
	sf::Vector2f getPosition();
	void giveMeMyCoodinates();

	void setVelocity(float argx, float argy);
	void setVelocity(sf::Vector2f argVelVec);

	void setSprite(sf::Sprite* argPtrSprite);
	/* nachdem Sprite geladen wurde
	zentriere den Sprite ! */
	void alignSpriteOrigin();


	bool GameObject::hitTest(GameObject *objectOne, GameObject *objectTwo);

	sf::Vector2f getVelocity();

	/* bei jeder abgeleiteten Klasse andere aktualisierung */
	virtual void update();

	void draw(sf::RenderWindow *argPtrRenderWindow);

	/* das auslagern oder bessern */
	GameObjectType whatAmI;

	sf::Vector2f m_velocity;

	float width;
	float height;

	float x;
	float y;
	sf::Sprite* m_Sprite;



};

#endif // !GAMEOBJECT_H