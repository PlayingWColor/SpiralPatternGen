#include "Node.h"
#include <stack>

Node::Node()
{
	m_parent = nullptr;
}

Node::Node(Node* parent)
{
	m_parent = parent;
}

void Node::draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const
{
	
	//call component updates
	for (std::size_t i = 0; i < m_components.size(); ++i)
		m_components[i]->Update();

	// combine the parent transform with the node's one
	sf::Transform combinedTransform = parentTransform * m_transform;

	// let the node draw itself
	onDraw(target, combinedTransform);

	// draw its children
	for (std::size_t i = 0; i < m_children.size(); ++i)
		m_children[i]->draw(target, combinedTransform);
}

void Node::update() const
{

	//call component updates
	for (std::size_t i = 0; i < m_components.size(); ++i)
		m_components[i]->Update();

	// update its children
	for (std::size_t i = 0; i < m_children.size(); ++i)
		m_children[i]->update();
}

void Node::setParent(Node* node)
{
	m_parent = node;
}

void Node::addChild(Node* node)
{
	m_children.push_back(node);
	node->setParent(this);
}

//if the user wishes to just get and handle nulls themselves
Node* Node::getChild(size_t i)
{
	if (i < m_children.size())
	{
		return m_children[i];
	}
	return nullptr;
}

//if the user wishes to be extra careful
bool Node::getChild(size_t i, Node* node)
{
	if (i < m_children.size())
	{
		node = m_children[i];
		return true;
	}
	return false;
}

//NOTE: INCOMPLETE: only returns position
sf::Transformable Node::get_LocalTransform()
{
	//find path to root node
	std::stack<Node*> nodes;
	
	Node* current = this;
	nodes.push(current);
	while (current != nullptr)
	{
		nodes.push(current);
		current = current->m_parent;
	}


	sf::Transform combined = nodes.top()->m_transform;
	nodes.pop();
	//transform down to this node
	while (nodes.size() > 0)
	{
		combined *= nodes.top()->m_transform;
		nodes.pop();
	}

	const float* m = combined.getMatrix();
	//float scale = std::sqrt(m[0] * m[0] + m[1] * m[1] + m[2] * m[2]);
	sf::Vector2f pos = sf::Vector2f(m[12], m[13]);

	sf::Transformable result;
	result.setPosition(pos);
	//result.setScale(
	return result;
}

void SpriteNode::onDraw(sf::RenderTarget& target, const sf::Transform& transform) const
{
	target.draw(m_sprite, transform);
}

ShapeNode::ShapeNode(sf::Shape* shape)
{
	m_shape = shape;
}

void ShapeNode::updateTransform()
{
	m_transform = sf::Transform(m_shape->getTransform());
}

void ShapeNode::onDraw(sf::RenderTarget& target, const sf::Transform& transform) const
{
	target.draw(*m_shape, transform);
}

TextNode::TextNode(sf::Text* text)
{
	m_text = text;
}

void TextNode::updateTransform()
{
	m_transform = sf::Transform(m_text->getTransform());
}

void TextNode::onDraw(sf::RenderTarget& target, const sf::Transform& transform) const
{
	target.draw(*m_text, transform);
}