#pragma once

//sfml includes
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

//game includes
#include "Game.h"
#include "mainMenu.h"

//Vector includes
#include <vector>
#include <string.h>

class Player
{
public:

	void playerController(sf::RenderWindow& window);
	void playerMovement(sf::RenderWindow& window);
	void playerRender(sf::RenderWindow& window);
	void enemyLogic(sf::RenderWindow& window);
	void PlayerScore(sf::RenderWindow& window);
	void shipShooting(sf::RenderWindow& window);
	void shields(sf::RenderWindow& window);
	void healthRender(sf::RenderWindow& window);
	void levelUp(sf::RenderWindow& window);
	bool GameOver();

	sf::Clock timer;
	sf::Clock timer2;

private:

	//Sprite creator class
	void spriteGenerator(sf::Texture& tex, std::string sFileName, size_t size, float x, float y, sf::Sprite& sprite);




	//Creation of player sprites
	sf::Texture tPlayerShip;
	sf::Sprite sPlayerShip;
	sf::Vector2f vPlayerSize;
	sf::Texture tHeart;
	sf::Sprite sHeart;
	sf::Vector2f vHeart;
	std::vector<sf::Sprite> vsHeart;
	int createHearts = 0;
	int currentLevel = 1;

	//Movement for ship
	bool firstSet = false;
	float currentPos;
	float xVelocity;
	float xSpeed;

	//Creation of missile
	sf::Texture tMissile;
	sf::Sprite sMissile1, sMissile1Shot;
	sf::Sprite sMissile2, sMissile2Shot;
	sf::Sprite sMissile3, sMissile3Shot;
	sf::Sprite sMissile4, sMissile4Shot;
	sf::Sprite sMissile5, sMissile5Shot;
	sf::Vector2f vMissileSize;

	//ability to shoot 5 missiles

	float missilePosX1;
	float missilePosY1;
	float missilePosX2;
	float missilePosY2;
	float missilePosX3;
	float missilePosY3;
	float missilePosX4;
	float missilePosY4;
	float missilePosX5;
	float missilePosY5;
	float mSpeed = 13;
	float mEnemySpeed = 12;
	bool isShot1 = false;
	bool isShot2 = false;
	bool isShot3 = false;
	bool isShot4 = false;
	bool isShot5 = false;

	//creation of aliens
	sf::Texture tInvaders;
	std::vector<sf::Sprite> vSprites;
	sf::Vector2f alienSize;
	int iEnemies = 10;
	int iEnemyRow = 5;
	float shipSpeed = 800.f;

	//Enemy shooting
	bool shipShoot1 = false;
	bool shipShoot2 = false;
	bool shipShoot3 = false;
	sf::Sprite sAlienShot1;
	bool alienShot1 = false;
	sf::Sprite sAlienShot2;
	bool alienShot2 = false;
	sf::Sprite sAlienShot3;
	bool alienShot3 = false;

	float shotPosX1;
	float shotPosY1;
	float shotPosX2;
	float shotPosY2;
	float shotPosX3;
	float shotPosY3;

	//Enemy destroyed
	int iSpawnShips = 0;
	std::vector<bool> shipAlive;

	//timer and time events

	float ticker1 = 1600;
	float ticker2 = 0;
	float ticker3 = 2;
	float ticker4 = 4;

	bool movementTime = false;
	std::vector<bool> isRight;

	//Font, score and health
	int playerScore = 0;
	sf::Color spaceBlue = sf::Color(9, 73, 165, 255);
	sf::Font spaceFont;
	int playerHealth = 3;
	int maxScore = 50;

	//shields
	sf::Texture tLowShield;
	sf::Texture tMidShield;
	sf::Texture tFullShield;

	sf::Sprite sShields1;
	sf::Sprite sShields2;
	sf::Sprite sShields3;

	int shieldState1 = 1;
	int shieldState2 = 1;
	int shieldState3 = 1;


	sf::Vector2f shieldSize;

	//gameover
	bool gameOver;
	
	//sound
	sf::SoundBuffer playerFire;
	sf::SoundBuffer enemyFire;
	sf::Sound playerShoot;
	sf::Sound enemyShoot;
	bool enemyLoaded = false;
	bool loadedShot = false;
	sf::SoundBuffer enemyHit;
	sf::Sound enemyDestroyed;
	bool loadedHit = false;
	sf::SoundBuffer playerHit;
	sf::Sound playerDestroyed;
	sf::Sound shieldDestroyed;
	bool shieldSound = false;
	bool loadedDestroy = false;


};