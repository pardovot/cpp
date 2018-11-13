/*
 * Player.h
 *
 *  Created on: 7 бреб„ 2018
 *      Author: OFIR
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Entity.h"

class Player : public Entity {
private:
	bool move;
	sf::RectangleShape player;
	int w;
	int h;
	float health = 100;
	float speed = 2.0f;
public:
	Player();
	virtual ~Player();
	void tick() override;
	void draw(sf::RenderWindow &window) override;
	void setX(float x) override;
	void setY(float y) override;
	void setVelX(float velX) override;
	void setVelY(float velY) override;
	void setColor(sf::Color color) override;
	void setW(int w);
	void setMove(bool move);
	void movePlayer(float velX, float velY);
	void setHealth(float health);

	float getX() override;
	float getY() override;
	float getVelX() override;
	float getVelY() override;
	int getW();
	float getHealth();

	void keyInput();
	bool getMove();
	virtual ID getId() override;
	sf::RectangleShape getBounds() override;
	void setBounds(float velX, float velY);
	sf::Color getColor() override;
};

#endif /* PLAYER_H_ */
