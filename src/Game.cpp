#include "Game.h"


//Starts classes for use with game
Player player;
mainMenu menu;


Game::Game() : _window(sf::VideoMode(1160, 912), "Space Invaders, By Tiernan McCallum.")
{
	_window.setFramerateLimit(60);	//sets frame rate for game window

}

void Game::run()
{
	while (_window.isOpen())
	{
		if (!musicStart)
		{

			bgm.openFromFile(".\\assets\\audio\\BGM.wav");
			bgm.setLoop(true);
			bgm.play();
			bgm.setVolume(70);
			musicStart = true;
		}

		processEvent();

		update();

		render();

	}
}
void Game::processEvent()
{
	sf::Event event;
	
	while (_window.pollEvent(event))
	{
		if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Space))
		{
			player.playerController(_window);
		}
		

		if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Enter))
		{
			menu.newGame(_window);
		}
		
		
		if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
		{
			_window.close();
		}

	}

}
void Game::update()
{
	if (menu.startGame())
	{
		gameState = 1;
		menuStart = false;
	}
	player.playerMovement(_window);
	
	if (gameState == 1)
	{
		if (player.GameOver())
		{
			menu.endGame();
			gameState = 0;
			startUp = false;
		}

	}


}
void Game::render()
{

	if (gameState == 1)
	{
		do
		{
			_window.clear(pitchBlack); //sets the background as black

			//Sets background
			tBackground.loadFromFile(".\\assets\\background\\starsBackground.png");// 1160 x 912
			sBackground.setScale(1160 / tBackground.getSize().x, 912 / tBackground.getSize().y);
			sBackground.setOrigin(0, 0);
			sBackground.setTexture(tBackground);
			_window.draw(sBackground);

			startUp = true;
		} while (!startUp);


		player.playerRender(_window);
		player.PlayerScore(_window);
		player.enemyLogic(_window);
		player.shipShooting(_window);
		player.shields(_window);
		player.healthRender(_window);
		player.levelUp(_window);



	}
	if (gameState == 0)
	{
		do
		{
			_window.clear(pitchBlack); //sets the background as black
			
			tBackground.loadFromFile(".\\assets\\background\\starsBackground.png");// 1160 x 912
			sBackground.setScale(1160 / tBackground.getSize().x, 912 / tBackground.getSize().y);
			sBackground.setOrigin(0, 0);
			sBackground.setTexture(tBackground);
			_window.draw(sBackground);

			menuStart = true;

		} while (!menuStart);

		menu.startScreen(_window);
		
		player.timer.restart();
		player.timer2.restart();

	}
	
	_window.display();
}


