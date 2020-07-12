#include "Game.h"

void Game::initVariables()
{
	this->endGame = false;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxSwagBalls = 10;
	this->points = 0;
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initFonts()
{
	if(!this->font.loadFromFile("Fonts/FreePixel.ttf"));
	{
		std::cout << "Unable to initiate font FreePixel.ttf!" << "\n";
	}
}

void Game::initText()
{
	//Gui text init
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(24);
	this->guiText.setString("test");
}

//Constructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFonts();
	this->initText();
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

void Game::spawnSwagBalls()
{
	//Spawn Timer
	if (this->spawnTimer < this->spawnTimerMax)	
		this->spawnTimer += 1.f;
	else
	{
		if (this->swagBalls.size() < this->maxSwagBalls)
		{
			this->swagBalls.push_back(SwagBall(*this->window));

			this->spawnTimer = 0.f;
		}		
	}	
}

void Game::updateCollision()
{
	//Check the collision between player and balls
	for (size_t i = 0; i < this->swagBalls.size(); i++)
	{
		//Remove ball if player touches it.
		if (this->player.getShape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds()))
		{
			this->swagBalls.erase(this->swagBalls.begin() + i);
		}
	}	
}

void Game::update()
{
	this->pollEvents();

	this->spawnSwagBalls();
	
	//Update Player 
	this->player.update(this->window);

	//Update Collison
	this->updateCollision();
}

void Game::renderGui(sf::RenderTarget* target)
{
	target->draw(this->guiText);
}

void Game::render()
{
	this->window->clear();

	//Render game objects
	this->player.render(this->window);

	//Draw Balls on Screen
	for (auto i : this->swagBalls)
	{
		i.render(*this->window);
	}

	//Render gui
	this->renderGui(this->window);

	//Render window
	this->window->display();
}
