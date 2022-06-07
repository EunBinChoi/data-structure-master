#pragma once
#include "CebNode.h"
#include "CebElement.h"

class CCebLinkedDeque : public CCebNode // 연결 덱를 구현하기 위한 클래스(이 클래스에서는 Node를 구현하는 클래스를 상속받는다)
{
	CCebNode m_front; // 첫 노드를 가리키기 위한 노드 헤드
	CCebNode m_rear; // 마지막 노드를 가리키기 위한 노드 헤드
	int m_nNodes; // 항목의 개수를 저장하는 변수

public:

	CCebNode* GetHead(){ // 연결된 덱의 head 의 링크값을 얻는 함수
		return m_front.Next(); // 첫 노드를 가리키는 노드 헤드 m_front의 다음 노드의 주소를 저장하는 링크 값을 반환
	}

	CCebNode* GetRear(){ // 연결된 덱의 rear 의 링크값을 얻는 함수
		return m_rear.Next(); // 마지막 노드를 가리키는 노드 헤드 m_rear의 다음 노드의 주소를 저장하는 링크 값을 반환
	} 


	CCebLinkedDeque(void): m_nNodes(0){m_front = m_rear = NULL;}
	// 생성자
	// m_nNodes를 0으로 초기화 하고, 첫 노드를 가리키기 위한 노드인 m_front와 마지막 노드를 가리키기 위한 노드인 m_rear을 NULL로 초기화
	~CCebLinkedDeque(void){ // 소멸자
		if( GetHead() != NULL ) { // 만약 연결된 덱이 구현되어있다면
			delete GetHead(); // head의 링크값을 얻어 delete 해주고
			delete GetRear(); // rear의 링크값을 얻어 delete 해준다
		}
	}

	// 연결덱에 데이터를 후단삽입하기 위한 함수
	void AddRear(CCebNode* e){
		if(IsEmpty()){ // 만약 비어있으면
			m_front.m_nextLink = e; // 첫 노드를 가리키기 위한 노드의 링크 값에 e을 대입
			m_rear.m_nextLink = e; // 마지막 노드를 가리키기 위한 노드의 링크 값에 e를 대입

		}

		else{ // 만약 비어있지 않으면
			  
			m_rear.m_nextLink->AddNext(e); // 연결된 덱에 다음 노드의 링크를 추가하는 함수 AddNext를 호출하여 다음 노드의 링크 값을 설정해주고
			m_rear.m_nextLink = e; // 마지막 노드를 가리키기 위한 노드의 링크 값에 e를 대입(e의 값이 마지막 노드가 되는 것)
			
		}
		m_nNodes++; // 항목의 개수를 저장하는 변수인 m_nNodes를 하나 증가시킨다
	}


	// 연결덱에 데이터를 전단삽입하기 위한 함수
	void AddFront(CCebNode* e){
		if(IsEmpty()){  // 만약 비어있으면
			m_front.m_nextLink = e; // 첫 노드를 가리키기 위한 노드의 링크 값에 e을 대입
			m_rear.m_nextLink = e; // 마지막 노드를 가리키기 위한 노드의 링크 값에 e를 대입
		}
		else{ // 만약 비어있지 않으면

			m_front.m_nextLink->AddPrev(e); // 연결된 덱에 이전 노드의 링크를 추가하는 함수 AddPrev를 호출하여 이전 노드의 링크 값을 설정해주고
			m_front.m_nextLink = e; // 처음 노드를 가리키기 위한 노드의 링크 값에 e를 대입(e의 값이 처음 노드가 되는 것)
		}
		m_nNodes++; // 항목의 개수를 저장하는 변수인 m_nNodes를 하나 증가시킨다
	}

	// 연결덱에 데이터를 후단삭제하기 위한 함수
	CCebNode* DeleteRear(){
		if(IsEmpty()) return NULL;
		// 만약 연결덱이 비어있으면 NULL를 반환 
		CCebNode* n = m_rear.Next(); // CCebNode*형 변수를 하나 선언해 m_rear의 링크값을 대입해주고
		if(m_rear.m_nextLink->Prev() == NULL) m_front.m_nextLink = m_rear.m_nextLink = NULL;
		// 만약 마지막 노드를 가리키는 m_rear의 이전 노드가 없다면 하나의 노드만 존재한다는 것 이므로
		// m_front와 m_rear의 다음 링크에 NULL로 설정

		else  // 하나의 노드만 존재하는 것이 아니라면
		{
			n->m_prevLink->m_nextLink = NULL; 
			// m_rear가 가리키고 있는 노드의 이전 노드의 다음 링크값을 NULL로 설정하고
			m_rear.m_nextLink = n->m_prevLink;
			// 마지막 노드를 가리키는 변수인 m_rear의 값을 이전 노드로 설정
		}
		m_nNodes--; // 항목의 개수를 저장하는 변수인 m_nNodes를 하나 감소시킨다
		return n; // 그리고 CCebNode*형 변수를 하나를 반환한다
	}

	// 연결덱에 데이터를 전단삭제하기 위한 함수
	CCebNode* DeleteFront(){
		if(IsEmpty()) return NULL; 
		// 만약 연결덱이 비어있으면 NULL를 반환 
		CCebNode* n = m_front.Next(); // CCebNode*형 변수를 하나 선언해 m_front의 링크값을 대입해주고
		
		if(m_front.m_nextLink->Next() == NULL) m_front.m_nextLink = m_rear.m_nextLink = NULL;
		// 만약 처음 노드를 가리키는 m_front의 다음 노드가 없다면 하나의 노드만 존재한다는 것 이므로
		// m_front와 m_rear의 다음 링크에 NULL로 설정
		else {
			n->m_nextLink->m_prevLink = NULL;
			// m_front가 가리키고 있는 노드의 다음 노드의 이전 링크값을 NULL로 설정하고
			m_front.m_nextLink = n->m_nextLink;
			// 처음 노드를 가리키는 변수인 m_front의 값을 다음 노드로 설정
		}

		m_nNodes--; // 항목의 개수를 저장하는 변수인 m_nNodes를 하나 감소시킨다
		return n; // 그리고 CCebNode*형 변수를 하나를 반환한다
	}

	

	bool IsEmpty(){ // 덱이 비어있는지 그렇지 않은지 확인하는 함수
		return m_nNodes == 0;
		// 만약 항목의 개수를 저장하는 변수 m_nNodes가 0이면 비어있다는 의미

	}
	
	void Display() // 덱의 항목의 수와 덱의 데이터들을 출력하는 함수
	{
		CCebNode* p; // CCebNode*형 변수를 하나 선언해서 
		printf("[전체 항목의 수  %d개] : ",m_nNodes); // 전체 항목의 수가 몇 개인지 출력해주고
		for(CCebNode* p = m_front.Next() ; p != NULL; p = p->Next())
			// p의 값을 m_front의 Next()값부터 계속 다음 링크 값을 대입하면서 그 값이 NULL일 때까지 반복
		{
			p->Display(); // 노드의 데이터 값을 출력한다

		}
		printf("\n"); // 줄바꿈
	}

};

