#pragma once
#include<string.h>
#include<stdio.h>
class CCebItem
{
	int m_price;
	char m_name[40];
public:

	CCebItem(char* name = "", int price = 0)
	{
		m_price = price;
		strcpy(m_name, name);
	}

	~CCebItem(void)
	{	}

	void Print(){
		printf("%20s %10d\n", m_name, m_price);
	}
};

