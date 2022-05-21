#include "EventTracker.h"

buttonInfo EventTracker::mouseLeft = { false, false, false};
buttonInfo EventTracker::mouseRight = { false, false, false };
sf::Vector2i EventTracker::mousePos = sf::Vector2i(0, 0);
sf::Vector2i EventTracker::windowSize = sf::Vector2i(0, 0);

bool EventTracker::get_mouseLeftHeld() { return EventTracker::mouseLeft.held; }
bool EventTracker::get_mouseLeftPressed() { return EventTracker::mouseLeft.pressed; }
bool EventTracker::get_mouseLeftReleased() { return EventTracker::mouseLeft.released; }
bool EventTracker::get_mouseRightHeld() { return EventTracker::mouseRight.held; }
bool EventTracker::get_mouseRightPressed() { return EventTracker::mouseRight.pressed; }
bool EventTracker::get_mouseRightReleased() { return EventTracker::mouseRight.released; }

sf::Vector2i EventTracker::get_mousePos() { return EventTracker::mousePos; }
sf::Vector2i EventTracker::get_windowSize() { return EventTracker::windowSize; }

void EventTracker::newFrame()
{
	mouseLeft.pressed = false;
	mouseLeft.released = false;

	mouseRight.pressed = false;
	mouseRight.released = false;
}

void EventTracker::initialize(sf::RenderTarget& window)
{
	sf::Vector2f size = window.getView().getSize();
	windowSize = (sf::Vector2i)window.getView().getSize();// sf::Vector2i(size.x, size.y);
}

bool EventTracker::checkEvent(sf::Event& event)
{
	if (event.type == sf::Event::Resized)
	{
		windowSize = sf::Vector2i(event.size.width, event.size.height);
	}
	
	else if (event.type == sf::Event::MouseButtonPressed)
	{

		if (event.mouseButton.button == sf::Mouse::Left)
		{
			mouseLeft.held = true; mouseLeft.pressed = true;
		}
		else if (event.mouseButton.button == sf::Mouse::Right)
		{
			mouseRight.held = true; mouseRight.pressed = true;
		}

		mousePos = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);

		return true;
	}

	else if (event.type == sf::Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			mouseLeft.held = false; mouseLeft.released = true;
		}
		else if (event.mouseButton.button == sf::Mouse::Right)
		{
			mouseRight.held = false; mouseRight.released = true;
		}
		return true;
	}

	else if (event.type == sf::Event::MouseMoved)
	{
		mousePos = sf::Vector2i(event.mouseMove.x, event.mouseMove.y);
		
		return true;
	}

	return false;
}