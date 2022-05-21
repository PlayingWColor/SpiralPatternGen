#include "Components.h"
#include <cmath>

float clampVal01(const float inV)
{
	if (inV > 1)
		return 1;
	else if (inV < 0)
		return 0;
	else
		return inV;
}

int clampVal255(const int inV)
{
	if (inV > 255)
		return 255;
	else if (inV < 0)
		return 0;
	else
		return inV;
}

sf::Color saturate(const sf::Color inC)
{
	return sf::Color(clampVal255(inC.r), clampVal255(inC.g), clampVal255(inC.b), clampVal255(inC.a));
}

sf::Color HUEtoRGB(const float H)
{
	float R = clampVal01(2 - std::abs(H * 6)) + clampVal01(2 - std::abs(H * 6 - 6));
	float G = clampVal01(2 - std::abs(H * 6 - 2));
	float B = clampVal01(2 - std::abs(H * 6 - 4));
	return (sf::Color(R*255, G * 255, B * 255,255));
}

void Rainbowify::Begin()
{
	shape = (sf::CircleShape*)((ShapeNode*)m_node)->m_shape;
}

void Rainbowify::Update()
{
	hueVal += Time::getDeltaTime()*speed;

	if (hueVal > 1)
		hueVal -= 1;

	sf::Color c = HUEtoRGB(hueVal);

	c = sf::Color(c.r/3 + 169, c.g/3 + 169, c.b/3 + 169, 20);

	shape->setFillColor(c);//(sf::Color(randomNum, randomNum, randomNum, 255));
}