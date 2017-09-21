#pragma once
#ifndef MISSLE
#define MISSLE




class Missle
{
	// private data members
	float XCoord = 0;
	float YCoord = 0;
	float m_missle[2]; //first position stores the X coord of the m_missle, the second position sotres the Y
	float speed;//speed of bullet
	bool missleActive;//bool to determine if the missle is laucnhed or destroyed/not fired
	int m_missleType = 0; //0 = nuke, 1 = heat-seeking, 2 = regular, 3 = regular 'with fries'


public:
	void missleSetup(int missleEntered);					//This setups the intial missle values to their defaults
	void missleType(int missleEntered);					//Setups the type of missle the player selected
	void misslePosition(float xCoord,float yCoord);				//sets where m_missle appears on the screen
	void missleSpeed();					//Sets up the initial speed the missle has
	double getPosY(); //returns x pos
	double getPosX(); //returns y pos
	double newMissleX;
	double newMissleY;
	void m_missleSetupPosition();

	void movement();				//Will update the bullet.



private:

};

#endif // !BULLET

