#pragma once
#include <stdio.h>

class CCebElement // ����� ���� ���(��� �ȿ��� �����Ϳ� ��ũ�� ���� ����)�� ��(����)�� �ش��ϴ� ���� �о���̴� Ŭ����
{
	int m_char; // ������ ������ �� �ִ� ���� ����
public:
	CCebElement(int ch =  0) : m_char(ch){} // ������(��� ���� m_char�� �о�帰 ch ���� ����)
	~CCebElement(void){} // �Ҹ���
	int getInt(){return m_char;} // ������ ����(��� ����)�� ��ȯ�ϴ� �Լ�
	void Display(){printf("%d ", m_char);} // ������ ����(��� ����)�� ������ִ� �Լ�
	
};

