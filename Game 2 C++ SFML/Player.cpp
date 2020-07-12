#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 5.f;
	this->hpMax = 10;
	this->hp = hpMax;	
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

//Get Player shape
const sf::RectangleShape& Player::getShape() const
{
	return this->shape;
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
	if (this->shape.getGlobalBounds().left <= 0.f)
		this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
	//Right Boundary Collision
	if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
	//Top Boundary Collision	
	if (this->shape.getGlobalBounds().top <= 0.f)
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
	//Bottom Boundary Collision
	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
		this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);
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
