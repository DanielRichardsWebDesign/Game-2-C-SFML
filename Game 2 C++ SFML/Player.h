#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class Player
{
private:
	//Variables
	sf::RectangleShape shape;

	//Private Functions
	void initVariables();
	void initShape();

public:
	Player();
	virtual ~Player();

	void update();
	void render(sf::RenderTarget* target);
};

