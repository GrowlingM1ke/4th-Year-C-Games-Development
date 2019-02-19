#include "scene.h"


void Scene::render() { _ents.render(); }

void Scene::update(double dt) {
	_ents.update(dt);
}

std::vector<std::shared_ptr<Entity>> &Scene::getEnts() { return _ents.list; }