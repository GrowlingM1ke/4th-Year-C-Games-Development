#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.h"
#include "maths.h"
#include "Levelsystem.h"
#include "player.h"
#include "ghost.h"
#include "system_renderer.h"
#include "pacman.h"

using namespace sf;
using namespace std;

std::shared_ptr<Scene> gameScene;
std::shared_ptr<Scene> menuScene;
std::shared_ptr<Scene> activeScene;

const int gameWidth = 800;
const int gameHeight = 600;

void Update(float &dt, RenderWindow &window) {

	// Quit Via ESC Key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}
	activeScene->update(dt);
}

void Load(RenderWindow &window) {
	gameScene.reset(new GameScene());
	menuScene.reset(new MenuScene());
	gameScene->load();
	menuScene->load();
	// Start at main menu
	activeScene = menuScene;
}

void Render() {
	activeScene->render();
	// flush to screen
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