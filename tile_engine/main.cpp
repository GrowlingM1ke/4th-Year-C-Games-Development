#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.h"
#include "player.h"

using namespace sf;
using namespace std;


const int gameWidth = 800;
const int gameHeight = 600;

void Update(float &dt, RenderWindow &window) {

	// Quit Via ESC Key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}
}

void Load() {

}

void Render(RenderWindow &window) {
	
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