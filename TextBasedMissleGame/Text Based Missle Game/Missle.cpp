#include "missle.h"


void Missle::missleSetup(int missleEntered)//initialise bullet
{
	m_missleSetupPosition();
	missleType(missleEntered);
	missleSpeed();
}

void Missle::missleType(int missleEntered)//set size
{
	m_missleType = missleEntered;
}

void Missle::misslePosition(float xCoord, float yCoord)//set position
{
	m_missle[0] = xCoord;
	m_missle[1] = yCoord;

	//setup the position of missle variable, start a 0,0 where base is
}

void Missle::missleSpeed()//set speed
{
	//*change this to approperiate speed depending on the missle type
	switch (m_missleType)
	{
	case 0:
		speed = 10;
		break;
	case 1:
		speed = 15;
		break;
	case 2:
		speed = 30;
		break;
	case 3:
		speed = 30;
		break;
	}
}


double Missle::getPosY() //return y pos
{
	double Y = m_missle[1];
	return Y;
	//Return the Y co-ord
}

double Missle::getPosX() //return x pos
{
	double X = m_missle[0];
	return X;
}


void Missle::movement() //move the bullet
{
	
	m_missle[0] += speed / 60;   //divide by 60 to account for fram rate, otherwise we would get a ludicrously fast missle
	m_missle[1] += speed / 60;
	
}


void Missle::m_missleSetupPosition()
{
	m_missle[0] = 0.0;
	m_missle[1] = 0.0;
}
