#include "Game.h"
#include <random>
#include <time.h>
#include <chrono>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");
	Game game(window);
	return 0;
}
