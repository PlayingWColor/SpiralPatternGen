#pragma once
#include "EngineDeclaration.h"
#include <vector>

class Scene
{
public:
	Scene();
	virtual void Update();
	virtual void Draw(sf::RenderTarget& target, std::vector<sf::View*>& allViews);

protected:
	const sf::Transform root;
	std::vector<Node*> nodes;
	std::vector<sf::View> views;
};

struct SceneSettings
{
	static bool window_clearing;
	static sf::Color window_background;
};

class SceneManager
{

private:

	static Scene* currentScene;
	static std::vector<sf::View*> views;

public:

	template<class T>
	static void setScene()
	{
		if (currentScene != nullptr)
			delete currentScene;
		currentScene = new T;
	}
	static void addView(sf::View* view);
	static void updateScene();
	static void drawScene(sf::RenderTarget& target);
};