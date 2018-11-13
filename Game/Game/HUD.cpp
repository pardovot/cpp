/*
 * HUD.cpp
 *
 *  Created on: 12 бреб„ 2018
 *      Author: OFIR
 */

#include "HUD.h"

HUD::HUD(Player *player) {
	this->player = player;
	this->gray = sf::Color(128, 128, 128, 255);
	this->healthColor = sf::Color(255 - getHealth() * 2.55, 255, 0, 255);
	this->background = sf::RectangleShape(sf::Vector2f(350, 40));
	this->background.setPosition(225, 5);
	this->background.setFillColor(gray);
	this->outline = sf::RectangleShape(sf::Vector2f(352, 42));
	this->outline.setPosition(224, 4);
	this->outline.setFillColor(sf::Color::White);
	this->health = sf::RectangleShape(sf::Vector2f(player->getHealth() * 3.5, 40));
	this->health.setPosition(225, 5);
	this->health.setFillColor(healthColor);
	this->red = 255 - getHealth() * 2.55;
}

void HUD::init(Player *player) {
	this->player = player;
	this->gray = sf::Color(128, 128, 128, 255);
	this->healthColor = sf::Color(255 - getHealth() * 2.55, 255, 0, 255);
	this->background = sf::RectangleShape(sf::Vector2f(350, 40));
	this->background.setPosition(225, 5);
	this->background.setFillColor(gray);
	this->outline = sf::RectangleShape(sf::Vector2f(352, 42));
	this->outline.setPosition(224, 4);
	this->outline.setFillColor(sf::Color::White);
	this->health = sf::RectangleShape(sf::Vector2f(player->getHealth() * 3.5, 40));
	this->health.setPosition(225, 5);
	this->health.setFillColor(healthColor);
	this->red = 255 - getHealth() * 2.55;
}

HUD::HUD() {

}

HUD::~HUD() {

}

float HUD::getHealth() {
	return this->player->getHealth();
}

void HUD::tick() {
	red = 255 - player->getHealth() * 2.55;
	healthColor = sf::Color(255 - getHealth() * 2.55, 255 - red, 0, 255);
	health.setSize(sf::Vector2f(player->getHealth() * 3.5, 40));
	health.setFillColor(healthColor);
}

void HUD::draw(sf::RenderWindow &window) {
	window.draw(outline);
	window.draw(background);
	window.draw(health);
}

