#pragma once
#include "cmp_actor_movement.h"
#include <SFML/Graphics.hpp>

class GhostAIComponent : public ActorMovementComponent {
protected:
	sf::Vector2f _direction;
	enum state { ROAMING, ROTATING, ROTATED };
	state _state = ROTATING;

public:
	explicit GhostAIComponent(Entity* p);
	GhostAIComponent() = delete;
	void update(double dt) override;
};