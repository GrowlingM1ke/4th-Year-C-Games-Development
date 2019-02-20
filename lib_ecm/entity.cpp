/* 
#include "entity.h"
//#include "Levelsystem.h"
using namespace std;
using namespace sf;

const Vector2f Entity::getPosition() { return _position; }

void Entity::setPosition(const Vector2f &pos) { _position = pos; }

void Entity::move(const Vector2f &pos) { _position += pos; }

void Entity::update(const double dt) {
	_shape->setPosition(_position);
}


bool Entity::validmove(sf::Vector2f &pos) const {
	return (ls::getTileAt(pos) != ls::WALL);
}


Entity::Entity(unique_ptr<Shape> s) : _shape(std::move(s)) {}

void EntityManager::update(const float dt) {
	for (auto &e : list) {
		e->update(dt);
	}
}

void EntityManager::render() {
	for (auto& e : list) {
			e->render();
	}
}
*/