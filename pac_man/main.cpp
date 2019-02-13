#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.h"
#include "maths.h"
#include "Levelsystem.h"
#include "player.h"
#include "ghost.h"
#include "system_renderer.h"

using namespace sf;
using namespace std;


const int gameWidth = 800;
const int gameHeight = 600;

EntityManager em;
std::shared_ptr<Player> player;
std::shared_ptr<Ghost> ghost;
std::shared_ptr<Ghost> ghost2;

void Update(float &dt, RenderWindow &window) {

	// Quit Via ESC Key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}

	em.update(dt);
}

void Load(RenderWindow &window) {
	player = std::make_shared<Player>();
	ghost = std::make_shared<Ghost>();
	ghost2 = std::make_shared<Ghost>();
	ghost->setPosition(Vector2f(100.0f, 100.0f));
	em.list.push_back(player);
	em.list.push_back(ghost);
	em.list.push_back(ghost2);
	Renderer::initialise(window);
	em.render();
}

void Render() {
	em.render();
	Renderer::render();
}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "PAC MAN");
	Load(window);
	static sf::Clock clock;
	while (window.isOpen()) {
		float dt = clock.restart().asSeconds();
		window.clear();
		Update(dt, window);
		Render();
		window.display();
	}
	return 0;
}