#pragma once
#include "CebNode.h"
#include "CebElement.h"

class CCebLinkedQueue : public CCebNode // ���� ť�� �����ϱ� ���� Ŭ����(�� Ŭ���������� Node�� �����ϴ� Ŭ������ ��ӹ޴´�)
{
	CCebNode* m_front; // ù ��带 ����Ű�� ���� ��� ������
	CCebNode* m_rear; // ������ ��带 ����Ű�� ���� ��� ������
	int m_nNodes; // �׸��� ������ �����ϴ� ����

public:

	CCebLinkedQueue(void): m_nNodes(0){m_front = m_rear = NULL;}
	// ������
	// m_nNodes�� 0���� �ʱ�ȭ �ϰ�, ù ��带 ����Ű�� ���� �������� m_front�� ������ ��带 ����Ű�� ���� �������� m_rear�� NULL�� �ʱ�ȭ
	~CCebLinkedQueue(void){
		if( m_front != NULL ) 
			delete m_front;
	}
	// �Ҹ���
	// ���� m_front �� NULL�� �ƴϸ� ���� ť�� �����Ǿ��ִٴ� ���̹Ƿ�, delete�� ����Ͽ� �����Ѵ� 

	// ����ť�� �����͸� �����ϱ� ���� �Լ�
	void EnQueue(CCebNode* e){
		if(IsEmpty()) m_front = m_rear = e;
		// ���� ���� ť�� ����ִٸ� m_front�� m_rear�� ��� �μ��� ���� e ���� �����Ѵ�
		else{ // ���� ������� ������
			m_rear -> AddNext(e); // ����� ť�� ���� ���� �߰��ϴ� �Լ� AddNext�� ȣ���Ͽ� m_link�� ���� �������ְ�  
			m_rear = e; // m_rear�� �μ��� ���� e�� ����
		}
		m_nNodes++; // �׸��� ������ �����ϴ� ������ m_nNodes�� �ϳ� ������Ų��
	}

	// ����ť�� �����͸� �����ϱ� ���� �Լ�
	CCebNode* DeQueue(){
		if(IsEmpty()) return NULL;
		// ���� ����ť�� ��������� NULL�� ��ȯ 
		CCebNode* n = m_front; // CCebNode*�� ������ �ϳ� ������ m_front�� �������ְ�
		if(m_front->m_link == NULL) m_front = m_rear = NULL; // ���� m_front�� ���� ��� �ּҸ� �����ϴ� m_link�� NULL�̸� m_front�� ���� ��尡 ���ٴ� ���̹Ƿ�, m_front�� m_rear�� ��� NULL�� ����
		else m_front =  m_front->m_link; // ���� m_front�� ���� ��� �ּҸ� �����ϴ� m_link�� NULL�� �ƴ϶�� m_front�� m_front�� ���� ����� �����ϰ� �ϰ�
		m_nNodes--; // �׸��� ������ �����ϴ� ������ m_nNodes�� �ϳ� ���ҽ�Ų��
		return n; // �׸��� CCebNode*�� ������ �ϳ��� ��ȯ�Ѵ�
	}

	// ����ť�� �����͸� �������� �ʰ� ��ȯ�� �ϴ� �Լ�
	CCebNode* Peek(){
		if(IsEmpty()) return NULL; // ���� ����ť�� ��������� NULL�� ��ȯ 
		CCebNode* n = m_front;  // CCebNode*�� ������ �ϳ� ������ m_front�� �������ְ�

		return n; // �׸��� CCebNode*�� ������ �ϳ��� ��ȯ�Ѵ�
	}

	bool IsEmpty(){ // ����ť�� �����ϴ� �迭�� ����ִ� �� Ȯ���ϴ� �Լ�
		return m_nNodes == 0;
		// ���� �׸��� ������ �����ϴ� ���� m_nNodes�� 0�̸� �迭�� ����ִٴ� �ǹ��̰� 0�� �ƴϸ� �迭�� ������� �ʴٴ� �ǹ��̴�

	}
	//bool IsEmpty(){  ����ť�� �����ϴ� �迭�� ����ִ� �� Ȯ���ϴ� �Լ�
	//	return (m_front==NULL && m_rear==NULL);

	//}

	void Display() // ����ť�� �׸� ������ �׸� ���� ���
	{
		CCebNode* p; // CCebNode*�� ������ �ϳ� �����ؼ� 
		printf("[��ü �׸��� ��  %d��] : ",m_nNodes); // ��ü �׸��� ���� �� ������ ������ְ�
		for(CCebNode* p = m_front ; p!=NULL; p=p->Next())
			// head ���� Next()��(����� ��ũ ��)�� NULL�� �� ���� �ݺ��ϸ鼭
		{
			p->Display(); // ����� ������ ���� ����Ѵ�

		}
		printf("\n"); // �ٹٲ�
	}

};

