#include <SFML/Graphics.hpp>
#include <cmath>
#include "EngineDeclaration.h"
#include "EventTracker.h"
#include "Scenes.h"

int main()
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 3;
	settings.minorVersion = 0;

	sf::RenderWindow window(sf::VideoMode(1600, 900), "Spiraling Pattern Generator", sf::Style::Default, settings);
	EventTracker::initialize(window);

	SceneManager::setScene<PatternGenerator>();
	window.clear(SceneSettings::window_background);

	bool mousePressed = false;

	while (window.isOpen())
	{
		sf::Event event;
		EventTracker::newFrame();
		while (window.pollEvent(event))
		{
			if (EventTracker::checkEvent(event)) {}

			else if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		Time::Update();

		if(SceneSettings::window_clearing)
			window.clear(SceneSettings::window_background);

		//eventually add ability to update multiple scenes
		SceneManager::updateScene();
		SceneManager::drawScene(window);
		//debugScene.Update(window);

		window.display();
	}

	return 0;
}