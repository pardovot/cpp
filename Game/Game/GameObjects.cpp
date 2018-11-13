/*
 * GameObjects.cpp
 *
 *  Created on: 11 бреб„ 2018
 *      Author: OFIR
 */

#include "GameObjects.h"

GameObjects::GameObjects() {

}

GameObjects::~GameObjects() {
	for (auto object : objects) {
		delete object;
	}
}

void GameObjects::draw(sf::RenderWindow &window) {
	for (auto object : objects) {
		object->draw(window);
	}
}

void GameObjects::tick() {
	for (auto object : objects) {
		object->tick();
	}
}

std::list<Entity*> GameObjects::getObjects() {
	return this->objects;
}

void GameObjects::addObject(Entity* object) {
	objects.push_back(object);
}

void GameObjects::removeObject(Entity *object) {
	objects.remove(object);
}
