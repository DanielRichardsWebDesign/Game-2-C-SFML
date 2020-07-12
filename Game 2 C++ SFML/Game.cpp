#include "Game.h"

void Game::initVariables()
{
	this->endGame = false;
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
}

//Constructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

//Destructor
Game::~Game()
{
	delete this->window;
}

//Functions
//Ensure game is running while window is open.
const bool Game::running() const
{
	return this->window->isOpen();
}

//Listen for events in window
void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	this->window->clear();

	//Render game objects
	this->window->display();
}
