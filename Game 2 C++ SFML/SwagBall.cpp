#include "SwagBall.h"

void SwagBall::initShape(const sf::RenderWindow& window)
{
	this->shape.setRadius(static_cast<float>(rand()%10+10));
	sf::Color colour(rand()%255 + 1, rand()%255 + 1, rand() % 255 + 1);
	this->shape.setFillColor(colour);
	this->shape.setPosition(sf::Vector2f(
		static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width), 
		static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height))
	);
}

SwagBall::SwagBall(const sf::RenderWindow& window)
{
	initShape(window);
}

SwagBall::~SwagBall()
{

}

void SwagBall::update()
{

}

void SwagBall::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
