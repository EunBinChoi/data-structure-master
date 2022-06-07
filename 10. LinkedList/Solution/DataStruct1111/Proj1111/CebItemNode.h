#pragma once
#include "cebitem.h"
class CCebItemNode :
	public CCebItem
{

	CCebItemNode* m_next;
	
public:

	CCebItemNode(char* name = "", int price = 0) : CCebItem(name,price){}

	~CCebItemNode(void)
	{}
};

