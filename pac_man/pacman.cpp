#include "pacman.h"
#include <sstream>
#include "player.h"
#include "ghost.h"

using namespace sf;
using namespace std;

MenuScene::MenuScene()
{
}

void MenuScene::update(double dt) {
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		activeScene = gameScene;
	}
}

void MenuScene::render() {
	Renderer::queue(&text);
	Scene::render();
}

void MenuScene::load() {
	_font.loadFromFile("res/fonts/RobotoMono-Regular.ttf");
	text.setFont(_font);
	text.setCharacterSize(24);
	text.setString("Almost Pacman");
	text.setPosition((800 * 0.5f) - (text.getLocalBounds().width * 0.5f), 0);
}

void GameScene::respawn()
{

}

void GameScene::update(double dt) {
	if (Keyboard::isKeyPressed(Keyboard::Tab)) {
		activeScene = menuScene;
	}
}

void GameScene::render() {
	//ls::render(Renderer::getWindow());
	_ents.render();
	Scene::render();
}

void GameScene::load() {

	std::shared_ptr<Player> player = std::make_shared<Player>();
	ls::loadLevelFile("assets/levels/pacman.txt", 25.0f);
	//player->setPosition(ls::getTilePosition(ls::findTiles(ls::START)[0]));
	_ents.list.push_back(player);

	for (int i = 0; i < 4; i++) {
		std::shared_ptr<Ghost> ghost = std::make_shared<Ghost>();
		_ents.list.push_back(ghost);
	}
}