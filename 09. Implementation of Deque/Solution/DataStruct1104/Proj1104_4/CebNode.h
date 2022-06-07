#pragma once
#include "CebElement.h"
class CCebNode : public CCebElement 
	// 연결된 덱을 위한 노드 클래스
	// 연결된 덱을 필요한 데이터 값이 들어있는 클래스 CCebElement 클래스를 상속
{
public:
	CCebNode* m_nextLink; // 현재 노드의 링크값(다음 노드의 주소) 값을 저장하는 변수 선언
	CCebNode* m_prevLink; // 현재 노드의 링크값(이전 노드의 주소) 값을 저장하는 변수 선언
	// 여기서 자료형이 CCebNode* 인 이유는 노드의 주소를 가리켜야하기 때문이다


public:
	CCebNode(int ch = 0): CCebElement(ch) { m_nextLink = NULL; m_prevLink = NULL;} // 생성자
	// 노드의 자식함수인 CCebElement에 ch값을 읽어들여 m_char에 저장하고, 다음 노드를 가리키는 포인터 변수 m_link을 NULL로 초기화
	~CCebNode(void) { } // 소멸자
	CCebNode* Next() { return m_nextLink; } // 현재 노드의 링크값(다음 노드의 주소) 변수를 반환하는 함수
	CCebNode* Prev() { return m_prevLink; } // 현재 노드의 링크값(이전 노드의 주소) 변수를 반환하는 함수

	void SetLink( CCebNode *p ) { 
		m_nextLink = p; 
	}
	// p의 값을 받아 m_link의 값에 p의 값을 저장하는 함수

	void AddNext( CCebNode *p ) { 
		// 연결된 덱에 다음 값을 추가하는 함수
	
		m_nextLink = p;
		p->m_prevLink = this;
		p->m_nextLink = NULL;
	}

	void AddPrev( CCebNode *p ) { 
		// 연결된 덱에 이전 값을 추가하는 함수
		
		m_prevLink = p;
		p->m_prevLink = NULL;
		p->m_nextLink = this;
	}

	CCebNode* RemovePrev( ) {
		// 연결된 덱에 다음 값을 제거하는 함수
		// 임의의 연결된 덱의 링크 값을 선언해 현재 노드의 링크값(다음 노드의 주소가 들어있는)을 대입해주고
		// 링크 값의 링크(다음 노드의 링크(다음 노드의 다음 노드의 주소가 들어있는))값을 현재 링크라고 지정
		CCebNode* p = m_prevLink;
		if( p != NULL ) 
			m_prevLink = p->m_prevLink;
		return p;
		// p의 값 반환, 나중에 delete 할 것이므로 다음 값에서 링크 값을 저장하는 주소를 반환
	}

	CCebNode* RemoveNext( ) {
		// 연결된 덱에 다음 값을 제거하는 함수
		// 임의의 연결된 덱의 링크 값을 선언해 현재 노드의 링크값(다음 노드의 주소가 들어있는)을 대입해주고
		// 링크 값의 링크(다음 노드의 링크(다음 노드의 다음 노드의 주소가 들어있는))값을 현재 링크라고 지정
		CCebNode* p = m_nextLink;
		if( p != NULL ) 
			m_nextLink = p->m_nextLink;
		return p;
		// p의 값 반환, 나중에 delete 할 것이므로 다음 값에서 링크 값을 저장하는 주소를 반환
	}

	int GetInt(){ // 정수형 변수를 반환하는 함수 
		return getInt(); // CCebElement의 getChar 함수를 호출하여 정수형 변수를 반환할 수 있도록 한다
	}


};


