#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class SwagBall
{
private:
	//Variables
	sf::CircleShape shape;

	void initShape(const sf::RenderWindow& window);

public:
	SwagBall(const sf::RenderWindow& window);
	virtual ~SwagBall();

	const sf::CircleShape getShape() const;

	//Public Functions
	void update();
	void render(sf::RenderTarget& target);
};

