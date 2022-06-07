#pragma once
#include <string.h> // ���ڿ��� �����ϴ� ������� ����
#include <stdio.h> // ǥ�� ���̺귯�� �Լ��� ����ִ� ������� ����

class CCebItem // ���� Ʈ������ �����͸� �����ϴ� Ŭ���� ����
{
	char m_name[40]; // ������ �̸��� �����ϴ� ���ڿ�
	int m_price; // ������ ������ �����ϴ� ������ ����
	int m_priority; // ������ �켱������ �����ϴ� ������ ����
	char m_method[40]; // ������ ��� ����� �����ϴ� ���ڿ�
	
public: // ��𼭵� ������ �� �ֵ��� public ���� ����

	CCebItem( int priority = 0,char* name = "",int price = 0 ,  char* method="..."){ // ������
		
		strcpy(m_name, name); // �μ��� �޾ƿ� �̸��� �����ϴ� ���ڿ��� ��������� ����
		m_price = price; // �μ��� �޾ƿ� ������ �����ϴ� ������ ������ ��������� ���� 
		m_priority = priority; // �μ��� �޾ƿ� �켱������ �����ϴ� ������ ������ ��������� ����
		strcpy(m_method,method); // �μ��� �޾ƿ� ���ǻ�� ����� �����ϴ� ���ڿ��� ��������� ����
	}
	~CCebItem(void){} // �Ҹ���
	
	void Display(){ printf(" [�켱����] : %2d [����] : %8s  [����] : %5d  [�޼���] : %s\n", m_priority,m_name, m_price,m_method); }
	// ��������� ����ϴ� �Լ�
	// ���ڿ��� ������ ����� �� ������ ���߾� ����Ѵ�

	bool HasName(char* name){return strcmp(name,m_name)==0;} 
	// �μ��� ���� name�� ������� m_name�� ������ ��
	// ���� �� ���ڿ��� ���ٸ� strcmp �Լ��� 0�� ��ȯ��
	
	bool IsPriceRange(int min,int max){ // �μ���  min max ���� �޾� ���� ��������� m_price �� ���̿� ������ true�� return
		return (m_price >=min && m_price <= max);
	
	} 

	char* getName(){return m_name;} // ��������� �̸��� �����ϴ� ���ڿ��� ��ȯ�ϴ� �Լ�
	int getPrice(){return m_price;} // ��������� ������ �����ϴ� ������ ������ ��ȯ�ϴ� �Լ�
	int getPriority(){return m_priority;} // ��������� �켱������ �����ϴ� ������ ������ ��ȯ�ϴ� �Լ�
	char* getMethod(){return m_method;} // ��������� ��� ����� �����ϴ� ���ڿ��� ��ȯ�ϴ� �Լ�
};