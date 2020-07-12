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

	float movementSpeed;

	//Private Functions
	void initVariables();
	void initShape();

public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	void updateInput();
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);

	void render(sf::RenderTarget* target);
};

