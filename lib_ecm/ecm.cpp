#include "ecm.h"

Entity::Entity() : _alive(true), _visible(true), _fordeletion(false) {}

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
	_fordeletion = true;
	_alive = false;
	_visible = false;
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

Component::~Component() {}

void EntityManager::render() {
	for (auto& e : list) {
		if (e->isVisible())
			e->render();
	}
}

void EntityManager::update(const float dt) {
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->is_fordeletion()) {
			list.erase(list.begin() + i);
			continue;
		}
		else if (list[i]->isAlive()) {
			list[i]->update(dt);
		}
	}
}

void Entity::update(const double dt) {
	for (auto &e : _components) {
		e->update(dt);
	}
}

Entity::~Entity() {
	int compNum = 0;	//Current Component Size(basically)
	while (compNum != _components.size())
	{
		compNum = _components.size();
		_components.erase(remove_if(_components.begin(), _components.end(),	[](auto &current) { return (current.use_count() <= 1); }), _components.end());
	}

	if (_components.size() > 0) {
		throw std::runtime_error(
			"Can't delete entity, components being used somewhere");
	}

	_components.clear();

}