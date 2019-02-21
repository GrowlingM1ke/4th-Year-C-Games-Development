#pragma once
#include <ecm.h>
#include "cmp_actor_movement.h"
#include <SFML/Graphics.hpp>

class PlayerMovementComponent : public ActorMovementComponent {
public:
	explicit PlayerMovementComponent(Entity* p);
	PlayerMovementComponent() = delete;
	void update(double dt) override;
};