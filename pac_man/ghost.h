#pragma once
#include "ecm.h"

class Ghost : public Entity {
private:
	float _speed;
	float _time;
	float value = 0.0f;

public:
	void update(double dt) override;
	Ghost();
	void InitializePosition(sf::Vector2f &pos);
	//void render() const override;
};