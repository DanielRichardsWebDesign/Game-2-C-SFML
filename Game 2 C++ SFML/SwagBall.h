#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

//Set the different types of balls in the enumerator
enum SwagBallTypes{DEFAULT = 0, DAMAGING, HEALING, NROFTYPES};

class SwagBall
{
private:
	//Variables
	sf::CircleShape shape;
	int type;

	void initShape(const sf::RenderWindow& window);

public:
	SwagBall(const sf::RenderWindow& window, int type);
	virtual ~SwagBall();

	//Accessors
	const sf::CircleShape getShape() const;
	const int& getType() const;

	//Public Functions
	void update();
	void render(sf::RenderTarget& target);
};

