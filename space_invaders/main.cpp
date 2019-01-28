#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"
#include "bullet.h"

using namespace sf;
using namespace std;


const int gameWidth = 800;
const int gameHeight = 600;

Texture spritesheet;
std::vector<Ship *> ships;

void Update(float &dt, RenderWindow &window) {
	for (auto &s : ships) {
		s->Update(dt);
	}

	// Quit Via ESC Key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}

	Bullet::Update(dt);
}

void Load() {
	if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
		cerr << "Failed to load spritesheet!" << endl;
	}

	for (int r = 0; r < 5; ++r) {
		auto rect = IntRect(0, 0, 32, 32);
		for (int c = 0; c < 12; ++c) {
			Vector2f position = { 60.0f * (c + 1), 50.0f * (r + 1)};
			auto inv = new Invader(rect, position);
			ships.push_back(inv);
		}
	}
	Invader::speed = 20;

	auto def = new Player();
	ships.push_back(def);
}

void Render(RenderWindow &window) {
	for (const auto s : ships) {
		window.draw(*s);
	}
	Bullet::Render(window);
}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "SPACE INVADERS");
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