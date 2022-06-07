#pragma once
#include "CebNode.h"
#include "CebElement.h"

class CCebLinkedDeque : public CCebNode // ���� ���� �����ϱ� ���� Ŭ����(�� Ŭ���������� Node�� �����ϴ� Ŭ������ ��ӹ޴´�)
{
	CCebNode* m_front; // ù ��带 ����Ű�� ���� ��� ������
	CCebNode* m_rear; // ������ ��带 ����Ű�� ���� ��� ������
	int m_nNodes; // �׸��� ������ �����ϴ� ����

public:

	CCebLinkedDeque(void): m_nNodes(0){m_front = m_rear = NULL;}
	// ������
	// m_nNodes�� 0���� �ʱ�ȭ �ϰ�, ù ��带 ����Ű�� ���� �������� m_front�� ������ ��带 ����Ű�� ���� �������� m_rear�� NULL�� �ʱ�ȭ
	~CCebLinkedDeque(void){
		if( m_front != NULL ) 
			delete m_front;
	}
	// �Ҹ���
	// ���� m_front �� NULL�� �ƴϸ� ���� ���� �����Ǿ��ִٴ� ���̹Ƿ�, delete�� ����Ͽ� �����Ѵ� 


	// ���ᵦ�� �����͸� �����ϱ� ���� �Լ�
	void AddRear(CCebNode* e){
		if(IsEmpty()) m_front = m_rear = e;
		// ���� ���� ���� ����ִٸ� m_front�� m_rear�� ��� �μ��� ���� e ���� �����Ѵ�
		else{ // ���� ������� ������
			m_rear -> AddNext(e); // ����� ���� ���� ���� �߰��ϴ� �Լ� AddNext�� ȣ���Ͽ� m_link�� ���� �������ְ�  
			m_rear = e; // m_rear�� �μ��� ���� e�� ����
		}
		m_nNodes++; // �׸��� ������ �����ϴ� ������ m_nNodes�� �ϳ� ������Ų��
	}


	// ���ᵦ�� �����͸� �����ϱ� ���� �Լ�
	void AddFront(CCebNode* e){
		if(IsEmpty()) m_front = m_rear = e;
		// ���� ���� ���� ����ִٸ� m_front�� m_rear�� ��� �μ��� ���� e ���� �����Ѵ�
		else{ // ���� ������� ������
			m_front -> AddPrev(e); // ����� ���� ���� ���� �߰��ϴ� �Լ� AddNext�� ȣ���Ͽ� m_link�� ���� �������ְ�  
			m_front = e; // m_rear�� �μ��� ���� e�� ����
		}
		m_nNodes++; // �׸��� ������ �����ϴ� ������ m_nNodes�� �ϳ� ������Ų��
	}

	// ���ᵦ�� �����͸� �����ϱ� ���� �Լ�
	CCebNode* DeleteRear(){
		if(IsEmpty()) return NULL;
		// ���� ���ᵦ�� ��������� NULL�� ��ȯ 
		CCebNode* n = m_rear; // CCebNode*�� ������ �ϳ� ������ m_rear�� �������ְ�
		if(m_rear->m_prevLink == NULL) m_front = m_rear = NULL; // ���� m_rear�� ���� �ּҸ� �����ϴ� m_link�� NULL�̸� ���� ��尡 ���ٴ�d ���̹Ƿ�, m_front�� m_rear�� ��� NULL�� ����
		else 
		{
			m_rear =  m_rear->m_prevLink; // ���� m_front�� ���� ��� �ּҸ� �����ϴ� m_link�� NULL�� �ƴ϶�� m_front�� m_front�� ���� ����� �����ϰ� �ϰ�
			m_rear -> m_nextLink = NULL; // m_rear�� ���� ����� �ּҸ� NULL�� �ٲ��ش�
		}
		m_nNodes--; // �׸��� ������ �����ϴ� ������ m_nNodes�� �ϳ� ���ҽ�Ų��
		return n; // �׸��� CCebNode*�� ������ �ϳ��� ��ȯ�Ѵ�
	}

	// ���ᵦ�� �����͸� �����ϱ� ���� �Լ�
	CCebNode* DeleteFront(){
		if(IsEmpty()) return NULL;
		// ���� ���ᵦ�� ��������� NULL�� ��ȯ 
		CCebNode* n = m_front; // CCebNode*�� ������ �ϳ� ������ m_front�� �������ְ�
		if(m_front->m_nextLink == NULL) m_front = m_rear = NULL; // ���� m_front�� ���� ��� �ּҸ� �����ϴ� m_link�� NULL�̸� m_front�� ���� ��尡 ���ٴ� ���̹Ƿ�, m_front�� m_rear�� ��� NULL�� ����
		else {
			m_front =  m_front->m_nextLink; // ���� m_front�� ���� ��� �ּҸ� �����ϴ� m_link�� NULL�� �ƴ϶�� m_front�� m_front�� ���� ����� �����ϰ� �ϰ�
			m_front->m_prevLink = NULL;
		}
		m_nNodes--; // �׸��� ������ �����ϴ� ������ m_nNodes�� �ϳ� ���ҽ�Ų��
		return n; // �׸��� CCebNode*�� ������ �ϳ��� ��ȯ�Ѵ�
	}

	// ���ᵦ�� �����͸� �������� �ʰ� ��ȯ�� �ϴ� �Լ�
	CCebNode* GetFront(){
		if(IsEmpty()) return NULL; // ���� ���ᵦ�� ��������� NULL�� ��ȯ 
		CCebNode* n = m_front;  // CCebNode*�� ������ �ϳ� ������ m_front�� �������ְ�

		return n; // �׸��� CCebNode*�� ������ �ϳ��� ��ȯ�Ѵ�
	}

	CCebNode* GetRear(){
		if(IsEmpty()) return NULL; // ���� ���ᵦ�� ��������� NULL�� ��ȯ 
		CCebNode* n = m_rear;  // CCebNode*�� ������ �ϳ� ������ m_rear�� �������ְ�

		return n; // �׸��� CCebNode*�� ������ �ϳ��� ��ȯ�Ѵ�
	}

	bool IsEmpty(){ //���ᵦ�� ����ִ��� Ȯ���ϴ� �Լ�
		return m_nNodes == 0;
		// ���� �׸��� ������ �����ϴ� ���� m_nNodes�� 0�̸� �迭�� ����ִٴ� �ǹ��̰� 0�� �ƴϸ� �迭�� ������� �ʴٴ� �ǹ��̴�

	}
	//bool IsEmpty(){  ���� �����ϴ� �迭�� ����ִ� �� Ȯ���ϴ� �Լ�
	//	return (m_front==NULL && m_rear==NULL);

	//}

	void Display() // ���ᵦ�� �׸� ������ �׸� ���� ���
	{
		CCebNode* p; // CCebNode*�� ������ �ϳ� �����ؼ� 
		printf("[��ü �׸��� ��  %d��] : ",m_nNodes); // ��ü �׸��� ���� �� ������ ������ְ�
		for(CCebNode* p = m_front ; p != NULL; p=p->Next())
			// head ���� Next()��(����� ��ũ ��)�� NULL�� �� ���� �ݺ��ϸ鼭
		{
			p->Display(); // ����� ������ ���� ����Ѵ�

		}
		printf("\n"); // �ٹٲ�
	}

};



