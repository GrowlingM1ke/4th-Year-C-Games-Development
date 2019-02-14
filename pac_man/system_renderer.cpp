#include "system_renderer.h"
#include <queue>


using namespace sf;


static std::queue<const sf::Drawable *> sprites1234;
static RenderWindow *rw;

void Renderer::initialise(sf::RenderWindow &r) { 
	rw = &r; 
}

sf::RenderWindow &Renderer::getWindow() { return *rw; }

// Won't this cause a memory leak?
void Renderer::shutdown() {
	while (!sprites1234.empty())
		sprites1234.pop();
}

void Renderer::update(const double &) {}

void Renderer::render() {
	static std::queue<int> coolQ;
	if (rw == nullptr) {
		throw("No render window set! ");
	}
	auto a = coolQ.size();
	auto b = sprites1234.size();
	while (!sprites1234.empty()) {
		rw->draw(*sprites1234.front());
		sprites1234.pop();
	}
}

void Renderer::queue(const sf::Drawable *s) { 
	//sprites.push(s); 
}