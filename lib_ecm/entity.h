/*
#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
//#include "system_renderer.h"

class Entity {
protected:
	std::unique_ptr<sf::Shape> _shape;
	sf::Vector2f _position;
	Entity(std::unique_ptr<sf::Shape> shp);

public:
	Entity() = delete;
	virtual ~Entity() = default;

	virtual void update(const double dt) ;
	//bool validmove(sf::Vector2f &pos) const;
	// const means that I can't change any other variable or function within this class
	// I can't call any other functions that aren't const
	// if it's = 0 then it's purely virtually and a Entity class can't instantiate this function
	virtual void render() const = 0;

	const sf::Vector2f getPosition();
	// I'm not going to change the pos a.k.a the variable being passed thorugh because of const
	void setPosition(const sf::Vector2f &pos);
	void move(const sf::Vector2f &pos);
};

struct EntityManager {
	std::vector<std::shared_ptr<Entity>> list;
	void update(const float dt);
	void render();
};
*/