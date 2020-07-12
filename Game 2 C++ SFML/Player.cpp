#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 10.f;
}

//Initialise Player shape properties
void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

Player::Player(float x, float y)
{
	//Player Position Start
	this->shape.setPosition(x, y);

	this->initVariables();
	this->initShape();
}

Player::~Player()
{

}

void Player::updateInput()
{
	//Keyboard Input
	//Left Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->shape.move(-this->movementSpeed, 0.f);
	}
	//Right Movement
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->shape.move(this->movementSpeed, 0.f);
	}
	//Forward Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->shape.move(0.f, -this->movementSpeed);
	}
	//Backward Movement
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->shape.move(0.f, this->movementSpeed);
	}
}

void Player::update(sf::RenderTarget* target)
{
	//Window Boundaries - Collisions
	

	this->updateInput();
}

//Render player to targeted window.
void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
