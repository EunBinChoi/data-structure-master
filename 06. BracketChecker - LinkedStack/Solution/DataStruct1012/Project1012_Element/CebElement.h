#pragma once
#include <stdio.h>

class CCebElement // ����� ������ ���(��� �ȿ��� �����Ϳ� ��ũ�� ���� ����)�� ��(����)�� �ش��ϴ� ���� �о���̴� Ŭ����
{
	char m_char; // ���ڸ� ������ �� �ִ� ���� ����
public:
	CCebElement(char ch =  0) : m_char(ch){} // ������(��� ���� m_char�� �о�帰 ch ���� ����)
	~CCebElement(void){} // �Ҹ���
	char getChar(){return m_char;} // ����(��� ����)�� ��ȯ�ϴ� �Լ�
	void Display(){printf("%c ", m_char);} // ����(��� ����)�� ������ִ� �Լ�
};

