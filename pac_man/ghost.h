#pragma once
#include "entity.h"

class Ghost : public Entity {
private:
	float _speed;
	float _time;
	float value = 0.0f;

public:
	void update(double dt) override;
	Ghost();
	void InitializePosition(sf::Vector2f &pos);
	void render(sf::RenderWindow &window) const override;
};