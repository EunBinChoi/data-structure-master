#pragma once
#include "CebItem.h" // 링크드 리스트에서 데이터를 저장하는 클래스가 저장되어있는 헤더파일 선언

class CCebItemNode : public CCebItem // 링크드 리스트에서 노드를 지정하는 클래스 선언
{
protected: // 자식에게 접근할 수 있도록 protected로 지정
	CCebItemNode* m_link; // 노드에서 링크 값을 저장하는 CCebItemNode*형 변수 선언

public: // 어디서든 접근할 수 있도록 public 으로 지정
	CCebItemNode(char* name="", int price=0 , int priority = 0, char* method="...") // 생성자
		: CCebItem(name,price,priority,method) // 초기화리스트(CCebItem의 클래스의 생성자를 호출하여 인수로 받은 값을 초기화한다)
	{m_link = NULL;}  // 멤버변수인 노드의 링크 값을 NULL로 초기화
	~CCebItemNode(void){} //소멸자
	CCebItemNode* Next(){ return m_link; } // 노드의 링크 값을 반환하는 함수
	
	int getPriority(){return m_priority;} // CCebItem의 멤버변수인 우선순위를 저장하는 priority 변수를 반환한다
	char* getName(){return m_name;}// CCebItem의 멤버변수인 이름을 저장하는 name 변수를 반환한다
	int getPrice(){return m_price;}// CCebItem의 멤버변수인 가격을 저장하는 price 변수를 반환한다
	char* getMethod(){return m_method;}// CCebItem의 멤버변수인 사는방법를 저장하는 method 변수를 반환한다
	void SetNext( CCebItemNode *link ) { m_link = link; } // 노드의 링크값을 인수로 들어온 링크 값으로 설정하는 함수
	void AddNext(CCebItemNode* n){ // 인수로 들어온 노드를 현재 노드의 다음 값으로 추가하는 함수
		if(n!=NULL){ // 만약 인수로 들어온 n이 NULL이 아니라면
			n->m_link = m_link;  // 인수로 들어온 노드의 링크값(다음 노드의 주소가 들어있는 값)을 m_link(현재 노드의 링크값)으로 주고
			m_link = n; // 현재 링크값(다음 노드의 주소가 들어있는 값)을 n으로 지정
		}
	}

	CCebItemNode* RemoveNext(){ // 다음 노드를 삭제하는 함수
		CCebItemNode* p = m_link; // 현재 노드의 링크값을 임의의 변수 p로 설정한 다음 
		
		if(p != NULL) { // 만약 p가 NULL이 아니면
			m_link = p -> m_link; // 현재 노드의 링크값을 다음 노드의 링크값으로 설정(즉, 현재 노드가 사라짐)
		}
		return p; // 사라진 노드를 반환 
	}
};