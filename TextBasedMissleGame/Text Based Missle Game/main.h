#include <iostream>
#include <ctime>
#include "Missle.h"
#include <string>

Missle missleObject;
int missleSelected = 0;			//0 for nuke, 1 for homing missle, 2 for regular
int currentAttempt = 0;			//keeps track of which missle the player is on, if exceeds three, gameover
int score = 0;					//the players score, once this is 6 or greater, you win
int homingMisslesFired = 0;		//If thei is equal to two or greater, you cant fire the homing missle anymore
float playerGuessedCoords[2];	//the storage for the players guessed co-ordinates, pos [0] for X, pos [1] for Y
float targetXCoord = 0.0;		//The actual X coord for the target 
float targetYCoord = 0.0;		//The actual Y coord for the target
std::string launchCode = "E1M1";	//The launch code for firing the missle, based on the first level of DOOM (the original version)
std::string playerGuessLaunchCode = ""; //Storage for the players guess of the launch code to be compared to E1M1

void CoreLoop();			//This will loop back on itself until either the player runs out of missles or they score enough points
void Introduction();		//The is the 'Intro blop of text'. Only runs the one time
void CheckRemainingMissles(); //A check before each run through the core loop that shows the players missle remaining and current score
void MissleSelection();		//Contains a switch statement to handle the player selecting which missle they would like to fire
void AquiringTarget();		//contains a random number generator to give an approximate range of the tartget
void EnterLaunchCode();		//asks the player to enter a launch code
void FireMissle();			//Blop of text to show the missle firing
void CheckCollision();		//The function dealing with if the explosion radius hits the target
