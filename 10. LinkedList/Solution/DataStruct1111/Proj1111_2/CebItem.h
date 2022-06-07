#pragma once
#include <string.h> // ���ڿ��� �����ϴ� ������� ����
#include <stdio.h> // ǥ�� ���̺귯�� �Լ��� ����ִ� ������� ����

class CCebItem // ��ũ�� ����Ʈ���� �����͸� �����ϴ� Ŭ���� ����
{

protected: // �ڽĿ��� ������ �� �ֵ��� protected�� ����

	char m_name[40]; // ������ �̸��� �����ϴ� ���ڿ�
	int m_price; // ������ ������ �����ϴ� ������ ����
	int m_priority; // ������ �켱������ �����ϴ� ������ ����
	char m_method[40]; // ������ ��� ����� �����ϴ� ���ڿ�
	
public: // ��𼭵� ������ �� �ֵ��� public ���� ����

	CCebItem(char* name = "", int price = 0 , int priority = 0, char* method="..."){ // ������
		
		strcpy(m_name, name); // �μ��� �޾ƿ� �̸��� �����ϴ� ���ڿ��� ��������� ����
		m_price = price; // �μ��� �޾ƿ� ������ �����ϴ� ������ ������ ��������� ���� 
		m_priority = priority; // �μ��� �޾ƿ� �켱������ �����ϴ� ������ ������ ��������� ����
		strcpy(m_method,method); // �μ��� �޾ƿ� ���ǻ�� ����� �����ϴ� ���ڿ��� ��������� ����
	}
	~CCebItem(void){} // �Ҹ���
	
	void Display(){ printf("[����] : %8s  [����] : %7d  [�켱����] : %2d  [�޼���] : %s\n", m_name, m_price,m_priority,m_method); }
	// ��������� ����ϴ� �Լ�
	// ���ڿ��� ������ ����� �� ������ ���߾� ����Ѵ�
};