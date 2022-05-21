#pragma once
#include <SFML/Graphics.hpp>

struct buttonInfo
{
	bool pressed;
	bool held;
	bool released;
};

class EventTracker
{
public:
	static void initialize(sf::RenderTarget& window);
	static void newFrame();
	static bool checkEvent(sf::Event& event);
	static bool get_mouseLeftPressed();
	static bool get_mouseLeftHeld();
	static bool get_mouseLeftReleased();
	static bool get_mouseRightPressed();
	static bool get_mouseRightHeld();
	static bool get_mouseRightReleased();
	static sf::Vector2i get_windowSize();
	static sf::Vector2i get_mousePos();
private:
	static buttonInfo mouseLeft;
	static buttonInfo mouseRight;
	static sf::Vector2i windowSize;
	static sf::Vector2i mousePos;
};