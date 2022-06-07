#pragma once
#include "CebElement.h"
class CCebNode : public CCebElement 
	// ����� ť�� ���� ��� Ŭ����
	// ����� ť�� �ʿ��� ������ ���� ����ִ� Ŭ���� CCebElement Ŭ������ ���
{
public:
	CCebNode* m_link; // ���� ����� ��ũ��(���� ����� �ּ�) ���� �����ϴ� ���� ����
	// ���⼭ �ڷ����� CCebNode* �� ������ ����� �ּҸ� �����Ѿ��ϱ� �����̴�
	
public:
	CCebNode(int ch = 0): CCebElement(ch) { m_link = NULL; } // ������
	// ����� �ڽ��Լ��� CCebElement�� ch���� �о�鿩 m_char�� �����ϰ�, ���� ��带 ����Ű�� ������ ���� m_link�� NULL�� �ʱ�ȭ
	~CCebNode(void) { } // �Ҹ���
	CCebNode* Next() { return m_link; } // ���� ����� ��ũ��(���� ����� �ּ�) ������ ��ȯ�ϴ� �Լ�

	void SetLink( CCebNode *p ) { m_link = p; }
	// p�� ���� �޾� m_link�� ���� p�� ���� �����ϴ� �Լ�
	
	void AddNext( CCebNode *p ) { 
		// ����� ť�� ���� ���� �߰��ϴ� �Լ�
		// ���� �о� ���� p�� NULL�� �ƴ϶�� p�� ���� ���̶�� �����ϰ� �߰��Ѵ�
		// ���� ���� �߰��� ���� �� ���� ���� ���� �� m_link�� �ǰ� �Ѵ�
		if( p != NULL ) {
			p->m_link = m_link;
			m_link = p;
		}
	}
	int GetInt(){ // ������ ������ ��ȯ�ϴ� �Լ� 
		return getInt(); // CCebElement�� getChar �Լ��� ȣ���Ͽ� ������ ������ ��ȯ�� �� �ֵ��� �Ѵ�
	}

	CCebNode* RemoveNext( ) {
		// ����� ť�� ���� ���� �����ϴ� �Լ�
		// ������ ����� ť�� ��ũ ���� ������ ���� ����� ��ũ��(���� ����� �ּҰ� ����ִ�)�� �������ְ�
		// ��ũ ���� ��ũ(���� ����� ��ũ(���� ����� ���� ����� �ּҰ� ����ִ�))���� ���� ��ũ��� ����
		CCebNode* p = m_link;
		if( p != NULL ) 
			m_link = p->m_link;
		return p;
		// p�� �� ��ȯ, ���߿� delete �� ���̹Ƿ� ���� ������ ��ũ ���� �����ϴ� �ּҸ� ��ȯ
	}
};


