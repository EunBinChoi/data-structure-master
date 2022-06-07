#pragma once
#include "CebElement.h"
class CCebNode : public CCebElement 
	// ����� ���� ���� ��� Ŭ����
	// ����� ���� �ʿ��� ������ ���� ����ִ� Ŭ���� CCebElement Ŭ������ ���
{
public:
	CCebNode* m_nextLink; // ���� ����� ��ũ��(���� ����� �ּ�) ���� �����ϴ� ���� ����
	CCebNode* m_prevLink; // ���� ����� ��ũ��(���� ����� �ּ�) ���� �����ϴ� ���� ����
	// ���⼭ �ڷ����� CCebNode* �� ������ ����� �ּҸ� �����Ѿ��ϱ� �����̴�


public:
	CCebNode(int ch = 0): CCebElement(ch) { m_nextLink = NULL; m_prevLink = NULL;} // ������
	// ����� �ڽ��Լ��� CCebElement�� ch���� �о�鿩 m_char�� �����ϰ�, ���� ��带 ����Ű�� ������ ���� m_link�� NULL�� �ʱ�ȭ
	~CCebNode(void) { } // �Ҹ���
	CCebNode* Next() { return m_nextLink; } // ���� ����� ��ũ��(���� ����� �ּ�) ������ ��ȯ�ϴ� �Լ�
	CCebNode* Prev() { return m_prevLink; } // ���� ����� ��ũ��(���� ����� �ּ�) ������ ��ȯ�ϴ� �Լ�

	void SetLink( CCebNode *p ) { 
		m_nextLink = p; 
	}
	// p�� ���� �޾� m_link�� ���� p�� ���� �����ϴ� �Լ�

	void AddNext( CCebNode *p ) { 
		// ����� ���� ���� ���� �߰��ϴ� �Լ�
	
		m_nextLink = p;
		p->m_prevLink = this;
		p->m_nextLink = NULL;
	}

	void AddPrev( CCebNode *p ) { 
		// ����� ���� ���� ���� �߰��ϴ� �Լ�
		
		m_prevLink = p;
		p->m_prevLink = NULL;
		p->m_nextLink = this;
	}

	CCebNode* RemovePrev( ) {
		// ����� ���� ���� ���� �����ϴ� �Լ�
		// ������ ����� ���� ��ũ ���� ������ ���� ����� ��ũ��(���� ����� �ּҰ� ����ִ�)�� �������ְ�
		// ��ũ ���� ��ũ(���� ����� ��ũ(���� ����� ���� ����� �ּҰ� ����ִ�))���� ���� ��ũ��� ����
		CCebNode* p = m_prevLink;
		if( p != NULL ) 
			m_prevLink = p->m_prevLink;
		return p;
		// p�� �� ��ȯ, ���߿� delete �� ���̹Ƿ� ���� ������ ��ũ ���� �����ϴ� �ּҸ� ��ȯ
	}

	CCebNode* RemoveNext( ) {
		// ����� ���� ���� ���� �����ϴ� �Լ�
		// ������ ����� ���� ��ũ ���� ������ ���� ����� ��ũ��(���� ����� �ּҰ� ����ִ�)�� �������ְ�
		// ��ũ ���� ��ũ(���� ����� ��ũ(���� ����� ���� ����� �ּҰ� ����ִ�))���� ���� ��ũ��� ����
		CCebNode* p = m_nextLink;
		if( p != NULL ) 
			m_nextLink = p->m_nextLink;
		return p;
		// p�� �� ��ȯ, ���߿� delete �� ���̹Ƿ� ���� ������ ��ũ ���� �����ϴ� �ּҸ� ��ȯ
	}

	int GetInt(){ // ������ ������ ��ȯ�ϴ� �Լ� 
		return getInt(); // CCebElement�� getChar �Լ��� ȣ���Ͽ� ������ ������ ��ȯ�� �� �ֵ��� �Ѵ�
	}


};


