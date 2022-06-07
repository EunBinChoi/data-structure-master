#pragma once  
#include <stdio.h>
#include "CebPoint2D.h"
#define MAX_STACK_SIZE 100 // MAX_STACK_SIZE �� 100���� ����	

typedef CCebPoint2D		CElement;// CCebPoint2D �̶�� ������ �ڷ����� CElement�� ��ȯ

class CCebStack // ������ ������ ����ϴ� Ŭ����
{

	CElement m_data[MAX_STACK_SIZE]; // ���ÿ� ���� ���ڳ� ���ڸ� ��� �迭, ���⿡�� ���� x,y�� ����
	int m_top; 
	// ������ ���� ���� �ڸ��� ���� ��� �ִ� �ε��� �� + 1
	// ���⼭�� ������ ���� ���� �ε����� �������شٰ� �����ϸ� ����

public:

	CCebStack(void) // ������ 
	{
		Reset(); // �����ڿ����� Reset�� �Լ��� ȣ��
	}

	~CCebStack(void) // �Ҹ���
	{
	}
	
	void Reset(){m_top  = 0;} // m_top�� 0���� ����

	bool IsEmpty(){ // ������ �迭�� ����ִ��� Ȯ���ϴ� �Լ�
		return m_top == 0; // ���� m_top(������ ���� ���� �ε���)�� 0 �̶�� ��, 0�� �ƴ϶�� ����
		/*if(m_top == 0) return true;
		else return false;*/
	}
	
	bool IsFull(){ // ������ �迭�� �� ���ִ��� Ȯ���ϴ� �Լ�
		return m_top == MAX_STACK_SIZE; // ���� m_top(������ ���� ���� �ε���)�� �ִ�ġ�� MAX_STACK_SIZE��� ��, �ƴϸ� ����
	}

	void Push(CElement e){ // ������ �迭�� ���� ����ִ� �Լ�
		if(IsFull())  // ���� ������ �迭�� �� ���ִٸ�..
		{
			printf("Error : ���� ��ȭ ���� \n"); // ���� ��ȭ ������� �޼����� ���
			return ;
		}
		m_data[m_top++] = e; // �迭�� �� ������ �ʴٸ�, ������ �迭�� �Լ��� �μ��� ���� ���� �����Ѵ�
	}
	
	CElement Pop(){  // ������ �迭�� ���� �ϳ��� ���� Ȯ���ϴ� �Լ�
		if(IsEmpty())  // ���� ������ �迭�� ����ִٸ�..
		{
			printf("Error : ���� ���� ���� \n"); // ���� ���� ������� �޼����� ���
			return 0;
		}
		return m_data[--m_top]; // �迭�� ������� �ʴٸ�, ������ �迭�� �ְ� ������ �ϳ��� ���� Ȯ���Ѵ�
	}

	CElement Peek(){  // ������ �迭�� ���� �ϳ��� ���� �ʰ�, �ܼ��� ���� �������� Ȯ���ϴ� �Լ�
		if(IsEmpty()) // ���� ������ �迭�� ����ִٸ�..
		{
			printf("Error : ���� ���� ���� \n"); // ���� ���� ������� �޼��� ���
			return 0;
		}
		return m_data[m_top-1]; 
		// �迭�� �ξ����� �ʴٸ�, ������ �迭�� �ְ� ���� ������ Ȯ��
		// ���⼭ �����ؾ��� ���� m_top�� �� ��ü�� ��ȭ��Ű�� �ʰ�, m_top�� �״�� �ΰ� �װ��� �ϳ� ���� ���� ��ȯ�Ѵٴ� ���̴�
	}

	void Display(){ // ������ �迭�� ���� ����ϴ� �Լ�
		printf("[���� �׸��� �� = %2d] ==>\n", m_top); // ������ �׸��� ���� ����ϰ�,
		for(int i = 0 ; i < m_top ; i++) // 0���� �迭�� �ְ��� �����ϴ� �ε��� - 1���� ���鼭
		{
			printf("<%d %d >", m_data[i].x ,m_data[i].y); // �迭�� ���� ���
			printf("\n");
		}
	}

};


