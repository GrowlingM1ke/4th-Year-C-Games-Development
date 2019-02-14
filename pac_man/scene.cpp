#include "scene.h"


void Scene::render() { _ents.render(); }

std::vector<std::shared_ptr<Entity>> &Scene::getEnts() { return _ents.list; }