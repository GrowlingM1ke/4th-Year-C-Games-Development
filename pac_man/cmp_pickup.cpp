#include "cmp_pickup.h"
#include "pacman.h"
#include <maths.h>
#include <SFML/Graphics.hpp>
#include "cmp_actor_movement.h"

using namespace std;
using namespace sf;

void PickupComponent::update(double) {
	for (const auto &ents : activeScene->getEnts()) {
		if (length(ents->getPosition() - _parent->getPosition()) < 30.0f) {
			auto cmpts = ents->GetCompatibleComponent<ActorMovementComponent>();
			if (!cmpts.empty()) {
					cmpts[0]->setSpeed(cmpts[0]->getSpeed() * 1.01f);
					_parent->setForDelete();
					break;
				}
		}
	}
}

PickupComponent::PickupComponent(Entity * p, bool big) : Component(p), _big(big) {}