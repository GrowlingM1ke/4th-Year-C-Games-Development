#include "cmp_ghost_movement.h"
#include <SFML/Graphics.hpp>

using namespace sf;


GhostMovementComponent::GhostMovementComponent(Entity * p) : ActorMovementComponent(p) {}

void GhostMovementComponent::update(double dt)
{
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

}
