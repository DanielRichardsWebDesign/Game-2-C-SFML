#pragma once

#include <iostream>
#include <ctime>
#include <vector>

#include "Player.h"
#include "SwagBall.h"

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

	//Display Points variables
	int points;
	sf::Font font;
	sf::Text guiText;

	//Enemy Object Variables
	std::vector<SwagBall> swagBalls;
	float spawnTimerMax;
	float spawnTimer;
	int maxSwagBalls;

	//Private Functions
	void initVariables();
	void initWindow();
	void initFonts();
	void initText();

public:
	//Constructors and Destructors
	Game();
	~Game();

	//Accessors

	//Modifiers

	//Public Functions
	const bool running() const;
	void pollEvents();

	void spawnSwagBalls();
	void updateCollision();
	void update();

	void renderGui(sf::RenderTarget* target);
	void render();
};

