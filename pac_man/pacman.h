#include <memory>
#include "player.h"
#include "ghost.h"
#include "system_renderer.h"
#include "scene.h"
#include "ecm.h"
#include "cmp_sprite.h"

extern std::shared_ptr<Scene> gameScene;
extern std::shared_ptr<Scene> menuScene;
extern std::shared_ptr<Scene> activeScene;

class MenuScene : public Scene {
private:
	sf::Text text;
	sf::Font _font;

public:
	MenuScene();
	void update(double dt) override;
	void render() override;
	void load()override;
};

class GameScene : public Scene {
private:
	sf::Text text;
	sf::Clock scoreClock;
	void respawn();

public:
	GameScene() = default;
	void update(double dt) override;
	void render()override;
	void load()override;
};