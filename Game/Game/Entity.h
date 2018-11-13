/*
 * Entity.h
 *
 *  Created on: 7 бреб„ 2018
 *      Author: OFIR
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <iostream>
#include "Globals.h"
#include "SFML/Graphics.hpp"

enum ID {
	player, bullet, asteroid, enemy, 
};

class Entity {
protected:
	float x, y;
	ID id;
	float velX, velY;
	sf::Color color;
public:

	Entity();
	virtual ~Entity();
	virtual sf::RectangleShape getBounds()=0;
	virtual void tick()=0;
	virtual void setX(float x)=0;
	virtual float getX()=0;
	virtual void setY(float y)=0;
	virtual float getY()=0;
	virtual ID getId()=0;
	virtual void setVelX(float velX)=0;
	virtual float getVelX()=0;
	virtual void setVelY(float velY)=0;
	virtual float getVelY()=0;
	virtual void setColor(sf::Color color)=0;
	virtual sf::Color getColor()=0;
	virtual void draw(sf::RenderWindow &window)=0;
};

#endif /* ENTITY_H_ */
