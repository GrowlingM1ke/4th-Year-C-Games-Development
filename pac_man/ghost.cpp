#include "ghost.h"
#include "system_renderer.h"

using namespace sf;
using namespace std;


void Ghost::update(double dt) {
	_time += dt;
	if (_time > 2.0f) {
		value = ((double)rand() / (RAND_MAX));
		_time = 0;
	}

	if (value < 0.25f)
		move(Vector2f(_speed * dt, 0.0f));
	else if (value < 0.5f)
		move(Vector2f(-_speed * dt, 0.0f));
	else if (value < 0.75f)
		move(Vector2f(0.0f, _speed * dt));
	else if (value < 1.0f)
		move(Vector2f(0.0f, -_speed * dt));

	Entity::update(dt);
}

Ghost::Ghost() : _speed(100.0f), Entity(make_unique<CircleShape>(10.f)), _time(0.0f) {
	_shape->setFillColor(Color::Blue);
	_shape->setOrigin(Vector2f(25.f, 60.0f));
}

void Ghost::InitializePosition(Vector2f &pos) {
	setPosition(pos + Vector2f(35.0f, 35.0f));
}

void Ghost::render() const {
	Renderer::queue(_shape.get());
}