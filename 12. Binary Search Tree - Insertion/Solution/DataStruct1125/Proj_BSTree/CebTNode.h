#pragma once
#include <stdio.h>
#include"CebItem.h"

class CCebTNode : public CCebItem // 이진 트리의 노드를 구현하는 클래스 선언
	// 여기서 CCebItem 클래스를 상속, 이 클래스는 노드의 데이터들을 구현해주는 클래스
{
	CCebTNode* m_left; // 왼쪽 자식노드의 주소를 저장하는 CCebTNode*형 변수
	CCebTNode* m_right; // 오른쪽 자식노드의 주소를 저장하는 CCebTNode*형 변수

public:
	CCebTNode(int priority = 0,char* name = "",int price = 0 ,  char* method="...") 
		: CCebItem(priority,name,price,method),m_left(NULL),m_right(NULL){} 

	// 생성자(인수의 디폴트 값이 들어있게하여 따로 생성자를 만들지 않게 함)
	// CCebItem의 생성자를 불러 데이터 값들을 초기화해주고, 왼쪽 자식노드의 주소와 오른쪽 자식노드의 주소를 초기화

	
	~CCebTNode(void){ // 소멸자

		if(m_left != NULL) delete m_left; // 만약 왼쪽 자식노드의 주소가 NULL이 아니라면 delete 연산으로 삭제
		if(m_right != NULL) delete m_right;
		// 만약 오른쪽  자식노드의 주소가 NULL이 아니라면 delete 연산으로 삭제
	}


	void PreOrder(){ // 전위순회하는 함수
		Display(); // 먼저 현재 가리키는 루트 노드의 데이터 값을 출력하고
		if(m_left != NULL) m_left -> PreOrder();
		// 만약 왼쪽 자식이 NULL이 아니라면 왼쪽 자식의 트리를 방문한다
		if(m_right != NULL) m_right -> PreOrder();
		// 만약 오른쪽 자식이 NULL이 아니라면 오른쪽 자식의 트리를 방문한다
	}

	void InOrder(){ // 중위순회하는 함수
		if(m_left != NULL) m_left -> InOrder();
		// 만약 왼쪽 자식이 NULL이 아니라면 왼쪽 자식의 트리를 방문한다
		Display(); // 현재 가리키는 루트 노드의 데이터 값 출력
		if(m_right != NULL) m_right -> InOrder();
		// 만약 오른쪽 자식이 NULL이 아니라면 오른쪽 자식의 트리를 방문한다
	}
	
	void PostOrder(){ // 후위순회하는 함수
		if(m_left != NULL) m_left -> PostOrder();
		// 만약 왼쪽 자식이 NULL이 아니라면 왼쪽 자식의 트리를 방문한다
		if(m_right != NULL) m_right -> PostOrder();
		// 만약 오른쪽 자식이 NULL이 아니라면 오른쪽 자식의 트리를 방문한다
		Display(); // 현재 가리키는 루트 노드의 데이터 값 출력
		
	}

	void Add(CCebTNode* n){ // 노드를 추가하는 함수
		if(n->getPriority() < getPriority()){ 
			// 만약 인수로 들어오는 값의 우선순위가 현재 우선순위보다 작으면 
			if(m_left == NULL) m_left = n; // 왼쪽자식이 NULL이면 왼쪽 자식에 대입하고
			else m_left->Add(n); // NULL이 아니면 왼쪽자식의 Add 함수를 호출하여 대입
		}

		else{ // 만약 인수로 들어오는 값의 우선순위가 현재 우선순위보다 크면
			if(m_right == NULL) m_right = n; // 오른쪾자식이 NULL이면 오른쪽 자식에 대입하고
			else m_right->Add(n); // NULL이 아니면 오른쪽자식의 Add 함수를 호출하여 대입
		}
	}

	int Height(){ // 트리의 높이를 반환하는 함수
      int n1 = 0,n2 = 0; // n1은 왼쪽 서브트리의 높이를 저장하고, n2은 오른쪽 서브트리의 높이를 저장하는 정수형변수
      if(m_left != NULL) n1 = m_left->Height();
	  // 만약 왼쪽 서브트리가 NULL이 아니라면 n1에 m_left의 Height 함수를 호출하여 함수 순회
      if(m_right != NULL) n2 = m_right->Height();
	  // 만약 오른쪽 서브트리가 NULL이 아니라면 n2에 m_right의 Height 함수를 호출하여 함수 순회
      return (n1>n2)? n1+1 : n2+1; 
	  // 만약 n1이 n2보다 크다면 n1이 이 트리의 높이가 되는 것이고, 작다면 n2가 이 트리의 높이가 됨
	  // 여기서 Height 함수를 호출할때마다 반환값으로 현재 트리의 높이보다 +1 증가시킴
   }
   
   int Count(){ // 트리의 노드 개수를 반환하는 함수
      int n1 = 0; // 정수형 변수 n1을 0으로 초기화
      int n2 = 0; // 정수형 변수 n2를 0으로 초기화
      if(m_left != NULL) n1 = m_left->Count(); // 만약 m_left가 NULL이 아니라면 m_left의 Count 호출
	  if(m_right != NULL) n2 = m_right->Count(); // 만약 m_right가 NULL이 아니라면 m_right의 Count 호출
      return n1+n2+1; // 노드가 정상적으로 호출될 때마다 반환값을 +1한 값을 줘서 노드의 개수 증가시킴
   }
	
	CCebTNode* FindItem(int val){ // 트리의 인수로 들어온 val값과 같은 우선순위를 가진 노드를 탐색(순환 방법)
      
      if(this == NULL) return NULL; // 만약 노드가 NULL이면 이것을 반환
      if(this->getPriority() == val){  // 만약 현재 가리키고 있는 노드의 우선순위와 인수로 들어온 값이 같다면    
         return this; // 현재 노드 반환 
      }else if(this->getPriority() > val){ // 만약 현재 가리키고 있는 노드의 우선순위보다 인수로 들어온 값이 더 크다면
         return m_left -> FindItem(val);
		 // 왼쪽 자식(현재 루트의 우선순위보다 더 작은 우선순위만 있는 노드)에서 FindItem 함수를 호출하여 val 값을 찾는다
      }else if(this->getPriority() < val){ // 만약 현재 가리키고 있는 노드의 우선순위보다 인수로 들어온 값이 더 작다면
         return m_right -> FindItem(val);
		 // 오른쪽 자식(현재 루트의 우선순위보다 더 큰 우선순위만 있는 노드)에서 FindItem 함수를 호출하여 val 값을 찾는다
      }
      
   }
	CCebTNode* FindItemIter(int val){ // 트리의 인수로 들어온 val값과 같은 우선순위를 가진 노드를 탐색(반복 방법)
      CCebTNode* p = this; // CCebTNode*형 변수를 하나 선언하여, this 값을 대입한다
      while(p != NULL){ // 반복문을 돌면서 만약 p가 NULL이 아니라면 p가 NULL이 될때까지 반복문을 돌면서
         if(p->getPriority() == val) return p; // 만약 p의 우선순위가 인수로 들어온 우선순위랑 같다면 p를 반환
         else if(p->getPriority() > val) p= p->m_left; // 만약 val 값이 p의 우선순위보다 작다면 p를 p의 왼쪽 자식으로 대입
         else if(p->getPriority() < val) p= p->m_right; // 만약 val 값이 p의 우선순위보다 크다면 p를 p의 오른쪽 자식으로 대입
      }
      return NULL; // 위의 반복문에서 반환되지 않았으면 NULL로 반환
   }


	void FindPriceRange( int minPrice, int maxPrice ){ // 가격이 인수로 들어온 두 값 사이에 존재하는 노드 출력하는 함수
      if(this->getPrice() >= minPrice && this->getPrice() <= maxPrice ) // 만약 현재 노드의 가격이 minPrice와 maxPrice 사이면
         Display(); // Display 함수 호출
      if(m_left != NULL) m_left -> FindPriceRange(minPrice, maxPrice); // 만약 m_left가 NULL이 아니라면, 왼쪽 자식의 FindPriceRange를 불러 노드 탐색
      if(m_right != NULL) m_right -> FindPriceRange(minPrice, maxPrice); // 만약 m_right가 NULL이 아니라면, 오른쪽 자식의 FindPriceRange를 불러 노드 탐색
   }
};

