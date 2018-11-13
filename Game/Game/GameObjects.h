/*
 * GameObjects.h
 *
 *  Created on: 11 бреб„ 2018
 *      Author: OFIR
 */

#ifndef GAMEOBJECTS_H_
#define GAMEOBJECTS_H_

#include <list>
#include "Entity.h"
#include <SFML/Graphics.hpp>

class GameObjects {
private:
	std::list<Entity*> objects;
public:
	GameObjects();
	virtual ~GameObjects();
	void addObject(Entity *object);
	void removeObject(Entity* object);
	std::list<Entity*> getObjects();
	void draw(sf::RenderWindow &window);
	void tick();
};

#endif /* GAMEOBJECTS_H_ */
