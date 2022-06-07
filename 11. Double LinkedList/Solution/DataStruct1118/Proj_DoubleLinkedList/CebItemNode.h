// 시험에 반환형 ... 인수같은거 다 .. 뭘선언해야하는지 알아야됨

#pragma once
#include "CebItem.h" // 더블 링크드 리스트에서 데이터를 저장하는 클래스가 저장되어있는 헤더파일 선언

class CCebItemNode : public CCebItem // 링크드 리스트에서 노드를 지정하는 클래스 선언
{
protected: // 자식에게 접근할 수 있도록 protected로 지정
	CCebItemNode* m_prev; // 노드에서 이전 링크 값을 저장하는 CCebItemNode*형 변수 선언
	CCebItemNode* m_next; // 노드에서 다음 링크 값을 저장하는 CCebItemNode*형 변수 선언

public: // 어디서든 접근할 수 있도록 public 으로 지정

	/* 주의 */
	// 부모 클래스의 생성자를 부를때는 초기화 리스트밖에 안됨
	// 그래서 여기서 생성자 {}괄호 안에 부모클래스의 생성자를 부르는것은 잘못된 코드

	CCebItemNode(char* name="", int price=0 , int priority = 0, char* method="...") // 생성자
		: CCebItem(name,price,priority,method) // 초기화리스트(CCebItem의 클래스의 생성자를 호출하여 인수로 받은 값을 초기화한다)
	{
		//CCebItem(name,price,priority,method); 이렇게 하면 안됨 (부모 클래스의 생성자를 부르는 경우이므로)
		m_prev = NULL; // 이전 링크 값을 저장하는 CCebItemNode*형 변수를 NULL로 선언
		m_next = NULL; // 다음 링크 값을 저장하는 CCebItemNode*형 변수를 NULL로 선언
	
	}  
	~CCebItemNode(void){} //소멸자
	CCebItemNode* GetPrev(){ return m_prev; } // 이전 노드의 링크 값을 반환하는 함수
	CCebItemNode* GetNext(){ return m_next; } // 다음 노드의 링크 값을 반환하는 함수
	void SetPrev(CCebItemNode* n){m_prev = n;} // 이전 노드의 링크 값을 인수로 받은 값으로 설정하는 함수
	void SetNext(CCebItemNode* n){m_next = n;} // 다음 노드의 링크 값을 인수로 받은 값으로 설정하는 함수
	// 이렇게 설정자 접근자 하기싫으면 멤버변수 public으로 하면 되지만 권장하지않음


	void AddNext(CCebItemNode* n){ // 현재 노드에서 인수로 받은 n을 추가하는 함수
		if(n != NULL){ // 만약 n이 NULL이 아니라면
			n->m_prev = this; // n의 이전 노드를 this(현재 노드)로 설정  
			// n->SetPrev(this)와 같음
			n->m_next = m_next; // n의 다음 노드를 현재 노드의 다음 노드로 설정 
			// n->SetNext(m_next);


			if(m_next != NULL){ // 만약 다음 노드가 NULL이 아니라면
				m_next->m_prev = n; // 다음 노드의 이전 노드를 n으로 설정 
				// m_next->SetPrev(n);
			}
			m_next = n; // 현재 노드의 다음 노드를 n으로 설정
			// SetNext(n);

		}	
	}

	void Remove(){ // 현재 노드를 삭제하는 함수
		if(m_prev != NULL) // 만약 현재 노드의 이전 노드가 NULL이 아니라면
		{
			m_prev -> m_next = m_next; // 이전 노드의 다음 노드를 현재 객체의 다음 노드로 설정 
			// m_prev->SetNext(m_next);
		}
		if(m_next != NULL){ // 만약 현재 노드의 다음 노드가 NULL이 아니라면
			m_next -> m_prev = m_prev;  // 다음 노드의 이전 노드를 현재 객체의 이전 노드로 설정
			// m_next->SetPrev(m_prev);
		}

	}


	int getPriority(){return m_priority;} // CCebItem의 멤버변수인 우선순위를 저장하는 priority 변수를 반환한다
	char* getName(){return m_name;}// CCebItem의 멤버변수인 이름을 저장하는 name 변수를 반환한다
	int getPrice(){return m_price;}// CCebItem의 멤버변수인 가격을 저장하는 price 변수를 반환한다
	char* getMethod(){return m_method;}// CCebItem의 멤버변수인 사는방법를 저장하는 method 변수를 반환한다

	
	void DisplayNodeRevRecur(){ // 노드를 마지막 노드부터 처음 노드까지 거꾸로 출력하는 함수(순환적인 방법)

		if(this != NULL){ // 만약 현재 노드가 NULL이 아니라면
			this->GetNext()->DisplayNodeRevRecur(); // 현재 노드의 다음 노드에서 DisplayNodeRevRecur 함수를 호출
			this->Display(); // 그리고 가장 마지막 노드부터 현재 노드까지 올라오면서 Display 함수 호출
		}

		else return; // 만약 NULL이면 출력할 수 없으므로 return
	}

};