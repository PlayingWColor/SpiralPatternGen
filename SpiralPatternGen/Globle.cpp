#include "Globle.h"

sf::Clock Time::clock;
float Time::deltaTime = 0;
float Time::timeInSeconds = 0;
float Time::lastTime = 0;


float Time::getDeltaTime()
{
	return Time::deltaTime;
}

float Time::getTimeInSeconds()
{
	return Time::timeInSeconds;
}

void Time::Update()
{
	timeInSeconds = clock.getElapsedTime().asSeconds();
	deltaTime = timeInSeconds - lastTime;
	lastTime = timeInSeconds;
}