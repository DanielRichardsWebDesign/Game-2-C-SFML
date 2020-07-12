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

//Update Boundary collisions if something collides with it
void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
	//Left Boundary Collision
	sf::FloatRect playerBounds = this->shape.getGlobalBounds();
	if (playerBounds.left <= 0.f)
		this->shape.setPosition(0.f, playerBounds.top);
	//Right Boundary Collision
	else if (playerBounds.left + playerBounds.width >= target->getSize().x)
		this->shape.setPosition(target->getSize().x - playerBounds.width, playerBounds.top);
	//Top Boundary Collision	
	if (playerBounds.top <= 0.f)
		this->shape.setPosition(playerBounds.left, 0.f);
	//Bottom Boundary Collision
	else if (playerBounds.top + playerBounds.height >= target->getSize().y)
		this->shape.setPosition(playerBounds.left, target->getSize().y - playerBounds.height);
}

void Player::update(const sf::RenderTarget* target)
{
	this->updateInput();

	//Window Boundaries - Collisions
	this->updateWindowBoundsCollision(target);
}

//Render player to targeted window.
void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
