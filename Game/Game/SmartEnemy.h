/*
 * Enemy.h
 *
 *  Created on: 13 бреб„ 2018
 *      Author: OFIR
 */



#include "Entity.h"
#include <random>
#include "Player.h"
#include <math.h>


class SmartEnemy : public Entity {
public:
	SmartEnemy(Player *player);
	virtual ~SmartEnemy();
	sf::RectangleShape getBounds();
	void tick();
	void setX(float x);
	float getX();
	void setY(float y);
	float getY();
	ID getId();
	void setVelX(float velX);
	float getVelX();
	void setVelY(float velY);
	float getVelY();
	void setColor(sf::Color color);
	sf::Color getColor();
	void draw(sf::RenderWindow &window);
private:
	void followPlayer();
	void bounceEnemy();
	sf::RectangleShape smartEnemy;
	int w = 16;
	int h = 16;
	float speedDivide = 2.0f;
	Player *player;
};

