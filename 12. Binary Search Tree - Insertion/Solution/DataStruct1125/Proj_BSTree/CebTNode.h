#pragma once
#include <stdio.h>
#include"CebItem.h"

class CCebTNode : public CCebItem // ���� Ʈ���� ��带 �����ϴ� Ŭ���� ����
	// ���⼭ CCebItem Ŭ������ ���, �� Ŭ������ ����� �����͵��� �������ִ� Ŭ����
{
	CCebTNode* m_left; // ���� �ڽĳ���� �ּҸ� �����ϴ� CCebTNode*�� ����
	CCebTNode* m_right; // ������ �ڽĳ���� �ּҸ� �����ϴ� CCebTNode*�� ����

public:
	CCebTNode(int priority = 0,char* name = "",int price = 0 ,  char* method="...") 
		: CCebItem(priority,name,price,method),m_left(NULL),m_right(NULL){} 

	// ������(�μ��� ����Ʈ ���� ����ְ��Ͽ� ���� �����ڸ� ������ �ʰ� ��)
	// CCebItem�� �����ڸ� �ҷ� ������ ������ �ʱ�ȭ���ְ�, ���� �ڽĳ���� �ּҿ� ������ �ڽĳ���� �ּҸ� �ʱ�ȭ

	
	~CCebTNode(void){ // �Ҹ���

		if(m_left != NULL) delete m_left; // ���� ���� �ڽĳ���� �ּҰ� NULL�� �ƴ϶�� delete �������� ����
		if(m_right != NULL) delete m_right;
		// ���� ������  �ڽĳ���� �ּҰ� NULL�� �ƴ϶�� delete �������� ����
	}


	void PreOrder(){ // ������ȸ�ϴ� �Լ�
		Display(); // ���� ���� ����Ű�� ��Ʈ ����� ������ ���� ����ϰ�
		if(m_left != NULL) m_left -> PreOrder();
		// ���� ���� �ڽ��� NULL�� �ƴ϶�� ���� �ڽ��� Ʈ���� �湮�Ѵ�
		if(m_right != NULL) m_right -> PreOrder();
		// ���� ������ �ڽ��� NULL�� �ƴ϶�� ������ �ڽ��� Ʈ���� �湮�Ѵ�
	}

	void InOrder(){ // ������ȸ�ϴ� �Լ�
		if(m_left != NULL) m_left -> InOrder();
		// ���� ���� �ڽ��� NULL�� �ƴ϶�� ���� �ڽ��� Ʈ���� �湮�Ѵ�
		Display(); // ���� ����Ű�� ��Ʈ ����� ������ �� ���
		if(m_right != NULL) m_right -> InOrder();
		// ���� ������ �ڽ��� NULL�� �ƴ϶�� ������ �ڽ��� Ʈ���� �湮�Ѵ�
	}
	
	void PostOrder(){ // ������ȸ�ϴ� �Լ�
		if(m_left != NULL) m_left -> PostOrder();
		// ���� ���� �ڽ��� NULL�� �ƴ϶�� ���� �ڽ��� Ʈ���� �湮�Ѵ�
		if(m_right != NULL) m_right -> PostOrder();
		// ���� ������ �ڽ��� NULL�� �ƴ϶�� ������ �ڽ��� Ʈ���� �湮�Ѵ�
		Display(); // ���� ����Ű�� ��Ʈ ����� ������ �� ���
		
	}

	void Add(CCebTNode* n){ // ��带 �߰��ϴ� �Լ�
		if(n->getPriority() < getPriority()){ 
			// ���� �μ��� ������ ���� �켱������ ���� �켱�������� ������ 
			if(m_left == NULL) m_left = n; // �����ڽ��� NULL�̸� ���� �ڽĿ� �����ϰ�
			else m_left->Add(n); // NULL�� �ƴϸ� �����ڽ��� Add �Լ��� ȣ���Ͽ� ����
		}

		else{ // ���� �μ��� ������ ���� �켱������ ���� �켱�������� ũ��
			if(m_right == NULL) m_right = n; // �����U�ڽ��� NULL�̸� ������ �ڽĿ� �����ϰ�
			else m_right->Add(n); // NULL�� �ƴϸ� �������ڽ��� Add �Լ��� ȣ���Ͽ� ����
		}
	}

	int Height(){ // Ʈ���� ���̸� ��ȯ�ϴ� �Լ�
      int n1 = 0,n2 = 0; // n1�� ���� ����Ʈ���� ���̸� �����ϰ�, n2�� ������ ����Ʈ���� ���̸� �����ϴ� ����������
      if(m_left != NULL) n1 = m_left->Height();
	  // ���� ���� ����Ʈ���� NULL�� �ƴ϶�� n1�� m_left�� Height �Լ��� ȣ���Ͽ� �Լ� ��ȸ
      if(m_right != NULL) n2 = m_right->Height();
	  // ���� ������ ����Ʈ���� NULL�� �ƴ϶�� n2�� m_right�� Height �Լ��� ȣ���Ͽ� �Լ� ��ȸ
      return (n1>n2)? n1+1 : n2+1; 
	  // ���� n1�� n2���� ũ�ٸ� n1�� �� Ʈ���� ���̰� �Ǵ� ���̰�, �۴ٸ� n2�� �� Ʈ���� ���̰� ��
	  // ���⼭ Height �Լ��� ȣ���Ҷ����� ��ȯ������ ���� Ʈ���� ���̺��� +1 ������Ŵ
   }
   
   int Count(){ // Ʈ���� ��� ������ ��ȯ�ϴ� �Լ�
      int n1 = 0; // ������ ���� n1�� 0���� �ʱ�ȭ
      int n2 = 0; // ������ ���� n2�� 0���� �ʱ�ȭ
      if(m_left != NULL) n1 = m_left->Count(); // ���� m_left�� NULL�� �ƴ϶�� m_left�� Count ȣ��
	  if(m_right != NULL) n2 = m_right->Count(); // ���� m_right�� NULL�� �ƴ϶�� m_right�� Count ȣ��
      return n1+n2+1; // ��尡 ���������� ȣ��� ������ ��ȯ���� +1�� ���� �༭ ����� ���� ������Ŵ
   }
	
	CCebTNode* FindItem(int val){ // Ʈ���� �μ��� ���� val���� ���� �켱������ ���� ��带 Ž��(��ȯ ���)
      
      if(this == NULL) return NULL; // ���� ��尡 NULL�̸� �̰��� ��ȯ
      if(this->getPriority() == val){  // ���� ���� ����Ű�� �ִ� ����� �켱������ �μ��� ���� ���� ���ٸ�    
         return this; // ���� ��� ��ȯ 
      }else if(this->getPriority() > val){ // ���� ���� ����Ű�� �ִ� ����� �켱�������� �μ��� ���� ���� �� ũ�ٸ�
         return m_left -> FindItem(val);
		 // ���� �ڽ�(���� ��Ʈ�� �켱�������� �� ���� �켱������ �ִ� ���)���� FindItem �Լ��� ȣ���Ͽ� val ���� ã�´�
      }else if(this->getPriority() < val){ // ���� ���� ����Ű�� �ִ� ����� �켱�������� �μ��� ���� ���� �� �۴ٸ�
         return m_right -> FindItem(val);
		 // ������ �ڽ�(���� ��Ʈ�� �켱�������� �� ū �켱������ �ִ� ���)���� FindItem �Լ��� ȣ���Ͽ� val ���� ã�´�
      }
      
   }
	CCebTNode* FindItemIter(int val){ // Ʈ���� �μ��� ���� val���� ���� �켱������ ���� ��带 Ž��(�ݺ� ���)
      CCebTNode* p = this; // CCebTNode*�� ������ �ϳ� �����Ͽ�, this ���� �����Ѵ�
      while(p != NULL){ // �ݺ����� ���鼭 ���� p�� NULL�� �ƴ϶�� p�� NULL�� �ɶ����� �ݺ����� ���鼭
         if(p->getPriority() == val) return p; // ���� p�� �켱������ �μ��� ���� �켱������ ���ٸ� p�� ��ȯ
         else if(p->getPriority() > val) p= p->m_left; // ���� val ���� p�� �켱�������� �۴ٸ� p�� p�� ���� �ڽ����� ����
         else if(p->getPriority() < val) p= p->m_right; // ���� val ���� p�� �켱�������� ũ�ٸ� p�� p�� ������ �ڽ����� ����
      }
      return NULL; // ���� �ݺ������� ��ȯ���� �ʾ����� NULL�� ��ȯ
   }


	void FindPriceRange( int minPrice, int maxPrice ){ // ������ �μ��� ���� �� �� ���̿� �����ϴ� ��� ����ϴ� �Լ�
      if(this->getPrice() >= minPrice && this->getPrice() <= maxPrice ) // ���� ���� ����� ������ minPrice�� maxPrice ���̸�
         Display(); // Display �Լ� ȣ��
      if(m_left != NULL) m_left -> FindPriceRange(minPrice, maxPrice); // ���� m_left�� NULL�� �ƴ϶��, ���� �ڽ��� FindPriceRange�� �ҷ� ��� Ž��
      if(m_right != NULL) m_right -> FindPriceRange(minPrice, maxPrice); // ���� m_right�� NULL�� �ƴ϶��, ������ �ڽ��� FindPriceRange�� �ҷ� ��� Ž��
   }
};

