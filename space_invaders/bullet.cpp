#include "bullet.h"
#include "game.h"
using namespace sf;
using namespace std;

//Create definition for the constructor
Bullet::Bullet(const sf::Vector2f &pos, const bool mode) {
	_mode = mode;
	setPosition(pos);
}

void Bullet::Update(const float &dt) {
	move(0, dt * 200.0f * (_mode ? 1.0f : -1.0f));
}
