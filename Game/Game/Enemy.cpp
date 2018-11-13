/*
 * Enemy.cpp
 *
 *  Created on: 11 бреб„ 2018
 *      Author: OFIR
 */

#include "Enemy.h"
#include <random>

Enemy::Enemy() {
	std::mt19937 seed(std::random_device{ }());
	std::uniform_int_distribution<> randX(1, 784);
	std::uniform_int_distribution<> randY(1, 584);
	std::mt19937 rd(std::random_device{ }());
	std::uniform_int_distribution<> randomDirection(1, 2);
	this->w = 16;
	this->h = 16;
	this->id = ID::enemy;
	this->x = randX(seed);
	this->y = randY(seed);
	if (randomDirection(rd) == 1) {
		this->velX = speed;
		this->velY = speed;
	} else {
		this->velX = -speed;
		this->velY = -speed;
	}
	this->color = sf::Color(sf::Color::Red);
	this->enemy.setSize(sf::Vector2f(w, h));
	this->enemy.setPosition(x, y);
	this->enemy.setFillColor(this->color);
}

Enemy::~Enemy() {
	std::cout << "LEAK" << std::endl;
}

sf::RectangleShape Enemy::getBounds() {
	return this->enemy;
}

void Enemy::tick() {
	x += velX;
	y += velY;

	this->enemy.setPosition(x, y);

	bounceEnemy();
}

void Enemy::setX(float x) {
	this->x = x;
}

float Enemy::getX() {
	return this->x;
}

void Enemy::setY(float y) {
	this->y = y;
}

float Enemy::getY() {
	return this->y;
}

ID Enemy::getId() {
	return this->id;
}

void Enemy::setVelX(float velX) {
	this->velX = velX;
}

float Enemy::getVelX() {
	return this->velX;
}

void Enemy::setVelY(float velY) {
	this->velY = velY;
}

float Enemy::getVelY() {
	return this->velY;
}

void Enemy::setColor(sf::Color color) {
	this->color = color;
}

sf::Color Enemy::getColor() {
	return this->color;
}

void Enemy::draw(sf::RenderWindow &window) {
	window.draw(enemy);
}

void Enemy::bounceEnemy() {
	if (x <= 0 || x >= WIDTH - 16) {
		velX *= -1;
	}

	if (y <= 0 || y >= HEIGHT - 16) {
		velY *= -1;
	}
}

