#pragma once
#include <SFML/Graphics.hpp>

class Ship : public sf::Sprite {
protected:
	sf::IntRect _sprite;
	Ship();
	bool _exploded;
	float _explosiontime = 0.4f;

public:
	explicit Ship(sf::IntRect ir);
	virtual ~Ship() = 0;
	virtual void Update(const float &dt);
	bool is_exploded() const;
	virtual void Explode();
};

class Invader : public Ship {
public:
	Invader(sf::IntRect ir, sf::Vector2f pos);
	Invader();
	void Update(const float &dt) override;
	static bool direction;
	static float speed;
};

class Player : public Ship {
public:
	Player();
	void Update(const float &dt) override;
};