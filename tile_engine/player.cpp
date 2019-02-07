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
	if (Keyboard::isKeyPressed(controls[0]) && validmove(getPosition() + Vector2f(100.0f * dt, 0.0f)))
		move(Vector2f(100.0f * dt, 0.0f));
	if (Keyboard::isKeyPressed(controls[1]) && validmove(getPosition() + Vector2f(-100.0f * dt, 0.0f)))
		move(Vector2f(-100.0f * dt, 0.0f));
	if (Keyboard::isKeyPressed(controls[2]) && validmove(getPosition() + Vector2f(0.0f, 100.0f * dt)))
		move(Vector2f(0.0f, 100.0f * dt));
	if (Keyboard::isKeyPressed(controls[3]) && validmove(getPosition() + Vector2f(0.0f, -100.0f * dt)))
		move(Vector2f(0.0f, -100.0f * dt));

	Entity::update(dt);
}

Player::Player() : _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) {
	_shape->setFillColor(Color::Magenta);
	_shape->setOrigin(Vector2f(25.f, 60.0f));
}

void Player::InitializePosition(Vector2f &pos) {
	setPosition(pos + Vector2f(35.0f, 35.0f));
}

void Player::render(sf::RenderWindow &window) const {
	window.draw(*_shape);
}

bool Player::validmove(Vector2f &pos) const {
	return (ls::getTileAt(pos) != ls::WALL);
}