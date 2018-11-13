/*
 * Player.cpp
 *
 *  Created on: 7 бреб„ 2018
 *      Author: OFIR
 */

#include "Player.h"

Player::Player() {
	this->w = 32;
	this->h = 32;
	this->x = 800 / 2 - 16;
	this->y = 600 / 2 - 17;
	this->id = ID::player;
	this->color = sf::Color::Blue;
	this->player = sf::RectangleShape(sf::Vector2f(w, h));
	this->player.setPosition(x, y);
	this->move = false;
	this->health = 100;
}

Player::~Player() {
	std::cout << "LEAK" << std::endl;
}

sf::RectangleShape Player::getBounds() {
	return this->player;
}

void Player::setBounds(float velX, float velY) {
	sf::RectangleShape s(sf::Vector2f(w, h));
	s.setPosition(x, y);
	this->player = s;
}

float Player::getHealth() {
	return this->health;
}

void Player::setHealth(float health) {
	this->health = health;
}

void Player::tick() {
	x += velX;
	y += velY;

	velX = 1.0f;

	x = player.getPosition().x;
	y = player.getPosition().y;

	player.setPosition(bounds(x, 0, 800 - w), bounds(y, 0, 600 - h));
	health = bounds(health, 0, 100);

	keyInput();
}

void Player::draw(sf::RenderWindow &window) {
	window.draw(player);
}

bool Player::getMove() {
	return this->move;
}

void Player::setMove(bool move) {
	this->move = move;
}

void Player::setX(float x) {
	this->x = x;
}

float Player::getX() {
	return this->x;
}

void Player::setY(float y) {
	this->y = y;
}

float Player::getY() {
	return this->y;
}

ID Player::getId() {
	return this->id;
}

void Player::setVelX(float velX) {
	this->velX = velX;
}

float Player::getVelX() {
	return velX;
}

void Player::setVelY(float velY) {
	this->velY = velY;
}

float Player::getVelY() {
	return velY;
}

void Player::setColor(sf::Color color) {
	this->color = color;
}

sf::Color Player::getColor() {
	return color;
}

void Player::movePlayer(float velX, float velY) {
	if (x < 768 && velX > 0) {
		player.move(velX, 0);
	}
	if (x > 0 && velX < 0) {
		player.move(velX, 0);
	}
	if (y < 568 && velY > 0) {
		player.move(0, velY);
	}
	if (y > 0 && velY < 0) {
		player.move(0, velY);
	}
}

void Player::keyInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		movePlayer(-speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		movePlayer(speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		movePlayer(0, -speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		movePlayer(0, speed);
	}
}
