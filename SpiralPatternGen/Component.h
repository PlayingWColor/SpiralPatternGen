#pragma once
#include "EngineDeclaration.h"

class Component
{
protected:
	Node* m_node;


public:
	Component();
	void Init(Node* node);
	virtual void Begin();
	virtual void Update();
};