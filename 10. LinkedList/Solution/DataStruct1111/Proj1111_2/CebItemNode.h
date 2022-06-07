#pragma once
#include "CebItem.h" // ��ũ�� ����Ʈ���� �����͸� �����ϴ� Ŭ������ ����Ǿ��ִ� ������� ����

class CCebItemNode : public CCebItem // ��ũ�� ����Ʈ���� ��带 �����ϴ� Ŭ���� ����
{
protected: // �ڽĿ��� ������ �� �ֵ��� protected�� ����
	CCebItemNode* m_link; // ��忡�� ��ũ ���� �����ϴ� CCebItemNode*�� ���� ����

public: // ��𼭵� ������ �� �ֵ��� public ���� ����
	CCebItemNode(char* name="", int price=0 , int priority = 0, char* method="...") // ������
		: CCebItem(name,price,priority,method) // �ʱ�ȭ����Ʈ(CCebItem�� Ŭ������ �����ڸ� ȣ���Ͽ� �μ��� ���� ���� �ʱ�ȭ�Ѵ�)
	{m_link = NULL;}  // ��������� ����� ��ũ ���� NULL�� �ʱ�ȭ
	~CCebItemNode(void){} //�Ҹ���
	CCebItemNode* Next(){ return m_link; } // ����� ��ũ ���� ��ȯ�ϴ� �Լ�
	
	int getPriority(){return m_priority;} // CCebItem�� ��������� �켱������ �����ϴ� priority ������ ��ȯ�Ѵ�
	char* getName(){return m_name;}// CCebItem�� ��������� �̸��� �����ϴ� name ������ ��ȯ�Ѵ�
	int getPrice(){return m_price;}// CCebItem�� ��������� ������ �����ϴ� price ������ ��ȯ�Ѵ�
	char* getMethod(){return m_method;}// CCebItem�� ��������� ��¹���� �����ϴ� method ������ ��ȯ�Ѵ�
	void SetNext( CCebItemNode *link ) { m_link = link; } // ����� ��ũ���� �μ��� ���� ��ũ ������ �����ϴ� �Լ�
	void AddNext(CCebItemNode* n){ // �μ��� ���� ��带 ���� ����� ���� ������ �߰��ϴ� �Լ�
		if(n!=NULL){ // ���� �μ��� ���� n�� NULL�� �ƴ϶��
			n->m_link = m_link;  // �μ��� ���� ����� ��ũ��(���� ����� �ּҰ� ����ִ� ��)�� m_link(���� ����� ��ũ��)���� �ְ�
			m_link = n; // ���� ��ũ��(���� ����� �ּҰ� ����ִ� ��)�� n���� ����
		}
	}

	CCebItemNode* RemoveNext(){ // ���� ��带 �����ϴ� �Լ�
		CCebItemNode* p = m_link; // ���� ����� ��ũ���� ������ ���� p�� ������ ���� 
		
		if(p != NULL) { // ���� p�� NULL�� �ƴϸ�
			m_link = p -> m_link; // ���� ����� ��ũ���� ���� ����� ��ũ������ ����(��, ���� ��尡 �����)
		}
		return p; // ����� ��带 ��ȯ 
	}
};