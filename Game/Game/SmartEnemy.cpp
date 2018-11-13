/*
 * SmartEnemy.h
 *
 *  Created on: 13 бреб„ 2018
 *      Author: OFIR
 */


#include "SmartEnemy.h"


SmartEnemy::SmartEnemy(Player *player) {
	this->player = player;
	std::mt19937 seed(std::random_device{ }());
	std::uniform_int_distribution<> randX(1, 784);
	std::uniform_int_distribution<> randY(1, 584);
	this->id = ID::enemy;
	this->x = randX(seed);
	this->y = randY(seed);
	this->color = sf::Color(sf::Color::Blue);
	this->smartEnemy.setSize(sf::Vector2f(w, h));
	this->smartEnemy.setPosition(x, y);
	this->smartEnemy.setFillColor(this->color);
}

SmartEnemy::~SmartEnemy() {
	std::cout << "LEAK" << std::endl;
}

sf::RectangleShape SmartEnemy::getBounds() {
	return this->smartEnemy;
}

void SmartEnemy::tick() {
	x += velX;
	y += velY;

	followPlayer();
	this->smartEnemy.setPosition(x, y);

	bounceEnemy();
}

void SmartEnemy::setX(float x) {
	this->x = x;
}

float SmartEnemy::getX() {
	return this->x;
}

void SmartEnemy::setY(float y) {
	this->y = y;
}

float SmartEnemy::getY() {
	return this->y;
}

ID SmartEnemy::getId() {
	return this->id;
}

void SmartEnemy::setVelX(float velX) {
	this->velX = velX;
}

float SmartEnemy::getVelX() {
	return this->velX;
}

void SmartEnemy::setVelY(float velY) {
	this->velY = velY;
}

float SmartEnemy::getVelY() {
	return this->velY;
}

void SmartEnemy::setColor(sf::Color color) {
	this->color = color;
}

sf::Color SmartEnemy::getColor() {
	return this->color;
}

void SmartEnemy::draw(sf::RenderWindow &window) {
	window.draw(smartEnemy);
}

void SmartEnemy::bounceEnemy() {
	if (x <= 0 || x >= WIDTH - 16) {
		velX *= -1;
	}

	if (y <= 0 || y >= HEIGHT - 16) {
		velY *= -1;
	}
}

void SmartEnemy::followPlayer() {
	float diffX = x - player->getX() - 8;
	float diffY = y - player->getY() - 8;
	float distance = sqrt((x - player->getX()) * (x - player->getX()) + ((y - player->getY()) * (y - player->getY())));

	velX = ((-1 / distance) * diffX) / speedDivide;
	velY = ((-1 / distance) * diffY) / speedDivide;
}

