#include "..\include\Player.h"

mainMenu menuCheck;

void Player::playerMovement(sf::RenderWindow& window)
{

	
	if (!firstSet)
	{
		sPlayerShip.setPosition((window.getSize().x + vPlayerSize.x) / 2.f, window.getSize().y + - 62.8f);
		
		currentPos = (window.getSize().x + vPlayerSize.x) / 2.f;

		firstSet = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		xVelocity = -0.5f;
		xSpeed = xSpeed + xVelocity;
	}

	if (xSpeed < -10)
	{
		xSpeed = -10;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		xVelocity = 0.5f;
		xSpeed = xSpeed + xVelocity;
	}

	if (xSpeed > 10)
	{
		xSpeed = 10;
	}

	currentPos = currentPos + xSpeed;

	if (currentPos < 0)
	{
		currentPos = 0;
		xSpeed = 2;
	}

	if (currentPos > window.getSize().x - 40)
	{
		currentPos = window.getSize().x - 40;
		xSpeed = -2;
	}

	sPlayerShip.setPosition(currentPos, window.getSize().y + -62.8f);
}

void Player::playerController(sf::RenderWindow& window)
{
	if (!loadedShot)
	{
		playerFire.loadFromFile(".\\assets\\audio\\playerShoot.wav");
		playerShoot.setBuffer(playerFire);
		playerShoot.setPitch(0.8f);
		loadedShot = true;
	}

	if (isShot1 == false)
	{
		playerShoot.play();
		missilePosY1 = window.getSize().y -  62.8f;
		missilePosX1 = currentPos + 20;
		isShot1 = true;
	}
	else if(isShot2 == false)
	{
		playerShoot.play();
		missilePosY2 = window.getSize().y - 62.8f;
		missilePosX2 = currentPos + 20;
		isShot2 = true;
	}
	else if (isShot3 == false)
	{
		playerShoot.play();
		missilePosY3 = window.getSize().y - 62.8f;
		missilePosX3 = currentPos + 20;
		isShot3 = true;
	}
	else if (isShot4 == false)
	{
		playerShoot.play();
		missilePosY4 = window.getSize().y - 62.8f;
		missilePosX4 = currentPos + 20;
		isShot4 = true;
	}
	else if (isShot5 == false)
	{
		playerShoot.play();
		missilePosY5 = window.getSize().y - 62.8f;
		missilePosX5 = currentPos + 20;
		isShot5 = true;
	}

}

void Player::playerRender(sf::RenderWindow& window)
{
	
	tPlayerShip.loadFromFile(".\\assets\\textures\\playerShip.png");// 200 x 264

	vPlayerSize.x = 200.f;
	vPlayerSize.y = 264.f;

	sPlayerShip.setScale((vPlayerSize.x / tPlayerShip.getSize().x) * 0.2f, (vPlayerSize.y / tPlayerShip.getSize().y) * 0.2f);
	sPlayerShip.setTexture(tPlayerShip);

	window.draw(sPlayerShip);

	tMissile.loadFromFile(".\\assets\\textures\\bullet.png");// 15 x 52

	vMissileSize.x = 15.f;
	vMissileSize.y = 52.f;

	sMissile1.setScale((vMissileSize.x / tMissile.getSize().x) * 0.4f, (vMissileSize.y / tMissile.getSize().y) * 0.4f);
	sMissile1.setTexture(tMissile);
	sMissile1Shot.setTexture(tMissile);
	sMissile2.setScale((vMissileSize.x / tMissile.getSize().x) * 0.4f, (vMissileSize.y / tMissile.getSize().y) * 0.4f);
	sMissile2.setTexture(tMissile);
	sMissile2Shot.setTexture(tMissile);
	sMissile3.setScale((vMissileSize.x / tMissile.getSize().x) * 0.4f, (vMissileSize.y / tMissile.getSize().y) * 0.4f);
	sMissile3.setTexture(tMissile);
	sMissile3Shot.setTexture(tMissile);
	sMissile4.setScale((vMissileSize.x / tMissile.getSize().x) * 0.4f, (vMissileSize.y / tMissile.getSize().y) * 0.4f);
	sMissile4.setTexture(tMissile);
	sMissile4Shot.setTexture(tMissile);
	sMissile5.setScale((vMissileSize.x / tMissile.getSize().x) * 0.4f, (vMissileSize.y / tMissile.getSize().y) * 0.4f);
	sMissile5.setTexture(tMissile);
	sMissile5Shot.setTexture(tMissile);

	if (isShot1 == false)
	{
		int missilePosX = 50;
		int missilePosY = 5;
		
		sMissile1.setPosition(missilePosX, missilePosY);

		window.draw(sMissile1);
	}
	else if (isShot1 == true)
	{

		missilePosY1 = missilePosY1 - mSpeed;
		sMissile1Shot.setPosition(missilePosX1, missilePosY1);
		sMissile1Shot.setScale((vMissileSize.x / tMissile.getSize().x) * 0.2f, (vMissileSize.y / tMissile.getSize().y) * 0.2f);


		if (missilePosY1 < 0)
		{
			isShot1 = false;
		}

		window.draw(sMissile1Shot);
	}

	if (isShot2 == false)
	{
		missilePosX2 = 40;
		missilePosY2 = 5;

		sMissile2.setPosition(missilePosX2, missilePosY2);


		window.draw(sMissile2);
	}
	else if (isShot2 == true)
	{

		missilePosY2 = missilePosY2 - mSpeed;
		sMissile2Shot.setPosition(missilePosX2, missilePosY2);
		sMissile2Shot.setScale((vMissileSize.x / tMissile.getSize().x) * 0.2f, (vMissileSize.y / tMissile.getSize().y) * 0.2f);

		if (missilePosY2 < 0)
		{
			isShot2 = false;
		}

		window.draw(sMissile2Shot);
	}

	if (isShot3 == false)
	{
		missilePosX3 = 30;
		missilePosY3 = 5;

		sMissile3.setPosition(missilePosX3, missilePosY3);


		window.draw(sMissile3);
	}
	else if (isShot3 == true)
	{

		missilePosY3 = missilePosY3 - mSpeed;
		sMissile3Shot.setPosition(missilePosX3, missilePosY3);
		sMissile3Shot.setScale((vMissileSize.x / tMissile.getSize().x) * 0.2f, (vMissileSize.y / tMissile.getSize().y) * 0.2f);


		if (missilePosY3 < 0)
		{
			isShot3 = false;
		}

		window.draw(sMissile3Shot);
	}

	if (isShot4 == false)
	{
		missilePosX4 = 20;
		missilePosY4 = 5;

		sMissile4.setPosition(missilePosX4, missilePosY4);


		window.draw(sMissile4);
	}
	else if (isShot4 == true)
	{

		missilePosY4 = missilePosY4 - mSpeed;
		sMissile4Shot.setPosition(missilePosX4, missilePosY4);
		sMissile4Shot.setScale((vMissileSize.x / tMissile.getSize().x) * 0.2f, (vMissileSize.y / tMissile.getSize().y) * 0.2f);


		if (missilePosY4 < 0)
		{
			isShot4 = false;
		}

		window.draw(sMissile4Shot);
	}

	if (isShot5 == false)
	{
		missilePosX5 = 10;
		missilePosY5 = 5;

		sMissile5.setPosition(missilePosX5, missilePosY5);


		window.draw(sMissile5);
	}
	else if (isShot5 == true)
	{

		missilePosY5 = missilePosY5 - mSpeed;
		sMissile5Shot.setPosition(missilePosX5, missilePosY5);
		sMissile5Shot.setScale((vMissileSize.x / tMissile.getSize().x) * 0.2f, (vMissileSize.y / tMissile.getSize().y) * 0.2f);


		if (missilePosY5 < 0)
		{
			isShot5 = false;
		}

		window.draw(sMissile5Shot);
	}

}

void Player::enemyLogic(sf::RenderWindow& window)
{
	alienSize.x = 198.f;
	alienSize.y = 138.f;

	sf::Sprite alienSprite;
	int index = 0;
	float maxElement = 0;

	if (!loadedHit)
	{
		enemyHit.loadFromFile(".\\assets\\audio\\enemyHit.wav");
		enemyDestroyed.setBuffer(enemyHit);
		loadedHit = true;
	}
	
	int speedAlter = 1;
	int tempEnemies = iEnemies + iEnemyRow;



	sf::Time checkTimer = timer.getElapsedTime();
	if (checkTimer.asMilliseconds() > ticker1)
	{
		ticker1 = ticker1 + shipSpeed;
		movementTime = true;
		
		if (ticker1 > 100000)
		{
			ticker1 = 0;
			timer.restart();
		}

	}
	
	for (int i = 0; i < iEnemies; i++)
	{
		for (int j = 0; j < iEnemyRow; j++)
		{
			if (iSpawnShips < (iEnemies * iEnemyRow))
			{
				spriteGenerator(tInvaders, ".\\assets\\textures\\enemyShips.png", vSprites.size(), alienSize.x, alienSize.y, alienSprite);
				vSprites.push_back(alienSprite);
				vSprites[index].setPosition(i * 58, 50 + (j * 60));
			}

			if (iSpawnShips < (iEnemies * iEnemyRow))
			{
				shipAlive.push_back(true);
				isRight.push_back(true);
				iSpawnShips++;
			}

			int counter = 0;
			for (int k = 0; k < vSprites.size(); k++)
			{

				if (maxElement <= vSprites[counter].getPosition().x)
				{
					if (shipAlive[counter])
					{
						maxElement = vSprites[counter].getPosition().x;
					}
					counter++;
				}
			}


		
			float minElement = 100;
			float counter2 = 0;
			for (int k = 0; k < vSprites.size(); k++)
			{
				
				if (shipAlive[counter2])
				{
					if (minElement > counter2)
					{
						minElement = counter2;
					}

				}
				counter2++;
			}


			int move = 0;
			if(movementTime)
			{

				if (isRight[index] && move == 0)
				{
					

					
					if ((maxElement + 59) > window.getSize().x)
					{
						vSprites[index].setPosition(vSprites[index].getPosition().x, vSprites[index].getPosition().y + 50);
						isRight[index] = false;
						if (speedAlter == 1)
						{
							shipSpeed = shipSpeed - 40.f;
							speedAlter = 0;
						}
						move++;
					}				
					else
					{
						vSprites[index].setPosition(vSprites[index].getPosition().x + 58, vSprites[index].getPosition().y);
						move++;
					}
				}
				if (!isRight[index] && move == 0)
				{

					if (move == 0)
					{
						vSprites[index].setPosition(vSprites[index].getPosition().x - 58, vSprites[index].getPosition().y);
						move++;
					}
					if (vSprites[minElement].getPosition().x <= 0)
					{
						vSprites[index].setPosition(vSprites[index].getPosition().x, vSprites[index].getPosition().y + 50);
						isRight[index] = true;
						if (speedAlter == 1)
						{
							shipSpeed = shipSpeed - -40.f;
							speedAlter = 0;
						}
						move++;
					}
				}
				

			}



			if (shipAlive[index])
			{
				if (sMissile1Shot.getPosition().x + 3 >= vSprites[index].getPosition().x && sMissile1Shot.getPosition().y + 10.4 >= vSprites[index].getPosition().y  &&
					sMissile1Shot.getPosition().x <= vSprites[index].getPosition().x + 57.02f && sMissile1Shot.getPosition().y <= vSprites[index].getPosition().y + 39.74
					&& isShot1)
				{

					enemyDestroyed.play();
					shipAlive[index] = false;
					isShot1 = false;

					playerScore++;
				}

				if (sMissile2Shot.getPosition().x + 3 >= vSprites[index].getPosition().x && sMissile2Shot.getPosition().y + 10.4 >= vSprites[index].getPosition().y &&
					sMissile2Shot.getPosition().x <= vSprites[index].getPosition().x + 57.02f && sMissile2Shot.getPosition().y <= vSprites[index].getPosition().y + 39.74
					&& isShot2)
				{
					enemyDestroyed.play();
					shipAlive[index] = false;
					isShot2 = false;

					playerScore++;
				}
				if (sMissile3Shot.getPosition().x + 3 >= vSprites[index].getPosition().x && sMissile3Shot.getPosition().y + 10.4 >= vSprites[index].getPosition().y &&
					sMissile3Shot.getPosition().x <= vSprites[index].getPosition().x + 57.02f && sMissile3Shot.getPosition().y <= vSprites[index].getPosition().y + 39.74
					&& isShot3)
				{
					enemyDestroyed.play();
					shipAlive[index] = false;
					isShot3 = false;

					playerScore++;
				}
				if (sMissile4Shot.getPosition().x + 3 >= vSprites[index].getPosition().x && sMissile4Shot.getPosition().y + 10.4 >= vSprites[index].getPosition().y &&
					sMissile4Shot.getPosition().x <= vSprites[index].getPosition().x + 57.02f && sMissile4Shot.getPosition().y <= vSprites[index].getPosition().y + 39.74
					&& isShot4)
				{
					enemyDestroyed.play();
					shipAlive[index] = false;
					isShot4 = false;

					playerScore++;
				}
				if (sMissile5Shot.getPosition().x + 3 >= vSprites[index].getPosition().x && sMissile5Shot.getPosition().y + 10.4 >= vSprites[index].getPosition().y &&
					sMissile5Shot.getPosition().x <= vSprites[index].getPosition().x + 57.02f && sMissile5Shot.getPosition().y <= vSprites[index].getPosition().y + 39.74
					&& isShot5)
				{
					enemyDestroyed.play();
					shipAlive[index] = false;
					isShot5 = false;

					playerScore++;
				}


			}



			if (shipAlive[index])
			{
				window.draw(vSprites[index]);
			}

			index++;



		}
	}
	movementTime = false;
}

void Player::PlayerScore(sf::RenderWindow& window)
{
	spaceFont.loadFromFile(".\\assets\\Fonts\\spaceText.ttf");

	sf::Text score;
	score.setFont(spaceFont);
	score.setString(to_string(playerScore));
	score.setCharacterSize(30);
	score.setFillColor(spaceBlue);
	score.setOutlineColor(sf::Color(52,133,188,255));
	score.setOutlineThickness(1);
	score.setStyle(sf::Text::Bold);
	score.setPosition(window.getSize().x - 80, 0);

	window.draw(score);

}

void Player::shipShooting(sf::RenderWindow& window)
{
	tMissile.loadFromFile(".\\assets\\textures\\bullet.png");// 15 x 52

	if (!loadedDestroy)
	{
		playerHit.loadFromFile(".\\assets\\audio\\playerHit.wav");
		playerDestroyed.setBuffer(playerHit);
		loadedDestroy = true;
	}
	if (!enemyLoaded)
	{
		enemyFire.loadFromFile(".\\assets\\audio\\enemyShoot.wav");
		enemyShoot.setBuffer(enemyFire);
		enemyShoot.setPitch(2);
		enemyLoaded = true;
	}



	vMissileSize.x = 15.f;
	vMissileSize.y = 52.f;

	sAlienShot1.setScale((vMissileSize.x / tMissile.getSize().x) * 0.3f, (vMissileSize.y / tMissile.getSize().y) * 0.3f);
	sAlienShot1.setTexture(tMissile);
	sAlienShot1.setRotation(180);
	sAlienShot2.setScale((vMissileSize.x / tMissile.getSize().x) * 0.3f, (vMissileSize.y / tMissile.getSize().y) * 0.3f);
	sAlienShot2.setTexture(tMissile);
	sAlienShot2.setRotation(180);
	sAlienShot3.setScale((vMissileSize.x / tMissile.getSize().x) * 0.3f, (vMissileSize.y / tMissile.getSize().y) * 0.3f);
	sAlienShot3.setTexture(tMissile);
	sAlienShot3.setRotation(180);
	
	srand(time(NULL));
	int randShip = rand() % vSprites.size();

	sf::Time checkTimer = timer2.getElapsedTime();
	if (checkTimer.asSeconds() > ticker2)
	{

		shipShoot1 = true;

		ticker2 = ticker2 + 5;

		if (ticker2 > 200.f)
		{

			ticker2 = 0;
		}
	}
	
	if (checkTimer.asSeconds() > ticker3)
	{

		shipShoot2 = true;

		ticker3 = ticker3 + 5;

		if (ticker3 > 200.f)
		{
			ticker3 = 0;
		}
	}
	
	if (checkTimer.asSeconds() > ticker4)
	{

		shipShoot3 = true;

		ticker4 = ticker4 + 5;

		if (ticker4 > 200.f)
		{
			ticker4 = 0;
			timer2.restart();
		}
	}
	
	if (shipAlive[randShip])
	{
		if (!alienShot1 && shipShoot1)
		{
			enemyShoot.play();
			shotPosY1 = vSprites[randShip].getPosition().y;
			shotPosX1 = vSprites[randShip].getPosition().x + 28.5;
			alienShot1 = true;
			shipShoot1 = false;
		}
		if (!alienShot2 && shipShoot2)
		{
			enemyShoot.play();
			shotPosY2 = vSprites[randShip].getPosition().y;
			shotPosX2 = vSprites[randShip].getPosition().x + 28.5;
			alienShot2 = true;
			shipShoot2 = false;
		}
		if (!alienShot3 && shipShoot3)
		{
			enemyShoot.play();
			shotPosY3 = vSprites[randShip].getPosition().y;
			shotPosX3 = vSprites[randShip].getPosition().x + 28.5;
			alienShot3 = true;
			shipShoot3 = false;
		}
	}

	if (alienShot1)
	{
		shotPosY1 = shotPosY1 + mEnemySpeed;

		sAlienShot1.setPosition(shotPosX1, shotPosY1);
		
		if (shotPosY1 > window.getSize().y)
		{
			alienShot1 = false;
		}

		window.draw(sAlienShot1);
	}
	if (alienShot2)
	{
		shotPosY2 = shotPosY2 + mEnemySpeed;

		sAlienShot2.setPosition(shotPosX2, shotPosY2);

		if (shotPosY2 > window.getSize().y)
		{
			alienShot2 = false;
		}

		window.draw(sAlienShot2);
	}
	if (alienShot3)
	{
		shotPosY3 = shotPosY3 + mEnemySpeed;

		sAlienShot3.setPosition(shotPosX3, shotPosY3);

		if (shotPosY3 > window.getSize().y)
		{
			alienShot3 = false;
		}

		window.draw(sAlienShot3);
	}

	if (sAlienShot1.getPosition().x < sPlayerShip.getPosition().x + 40 && sAlienShot1.getPosition().x + 4.5 > sPlayerShip.getPosition().x
		&& sAlienShot1.getPosition().y < sPlayerShip.getPosition().y + 52.8 && sAlienShot1.getPosition().y + 15.6 > sPlayerShip.getPosition().y && alienShot1)
	{
		playerDestroyed.play();
		alienShot1 = false;
		playerHealth--;
	}
	if (sAlienShot2.getPosition().x < sPlayerShip.getPosition().x + 40 && sAlienShot2.getPosition().x + 4.5 > sPlayerShip.getPosition().x
		&& sAlienShot2.getPosition().y < sPlayerShip.getPosition().y + 52.8 && sAlienShot2.getPosition().y + 15.6 > sPlayerShip.getPosition().y && alienShot2)
	{
		playerDestroyed.play();
		alienShot2 = false;
		playerHealth--;
	}
	if (sAlienShot3.getPosition().x < sPlayerShip.getPosition().x + 40 && sAlienShot3.getPosition().x + 4.5 > sPlayerShip.getPosition().x
		&& sAlienShot3.getPosition().y < sPlayerShip.getPosition().y + 52.8 && sAlienShot3.getPosition().y + 15.6 > sPlayerShip.getPosition().y && alienShot3)
	{
		playerDestroyed.play();
		alienShot3 = false;
		playerHealth--;
	}
	

}

void Player::shields(sf::RenderWindow& window)
{
	tLowShield.loadFromFile(".\\assets\\textures\\lowShield.png");// 40 x 125
	tMidShield.loadFromFile(".\\assets\\textures\\halfShield.png");// 40 x 125
	tFullShield.loadFromFile(".\\assets\\textures\\fullShield.png");// 40 x 125

	if (!shieldSound)
	{
		shieldDestroyed.setBuffer(playerHit);
		shieldDestroyed.setPitch(1.4f);
		shieldSound = true;
	}

	shieldSize.x = 40;
	shieldSize.y = 125;

	sShields1.setScale(shieldSize.x / tLowShield.getSize().x * 1, shieldSize.y / tLowShield.getSize().y * 1);
	sShields2.setScale(shieldSize.x / tLowShield.getSize().x * 1, shieldSize.y / tLowShield.getSize().y * 1);
	sShields3.setScale(shieldSize.x / tLowShield.getSize().x * 1, shieldSize.y / tLowShield.getSize().y * 1);



	sShields1.setRotation(270);
	sShields2.setRotation(270);
	sShields3.setRotation(270);

	sShields1.setPosition((window.getSize().x / 4) - 62.5, sPlayerShip.getPosition().y - 10);
	sShields2.setPosition((window.getSize().x / 2) - 62.5, sPlayerShip.getPosition().y - 10);
	sShields3.setPosition(((window.getSize().x / 4) * 3) - 62.5, sPlayerShip.getPosition().y - 10);


	switch (shieldState1)
	{
	case 1: 

		sShields1.setTexture(tFullShield);


		break;
	case 2:

		sShields1.setTexture(tMidShield);
		break;
	case 3:

		sShields1.setTexture(tLowShield);
		break;
	}

	switch (shieldState2)
	{
	case 1:

		sShields2.setTexture(tFullShield);


		break;
	case 2:

		sShields2.setTexture(tMidShield);
		break;
	case 3:

		sShields2.setTexture(tLowShield);
		break;
	}

	switch (shieldState3)
	{
	case 1:

		sShields3.setTexture(tFullShield);


		break;
	case 2:

		sShields3.setTexture(tMidShield);
		break;
	case 3:

		sShields3.setTexture(tLowShield);
		break;
	}

	if (shieldState1 <= 3)
	{
		if (shieldState1 == 3)
		{
			if (sAlienShot3.getPosition().x > sShields1.getPosition().x && sAlienShot3.getPosition().x + 4.5 < sShields1.getPosition().x + 125
				&& sAlienShot3.getPosition().y + 15.6 > sShields1.getPosition().y && sAlienShot3.getPosition().y < sShields1.getPosition().y + 40 && alienShot3)
			{
				alienShot3 = false;
				shieldState1++;
				shieldDestroyed.play();

			}

			if (sAlienShot2.getPosition().x > sShields1.getPosition().x && sAlienShot2.getPosition().x + 4.5 < sShields1.getPosition().x + 125
				&& sAlienShot2.getPosition().y + 15.6 > sShields1.getPosition().y && sAlienShot2.getPosition().y < sShields1.getPosition().y + 40 && alienShot2)
			{
				alienShot2 = false;
				shieldState1++;
				shieldDestroyed.play();
			}

			if (sAlienShot1.getPosition().x > sShields1.getPosition().x && sAlienShot1.getPosition().x + 4.5 < sShields1.getPosition().x + 125
				&& sAlienShot1.getPosition().y + 15.6 > sShields1.getPosition().y && sAlienShot1.getPosition().y < sShields1.getPosition().y + 40 && alienShot1)
			{
				alienShot1 = false;
				shieldState1++;
				shieldDestroyed.play();
			}
		}

		if (shieldState1 == 2)
		{
			if (sAlienShot3.getPosition().x > sShields1.getPosition().x && sAlienShot3.getPosition().x + 4.5 < sShields1.getPosition().x + 125
				&& sAlienShot3.getPosition().y + 15.6 > sShields1.getPosition().y && sAlienShot3.getPosition().y < sShields1.getPosition().y + 40 && alienShot3)
			{
				alienShot3 = false;
				shieldState1++;
				shieldDestroyed.play();
			}

			if (sAlienShot2.getPosition().x > sShields1.getPosition().x && sAlienShot2.getPosition().x + 4.5 < sShields1.getPosition().x + 125
				&& sAlienShot2.getPosition().y + 15.6 > sShields1.getPosition().y && sAlienShot2.getPosition().y < sShields1.getPosition().y + 40 && alienShot2)
			{
				alienShot2 = false;
				shieldState1++;
				shieldDestroyed.play();
			}

			if (sAlienShot1.getPosition().x > sShields1.getPosition().x && sAlienShot1.getPosition().x + 4.5 < sShields1.getPosition().x + 125
				&& sAlienShot1.getPosition().y + 15.6 > sShields1.getPosition().y && sAlienShot1.getPosition().y < sShields1.getPosition().y + 40 && alienShot1)
			{
				alienShot1 = false;
				shieldState1++;
				shieldDestroyed.play();
			}
		}

		if (shieldState1 == 1)
		{
			if (sAlienShot3.getPosition().x > sShields1.getPosition().x && sAlienShot3.getPosition().x + 4.5 < sShields1.getPosition().x + 125
				&& sAlienShot3.getPosition().y + 15.6 > sShields1.getPosition().y && sAlienShot3.getPosition().y < sShields1.getPosition().y + 40 && alienShot3)
			{
				alienShot3 = false;
				shieldState1++;
				shieldDestroyed.play();
			}

			if (sAlienShot2.getPosition().x > sShields1.getPosition().x && sAlienShot2.getPosition().x + 4.5 < sShields1.getPosition().x + 125
				&& sAlienShot2.getPosition().y + 15.6 > sShields1.getPosition().y && sAlienShot2.getPosition().y < sShields1.getPosition().y + 40 && alienShot2)
			{
				alienShot2 = false;
				shieldState1++;
				shieldDestroyed.play();
			}

			if (sAlienShot1.getPosition().x > sShields1.getPosition().x && sAlienShot1.getPosition().x + 4.5 < sShields1.getPosition().x + 125
				&& sAlienShot1.getPosition().y + 15.6 > sShields1.getPosition().y && sAlienShot1.getPosition().y < sShields1.getPosition().y + 40 && alienShot1)
			{

				alienShot1 = false;
				shieldState1++;
				shieldDestroyed.play();
			}
		}

		window.draw(sShields1);
	}

	if (shieldState2 <= 3)
	{
		if (shieldState2 == 3)
		{
			if (sAlienShot3.getPosition().x > sShields2.getPosition().x && sAlienShot3.getPosition().x + 4.5 < sShields2.getPosition().x + 125
				&& sAlienShot3.getPosition().y + 15.6 > sShields2.getPosition().y && sAlienShot3.getPosition().y < sShields2.getPosition().y + 40 && alienShot3)
			{
				alienShot3 = false;
				shieldState2++;
				shieldDestroyed.play();
			}

			if (sAlienShot2.getPosition().x > sShields2.getPosition().x && sAlienShot2.getPosition().x + 4.5 < sShields2.getPosition().x + 125
				&& sAlienShot2.getPosition().y + 15.6 > sShields2.getPosition().y && sAlienShot2.getPosition().y < sShields2.getPosition().y + 40 && alienShot2)
			{

				alienShot2 = false;
				shieldState2++;
				shieldDestroyed.play();
			}

			if (sAlienShot1.getPosition().x > sShields2.getPosition().x && sAlienShot1.getPosition().x + 4.5 < sShields2.getPosition().x + 125
				&& sAlienShot1.getPosition().y + 15.6 > sShields2.getPosition().y && sAlienShot1.getPosition().y < sShields2.getPosition().y + 40 && alienShot1)
			{
				alienShot1 = false;
				shieldState2++;
				shieldDestroyed.play();
			}
		}

		if (shieldState2 == 2)
		{
			if (sAlienShot3.getPosition().x > sShields2.getPosition().x && sAlienShot3.getPosition().x + 4.5 < sShields2.getPosition().x + 125
				&& sAlienShot3.getPosition().y + 15.6 > sShields2.getPosition().y && sAlienShot3.getPosition().y < sShields2.getPosition().y + 40 && alienShot3)
			{
				alienShot3 = false;
				shieldState2++;
				shieldDestroyed.play();
			}

			if (sAlienShot2.getPosition().x > sShields2.getPosition().x && sAlienShot2.getPosition().x + 4.5 < sShields2.getPosition().x + 125
				&& sAlienShot2.getPosition().y + 15.6 > sShields2.getPosition().y && sAlienShot2.getPosition().y < sShields2.getPosition().y + 40 && alienShot2)
			{
				alienShot2 = false;
				shieldState2++;
				shieldDestroyed.play();
			}

			if (sAlienShot1.getPosition().x > sShields2.getPosition().x && sAlienShot1.getPosition().x + 4.5 < sShields2.getPosition().x + 125
				&& sAlienShot1.getPosition().y + 15.6 > sShields2.getPosition().y && sAlienShot1.getPosition().y < sShields2.getPosition().y + 40 && alienShot1)
			{
				alienShot1 = false;
				shieldState2++;
				shieldDestroyed.play();
			}
		}

		if (shieldState2 == 1)
		{
			if (sAlienShot3.getPosition().x > sShields2.getPosition().x && sAlienShot3.getPosition().x + 4.5 < sShields2.getPosition().x + 125
				&& sAlienShot3.getPosition().y + 15.6 > sShields2.getPosition().y && sAlienShot3.getPosition().y < sShields2.getPosition().y + 40 && alienShot3)
			{
				alienShot3 = false;
				shieldState2++;
				shieldDestroyed.play();
			}

			if (sAlienShot2.getPosition().x > sShields2.getPosition().x && sAlienShot2.getPosition().x + 4.5 < sShields2.getPosition().x + 125
				&& sAlienShot2.getPosition().y + 15.6 > sShields2.getPosition().y && sAlienShot2.getPosition().y < sShields2.getPosition().y + 40 && alienShot2)
			{
				alienShot2 = false;
				shieldState2++;
				shieldDestroyed.play();
			}

			if (sAlienShot1.getPosition().x > sShields2.getPosition().x && sAlienShot1.getPosition().x + 4.5 < sShields2.getPosition().x + 125
				&& sAlienShot1.getPosition().y + 15.6 > sShields2.getPosition().y && sAlienShot1.getPosition().y < sShields2.getPosition().y + 40 && alienShot1)
			{
				alienShot1 = false;
				shieldState2++;
				shieldDestroyed.play();
			}
		}
	
		window.draw(sShields2);
	}

	if (shieldState3 <= 3)
	{
		if (shieldState3 == 3)
		{
			if (sAlienShot3.getPosition().x > sShields3.getPosition().x && sAlienShot3.getPosition().x + 4.5 < sShields3.getPosition().x + 125
				&& sAlienShot3.getPosition().y + 15.6 > sShields3.getPosition().y && sAlienShot3.getPosition().y < sShields3.getPosition().y + 40 && alienShot3)
			{
				alienShot3 = false;
				shieldState3++;
				shieldDestroyed.play();
			}

			if (sAlienShot2.getPosition().x > sShields3.getPosition().x && sAlienShot2.getPosition().x + 4.5 < sShields3.getPosition().x + 125
				&& sAlienShot2.getPosition().y + 15.6 > sShields3.getPosition().y && sAlienShot2.getPosition().y < sShields3.getPosition().y + 40 && alienShot2)
			{

				alienShot2 = false;
				shieldState3++;
				shieldDestroyed.play();
			}

			if (sAlienShot1.getPosition().x > sShields3.getPosition().x && sAlienShot1.getPosition().x + 4.5 < sShields3.getPosition().x + 125
				&& sAlienShot1.getPosition().y + 15.6 > sShields3.getPosition().y && sAlienShot1.getPosition().y < sShields3.getPosition().y + 40 && alienShot1)
			{
				alienShot1 = false;
				shieldState3++;
				shieldDestroyed.play();
			}
		}

		if (shieldState3 == 2)
		{
			if (sAlienShot3.getPosition().x > sShields3.getPosition().x && sAlienShot3.getPosition().x + 4.5 < sShields3.getPosition().x + 125
				&& sAlienShot3.getPosition().y + 15.6 > sShields3.getPosition().y && sAlienShot3.getPosition().y < sShields3.getPosition().y + 40 && alienShot3)
			{
				alienShot3 = false;
				shieldState3++;
				shieldDestroyed.play();
			}

			if (sAlienShot2.getPosition().x > sShields3.getPosition().x && sAlienShot2.getPosition().x + 4.5 < sShields3.getPosition().x + 125
				&& sAlienShot2.getPosition().y + 15.6 > sShields3.getPosition().y && sAlienShot2.getPosition().y < sShields3.getPosition().y + 40 && alienShot2)
			{
				alienShot2 = false;
				shieldState3++;
				shieldDestroyed.play();
			}

			if (sAlienShot1.getPosition().x > sShields3.getPosition().x && sAlienShot1.getPosition().x + 4.5 < sShields3.getPosition().x + 125
				&& sAlienShot1.getPosition().y + 15.6 > sShields3.getPosition().y && sAlienShot1.getPosition().y < sShields3.getPosition().y + 40 && alienShot1)
			{
				alienShot1 = false;
				shieldState3++;
				shieldDestroyed.play();
			}
		}

		if (shieldState3 == 1)
		{
			if (sAlienShot3.getPosition().x > sShields3.getPosition().x && sAlienShot3.getPosition().x + 4.5 < sShields3.getPosition().x + 125
				&& sAlienShot3.getPosition().y + 15.6 > sShields3.getPosition().y && sAlienShot3.getPosition().y < sShields3.getPosition().y + 40 && alienShot3)
			{
				alienShot3 = false;
				shieldState3++;
				shieldDestroyed.play();
			}

			if (sAlienShot2.getPosition().x > sShields3.getPosition().x && sAlienShot2.getPosition().x + 4.5 < sShields3.getPosition().x + 125
				&& sAlienShot2.getPosition().y + 15.6 > sShields3.getPosition().y && sAlienShot2.getPosition().y < sShields3.getPosition().y + 40 && alienShot2)
			{
				alienShot2 = false;
				shieldState3++;
				shieldDestroyed.play();
			}

			if (sAlienShot1.getPosition().x > sShields3.getPosition().x && sAlienShot1.getPosition().x + 4.5 < sShields3.getPosition().x + 125
				&& sAlienShot1.getPosition().y + 15.6 > sShields3.getPosition().y && sAlienShot1.getPosition().y < sShields3.getPosition().y + 40 && alienShot1)
			{
				alienShot1 = false;
				shieldState3++;
				shieldDestroyed.play();
			}
		}

		window.draw(sShields3);
	}
	
}

void Player::healthRender(sf::RenderWindow& window)
{
	tHeart.loadFromFile(".\\assets\\textures\\heart.png"); // 150 x 130

	vHeart.x = 150;
	vHeart.y = 130;

	sHeart.setScale(vHeart.x / tHeart.getSize().x * .2f, vHeart.y / tHeart.getSize().y * .2f);
	sHeart.setTexture(tHeart);

	for (int i = 0; i < playerHealth; i++)
	{
		if (createHearts < playerHealth)
		{
			vsHeart.push_back(sHeart);
			createHearts++;
		}

		vsHeart[i].setPosition(sPlayerShip.getPosition().x + (30 * i) + 54, sPlayerShip.getPosition().y + 14);
		window.draw(vsHeart[i]);
	}
}

void Player::levelUp(sf::RenderWindow& window)
{
	sf::Text levelUp;
	levelUp.setFont(spaceFont);
	levelUp.setString("Current level = " + to_string(currentLevel));
	levelUp.setCharacterSize(30);
	levelUp.setFillColor(spaceBlue);
	levelUp.setOutlineColor(sf::Color(52, 133, 188, 255));
	levelUp.setOutlineThickness(1);
	levelUp.setStyle(sf::Text::Bold);
	levelUp.setPosition(400, 0);

	
	if (maxScore == playerScore)
	{
		spaceFont.loadFromFile(".\\assets\\Fonts\\spaceText.ttf");


		

		vSprites.clear();
		shipAlive.clear();
		isRight.clear();
		timer.restart();
		timer2.restart();
		shipShoot1 = false;
		shipShoot2 = false;
		shipShoot3 = false;
		if (shieldState1 >= 3 && shieldState1 > 1)
		{
			shieldState1--;
		}
		if (shieldState2 >= 3 && shieldState2 > 1)
		{
			shieldState2--;
		}
		if (shieldState3 >= 3 && shieldState3 > 1)
		{
			shieldState3--;
		}
		iSpawnShips = 0;
		ticker1 = 1600.f;
		ticker2 = 0;
		ticker3 = 2;
		ticker4 = 4;
		shipSpeed = 800.f - maxScore;
		isShot1 = false;
		isShot2 = false;
		isShot3 = false;
		isShot4 = false;
		isShot5 = false;

		currentLevel++;
		playerHealth = playerHealth + 1;
		maxScore = maxScore + 50;
	}
	window.draw(levelUp);
}

bool Player::GameOver()
{
	gameOver = false;
	
	float maxElementy = 0;
	int counter3 = 0;
	for (int k = 0; k < vSprites.size(); k++)
	{

		if (maxElementy <= vSprites[counter3].getPosition().y)
		{
			if (shipAlive[counter3])
			{
				maxElementy = vSprites[counter3].getPosition().y;
			}
			counter3++;
		}
	}



	if (maxElementy >= 700 || playerHealth <= 0)
	{
		vSprites.clear();
		shipAlive.clear();
		isRight.clear();
		timer.restart();
		timer2.restart();
		shipShoot1 = false;
		shipShoot2 = false;
		shipShoot3 = false;
		iSpawnShips = 0;
		playerScore = 0;
		currentLevel = 1;
		ticker1 = 1600.f;
		ticker2 = 0;
		ticker3 = 2;
		ticker4 = 4;
		shieldState1 = 1;
		shieldState3 = 1;
		shieldState2 = 1;
		shipSpeed = 800.f;
		firstSet = false;
		playerHealth = 3;
		gameOver = true;
	}

	
	return gameOver;
}

void Player::spriteGenerator(sf::Texture& tex, std::string sFileName, size_t size,float x ,float y, sf::Sprite& sprite)
{
	tex.loadFromFile(sFileName);

	sprite.setScale((x / tex.getSize().x) * 0.288f, (y / tex.getSize().y) * 0.288f);
	sprite.setTexture(tex);
}


