#include "..\include\mainMenu.h"

Player playerCheck;

void mainMenu::newGame(sf::RenderWindow& window)
{
	if (!newGameCheck)
	{
		newGameCheck = true;
	}
	
}

bool mainMenu::startGame()
{
	return newGameCheck;
}

void mainMenu::endGame()
{
	gameOver = 1;
	newGameCheck = false;
}

void mainMenu::startScreen(sf::RenderWindow& window)
{
	spaceFont.loadFromFile(".\\assets\\Fonts\\spaceText.ttf");

	if (gameOver == 1)
	{
		sf::Text gameOver;
		gameOver.setFont(spaceFont);
		gameOver.setString("Game Over :(");
		gameOver.setCharacterSize(60);
		gameOver.setFillColor(spaceBlue);
		gameOver.setOutlineColor(sf::Color(52, 133, 188, 255));
		gameOver.setOutlineThickness(1);
		gameOver.setStyle(sf::Text::Bold);
		gameOver.setPosition(350, window.getSize().y / 2 - 240);

		window.draw(gameOver);
	}
		
	sf::Text menu;
	menu.setFont(spaceFont);
	menu.setString("Press enter to begin!");
	menu.setCharacterSize(60);
	menu.setFillColor(spaceBlue);
	menu.setOutlineColor(sf::Color(52, 133, 188, 255));
	menu.setOutlineThickness(1);
	menu.setStyle(sf::Text::Bold);
	menu.setPosition(240, window.getSize().y /2 - 30);

	window.draw(menu);
}


