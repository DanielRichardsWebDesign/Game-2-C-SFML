#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

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
	sf::Text endGameText;

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
	const bool& getEndGame() const;

	//Modifiers

	//Public Functions
	const bool running() const;
	void pollEvents();

	void spawnSwagBalls();
	const int randBallType() const;
	void updatePlayer();
	void updateCollision();
	void updateGui();	
	void update();

	void renderGui(sf::RenderTarget* target);
	void render();
};

