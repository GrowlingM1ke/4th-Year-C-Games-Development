#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.h"
#include "player.h"

using namespace sf;
using namespace std;


const int gameWidth = 800;
const int gameHeight = 600;

std::vector<Entity *> entities;;
Player* player;

void Update(float &dt, RenderWindow &window) {

	// Quit Via ESC Key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}

	for (auto &e : entities) {
		e->update(dt);
	}
}

void Load() {
	player = new Player;
	entities.push_back(player);
}

void Render(RenderWindow &window) {
	for (auto &e : entities) {
		e->render(window);
	}
}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "TILE ENGINE");
	Load();
	static sf::Clock clock;
	while (window.isOpen()) {
		float dt = clock.restart().asSeconds();
		window.clear();
		Update(dt, window);
		Render(window);
		window.display();
	}
	return 0;
}