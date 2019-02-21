#include "ecm.h"

Entity::Entity()
{
}

void Entity::render()
{
	for (auto &e : _components) {
		e->render();
	}
}

const sf::Vector2f & Entity::getPosition() const
{
	return _position;
}

bool Entity::is_fordeletion() const
{
	return _fordeletion;
}

float Entity::getRotation() const
{
	return 0.0f;
}

void Entity::setRotation(float rotation)
{
	_rotation = rotation;
}

bool Entity::isAlive() const
{
	return _alive;
}

void Entity::setAlive(bool alive)
{
	_alive = alive;
}

void Entity::setForDelete()
{
}

bool Entity::isVisible() const
{
	return _visible;
}

void Entity::setVisible(bool visible)
{
	_visible = visible;
}

Component::Component(Entity *const p) : _parent(p), _fordeletion(false) {}

bool Component::is_fordeletion() const
{
	return false;
}

Component::~Component()
{
}

void EntityManager::render() {
	for (auto& e : list) {
		e->render();
	}
}

void EntityManager::update(const float dt) {
	for (auto &e : list) {
		e->update(dt);
	}
}

void Entity::update(const double dt) {
	for (auto &e : _components) {
		e->update(dt);
	}
}