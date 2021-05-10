#pragma once

//sfml includes
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

//game includes
#include "Game.h"
#include "Player.h"

class mainMenu {

public:
	void newGame(sf::RenderWindow& window);
	bool startGame();
	void endGame();
	void startScreen(sf::RenderWindow& window);


private:

	bool newGameCheck = false;
	int gameOver = 0;

	//font
	sf::Color spaceBlue = sf::Color(9, 73, 165, 255);
	sf::Font spaceFont;

};