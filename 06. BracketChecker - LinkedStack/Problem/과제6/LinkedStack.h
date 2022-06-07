#pragma once
#include "CebNode.h"

class CCebLinkedStack // ����� ������ �����ϱ� ���� Ŭ����
{
	CCebNode m_org; // CCebNode Ŭ������ ��ü�� �����
	
public:

	CCebLinkedStack(void){} // ������
	~CCebLinkedStack(void){} // �Ҹ���

	// Peak�� ����
	CCebNode* GetHead(){ // ����� ������ head ���� ��� �Լ�
		return m_org.Next(); // ���� ����Ű�� �ִ� ���(���� ���� �����Ƿ� head�� ��)�� ��ũ ���� ��ȯ�Ѵ�
	} 

	bool IsEmpty(){ 
		// ����� ������ ����ִ��� Ȯ���ϴ� �Լ�
		// ���� ����ִٸ� TRUE�� ��ȯ, ������� �ʴٸ� FALSE�� ��ȯ
		return GetHead() == NULL; 
		// GetHead == NULL�� ���� TRUE �̸� �� ������ ����ִ� ���̰�
		// FALSE��� �� ������ ������� �ʴٴ� ���̴�
	}
	
	int GetLength() // ����Ʈ �׸� ���� ��ȯ
	{
		int count = 0 ; // �׸��� ������ ������ ������ ���� ����
		for(CCebNode* p = GetHead() ; p!=NULL; p=p->Next())
			// head ���� Next()��(����� ��ũ ��)�� NULL�� �� ���� �ݺ��ϸ鼭
		{
			count ++; // count ���� ������Ų��
		}

		return count; // ����Ʈ�� �׸��� ������ �����ϴ� ����(count) ��ȯ


	}


	void DisPlay() // ����Ʈ �׸� ���� ���
	{
		printf("[%d]����", GetLength());

		for(CCebNode* p = GetHead() ; p!=NULL; p=p->Next())
			// head ���� Next()��(����� ��ũ ��)�� NULL�� �� ���� �ݺ��ϸ鼭
		{
			p->Display(); // ����� ������ ���� ����Ѵ�
		}
		printf("\n");
	}

	void AddHead(CCebNode* n) // Push();
	{
		m_org.AddNext(n); // ���� ���� �߰��ϴ� �Լ� ȣ��
	}

	CCebNode* RemoveHead() // Pop();
	{
		return m_org.RemoveNext(); // ���� ���� �����ϴ� �Լ� ȣ��
	}


	void Reset(){ // ����� ������ �����ϴ� �Լ�
		Clear(); // Clear �Լ��� �θ���
		// �� �Լ��� ����� ������ �� ������ �� ������ ���� ���� �����Ѵ�
		m_org.SetLink(NULL); // SetLink �Լ��� ���� ���� ����� ��ũ ���� NULL�� ����
	}	

	void Clear() // ����� ������ ������� �� ���� ���� ���� �����ϴ� �Լ�
	{
		while(!IsEmpty()){ // �ݺ����� ���鼭 ���� ������� ������
			delete RemoveHead(); 
			// ���� ���� �����ϴ� �Լ��� ȣ���ϰ�, �� ���� ��ȯ���� delete �Ѵ�
		}

	}
	void Push(char ch){ // Push �Լ�(����� ���ÿ� ���� ����ִ� �Լ�)
		AddHead(new CCebNode(ch)); 
		// ���� ���� �ش��ϴ� ���� �����Ҵ��� ���� CCebNode ��带 �������ְ�, ���� ���� �߰��ϴ� �Լ��� ȣ���Ѵ�
	}

	char Pop(){ // Pop �Լ�(����� ���ÿ� ���� �����ϴ� �Լ�)
		CCebNode* p = RemoveHead();
		// head ���� �����ϴ� �Լ� ȣ��
		// ������ ����� ��ũ ���� p�� �����Ѵ� 

		if(p == NULL) return -1;  // ���� p�� NULL�̸� �������ְ�
		
		// NULL�� �ƴ϶�� ������ ���� �����Ѵ�
		char ch = p->getChar(); // ������ ����� ������ ���� �о�鿩 ch�� �����ϰ� 
		delete p; // �����Ҵ��� p���� delete�� �����Ѵ�
		return ch; // ������ ���� ��ȯ�Ѵ�
	}

	char Peek(){ // Peek �Լ�(����� ���ÿ� ���� �������� �ʰ�, ���� �������� Ȯ���ϴ� �Լ�)
		CCebNode* p = GetHead();
		// head ��(���� ����� ��ũ��)�� �о���δ�

		if(p == NULL) return -1;   // ���� p�� NULL�̸� �������ְ�

		// NULL�� �ƴ϶�� ������ ���� �����Ѵ�
		char ch = p->getChar(); // ����� ������ ���� �о�鿩 ch�� �����ϰ� 
		return ch; // ������ ���� ��ȯ�Ѵ�
	}

};

