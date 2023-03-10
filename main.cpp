#include "settings.h"
#include "functions.h"
#include "bat.h"
#include "ball.h"
#include <ctime>

using namespace sf;
int main()
{
	srand(time(0));

	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE
	);
	Bat bat;
	batInit(bat);

	Ball ball;
	ballInit(ball);


	while (window.isOpen()) {
		checkEvents(window);
		updateGame(bat, ball);
		if (ball.shape.getPosition().y >= (WINDOW_HEIGHT - 2 * BALL_RADIUS))
			break;
		checkCollisions(bat, ball);
		drawGame(window, bat, ball);

	}


	return 0;
}
