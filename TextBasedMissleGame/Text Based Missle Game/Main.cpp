#include "main.h"

//@author Greg Cahill, C00216328
//Date: 18/09/2017
//Text Based Missle Game (T.B.M.G.)
//create a text based game that allows selecting of warhead, aquiring target, entering a launch code
//and then check for the collision


int main()
{
	if (currentAttempt < 1)
	{
		Introduction();
	}
	CoreLoop();
		

	std::system("PAUSE");
	return 0;
}

void CoreLoop()
{
	//This if is the core loop, this will keep looping as long as the player hasnt scored 6 or higher (The win condition)
	//or fired 3 missles and failed to reach the required score (the lose condition)
	if (score < 6 && currentAttempt <= 3)
	{
		CheckRemainingMissles();
		MissleSelection();
		AquiringTarget();
		EnterLaunchCode();
		FireMissle();
	}
	else if(currentAttempt > 3)
	{
		std::system("CLS");		//This clears the screen of text, prevents clutter on the players end
		std::cout << "GAME OVER" << std::endl;
		std::cout << "Restarting simulation..." << std::endl;
		score = 0;
		currentAttempt = 0;
		std::system("PAUSE");   //needed after every speech section, and before the screen clear, so the player can read the text
		std::system("CLS");		//This clears the screen of text, prevents clutter on the players end
		CoreLoop();
	}
	else if (score >= 6)
	{
		std::system("CLS");		//This clears the screen of text, prevents clutter on the players end
		std::cout << "CONGLATURATION" << std::endl;
		std::cout << "Restarting simulation..." << std::endl;
		score = 0;
		currentAttempt = 0;
		std::system("PAUSE");   //needed after every speech section, and before the screen clear, so the player can read the text
		std::system("CLS");		//This clears the screen of text, prevents clutter on the players end
		CoreLoop();
	}
}

void Introduction()
{
	std::cout << "Greetings commander, we just got word over from" << std::endl <<"the boys in intelligence that there is" << std::endl
		<< "a potential threat to our great nation of Tragodia." << std::endl << "As commander, you must assess the situation and choose" << std::endl
		<< "The correct...'problem solver' for" << std::endl << "the mission. Good luck commander" << std::endl << std::endl;
	std::system("PAUSE");   //needed after every speech section, and before the screen clear, so the player can read the text
	std::system("CLS");		//This clears the screen of text, prevents clutter on the players end

	std::cout << "Hey there! I'm you're friendly 'NICE but UNEXPECTDLY" << std::endl << "great at KILLING UNIVERSALLY everyone," << std::endl << "or N.U.K.E for short" << std::endl
		<< "The other words aren't important for the anagram," << std::endl << "and thats totally how anagrams work." << std::endl << "I'm here to guide through the genocide/protection program" << std::endl
		<< "First, we'll get you to select a warhead" << std::endl << ",Nuke is 0, homing missle is 1, regular is 2!" << std::endl << "be warned, you only get two homing missles!" << std::endl << std::endl
		<< "nukes are worth one point, but have a 50 KM explosion radius" << std::endl << ",quite the overkill eh? (hence the genocide)" << std::endl << "however, they are the slowest missle" << std::endl
		<< "homing missles have the smallest explosion radius at 15 km" << std::endl << ",average speed aswell," << std::endl << "but will home in once you" << std::endl << " are withen 20 km of the target! "
		<< "homing missles are also worth two" << std::endl << " points, but we only have" << std::endl << "two at our disposal" << std::endl << "...too much funding spent on nukes." << std::endl
		<< "Finally, regular missles are worth 5 points," << std::endl << "have an explosion radius of 20 km, and no other gimmicks" << std::endl << std::endl;
	std::system("PAUSE");   //needed after every speech section, and before the screen clear, so the player can read the text
	std::system("CLS");		//This clears the screen of text, prevents clutter on the players end
}

void CheckRemainingMissles()
{
	std::cout << "Remaining missles = " << 3 - currentAttempt << std::endl;
	std::cout << "Current Score " << score << std::endl;
	std::system("PAUSE");   //needed after every speech section, and before the screen clear, so the player can read the text
	std::system("CLS");		//This clears the screen of text, prevents clutter on the players end
}

void MissleSelection()
{
	std::cout << "Now then, please choose your choice of mass destruction " << std::endl << "*note, you only get 3 missles to score a 6 or higher" << std::endl;
	std::cin >> missleSelected;
	if (missleSelected < 0 || missleSelected > 2 || (homingMisslesFired >=2 && missleSelected == 1))
	{
		std::cout << "I think we both know that" << std::endl << " wasnt a valid choice, try again" << std::endl << std::endl;
		std::system("PAUSE");   //needed after every speech section, and before the screen clear, so the player can read the text
		std::system("CLS");		//This clears the screen of text, prevents clutter on the players end
		MissleSelection();
	}
	missleObject.missleSetup(missleSelected);
	std::system("CLS");		//This clears the screen of text, prevents clutter on the players end
	//missleObject.missleSetup(missleSelected);
}

void AquiringTarget()
{
	targetXCoord = rand() % 120 + 1;
	targetYCoord = rand() % 120 + 1;

	std::cout << "Using our expert satelites, we were able" << std::endl << " to get an estimated location for the target" << std::endl
		<< "it is somewhere bewtween Co-ordinate " << targetXCoord - rand() % 40 + 1 << " and " << targetXCoord + rand() % 40 + 1 << " on the X plane" << std::endl
		<< ", As for the Y plane," << std::endl << " it is between Co-ordinate " << targetYCoord - rand() % 40 + 1 << " and " << targetYCoord + rand() % 40 + 1 << std::endl << std::endl;

	std::cout << "Please enter where you believe" << std::endl << " the target lie on the X plane" << std::endl;
	std::cin >> playerGuessedCoords[0];
	std::cout << std::endl << "Please enter where you believe" << std::endl << " the target lie on the Y plane" << std::endl;
	std::cin >> playerGuessedCoords[1];

	
	std::system("CLS");		//This clears the screen of text, prevents clutter on the players end


}

void EnterLaunchCode()
{
	std::cout << "now that that's out of the way," << std::endl << " enter the launch code. "<< std::endl << " Its the first level in the original doom, note capitals matter!" << std::endl;
	std::cin >> playerGuessLaunchCode;
	if (playerGuessLaunchCode != launchCode)
	{
		std::cout << "Nope! *its E1M1...c'mon man, try again" << std::endl;
		std::system("PAUSE");   //needed after every speech section, and before the screen clear, so the player can read the text
		std::system("CLS");		//This clears the screen of text, prevents clutter on the players end
		EnterLaunchCode();
	}
	std::system("CLS");		//This clears the screen of text, prevents clutter on the players end
	std::cout << "MISSLE_ARMED" << std::endl;
	std::system("PAUSE");   //needed after every speech section, and before the screen clear, so the player can read the text
	std::system("CLS");		//This clears the screen of text, prevents clutter on the players end
	
}

void FireMissle()
{
	std::cout << "Preparing for launch in T-minus 3..." << std::endl;
	std::system("PAUSE");   //needed after every speech section, and before the screen clear, so the player can read the text
	std::cout << "2..." << std::endl;
	std::system("PAUSE");   //needed after every speech section, and before the screen clear, so the player can read the text
	std::cout << "1.." << std::endl;
	std::system("PAUSE");   //needed after every speech section, and before the screen clear, so the player can read the text
	std::cout << "Take off" << std::endl << std::endl;
	std::system("PAUSE");   //needed after every speech section, and before the screen clear, so the player can read the text
	while (missleObject.getPosX() < playerGuessedCoords[0] &&
		missleObject.getPosY() < playerGuessedCoords[1])
	{
		missleObject.movement();
		std::cout << "Current Missle X Pos" << missleObject.getPosX() << std::endl;
		std::cout << "Current Missle Y Pos" << missleObject.getPosY() << std::endl << std::endl;
		
	}
	std::cout << "Detonation confirmed" << std::endl;
	if (missleSelected == 1)
	{
		homingMisslesFired++;
	}
	std::system("PAUSE");   //needed after every speech section, and before the screen clear, so the player can read the text
	std::system("CLS");		//This clears the screen of text, prevents clutter on the players end

	CheckCollision();
	
	
}

void CheckCollision()
{

	//the plus and minus for each of the switch statements below check if the target coords falls withen the explosion radius
	switch (missleSelected)
	{
	case 0:
		if (playerGuessedCoords[0] + 50 > targetXCoord && playerGuessedCoords[0] - 50 < targetXCoord &&
			playerGuessedCoords[1] + 50 > targetYCoord && playerGuessedCoords[1] - 50 < targetYCoord)
		{
			std::cout << "Confirmed hit commander" << std::endl;
			score = score + 1;
			currentAttempt = currentAttempt + 1;
		}
		else
		{
			std::cout << "Sorry commander...this ones a failure" << std::endl;
			currentAttempt = currentAttempt + 1;
			break;
		}
		break;
	case 1:
		if (playerGuessedCoords[0] + 35 > targetXCoord && playerGuessedCoords[0] - 35 < targetXCoord &&
			playerGuessedCoords[1] + 35 > targetYCoord && playerGuessedCoords[1] - 35 < targetYCoord)
		{
			std::cout << "Confirmed hit commander" << std::endl;
			score = score + 2;
			currentAttempt = currentAttempt + 1;
		}
		else
		{
			std::cout << "Sorry commander...this ones a failure" << std::endl;
			currentAttempt = currentAttempt + 1;
			break;
		}
		break;
	case 2:
		if (playerGuessedCoords[0] + 20 > targetXCoord && playerGuessedCoords[0] - 20 < targetXCoord &&
			playerGuessedCoords[1] + 20 > targetYCoord && playerGuessedCoords[1] - 20 < targetYCoord)
		{
			std::cout << "Confirmed hit commander" << std::endl;
			score = score + 5;
			currentAttempt = currentAttempt + 1;
		}
		else
		{
			std::cout << "Sorry commander...this ones a failure" << std::endl;
			currentAttempt = currentAttempt + 1;
			break;
		}
		break;
		

	}
	std::system("PAUSE");   //needed after every speech section, and before the screen clear, so the player can read the text
	std::system("CLS");		//This clears the screen of text, prevents clutter on the players end
	CoreLoop();
}
