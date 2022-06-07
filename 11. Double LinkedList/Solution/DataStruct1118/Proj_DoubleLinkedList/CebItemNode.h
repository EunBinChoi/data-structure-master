// ���迡 ��ȯ�� ... �μ������� �� .. �������ؾ��ϴ��� �˾ƾߵ�

#pragma once
#include "CebItem.h" // ���� ��ũ�� ����Ʈ���� �����͸� �����ϴ� Ŭ������ ����Ǿ��ִ� ������� ����

class CCebItemNode : public CCebItem // ��ũ�� ����Ʈ���� ��带 �����ϴ� Ŭ���� ����
{
protected: // �ڽĿ��� ������ �� �ֵ��� protected�� ����
	CCebItemNode* m_prev; // ��忡�� ���� ��ũ ���� �����ϴ� CCebItemNode*�� ���� ����
	CCebItemNode* m_next; // ��忡�� ���� ��ũ ���� �����ϴ� CCebItemNode*�� ���� ����

public: // ��𼭵� ������ �� �ֵ��� public ���� ����

	/* ���� */
	// �θ� Ŭ������ �����ڸ� �θ����� �ʱ�ȭ ����Ʈ�ۿ� �ȵ�
	// �׷��� ���⼭ ������ {}��ȣ �ȿ� �θ�Ŭ������ �����ڸ� �θ��°��� �߸��� �ڵ�

	CCebItemNode(char* name="", int price=0 , int priority = 0, char* method="...") // ������
		: CCebItem(name,price,priority,method) // �ʱ�ȭ����Ʈ(CCebItem�� Ŭ������ �����ڸ� ȣ���Ͽ� �μ��� ���� ���� �ʱ�ȭ�Ѵ�)
	{
		//CCebItem(name,price,priority,method); �̷��� �ϸ� �ȵ� (�θ� Ŭ������ �����ڸ� �θ��� ����̹Ƿ�)
		m_prev = NULL; // ���� ��ũ ���� �����ϴ� CCebItemNode*�� ������ NULL�� ����
		m_next = NULL; // ���� ��ũ ���� �����ϴ� CCebItemNode*�� ������ NULL�� ����
	
	}  
	~CCebItemNode(void){} //�Ҹ���
	CCebItemNode* GetPrev(){ return m_prev; } // ���� ����� ��ũ ���� ��ȯ�ϴ� �Լ�
	CCebItemNode* GetNext(){ return m_next; } // ���� ����� ��ũ ���� ��ȯ�ϴ� �Լ�
	void SetPrev(CCebItemNode* n){m_prev = n;} // ���� ����� ��ũ ���� �μ��� ���� ������ �����ϴ� �Լ�
	void SetNext(CCebItemNode* n){m_next = n;} // ���� ����� ��ũ ���� �μ��� ���� ������ �����ϴ� �Լ�
	// �̷��� ������ ������ �ϱ������ ������� public���� �ϸ� ������ ������������


	void AddNext(CCebItemNode* n){ // ���� ��忡�� �μ��� ���� n�� �߰��ϴ� �Լ�
		if(n != NULL){ // ���� n�� NULL�� �ƴ϶��
			n->m_prev = this; // n�� ���� ��带 this(���� ���)�� ����  
			// n->SetPrev(this)�� ����
			n->m_next = m_next; // n�� ���� ��带 ���� ����� ���� ���� ���� 
			// n->SetNext(m_next);


			if(m_next != NULL){ // ���� ���� ��尡 NULL�� �ƴ϶��
				m_next->m_prev = n; // ���� ����� ���� ��带 n���� ���� 
				// m_next->SetPrev(n);
			}
			m_next = n; // ���� ����� ���� ��带 n���� ����
			// SetNext(n);

		}	
	}

	void Remove(){ // ���� ��带 �����ϴ� �Լ�
		if(m_prev != NULL) // ���� ���� ����� ���� ��尡 NULL�� �ƴ϶��
		{
			m_prev -> m_next = m_next; // ���� ����� ���� ��带 ���� ��ü�� ���� ���� ���� 
			// m_prev->SetNext(m_next);
		}
		if(m_next != NULL){ // ���� ���� ����� ���� ��尡 NULL�� �ƴ϶��
			m_next -> m_prev = m_prev;  // ���� ����� ���� ��带 ���� ��ü�� ���� ���� ����
			// m_next->SetPrev(m_prev);
		}

	}


	int getPriority(){return m_priority;} // CCebItem�� ��������� �켱������ �����ϴ� priority ������ ��ȯ�Ѵ�
	char* getName(){return m_name;}// CCebItem�� ��������� �̸��� �����ϴ� name ������ ��ȯ�Ѵ�
	int getPrice(){return m_price;}// CCebItem�� ��������� ������ �����ϴ� price ������ ��ȯ�Ѵ�
	char* getMethod(){return m_method;}// CCebItem�� ��������� ��¹���� �����ϴ� method ������ ��ȯ�Ѵ�

	
	void DisplayNodeRevRecur(){ // ��带 ������ ������ ó�� ������ �Ųٷ� ����ϴ� �Լ�(��ȯ���� ���)

		if(this != NULL){ // ���� ���� ��尡 NULL�� �ƴ϶��
			this->GetNext()->DisplayNodeRevRecur(); // ���� ����� ���� ��忡�� DisplayNodeRevRecur �Լ��� ȣ��
			this->Display(); // �׸��� ���� ������ ������ ���� ������ �ö���鼭 Display �Լ� ȣ��
		}

		else return; // ���� NULL�̸� ����� �� �����Ƿ� return
	}

};