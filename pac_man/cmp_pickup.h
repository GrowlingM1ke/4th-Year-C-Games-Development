#pragma once
#include "ecm.h"

class PickupComponent : public Component {
private:
	bool _big;
public:
	void update(double dt) override;
	explicit PickupComponent(Entity * p, bool big);
	PickupComponent() = delete;
	void render()  override {};
};