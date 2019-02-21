#include "cmp_ghost_ai.h"

using namespace std;
using namespace sf;

static const Vector2i directions[] = { {1, 0}, {0, 1}, {0, -1}, {-1, 0} };

GhostAIComponent::GhostAIComponent(Entity * p) : ActorMovementComponent(p) {}

void GhostAIComponent::update(double dt) {
	//amount to move
	const auto mva = (float)(dt * _speed);
	//Curent position
	const Vector2f pos = _parent->getPosition();
	//Next position
	const Vector2f newpos = pos + _direction * mva;
	//Inverse of our current direction
	const Vector2i baddir = -1 * Vector2i(_direction);
	//Random new direction
	Vector2i newdir = directions[(rand() % 4)];

	switch (_state) {
	case ROAMING:
		if (LevelSystem::getTileAt(pos) == LevelSystem::WAYPOINT || LevelSystem::getTileAt(newpos) == LevelSystem::WALL) // Wall in front or at waypoint
		{
			_state = ROTATING; // start rotate
		}
		else {
			move(_direction * mva); //keep moving
		}
		break;

	case ROTATING:
		while (newdir == baddir || ls::getTileAt(pos + (Vector2f(newdir)*25.0f)) == ls::WALL) {
			newdir = directions[(rand() % 4)];
		}
		_direction = Vector2f(newdir);
		_state = ROTATED;
		break;

	case ROTATED:
		//have we left the waypoint?
		if (LevelSystem::getTileAt(pos) != LevelSystem::WAYPOINT) {
			_state = ROAMING; //yes
		}
		move(_direction * mva); //No
		break;
	}
	ActorMovementComponent::update(dt);
}