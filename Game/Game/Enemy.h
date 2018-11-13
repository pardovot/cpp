/*
 * Enemy.h
 *
 *  Created on: 11 бреб„ 2018
 *      Author: OFIR
 */

#ifndef ENEMY_H_
#define ENEMY_H_

#include "Entity.h"

class Enemy: public Entity {
private:
	sf::RectangleShape enemy;
	int w;
	int h;
	float speed = 1.0f;
	void bounceEnemy();
public:
	Enemy();
	virtual ~Enemy() override;
	sf::RectangleShape getBounds() override;
	void tick() override;
	void setX(float x) override;
	float getX() override;
	void setY(float y) override;
	float getY() override;
	ID getId() override;
	void setVelX(float velX) override;
	float getVelX() override;
	void setVelY(float velY) override;
	float getVelY() override;
	void setColor(sf::Color color) override;
	sf::Color getColor() override;
	void draw(sf::RenderWindow &window) override;
};

#endif /* ENEMY_H_ */
