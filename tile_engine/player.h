#pragma once
#include "entity.h"
#include "Levelsystem.h"

class Player : public Entity {
private:
	float _speed;

public:
	void update(double dt) override;
	Player();
	void InitializePosition(sf::Vector2f &pos);
	void render(sf::RenderWindow &window) const override;
	bool Player::validmove(sf::Vector2f &pos) const;
};