#pragma once
#include "BSTNode.h"

class CBinSrchTree
{
	CBSTNode*	m_root; // 루트의 위치를 저장하는 CBSTNode*형 변수

public:
	CBinSrchTree(void) { m_root = NULL; }
	// 생성자, 루트의 위치를 저장하는 변수를 NULL로 초기화
	~CBinSrchTree(void){ }
	// 소멸자

	bool IsEmpty()	{ return m_root==NULL; }
	// 이진 트리가 비어있는 지 확인하는 함수
	// m_root가 NULL이면 이진 트리가 비어있다는 의미고, NULL이 아니면, 이진 트리가 비어있지 않다는 의미이다.

	void AddNode( int data ) { // 이진 트리에 노드를 추가하는 함수, 인수로 받아온 데이터를 추가한다.
		CBSTNode* n = new CBSTNode( data );
		// CBSTNode*형 임시변수를 선언한 뒤에, 인수로 받아온 data를 키 값으로 갖는 노드를 new 연산자로 생성한다.
		if( IsEmpty() ) { // 만약 이진 트리가 비어있으면(이진 트리가 구현되지 않았으면)
			m_root = n; // m_root 값을 n으로 설정한다.
		}
		else { // 그렇지 않으면
			m_root->Add( n );
			// m_root에서 Add 함수를 호출하여 키 값이 n인 노드를 추가한다.
		}
	}
	void PrintInOrder() { // 중위 순회를 하면서 이진 트리를 출력하는 함수
		printf(" Tree의 중위순회: ");
		if(!IsEmpty()) m_root->InOrder();
		// 만약 비어있지 않으면 m_root에서 InOrder 함수를 불러 중위 순회를 시작한다.
		printf("\n");
	}
	void PrintPreOrder(){ // 전위 순회를 하면서 이진 트리를 출력하는 함수
		printf(" Tree의 전위순회: ");
		if(!IsEmpty()) m_root->PreOrder();
		// 만약 비어있지 않으면 m_root에서 PreOrder 함수를 불러 전위 순회를 시작한다.
		printf("\n");
	}
	void PrintPostOrder(){ // 후위 순회를 하면서 이진 트리를 출력하는 함수
		printf(" Tree의 후위순회: ");
		if(!IsEmpty()) m_root->PostOrder();
		// 만약 비어있지 않으면 m_root에서 PostOrder 함수를 불러 후위 순회를 시작한다.
		printf("\n");
	}

	void Find( int data ) { // 노드를 키값으로 탐색하는 함수
		CBSTNode *n = (IsEmpty()) ? NULL : m_root->Search( data );
		// CBSTNode*형 임시변수를 선언한 뒤에, 이진트리가 비어있으면 NULL으로 초기화하고,
		// 비어있지 않으면, 인수로 받아온 data를 키 값으로 갖는 노드를 Search 함수로 탐색한다. 
		
		if( n == NULL ) // 만약 n이 NULL이면 이진트리가 비어있다는 의미이므로
			printf("탐색 실패: 키값%d를 갖는 노드가 없습니다.\n", data ); // 탐색에 실패했다는 메세지와 키값을 출력한다.
		else // 만약 n이 NULL이 아니라면 이진트리가 비어있지 않다는 의미이므로 
			printf("탐색 성공: 키값%d(%d)를 갖는 노드를 찾았습니다.\n", data, n->m_noKey ); 
			// 탐색에 성공했다는 메세지를 출력하고 키값과 키 값이 아닌 것을 출력한다.
	}
	void Find2( int nokey ) { // 노드를 키값이 아닌 것으로 탐색하는 함수
		CBSTNode *n = (IsEmpty()) ? NULL : m_root->Search2( nokey );
		// CBSTNode*형 임시변수를 선언한 뒤에, 이진트리가 비어있으면 NULL으로 초기화하고,
		// 비어있지 않으면, 인수로 받아온 키값이 아닌 것으로 노드를 찾는 Search2 함수를 호출하여 노드를 탐색한다. 
		
		if( n == NULL ) // 만약 n이 NULL이면 이진트리가 비어있다는 의미이므로
			printf("탐색2 실패: %d를 갖는 노드가 없습니다.\n", nokey );
			// 탐색에 실패했다는 메세지와 키값이 아닌 것을 출력한다.
		else // 만약 n이 NULL이 아니라면 이진트리가 비어있지 않다는 의미이므로
			printf("탐색2 성공: <%d>%d를 갖는 노드를 찾았습니다.\n", n->m_key, nokey );
			// 탐색에 성공했다는 메세지와 키값과 키 값이 아닌 것을 출력한다. 
	}

	// 이진 탐색 트리의 삭제 연산
	// 먼저 data를 키값으로 갖는 노드를 찾고
	// 찾아진 노드를 트리에서 제거하면서도
	// 이진 탐색 트리의 특성을 그대로 유지하도록 한다.
	void DeleteNode (int data) {
		if( IsEmpty() ) return;
		// 빈 트리이면 이진 트리를 삭제할 수 없으므로 return 함
		CBSTNode *n = m_root->Search( data );	
		// CBSTNode*형 임시변수를 선언하고, m_root의 Search 함수를 인수로 들어온 키 값으로 탐색한다.  
		if( n == NULL ) return;
		// 만약 임시변수 n이 NULL이면 인수로 들어온 키 값을 갖는 노드가 없다는 의미이므로 return 함

		// case 1: 삭제하려는 노드가 단말 노드일 경우
		if( n->IsTerminal() ) { // 만약 삭제하려고 하는 노드가 단말 노드라면
			if( n->IsRoot() ) m_root = NULL; // 만약 단말 노드이면서 루트가 NULL인 경우, m_root를 NULL로 설정
			else n->Delete(); // 루트가 NULL이 아닌 경우, n을 Delete 함수를 통해 삭제한다.
		}
		// case 2: 삭제하려는 노드가 왼쪽이나 오른쪽 자식만 갖는 경우
		else if( n->m_left== NULL|| n->m_right==NULL ) { // 만약 삭제하려고 하는 노드의 왼쪽 자식이 NULL이거나 오른쪽 자식이 NULL인 경우
			CBSTNode *child = (n->m_left != NULL ) ? n->m_left : n->m_right;
			// CBSTNode *형 child 변수를 하나 선언해준 뒤, 만약 왼쪽 자식이 NULL이 아니면 child에 n->m_left를.
			// 오른쪽 자식이 NULL이 아니면 child에 n->m_right를 대입한다
			if( !n->IsRoot() ) { // 만약 루트가 비어있지않다면 (부모 노드가 존재한다면)
				if( n->IsLeft() ) n->m_parent->m_left = child;  
				// 만약 삭제하려고 하는 노드의 왼쪽 자식이 존재한다면, 삭제하려고 하는 노드의 부모 노드의 왼쪽 자식을 child으로 대입해준다.
				else			  n->m_parent->m_right= child;
				// 만약 삭제하려고 하는 노드의 오른쪽 자식이 존재한다면, 삭제하려고 하는 노드의 부모 노드의 오른쪽 자식을 child으로 대입해준다.
				child->m_parent = n->m_parent; 
				// child의 부모 노드를 삭제하려고 하는 노드의 부모 노드로 대입한다.
			}
			else m_root = child; // 만약 루트가	비어있다면, m_root를 child로 대입한다.
		}
		
		 // case 3: 삭제하려는 노드가 두개의 자식이 모두 있는 경우
		else { // 만약 삭제하려고 하는 노드가 두 개의 자식이 모두 있는 경우
			CBSTNode* minnode = n->m_right->GetMinNode(); // 삭제하려고 하는 노드의 오른쪽 서브트리에서 제일 작은 값을 minnode에 대입 
			n->Copy(minnode);//삭제하려고 하는 노드의 Copy함수를 호출하여 n의 key 값과 noKey 값을 minnode 값과 같게 해준다 
			n = minnode; // n에 minnode 값 대입
			if( n->m_right != NULL ) { // 만약 제일 작은 값을 가지고 있는 노드의 오른쪽 자식이 NULL이 아니면 
				n->m_parent->m_left  = n->m_right; // 제일 작은 값을 가지고 있는 노드의 부모 노드의 왼쪽 자식을 n의 오른쪽 노드로 설정 
				n->m_right->m_parent = n->m_parent; // 제일 작은 값을 가지고 있는 노드의 오른쪽 노드의 부모를 n의 부모로 설정
			}
			else n->Delete(); // 만약 제일 작은 값을 가지고 있는 노드의 오른쪽 자식이 NULL이면 제일 작은 값을 삭제한다
		}
		delete n; // 삭제된 n을 반환한다
	}
};   