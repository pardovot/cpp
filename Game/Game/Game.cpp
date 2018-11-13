#include "Game.h"

Game::Game(sf::RenderWindow &window) :
	window(window) {
	init();
	gameLoop();
}

Game::~Game() {

}

void Game::init() {
	this->enemy = new Enemy;
	this->player = new Player;
	this->smartEnemy = new SmartEnemy(player);
	this->hud.init(player);
	objects.addObject(player);
	for (int i = 0; i < 5; i++) {
		Enemy *enemy = new Enemy;
		objects.addObject(enemy);
	}
	objects.addObject(enemy);
	objects.addObject(smartEnemy);
}

void Game::gameLoop() {
	window.setFramerateLimit(144);
	while (window.isOpen()) {

		window.clear();
		collisionLoop();
		update(window);
		window.display();

		callEvents(window);
	}
}

void Game::display(sf::RenderWindow &window) {
	objects.draw(window);
	hud.draw(window);
}

void Game::tick() {
	objects.tick();
	hud.tick();
}

void Game::update(sf::RenderWindow &window) {
	display(window);
	tick();
}

void Game::callEvents(sf::RenderWindow &window) {
	sf::Event evnt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		for (auto object : objects.getObjects()) {
			objects.removeObject(object);
		}
		window.close();
	}
	while (window.pollEvent(evnt)) {
		if (evnt.type == sf::Event::Closed) {
			for (auto object : objects.getObjects()) {
				objects.removeObject(object);
			}
			window.close();
		}
	}
}

void Game::enemyHit() {
	player->setHealth(player->getHealth() - 0.3f);
}

void Game::collisionLoop() {
	for (auto object : objects.getObjects()) {
		if (object->getId() == ID::enemy) {
			if (collision(object->getBounds(), player->getBounds())) {
				enemyHit();
			}
		}
	}
}

bool Game::collision(sf::RectangleShape A, sf::RectangleShape B) {
	bool xCollision = (A.getPosition().x >= B.getPosition().x && A.getPosition().x <= B.getPosition().x + B.getSize().x)
		|| (B.getPosition().x >= A.getPosition().x && B.getPosition().x <= A.getPosition().x + A.getSize().x);

	bool yCollision = (A.getPosition().y >= B.getPosition().y && A.getPosition().y <= B.getPosition().y + B.getSize().y)
		|| (B.getPosition().y >= A.getPosition().y && B.getPosition().y <= A.getPosition().y + A.getSize().y);

	return xCollision && yCollision;
}
