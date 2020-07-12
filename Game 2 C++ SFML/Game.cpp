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
void Game::update()
{

}

void Game::render()
{

}
