/*
 * Game.h
 *
 *  Created on: 12 бреб„ 2018
 *      Author: OFIR
 */

#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "HUD.h"
#include <list>
#include "GameObjects.h"
#include "SmartEnemy.h"

class Game {
public:
	Game(sf::RenderWindow &window);
	virtual ~Game();
	void gameLoop();
	bool collision(sf::RectangleShape A, sf::RectangleShape B);
	void callEvents(sf::RenderWindow &window);
	void display(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);
	void tick();
	void collisionLoop();
	void enemyHit();
private:
	void init();

public:

private:
	sf::RenderWindow &window;
	Player *player;
	Enemy *enemy;
	SmartEnemy *smartEnemy;
	GameObjects objects;
	HUD hud;

	enum gameState {
		menu, game, gameOver, 
	};
};

#endif /* GAME_H_ */
