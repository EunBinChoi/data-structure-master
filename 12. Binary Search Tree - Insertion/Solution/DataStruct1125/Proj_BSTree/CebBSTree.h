#pragma once
#include "CebTNode.h"

class CCebBSTree // ����Ʈ���� �����ϴ� Ŭ���� ����
{
	CCebTNode* m_root; // ����Ʈ���� �����ϴ� CCebTNode*�� ��������

public:

	CCebBSTree(void){m_root = NULL;} // ������, m_root�� NULL�� �ʱ�ȭ
	~CCebBSTree(void){if(m_root!=NULL) delete m_root;}
	// �Ҹ���, ���� m_root�� NULL�� �ƴ϶�� �� ���� delete�� ����

	void PrintPreOrder(){ // ������ȸ�� �ϴ� �Լ�
		if(m_root != NULL) m_root->PreOrder(); 
		// ���� m_root�� NULL�� �ƴ϶�� PreOrder �Լ��� ȣ���Ͽ� ������ȸ
	 
		printf("\n");
	}
	void PrintInOrder(){ // ������ȸ�� �ϴ� �Լ�
		if(m_root != NULL) m_root->InOrder();
		// ���� m_root�� NULL�� �ƴ϶�� InOrder �Լ��� ȣ���Ͽ� ������ȸ

		printf("\n");
	}
	void PrintPostOrder(){ // ������ȸ�� �ϴ� �Լ�
		
		if(m_root != NULL) m_root->PostOrder();
		// ���� m_root�� NULL�� �ƴ϶�� PostOrder �Լ��� ȣ���Ͽ� ������ȸ

		printf("\n");
	}

	void Add(CCebTNode* n){ // ��带 �߰��ϴ� �Լ�
		if(n == NULL) return; // ���� �μ��� ���� ��尡 NULL�̶�� return
		if(m_root == NULL) m_root = n; 
		// ���� m_root�� NULL�̶��(���� ����Ʈ���� �������� �ʾ�����) m_root�� n ����
		else{ // ���� m_root�� NULL�� �ƴ϶��
			m_root ->Add (n); // Add �Լ��� ȣ���Ͽ� ��带 �߰���
		}

	}
	int GetCount(){ // ����Ʈ���� �����ϴ� ����� ������ ��ȯ�ϴ� �Լ�
		if(m_root == NULL) return 0; // ���� m_root�� NULL�̸� 0�� ��ȯ
		else // �װ� �ƴ϶��
			return m_root->Count();
		// Count �Լ��� �ҷ� ����� ������ ��ȯ
	}

	int GetHeight(){ // ����Ʈ���� �����ϴ� ����� ���̸� ��ȯ�ϴ� �Լ�
		if(m_root == NULL) return 0; // ���� m_root�� NULL�̸� 0�� ��ȯ
		else // �װ� �ƴ϶��
			return m_root->Height();
		// Height �Լ��� �ҷ� ����� ���̸� ��ȯ
	}

void SearchPriority(int val) // �μ��� ���� ���� ��ġ�ϴ� �켱������ ���� ����� ��ġ�� ã�� �Լ�
   {
      CCebTNode* n1; // CCebTNode* �� ���� ����
      CCebTNode* n2; // CCebTNode* �� ���� ����
      if(this->m_root == NULL){ // ���� m_root�� NULL�̸�
         printf("Ʈ���� ����ֽ��ϴ�"); // Ʈ���� ����ִٴ� �޽��� ���
      }
      else{ // �װ� �ƴ϶�� 
         printf("(�ݺ�) "); // �ݺ������� ������ SearchPriority
         n1 = m_root->FindItemIter(val); // FindItemIter �Լ��� ȣ���Ͽ� ��ȯ ���� n1�� ����
         if(n1 != NULL) n1->Display(); // ���� n1�� NULL�� �ƴϸ� Display �Լ� ȣ��
         else printf("��忡 �Է��� priority�� %2d�� �����ϴ�\n",val);
		 // ���� NULL�̶�� ���� ���� �޽��� ���

         printf("(���) "); // ��ͷ� ������ SearchPriority
         n2 = m_root->FindItem(val); // FindItem �Լ��� ȣ���Ͽ� ��ȯ ���� n2�� ����
         if(n2 != NULL) n2->Display(); // ���� n2�� NULL�� �ƴϸ� Display �Լ� ȣ��
         else printf("��忡 �Է��� priority�� %2d�� �����ϴ�",val);
		  // ���� NULL�̶�� ���� ���� �޽��� ���
      }
	  printf("\n");
   }
	void SearchPriceRange(int minPrice, int maxPrice){ // �μ��� ������ min, max�� �ش��ϴ� ������ ���� ��� ���
		m_root->FindPriceRange(minPrice,maxPrice);
		// �μ��� min,max�� ������ �ִ� FindPriceRange �Լ� ȣ��

	}

};	

