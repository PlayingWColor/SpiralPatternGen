#pragma once
#include <type_traits>
#include "EngineDeclaration.h"


class Node
{
public:

	Node();
	Node(Node* node);

	void draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const;
	//call update, each camera will add a view, then 
	void update() const;

	template <class T>
	T* addComponent()
	{
		Component* c = new T();
		c->Init(this);
		m_components.push_back(c);
		return (T*)c;
	}

	void setParent(Node* node);
	void addChild(Node* node);
	bool getChild(size_t i, Node* node);
	Node* getChild(size_t i);

	sf::Transformable get_LocalTransform();

protected:
	sf::Transform m_transform;


private:

	virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const = 0;


	std::vector<Component*> m_components;
	Node* m_parent;
	std::vector<Node*> m_children;

	friend class Component;
};

class SpriteNode : public Node
{
public:

	sf::Sprite m_sprite;

private:

	virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const;


};

class ShapeNode : public Node
{
public:
	ShapeNode(sf::Shape* shape);

	sf::Shape* m_shape;

	void updateTransform();

private:

	virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const;

};

class TextNode : public Node
{
public:
	TextNode(sf::Text* shape);

	sf::Text* m_text;

	void updateTransform();

private:

	virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const;

};