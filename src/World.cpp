#include "World.h"


World::World(sf::RenderWindow *argPtrRenderWindow)
{
	/* hier initialisiere ich alles durcheinander was in der Welt alles sein soll */
	m_pWindow = argPtrRenderWindow;

	m_isMovingUp = m_isMovingDown = m_isMovingLeft = m_isMovingRight = false;

	std::cout << "Hehehehekeek\n";

	//drehung init - funkt erstmal, was ist mit Collision testing? wird das per Bounding Box gelöst?
	m_isTurningLeft = m_isTurningRight = false;

	go1 = new GameObject();

	txt1.loadFromFile("../more_pictures/GameState.png");
	spr1.setTexture(txt1);
	
	go1->m_Sprite = &spr1;
	go1->x = 0;
	go1->y = 0;

	player = new GameObject();
	txt2.loadFromFile("../more_pictures/player.png");
	spr2.setTexture(txt2);
	player->setSprite(&spr2);
	player->alignSpriteOrigin();
	player->setPosition(0, 0);

	gameObjects.push_back(player);

	GameObject *pEnemy = new GameObject();
	sf::Texture *ptrEnemyTexture = new sf::Texture;
	ptrEnemyTexture->loadFromFile("../more_pictures/enemy.png");
	sf::Sprite *ptrEnemySprite = new sf::Sprite;
	ptrEnemySprite->setTexture(*ptrEnemyTexture);
	pEnemy->setSprite(ptrEnemySprite);
	pEnemy->setPosition(200, 200);

	gameObjects.push_back(pEnemy);

	
	



	/* initialisiert die SCHICHTEN der Welt */
	sf::Texture *ptrTextBgOne = new sf::Texture;
	ptrTextBgOne->loadFromFile("../more_pictures/background_one.png");
	sf::Sprite *ptrSpriteBgOne = new sf::Sprite;
	ptrSpriteBgOne->setTexture(*ptrTextBgOne);

	layerOne.push_back(ptrSpriteBgOne);

	sf::Texture *ptrTextBgTwo = new sf::Texture;
	ptrTextBgTwo->loadFromFile("../more_pictures/background_two.png");
	sf::Sprite *ptrSpriteBgTwo = new sf::Sprite;
	ptrSpriteBgTwo->setTexture(*ptrTextBgTwo);

	layerOne.push_back(ptrSpriteBgTwo);



}


World::~World()
{

}


void World::update(sf::Time argtimeSinceLastUpdate)
{
	/* ich bewege den Player abhängig vom Zustand der Welt */
	if (m_isMovingDown)
	{
		int y = player->getPosition().y;
		player->setPosition(player->getPosition().x, y += 1); //TESTZWECK !
	}
	if (m_isMovingUp)
	{
		int y = player->getPosition().y;
		player->setPosition(player->getPosition().x, y -= 1); //TESTZWECK !
	}
	if (m_isMovingLeft)
	{
		int x = player->getPosition().x;
		player->setPosition(x-=1, player->getPosition().y); //TESTZWECK !
	}
	if (m_isMovingRight)
	{
		int x = player->getPosition().x;
		player->setPosition(x += 1, player->getPosition().y); //TESTZWECK !
	}
	if (m_isTurningLeft)
	{
		/* Ich drehe an dieser Stelle den SPRITE, der die Darstellung 
		repräsentiert ! das Logische Objekt dahinter bleibt unverändert ! irgendwie ist das
		nicht so das Richtige */
		player->m_Sprite->rotate(-0.2); 
	}
	if (m_isTurningRight)
	{
		/* wie wäre es wenn das OBJEKT eine durch Vektor gegebene Orientierung hat
		und der SPrite wird an diese Orientierung angepasst */
		player->m_Sprite->rotate(+0.2);
	}
	


	for (GameObject *a : gameObjects)
	{
		a->update();
	}
}


void World::render()
{

	/* beim draw() in GameObject werden die Koordinaten des Sprites aktualisiert
	was beim Background unnütz ist */
	go1->draw(m_pWindow);

	for (auto a : layerOne)
	{
		m_pWindow->draw(*a);
	}

	for (auto a : layerTwo)
	{
		m_pWindow->draw(*a);
	}

	for (GameObject *a : gameObjects)
	{
		a->draw(m_pWindow);
		
	}

}