#include "player.h"
using namespace sf;
using namespace std;


const Keyboard::Key controls[4] = {
	Keyboard::Right,
	Keyboard::Left,
	Keyboard::Down,
	Keyboard::Up
};

void Player::update(double dt) {
	//Move in four directions based on keys
	if (Keyboard::isKeyPressed(controls[0]))
		move(Vector2f(10.0f * dt, 0.0f));
	if (Keyboard::isKeyPressed(controls[1]))
		move(Vector2f(-10.0f * dt, 0.0f));
	if (Keyboard::isKeyPressed(controls[2]))
		move(Vector2f(0.0f, 10.0f * dt));
	if (Keyboard::isKeyPressed(controls[3]))
		move(Vector2f(0.0f, -10.0f * dt));

	Entity::update(dt);
}

Player::Player() : _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) {
	_shape->setFillColor(Color::Magenta);
	_shape->setOrigin(Vector2f(25.f, 25.f));
}

void Player::render(sf::RenderWindow &window) const {
	window.draw(*_shape);
}