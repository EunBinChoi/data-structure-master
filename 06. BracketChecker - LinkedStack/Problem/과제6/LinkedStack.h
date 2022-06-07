#pragma once
#include "CebNode.h"

class CCebLinkedStack // 연결된 스택을 구현하기 위한 클래스
{
	CCebNode m_org; // CCebNode 클래스의 객체를 만든다
	
public:

	CCebLinkedStack(void){} // 생성자
	~CCebLinkedStack(void){} // 소멸자

	// Peak와 관련
	CCebNode* GetHead(){ // 연결된 스택의 head 값을 얻는 함수
		return m_org.Next(); // 현재 가리키고 있는 노드(가장 위에 있으므로 head가 됨)의 링크 값을 반환한다
	} 

	bool IsEmpty(){ 
		// 연결된 스택이 비어있는지 확인하는 함수
		// 만약 비어있다면 TRUE를 반환, 비어있지 않다면 FALSE를 반환
		return GetHead() == NULL; 
		// GetHead == NULL의 값이 TRUE 이면 그 스택은 비어있는 것이고
		// FALSE라면 그 스택은 비어있지 않다는 것이다
	}
	
	int GetLength() // 리스트 항목 갯수 반환
	{
		int count = 0 ; // 항목의 갯수를 저장할 정수형 변수 선언
		for(CCebNode* p = GetHead() ; p!=NULL; p=p->Next())
			// head 부터 Next()값(노드의 링크 값)이 NULL일 때 까지 반복하면서
		{
			count ++; // count 값을 증가시킨다
		}

		return count; // 리스트의 항목의 갯수를 저장하는 변수(count) 반환


	}


	void DisPlay() // 리스트 항목 개수 출력
	{
		printf("[%d]문자", GetLength());

		for(CCebNode* p = GetHead() ; p!=NULL; p=p->Next())
			// head 부터 Next()값(노드의 링크 값)이 NULL일 때 까지 반복하면서
		{
			p->Display(); // 노드의 데이터 값을 출력한다
		}
		printf("\n");
	}

	void AddHead(CCebNode* n) // Push();
	{
		m_org.AddNext(n); // 다음 값을 추가하는 함수 호출
	}

	CCebNode* RemoveHead() // Pop();
	{
		return m_org.RemoveNext(); // 다음 값을 삭제하는 함수 호출
	}


	void Reset(){ // 연결된 스택을 리셋하는 함수
		Clear(); // Clear 함수를 부른다
		// 이 함수는 연결된 스택이 빈 공간이 될 때까지 다음 값을 삭제한다
		m_org.SetLink(NULL); // SetLink 함수를 통해 현재 노드의 링크 값을 NULL로 선언
	}	

	void Clear() // 연결된 스택이 비어있을 때 까지 다음 값을 삭제하는 함수
	{
		while(!IsEmpty()){ // 반복문을 돌면서 만약 비어있지 않으면
			delete RemoveHead(); 
			// 다음 값을 삭제하는 함수를 호출하고, 그 값의 반환값을 delete 한다
		}

	}
	void Push(char ch){ // Push 함수(연결된 스택에 값을 집어넣는 함수)
		AddHead(new CCebNode(ch)); 
		// 다음 값에 해당하는 값을 동적할당을 통해 CCebNode 노드를 생성해주고, 다음 값을 추가하는 함수를 호출한다
	}

	char Pop(){ // Pop 함수(연결된 스택에 값을 삭제하는 함수)
		CCebNode* p = RemoveHead();
		// head 값을 제거하는 함수 호출
		// 제거한 노드의 링크 값을 p에 대입한다 

		if(p == NULL) return -1;  // 만약 p가 NULL이면 리턴해주고
		
		// NULL이 아니라면 다음과 같이 실행한다
		char ch = p->getChar(); // 제거한 노드의 데이터 값을 읽어들여 ch에 대입하고 
		delete p; // 동적할당한 p값을 delete로 제거한다
		return ch; // 데이터 값을 반환한다
	}

	char Peek(){ // Peek 함수(연결된 스택에 값을 삭제하지 않고, 값이 무엇인지 확인하는 함수)
		CCebNode* p = GetHead();
		// head 값(현재 노드의 링크값)을 읽어들인다

		if(p == NULL) return -1;   // 만약 p가 NULL이면 리턴해주고

		// NULL이 아니라면 다음과 같이 실행한다
		char ch = p->getChar(); // 노드의 데이터 값을 읽어들여 ch에 대입하고 
		return ch; // 데이터 값을 반환한다
	}

};

