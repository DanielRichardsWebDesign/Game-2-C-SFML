#include "Game.h"

int main()
{
	//Initialise Random Seed
	srand(static_cast<unsigned>(time(0)));

	//Initialise Game Object
	Game game;

	//Game Loop
	while (game.running())
	{
		game.update();
		game.render();
	}

	return 0;
}