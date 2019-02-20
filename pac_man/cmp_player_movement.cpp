#pragma once
#include "cmp_player_movement.h"


using namespace sf;
using namespace std;

const Keyboard::Key controls[4] = {
	Keyboard::Right,
	Keyboard::Left,
	Keyboard::Down,
	Keyboard::Up
};

void PlayerMovementComponent::update(double dt) {

	//Move in four directions based on keys
	if (Keyboard::isKeyPressed(controls[0]))
		move(Vector2f(_speed * dt, 0.0f));
	if (Keyboard::isKeyPressed(controls[1]))
		move(Vector2f(-_speed * dt, 0.0f));
	if (Keyboard::isKeyPressed(controls[2]))
		move(Vector2f(0.0f, _speed * dt));
	if (Keyboard::isKeyPressed(controls[3]))
		move(Vector2f(0.0f, -_speed * dt));
}
