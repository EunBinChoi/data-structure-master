#pragma once
#include "CebTNode.h"

class CCebBSTree // 이진트리를 구현하는 클래스 선언
{
	CCebTNode* m_root; // 이진트리를 구현하는 CCebTNode*형 변수선언

public:

	CCebBSTree(void){m_root = NULL;} // 생성자, m_root를 NULL로 초기화
	~CCebBSTree(void){if(m_root!=NULL) delete m_root;}
	// 소멸자, 만약 m_root가 NULL이 아니라면 이 값을 delete로 삭제

	void PrintPreOrder(){ // 전위순회를 하는 함수
		if(m_root != NULL) m_root->PreOrder(); 
		// 만약 m_root가 NULL이 아니라면 PreOrder 함수를 호출하여 전위순회
	 
		printf("\n");
	}
	void PrintInOrder(){ // 중위순회를 하는 함수
		if(m_root != NULL) m_root->InOrder();
		// 만약 m_root가 NULL이 아니라면 InOrder 함수를 호출하여 중위순회

		printf("\n");
	}
	void PrintPostOrder(){ // 후위순회를 하는 함수
		
		if(m_root != NULL) m_root->PostOrder();
		// 만약 m_root가 NULL이 아니라면 PostOrder 함수를 호출하여 후위순회

		printf("\n");
	}

	void Add(CCebTNode* n){ // 노드를 추가하는 함수
		if(n == NULL) return; // 만약 인수로 받은 노드가 NULL이라면 return
		if(m_root == NULL) m_root = n; 
		// 만약 m_root가 NULL이라면(아직 이진트리가 구현되지 않았으면) m_root에 n 대입
		else{ // 만약 m_root가 NULL이 아니라면
			m_root ->Add (n); // Add 함수를 호출하여 노드를 추가함
		}

	}
	int GetCount(){ // 이진트리를 구현하는 노드의 갯수를 반환하는 함수
		if(m_root == NULL) return 0; // 만약 m_root가 NULL이면 0을 반환
		else // 그게 아니라면
			return m_root->Count();
		// Count 함수를 불러 노드의 갯수를 반환
	}

	int GetHeight(){ // 이진트리를 구현하는 노드의 높이를 반환하는 함수
		if(m_root == NULL) return 0; // 만약 m_root가 NULL이면 0을 반환
		else // 그게 아니라면
			return m_root->Height();
		// Height 함수를 불러 노드의 높이를 반환
	}

void SearchPriority(int val) // 인수로 받은 값과 일치하는 우선순위를 가진 노드의 위치를 찾는 함수
   {
      CCebTNode* n1; // CCebTNode* 형 변수 선언
      CCebTNode* n2; // CCebTNode* 형 변수 선언
      if(this->m_root == NULL){ // 만약 m_root가 NULL이면
         printf("트리가 비어있습니다"); // 트리가 비어있다는 메시지 출력
      }
      else{ // 그게 아니라면 
         printf("(반복) "); // 반복문으로 구현한 SearchPriority
         n1 = m_root->FindItemIter(val); // FindItemIter 함수를 호출하여 반환 값을 n1에 저장
         if(n1 != NULL) n1->Display(); // 만약 n1이 NULL이 아니면 Display 함수 호출
         else printf("노드에 입력한 priority값 %2d가 없습니다\n",val);
		 // 만약 NULL이라면 위와 같은 메시지 출력

         printf("(재귀) "); // 재귀로 구현한 SearchPriority
         n2 = m_root->FindItem(val); // FindItem 함수를 호출하여 반환 값을 n2에 저장
         if(n2 != NULL) n2->Display(); // 만약 n2이 NULL이 아니면 Display 함수 호출
         else printf("노드에 입력한 priority값 %2d가 없습니다",val);
		  // 만약 NULL이라면 위와 같은 메시지 출력
      }
	  printf("\n");
   }
	void SearchPriceRange(int minPrice, int maxPrice){ // 인수로 들어오는 min, max에 해당하는 가격을 가진 노드 출력
		m_root->FindPriceRange(minPrice,maxPrice);
		// 인수로 min,max를 가지고 있는 FindPriceRange 함수 호출

	}

};	

