#pragma once

//sfml includes
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

//other needed includes
#include <string.h>

//game includes
#include "player.h"
#include "mainMenu.h"

using namespace std;

class Game
{

public:

	//public fuctions
	Game();
	void run();

	//Defines playable window
	sf::RenderWindow _window;



private:

	//private functions
	void processEvent();
	void update();
	void render();


	//Background info
	sf::Texture tBackground;
	sf::Sprite sBackground;
	sf::Vector2f vBackground;
	bool startUp = false;
	bool menuStart = false;


	
	
	//Additional colors for sfml
	sf::Color pitchBlack = sf::Color(0, 0, 0, 255);

	//gameover?
	bool gameOver = true;
	int gameState = 0;

	//BGM
	sf::Music bgm;
	bool musicStart = false;

	

};