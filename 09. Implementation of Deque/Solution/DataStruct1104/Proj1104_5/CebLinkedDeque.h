#pragma once
#include "CebNode.h"
#include "CebElement.h"

class CCebLinkedDeque : public CCebNode // ���� ���� �����ϱ� ���� Ŭ����(�� Ŭ���������� Node�� �����ϴ� Ŭ������ ��ӹ޴´�)
{
	CCebNode m_front; // ù ��带 ����Ű�� ���� ��� ���
	CCebNode m_rear; // ������ ��带 ����Ű�� ���� ��� ���
	int m_nNodes; // �׸��� ������ �����ϴ� ����

public:

	CCebNode* GetHead(){ // ����� ���� head �� ��ũ���� ��� �Լ�
		return m_front.Next(); // ù ��带 ����Ű�� ��� ��� m_front�� ���� ����� �ּҸ� �����ϴ� ��ũ ���� ��ȯ
	}

	CCebNode* GetRear(){ // ����� ���� rear �� ��ũ���� ��� �Լ�
		return m_rear.Next(); // ������ ��带 ����Ű�� ��� ��� m_rear�� ���� ����� �ּҸ� �����ϴ� ��ũ ���� ��ȯ
	} 


	CCebLinkedDeque(void): m_nNodes(0){m_front = m_rear = NULL;}
	// ������
	// m_nNodes�� 0���� �ʱ�ȭ �ϰ�, ù ��带 ����Ű�� ���� ����� m_front�� ������ ��带 ����Ű�� ���� ����� m_rear�� NULL�� �ʱ�ȭ
	~CCebLinkedDeque(void){ // �Ҹ���
		if( GetHead() != NULL ) { // ���� ����� ���� �����Ǿ��ִٸ�
			delete GetHead(); // head�� ��ũ���� ��� delete ���ְ�
			delete GetRear(); // rear�� ��ũ���� ��� delete ���ش�
		}
	}

	// ���ᵦ�� �����͸� �Ĵܻ����ϱ� ���� �Լ�
	void AddRear(CCebNode* e){
		if(IsEmpty()){ // ���� ���������
			m_front.m_nextLink = e; // ù ��带 ����Ű�� ���� ����� ��ũ ���� e�� ����
			m_rear.m_nextLink = e; // ������ ��带 ����Ű�� ���� ����� ��ũ ���� e�� ����

		}

		else{ // ���� ������� ������
			  
			m_rear.m_nextLink->AddNext(e); // ����� ���� ���� ����� ��ũ�� �߰��ϴ� �Լ� AddNext�� ȣ���Ͽ� ���� ����� ��ũ ���� �������ְ�
			m_rear.m_nextLink = e; // ������ ��带 ����Ű�� ���� ����� ��ũ ���� e�� ����(e�� ���� ������ ��尡 �Ǵ� ��)
			
		}
		m_nNodes++; // �׸��� ������ �����ϴ� ������ m_nNodes�� �ϳ� ������Ų��
	}


	// ���ᵦ�� �����͸� ���ܻ����ϱ� ���� �Լ�
	void AddFront(CCebNode* e){
		if(IsEmpty()){  // ���� ���������
			m_front.m_nextLink = e; // ù ��带 ����Ű�� ���� ����� ��ũ ���� e�� ����
			m_rear.m_nextLink = e; // ������ ��带 ����Ű�� ���� ����� ��ũ ���� e�� ����
		}
		else{ // ���� ������� ������

			m_front.m_nextLink->AddPrev(e); // ����� ���� ���� ����� ��ũ�� �߰��ϴ� �Լ� AddPrev�� ȣ���Ͽ� ���� ����� ��ũ ���� �������ְ�
			m_front.m_nextLink = e; // ó�� ��带 ����Ű�� ���� ����� ��ũ ���� e�� ����(e�� ���� ó�� ��尡 �Ǵ� ��)
		}
		m_nNodes++; // �׸��� ������ �����ϴ� ������ m_nNodes�� �ϳ� ������Ų��
	}

	// ���ᵦ�� �����͸� �Ĵܻ����ϱ� ���� �Լ�
	CCebNode* DeleteRear(){
		if(IsEmpty()) return NULL;
		// ���� ���ᵦ�� ��������� NULL�� ��ȯ 
		CCebNode* n = m_rear.Next(); // CCebNode*�� ������ �ϳ� ������ m_rear�� ��ũ���� �������ְ�
		if(m_rear.m_nextLink->Prev() == NULL) m_front.m_nextLink = m_rear.m_nextLink = NULL;
		// ���� ������ ��带 ����Ű�� m_rear�� ���� ��尡 ���ٸ� �ϳ��� ��常 �����Ѵٴ� �� �̹Ƿ�
		// m_front�� m_rear�� ���� ��ũ�� NULL�� ����

		else  // �ϳ��� ��常 �����ϴ� ���� �ƴ϶��
		{
			n->m_prevLink->m_nextLink = NULL; 
			// m_rear�� ����Ű�� �ִ� ����� ���� ����� ���� ��ũ���� NULL�� �����ϰ�
			m_rear.m_nextLink = n->m_prevLink;
			// ������ ��带 ����Ű�� ������ m_rear�� ���� ���� ���� ����
		}
		m_nNodes--; // �׸��� ������ �����ϴ� ������ m_nNodes�� �ϳ� ���ҽ�Ų��
		return n; // �׸��� CCebNode*�� ������ �ϳ��� ��ȯ�Ѵ�
	}

	// ���ᵦ�� �����͸� ���ܻ����ϱ� ���� �Լ�
	CCebNode* DeleteFront(){
		if(IsEmpty()) return NULL; 
		// ���� ���ᵦ�� ��������� NULL�� ��ȯ 
		CCebNode* n = m_front.Next(); // CCebNode*�� ������ �ϳ� ������ m_front�� ��ũ���� �������ְ�
		
		if(m_front.m_nextLink->Next() == NULL) m_front.m_nextLink = m_rear.m_nextLink = NULL;
		// ���� ó�� ��带 ����Ű�� m_front�� ���� ��尡 ���ٸ� �ϳ��� ��常 �����Ѵٴ� �� �̹Ƿ�
		// m_front�� m_rear�� ���� ��ũ�� NULL�� ����
		else {
			n->m_nextLink->m_prevLink = NULL;
			// m_front�� ����Ű�� �ִ� ����� ���� ����� ���� ��ũ���� NULL�� �����ϰ�
			m_front.m_nextLink = n->m_nextLink;
			// ó�� ��带 ����Ű�� ������ m_front�� ���� ���� ���� ����
		}

		m_nNodes--; // �׸��� ������ �����ϴ� ������ m_nNodes�� �ϳ� ���ҽ�Ų��
		return n; // �׸��� CCebNode*�� ������ �ϳ��� ��ȯ�Ѵ�
	}

	

	bool IsEmpty(){ // ���� ����ִ��� �׷��� ������ Ȯ���ϴ� �Լ�
		return m_nNodes == 0;
		// ���� �׸��� ������ �����ϴ� ���� m_nNodes�� 0�̸� ����ִٴ� �ǹ�

	}
	
	void Display() // ���� �׸��� ���� ���� �����͵��� ����ϴ� �Լ�
	{
		CCebNode* p; // CCebNode*�� ������ �ϳ� �����ؼ� 
		printf("[��ü �׸��� ��  %d��] : ",m_nNodes); // ��ü �׸��� ���� �� ������ ������ְ�
		for(CCebNode* p = m_front.Next() ; p != NULL; p = p->Next())
			// p�� ���� m_front�� Next()������ ��� ���� ��ũ ���� �����ϸ鼭 �� ���� NULL�� ������ �ݺ�
		{
			p->Display(); // ����� ������ ���� ����Ѵ�

		}
		printf("\n"); // �ٹٲ�
	}

};

