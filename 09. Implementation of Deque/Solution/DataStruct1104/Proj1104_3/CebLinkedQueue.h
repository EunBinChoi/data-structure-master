#pragma once
#include "CebNode.h"
#include "CebElement.h"

class CCebLinkedQueue : public CCebNode // 연결 큐를 구현하기 위한 클래스(이 클래스에서는 Node를 구현하는 클래스를 상속받는다)
{
	CCebNode* m_front; // 첫 노드를 가리키기 위한 노드 포인터
	CCebNode* m_rear; // 마지막 노드를 가리키기 위한 노드 포인터
	int m_nNodes; // 항목의 개수를 저장하는 변수

public:

	CCebLinkedQueue(void): m_nNodes(0){m_front = m_rear = NULL;}
	// 생성자
	// m_nNodes를 0으로 초기화 하고, 첫 노드를 가리키기 위한 포인터인 m_front와 마지막 노드를 가리키기 위한 포인터인 m_rear을 NULL로 초기화
	~CCebLinkedQueue(void){
		if( m_front != NULL ) 
			delete m_front;
	}
	// 소멸자
	// 만약 m_front 가 NULL이 아니면 연결 큐가 구현되어있다는 말이므로, delete를 사용하여 삭제한다 

	// 연결큐에 데이터를 삽입하기 위한 함수
	void EnQueue(CCebNode* e){
		if(IsEmpty()) m_front = m_rear = e;
		// 만약 연결 큐가 비어있다면 m_front와 m_rear을 모두 인수로 받은 e 값을 대입한다
		else{ // 만약 비어있지 않으면
			m_rear -> AddNext(e); // 연결된 큐에 다음 값을 추가하는 함수 AddNext를 호출하여 m_link의 값을 설정해주고  
			m_rear = e; // m_rear에 인수로 받은 e를 삽입
		}
		m_nNodes++; // 항목의 개수를 저장하는 변수인 m_nNodes를 하나 증가시킨다
	}

	// 연결큐에 데이터를 삭제하기 위한 함수
	CCebNode* DeQueue(){
		if(IsEmpty()) return NULL;
		// 만약 연결큐가 비어있으면 NULL를 반환 
		CCebNode* n = m_front; // CCebNode*형 변수를 하나 선언해 m_front를 대입해주고
		if(m_front->m_link == NULL) m_front = m_rear = NULL; // 만약 m_front의 다음 노드 주소를 저장하는 m_link가 NULL이면 m_front의 다음 노드가 없다는 것이므로, m_front와 m_rear을 모두 NULL로 대입
		else m_front =  m_front->m_link; // 만약 m_front의 다음 노드 주소를 저장하는 m_link가 NULL이 아니라면 m_front를 m_front의 다음 노드을 대입하게 하고
		m_nNodes--; // 항목의 개수를 저장하는 변수인 m_nNodes를 하나 감소시킨다
		return n; // 그리고 CCebNode*형 변수를 하나를 반환한다
	}

	// 연결큐에 데이터를 삭제하지 않고 반환만 하는 함수
	CCebNode* Peek(){
		if(IsEmpty()) return NULL; // 만약 연결큐가 비어있으면 NULL를 반환 
		CCebNode* n = m_front;  // CCebNode*형 변수를 하나 선언해 m_front를 대입해주고

		return n; // 그리고 CCebNode*형 변수를 하나를 반환한다
	}

	bool IsEmpty(){ // 연결큐를 구현하는 배열이 비어있는 지 확인하는 함수
		return m_nNodes == 0;
		// 만약 항목의 개수를 저장하는 변수 m_nNodes가 0이면 배열이 비어있다는 의미이고 0이 아니면 배열이 비어있지 않다는 의미이다

	}
	//bool IsEmpty(){  연결큐를 구현하는 배열이 비어있는 지 확인하는 함수
	//	return (m_front==NULL && m_rear==NULL);

	//}

	void Display() // 연결큐의 항목 개수와 항목 값을 출력
	{
		CCebNode* p; // CCebNode*형 변수를 하나 선언해서 
		printf("[전체 항목의 수  %d개] : ",m_nNodes); // 전체 항목의 수가 몇 개인지 출력해주고
		for(CCebNode* p = m_front ; p!=NULL; p=p->Next())
			// head 부터 Next()값(노드의 링크 값)이 NULL일 때 까지 반복하면서
		{
			p->Display(); // 노드의 데이터 값을 출력한다

		}
		printf("\n"); // 줄바꿈
	}

};

