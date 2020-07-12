#pragma once

#include <iostream>
#include <ctime>

#include "Player.h"

class Game
{
private:	
	//Variables
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	//Player Object
	Player player;

	//Private Functions
	void initVariables();
	void initWindow();

public:
	//Constructors and Destructors
	Game();
	~Game();

	//Accessors

	//Modifiers

	//Public Functions
	const bool running() const;
	void pollEvents();

	void update();
	void render();
};

