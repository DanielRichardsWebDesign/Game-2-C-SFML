#pragma once

#include <iostream>
#include <ctime>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"


class Game
{
private:	
	//Variables
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;

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
	void update();
	void render();
};

