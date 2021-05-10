//Normal includes
#include <stdio.h>
#include <iostream>

//SFML includes
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <SFML/Main.hpp>
#include <SFML/Audio.hpp>

//Game includes
#include "Game.h"
#include "Player.h"



using namespace std;

int main()
{


	//Starts the game loop
	Game game;

	game.run();


	
	return 0;
}