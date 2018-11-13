/*
 * HUD.h
 *
 *  Created on: 12 бреб„ 2018
 *      Author: OFIR
 */

#ifndef HUD_H_
#define HUD_H_

#include <SFML/Graphics.hpp>
#include "Player.h"

class HUD {
	public:
		HUD();
		HUD(Player *player);
		virtual ~HUD();
		void tick();
		void draw(sf::RenderWindow &window);
		void init(Player *player);
	private:
		float getHealth();

	public:
	private:
		sf::RectangleShape background;
		sf::RectangleShape outline;
		sf::RectangleShape health;
		sf::Color gray;
		sf::Color healthColor;
		float red;
		Player *player;
};

#endif /* HUD_H_ */
