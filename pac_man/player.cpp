#include "player.h"
#include "system_renderer.h"
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
	if (Keyboard::isKeyPressed(controls[0]))// && validmove(getPosition() + Vector2f(100.0f * dt, 0.0f)))
		move(Vector2f(_speed * dt, 0.0f));
	if (Keyboard::isKeyPressed(controls[1]))// && validmove(getPosition() + Vector2f(-100.0f * dt, 0.0f)))
		move(Vector2f(-_speed * dt, 0.0f));
	if (Keyboard::isKeyPressed(controls[2]))// && validmove(getPosition() + Vector2f(0.0f, 100.0f * dt)))
		move(Vector2f(0.0f, _speed * dt));
	if (Keyboard::isKeyPressed(controls[3]))// && validmove(getPosition() + Vector2f(0.0f, -100.0f * dt)))
		move(Vector2f(0.0f, -_speed * dt));

	Entity::update(dt);
}

Player::Player() : _speed(300.0f), Entity(make_unique<CircleShape>(14.f)) {
	_shape->setFillColor(Color::Yellow);
	_shape->setOrigin(Vector2f(20.0f, 20.0f));
}

void Player::InitializePosition(Vector2f &pos) {
	setPosition(pos + Vector2f(35.0f, 35.0f));
}

void Player::render() const {
	Renderer::queue(_shape.get());
}