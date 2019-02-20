#pragma once
#include <ecm.h>
#include "cmp_actor_movement.h"
#include <SFML/Graphics.hpp>

class PlayerMovementComponent : public ActorMovementComponent {
public:
	void update(double dt) override;
};