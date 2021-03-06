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

	friend class CBinSrchTree;

public:
	CBSTNode( int data = 0 ) {
		m_key = data;
		m_noKey= rand() % 10;
		m_left = m_right = m_parent = NULL;
	}
	~CBSTNode(void){ }

	bool IsRoot()		{ return ( m_parent== NULL); }
	bool IsTerminal()	{ return ((m_left == NULL) && (m_right == NULL)); }
	bool HasLeft()		{ return m_left != NULL; }
	bool HasRight()		{ return m_right!= NULL; }
	bool IsLeft()		{ return ( !IsRoot() && (m_parent->m_left ==this)); }
	bool IsRight()		{ return ( !IsRoot() && (m_parent->m_right==this)); }
	
	void Add( CBSTNode *n ) {
		if( n->m_key < m_key ) {
			if( m_left == NULL ) {
				m_left = n;
				n->m_parent = this;
			}
			else m_left->Add(n);
		}
		else {
			if( m_right== NULL ) {
				m_right = n;
				n->m_parent = this;
			}
			else m_right->Add(n);
		}
	}

	void Print() {
//		printf("%3d(%d)", m_key, m_noKey );
		printf("%3d", m_key );
	}
	void InOrder() {
		if( m_left != NULL ) m_left->InOrder();		// (1)
		Print();									// (2)
		if( m_right!= NULL ) m_right->InOrder();	// (3)
	}
	void PreOrder() {
		Print();									// (1)
		if( m_left != NULL ) m_left->PreOrder();	// (2)
		if( m_right!= NULL ) m_right->PreOrder();	// (3)
	}
	void PostOrder() {
		if( m_left != NULL ) m_left->PostOrder();	// (1)
		if( m_right!= NULL ) m_right->PostOrder();	// (2)
		Print();									// (3)
	}

	// 키 값으로 탐색하는 함수
	CBSTNode* Search( int data ) {
		if( data == m_key ) return this;
		if( data < m_key )
			return ( m_left == NULL ) ? NULL : m_left->Search(data);
		else 
			return ( m_right == NULL ) ? NULL : m_right->Search(data);
	}
	// NoKey 값으로 탐색하는 함수
	CBSTNode* Search2( int val ) {
		if( val == m_noKey ) return this;
		CBSTNode *n = NULL;
		if( m_left != NULL )
			n = m_left->Search2(val);
		if( n != NULL ) return n;

		if( m_right != NULL )
			n = m_right->Search2(val);
		return n;
	}

	void Delete() {
		if( m_parent == NULL ) return;
		if( m_parent->m_left == this )
			 m_parent->m_left = NULL;
		else m_parent->m_right= NULL;
	}
	bool IsLeftChild()	{ return m_parent->m_left == this; }


	CBSTNode* GetMinNode() {
		CBSTNode* node = this;
		while( node->m_left != NULL ) node = node->m_left;
		return node;
	}
	CBSTNode* GetMaxNode() {
		CBSTNode* node = this;
		while( node->m_right != NULL ) node = node->m_right;
		return node;
	}
	void Copy( CBSTNode *n ) {
		m_key = n->m_key;
		m_noKey= n->m_noKey;
	}
};

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             