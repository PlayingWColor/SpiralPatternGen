#include "Scene.h"
#include <iostream>


Scene::Scene()
{

}

void Scene::Update()
{
	//update all nodes
	for (std::size_t i = 0; i < nodes.size(); ++i)
		nodes[i]->update();
	//set views from this scene to be used for drawing this frame
	for (std::size_t i = 0; i < views.size(); ++i)
	{
		sf::Vector2f size = views[i].getSize();
		sf::Vector2f center = views[i].getCenter();
		//std::cout << "(" << center.x << "," << center.y << "," << size.x << "," << size.y << ")" << std::endl;
		SceneManager::addView(&views[i]);
	}
}

void Scene::Draw(sf::RenderTarget& target, std::vector<sf::View*>& allViews)
{
	for (std::size_t i = 0; i < allViews.size(); ++i)
	{
		target.setView(*allViews[i]);

		//draw all nodes
		for (std::size_t i = 0; i < nodes.size(); ++i)
			nodes[i]->draw(target, root);
	}
}

Scene* SceneManager::currentScene = nullptr;
std::vector<sf::View*> SceneManager::views;

bool SceneSettings::window_clearing = true;
sf::Color SceneSettings::window_background = sf::Color(0, 0, 0, 0);

/*
template<class T>
void SceneManager::setScene()
{
	if (currentScene != nullptr)
		delete currentScene;
	currentScene = new T;
}
*/
void SceneManager::updateScene()
{
	if (currentScene != nullptr)
		currentScene->Update();
}

void SceneManager::drawScene(sf::RenderTarget& target)
{
	if (currentScene != nullptr)
		currentScene->Draw(target, views);

	views.clear();
}

void SceneManager::addView(sf::View* view)
{
	views.push_back(view);
}