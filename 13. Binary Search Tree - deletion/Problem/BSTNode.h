#pragma once
#include <stdio.h>
#include <stdlib.h>

class CBSTNode
{
	int			m_key;		// 키값
	int			m_noKey;	// 키가 아님

	CBSTNode*	m_left;		// 왼쪽 자식
	CBSTNode*	m_right;	// 오른쪽 자식
	CBSTNode*	m_parent;	// 부모 노드

	friend class CBinSrchTree; // CBinSrchTree을 friend 클래스로 선언, friend 클래스에서는 위의 선언된 변수들을 모두 접근할 수 있음

public:
	CBSTNode( int data = 0 ) { // 생성자, 인수로 키 값이 들어옴
		m_key = data; // 인수로 들어온 data 값을 key 값에 대입
		m_noKey = rand() % 10; // m_nokey 값을 랜덤함수로 설정
		m_left = m_right = m_parent = NULL;
		// 왼쪽 자식, 오른쪽 자식, 부모 노드 모두 NULL로 설정
	}
	~CBSTNode(void){ } // 소멸자

	bool IsRoot()		{ return ( m_parent== NULL); } // 부모 노드가 존재하는지 판단하는 함수, 만약 m_parent가 NULL인 것을 만족하면 루트가 존재하지 않다는 의미 
	bool IsTerminal()	{ return ((m_left == NULL) && (m_right == NULL)); }
	// 단말 노드인지 판단하는 함수, 만약 왼쪽 자식과 오른쪽 자식이 NULL이면 단말 노드이다.
	bool HasLeft()		{ return m_left != NULL; } // 왼쪽 자식을 가지고 있는지 판단하는 함수, 만약 m_left가 NULL이 아니면 TRUE 반환
	bool HasRight()		{ return m_right!= NULL; } // 오른쪽 자식을 가지고 있는지 판단하는 함수, 만약 m_right가 NULL이 아니면 TRUE 반환
	bool IsLeft()		{ return ( !IsRoot() && (m_parent->m_left ==this)); } 
	// 왼쪽 자식인지 판단하는 함수, 루트가 비어있지 않고, 부모 노드에서 왼쪽 자식이 자기 자신이면 왼쪽 자식이다
	bool IsRight()		{ return ( !IsRoot() && (m_parent->m_right==this)); }
	// 오른쪽 자신인지 판단하는 함수, 루트가 비어있지 않고, 부모 노드에서 오른쪽 자식이 자기 자신이면 오른쪽 자식이다
	
	void Add( CBSTNode *n ) { // 노드를 추가하는 함수
		if( n->m_key < m_key ) { // 만약 인수로 들어오려고 하는 키값이 현재의 키 값보다 작다면
			if( m_left == NULL ) { // m_left가 NULL일 경우에는
				m_left = n; // 들어오려고 하는 n값을 m_left로 설정
				n->m_parent = this; // n의 부모 노드를 현재 노드로 설정
			}
			else m_left->Add(n); // m_left가 NULL이 아닐 경우에는 m_left에 Add 함수를 호출하여 n을 추가한다.
		}
		else { // 만약 인수로 들어오려고 하는 키값이 현재의 키 값보다 크다면
			if( m_right== NULL ) { // m_right가 NULL일 경우에는
				m_right = n; // 들어오려고 하는 n값을 m_right로 설정
				n->m_parent = this; // n의 부모 노드를 현재 노드로 설정
			}
			else m_right->Add(n); // m_right가 NULL이 아닐 경우에는 m_right에 Add 함수를 호출하여 n을 추가한다.
		
		}
	}

	void Print() { // 노드의 키 값을 출력하는 함수
//		printf("%3d(%d)", m_key, m_noKey );
		printf("%3d", m_key );
	}
	void InOrder() { // 중위 순회
		if( m_left != NULL ) m_left->InOrder();		// (1)
		Print();									// (2)
		if( m_right!= NULL ) m_right->InOrder();	// (3)
	}
	void PreOrder() { // 전위 순회
		Print();									// (1)
		if( m_left != NULL ) m_left->PreOrder();	// (2)
		if( m_right!= NULL ) m_right->PreOrder();	// (3)
	}
	void PostOrder() { // 후위 순회
		if( m_left != NULL ) m_left->PostOrder();	// (1)
		if( m_right!= NULL ) m_right->PostOrder();	// (2)
		Print();									// (3)
	}

	// 인수로 들어온 키 값으로 탐색하는 함수
	CBSTNode* Search( int data ) {
		if( data == m_key ) return this; // 만약 인수로 들어온 data값과 현재 키 값이 같으면 현재 노드 반환
		if( data < m_key ) // 만약 인수로 들어온 data값이 더 작다면
			return ( m_left == NULL ) ? NULL : m_left->Search(data); // m_left이 NULL이면 NULL, NULL이 아니면 m_left의 Search 함수를 호출하여 키 값을 탐색한다
		else  // 만약 인수로 들어온 data값이 더 크다면
			return ( m_right == NULL ) ? NULL : m_right->Search(data);
		// m_right이 NULL이면 NULL, NULL이 아니면 m_right의 Search 함수를 호출하여 키 값을 탐색한다

	}

	// 인수로 들어온 NoKey 값으로 탐색하는 함수
	CBSTNode* Search2( int val ) {
		if( val == m_noKey ) return this;
		// 만약 현재 노드의 키 값이 아닌 것이 인수로 들어온 val과 같다면, 현재 노드를 반환한다.
		
		CBSTNode *n = NULL;
		// CBSTNode *n형 임시변수 n을 선언하고, 이를 NULL로 초기화한다.

		if( m_left != NULL ) // 만약 왼쪽 자식이 NULL이 아니라면 
			n = m_left->Search2(val); 
		// 왼쪽 자식에서 인수로 들어온 val을 키 값이 아닌 것으로 가진 노드를 Search2 함수로 찾아 반환형을 n에 대입한다.
		if( n != NULL ) return n; // 만약 n이 NULL이 아니라면(위에서 노드를 NoKey 값으로 노드를 탐색해 노드를 찾았다면) n을 반환한다. 
		if( m_right != NULL ) // 만약 m_right가 NULL이 아니라면
			n = m_right->Search2(val); 
		// 오른쪽 자식에서 인수로 들어온 val을 키 값이 아닌 것으로 가진 노드를 Search2 함수로 찾아 반환형을 n에 대입한다.
		return n; // n을 반환
	}

	void Delete() { // 삭제하는 함수
		if( m_parent == NULL ) return; // 만약 부모 노드가 없다면 return 반환
		if( m_parent->m_left == this ) // 만약 부모 노드의 왼쪽 자식 노드가 현재 노드와 같다면
			 m_parent->m_left = NULL; // 부모 노드의 왼쪽 자식 노드를 NULL로 설정
		else m_parent->m_right= NULL; // 만야 부모 노드의 오른쪽 자식 노드가 현재 노드와 같다면 부모 노드의 오른쪽 자식 노드를 NULL로 설정
	}
	bool IsLeftChild()	{ return m_parent->m_left == this; }
	// 왼쪽 자식인지를 판단하기 위한 bool형 함수, 만약 형재 객체의 부모의 왼쪽 노드가 this와 같으면 왼쪽 자식임을 나타냄

	CBSTNode* GetMinNode() { // 오른쪽 서브트리에서 제일 작은 값을 찾는 함수
		CBSTNode* node = this; // 현재 노드를 저장해주고
		while( node->m_left != NULL ) node = node->m_left; // 현재 노드에서 계속해서 왼쪽 노드에 접근
		return node; // 마지막 왼쪽 노드 값을 반환
	}
	CBSTNode* GetMaxNode() { // 왼쪽 서브트리에서 제일 큰 값을 찾는 함수
		CBSTNode* node = this; // 현재 노드를 저장해주고
		while( node->m_right != NULL ) node = node->m_right;  // 현재 노드에서 계속해서 오른쪽 노드에 접근
		return node; // 마지막 오른쪽 노드 값을 반환
	}
	void Copy( CBSTNode *n ) { // 복사해주는 함수
		m_key = n->m_key; // key 값을 복사 
		m_noKey= n->m_noKey; // noKey 값을 복사
	}
};
 