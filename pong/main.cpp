#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const Keyboard::Key controls[4] = {
	Keyboard::A,   // Player1 UP
	Keyboard::Z,   // Player1 Down
	Keyboard::Up,  // Player2 UP
	Keyboard::Down // Player2 Down
};
const Vector2f paddleSize(25.f, 100.f);
const float ballRadius = 10.f;
const int gameWidth = 800;
const int gameHeight = 600;
const float paddleSpeed = 400.f;

Vector2f ballVelocity;
bool server = false;
bool aiEnabled = false;

CircleShape ball;
RectangleShape paddles[2];
Font font;
Text text;
int player1Score = 0;
int player2Score = 0;

void Load() {
	// Set size and origin of paddles
	for (auto &p : paddles) {
		p.setSize(paddleSize - Vector2f(3, 3));
		p.setOrigin(paddleSize / 2.f);
	}
	// Set size and origin of ball
	ball.setRadius(ballRadius - 3);
	ball.setOrigin(ballRadius / 2, ballRadius / 2);
	// reset paddle position
	paddles[0].setPosition(10 + paddleSize.x / 2, gameHeight / 2);
	paddles[1].setPosition(gameWidth - 10 - paddleSize.x / 2, gameHeight / 2);
	// reset Ball Position
	ball.setPosition(gameWidth / 2, gameHeight / 2);
	ballVelocity = { (server ? 100.0f : -100.0f), 60.0f };

	// Load font-face from res dir
	font.loadFromFile("res/fonts/RobotoMono-Regular.ttf");
	// Set text element to use font
	text.setFont(font);
	// set the character size to 24 pixels
	text.setCharacterSize(24);

	// Update Score Text
	text.setString(to_string(player1Score) + " : " + to_string(player2Score));
	// Keep Score Text Centered
	text.setPosition((gameWidth * .5f) - (text.getLocalBounds().width * .5f), 0);
}

void reset() {
	// reset paddle position
	paddles[0].setPosition(10 + paddleSize.x / 2, gameHeight / 2);
	paddles[1].setPosition(gameWidth - 10 - paddleSize.x / 2, gameHeight / 2);
	// reset Ball Position
	ball.setPosition(gameWidth / 2, gameHeight / 2);
	ballVelocity = { (server ? 100.0f : -100.0f), 60.0f };

	// Update Score Text
	text.setString(to_string(player1Score) + " : " + to_string(player2Score));
	// Keep Score Text Centered
	text.setPosition((gameWidth * .5f) - (text.getLocalBounds().width * .5f), 0);
}

void Update(RenderWindow &window) {
	// Reset clock, recalculate deltatime
	static Clock clock;
	float dt = clock.restart().asSeconds();
	// check and consume events
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
			return;
		}
	}

	// Quit Via ESC Key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}

	// handle paddle1 movement
	float direction = 0.0f;
	if (Keyboard::isKeyPressed(controls[0]) && (paddles[0].getPosition().y > paddleSize.y / 2)) {
		direction--;
	}
	if (Keyboard::isKeyPressed(controls[1]) && (paddles[0].getPosition().y < (gameHeight - paddleSize.y / 2))) {
		direction++;
	}
	paddles[0].move(0, direction * paddleSpeed * dt);

	// handle paddle2 movement
	float direction2 = 0.0f;
	if (aiEnabled) {
		if (ball.getPosition().y > paddles[1].getPosition().y && (paddles[1].getPosition().y < (gameHeight - paddleSize.y / 2)))
			direction2++;
		if (ball.getPosition().y < paddles[1].getPosition().y && (paddles[1].getPosition().y > paddleSize.y / 2))
			direction2--;
	}
	else {
		if (Keyboard::isKeyPressed(controls[2]) && (paddles[1].getPosition().y > paddleSize.y / 2)) {
			direction2--;
		}
		if (Keyboard::isKeyPressed(controls[3]) && (paddles[1].getPosition().y < (gameHeight - paddleSize.y / 2))) {
			direction2++;
		}
	}
	paddles[1].move(0, direction2 * paddleSpeed * dt);

	// ball collision
	const float bx = ball.getPosition().x;
	const float by = ball.getPosition().y;
	if (by > gameHeight) { //bottom wall
	  // bottom wall
		ballVelocity.x *= 1.1f;
		ballVelocity.y *= -1.1f;
		ball.move(0, -10);
	}
	else if (by < 0) { //top wall
   // top wall
		ballVelocity.x *= 1.1f;
		ballVelocity.y *= -1.1f;
		ball.move(0, 10);
	}

	else if (bx > gameWidth) {
		// right wall
		server = false;
		player1Score++;
		reset();
	}
	else if (bx < 0) {
		// left wall
		server = true;
		player2Score++;
		reset();
	}
	else if (bx < paddleSize.x + 10 && by > paddles[0].getPosition().y - (paddleSize.y * 0.5) &&	by < paddles[0].getPosition().y + (paddleSize.y * 0.5)) {
		ballVelocity.x *= -1.1f;
	}
	else if (bx > gameWidth - 10 - paddleSize.x && by > paddles[1].getPosition().y - (paddleSize.y * 0.5) && by < paddles[1].getPosition().y + (paddleSize.y * 0.5)) {
		ballVelocity.x *= -1.1f;
	}

	// ball movement
	ball.move(ballVelocity * dt);
}

void Render(RenderWindow &window) {
	// Draw Everything
	window.draw(paddles[0]);
	window.draw(paddles[1]);
	window.draw(ball);
	window.draw(text);
}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "PONG");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}