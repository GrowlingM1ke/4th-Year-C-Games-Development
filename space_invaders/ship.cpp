#include "ship.h"
#include "game.h"
#include "bullet.h"

using namespace sf;
using namespace std;

const Keyboard::Key controls[3] = {
	Keyboard::Right,
	Keyboard::Left,
	Keyboard::Space
};

Ship::Ship()
{
}

Ship::Ship(IntRect ir) : Sprite() {
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
	_exploded = false;
	float explodeTime = 0.5f;
}

void Ship::Update(const float &dt) {
	if (_exploded) {
		_explosiontime -= dt;
	}
	if (_explosiontime <= 0.f) {
		setColor(Color(0, 0, 0, 0));
	}
}

Ship::~Ship() = default;

bool Ship::is_exploded() const {
	return _exploded;
}

Invader::Invader() : Ship() {}

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
	setOrigin(16, 16);
	setPosition(pos);
}

bool Invader::direction;
float Invader::speed;

void Invader::Update(const float &dt) {
	Ship::Update(dt);
	static float firetime = 0.0f;
	firetime -= dt;

	move(dt * (direction ? 1.0f : -1.0f) * speed, 0);
	if ((direction && getPosition().x > gameWidth - 16) ||
		(!direction && getPosition().x < 16)) {
		direction = !direction;
		for (int i = 0; i < ships.size() - 1; ++i) {
			ships[i]->move(0, 24);
		}
	}

	if (firetime <= 0 && rand() % 100 == 0) {
		Bullet::Fire(getPosition(), true);
		firetime = 4.0f + (rand() % 60);
	}
}

//ship.cpp
Player::Player() : Ship(IntRect(160, 32, 32, 32)) {
	setPosition({ gameHeight * .5f, gameHeight - 32.f });
}

void Player::Update(const float &dt) {
	Ship::Update(dt);
	

	//Move left and right and shoot
	float direction = 0.0f;
	if (Keyboard::isKeyPressed(controls[0]) && getPosition().x < gameWidth - 32)
		direction += 100.0f;
	if (Keyboard::isKeyPressed(controls[1]) &&  getPosition().x > 0)
		direction -= 100.0f;

	move(direction * dt, 0.0f);

	static float firetime = 0.0f;
	firetime -= dt;
	if (firetime <= 0 && Keyboard::isKeyPressed(controls[2])) {
		Bullet::Fire(getPosition(), false);
		firetime = 0.7f;
	}
}
