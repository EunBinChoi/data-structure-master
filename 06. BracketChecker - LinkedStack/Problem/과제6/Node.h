#pragma once
#include "CebElement.h"
class CCebNode : public CCebElement 
	// ����� ������ ���� ��� Ŭ����
	// Ŭ���� CCebElement Ŭ������ ��ӹ޴´�(�� Ŭ�������� ����� ���ÿ� �ʿ��� ������ ���� ����ִ�)
{
	CCebNode* m_link; // ���� ����� ��ũ��(���� ����� �ּ�) ���� �����ϴ� ���� ����
	// ���⼭ �ڷ����� CCebNode* �� ������ ����� �ּҸ� �����Ѿ��ϱ� �����̴�
	
public:
	CCebNode(char ch = 0): CCebElement(ch) { m_link = NULL; } // ������
	// ����� �ڽ��Լ��� CCebElement�� ch���� �о�鿩 m_char�� �����ϰ�, ���� ��带 ����Ű�� ������ ���� m_link�� NULL�� �ʱ�ȭ
	~CCebNode(void) { } // �Ҹ���
	CCebNode* Next() { return m_link; } // ���� ����� ��ũ��(���� ����� �ּ�) ������ ��ȯ�ϴ� �Լ�

	void SetLink( CCebNode *p ) { m_link = p; }
	// p�� ���� �޾� m_link�� ���� p�� ���� �����ϴ� �Լ�
	
	void AddNext( CCebNode *p ) { 
		// ����� ���ÿ� ���� ���� �߰��ϴ� �Լ�
		// ���� �о� ���� p�� NULL�� �ƴ϶�� p�� ���� ���̶�� �����ϰ� �߰��Ѵ�
		// ���� ���� �߰��� ���� �� ���� ���� ���� �� m_link�� �ǰ� �Ѵ�
		if( p != NULL ) {
			p->m_link = m_link;
			m_link = p;
		}
	}

	CCebNode* RemoveNext( ) {
		// ����� ���ÿ� ���� ���� �����ϴ� �Լ�
		// ������ ����� ������ ��ũ ���� ������ ���� ����� ��ũ��(���� ����� �ּҰ� ����ִ�)�� �������ְ�
		// ��ũ ���� ��ũ(���� ����� ��ũ(���� ����� ���� ����� �ּҰ� ����ִ�))���� ���� ��ũ��� ����
		CCebNode* p = m_link;
		if( p != NULL ) 
			m_link = p->m_link;
		return p;
		// p�� �� ��ȯ, ���߿� delete �� ���̹Ƿ� ���� ������ ��ũ ���� �����ϴ� �ּҸ� ��ȯ
	}
};


