#pragma once
#include <SFML/Graphics.hpp>

class Time
{
private:
	static sf::Clock clock;
	static float deltaTime;
	static float timeInSeconds;
	static float lastTime;
public:
	static float getDeltaTime();
	static float getTimeInSeconds();
	static void Update();
};