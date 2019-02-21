#pragma once
#include <ecm.h>
#include "cmp_actor_movement.h"
#include <SFML/Graphics.hpp>

class GhostMovementComponent : public ActorMovementComponent {
private:
	float _time;
	float value;
public:
	void update(double dt) override;
	explicit GhostMovementComponent(Entity * p);
	GhostMovementComponent() = delete;
};