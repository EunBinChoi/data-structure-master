#pragma once
#include "CebItemNode.h" // ��ũ�� ����Ʈ���� ��带 �����ϴ� Ŭ������ ����Ǿ��ִ� ������� ����

class CCebLinkedList // ��ũ�� ����Ʈ�� �����ϴ� Ŭ���� ����
{
	int cnt; // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ���� ����
	CCebItemNode m_org; // ��ũ�� ����Ʈ���� ��� ��带 ����  

public:  // ��𼭵� ������ �� �ֵ��� public ���� ����
	CCebLinkedList(void) : m_org(""){cnt = 0;} // ������, CCebItemNode�� ��ü m_org�� ""���� �ʱ�ȭ����Ʈ�� ���� �ʱ�ȭ ���ְ�, �׸� ���� ������ �����ϴ� ������ 0���� �ʱ�ȭ
	~CCebLinkedList(void){Clear();} // �Ҹ���, Clear �Լ��� ȣ���Ѵ�
	CCebItemNode* GetHead() {return m_org.Next();} // CCebItemNode ��ü(m_org)�� ���� ó���� ��带 ��ȯ�ϴ� �Լ�

	bool IsEmpty(){return GetHead() == NULL; } 
	// ��ũ�� ����Ʈ�� ����ִ��� Ȯ���ϴ� �Լ�(���� GetHead �Լ�(��ũ��)�� NULL�̸� ��ũ�� ����Ʈ�� �������)
	int GetLength(){return cnt;}
	// ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ���� cnt�� ��ȯ�ϴ� �Լ�

	CCebItemNode* GetTail(){ // ��ũ�� ����Ʈ���� ���� ������ ��带 ��ȯ�ϴ� �Լ�
		CCebItemNode* tail = &m_org; // CCebItemNode* ��ü�� �ϳ� ������ �� �� ������ ���� ó���� ����� �ּҸ� �������ش�
		for(; tail->Next() != NULL ; tail = tail->Next()); // �ݺ����� ���鼭 tail�� ��ũ ���� ���� ��ũ ������ ����ؼ� �������ְ�, ���� tail�� ��ũ���� NULL�̸� tail�� ������ ����� �ǹ��̴�
		// �ݺ����� tail�� ��ũ���� NULL�� �ƴ� �������� �ݺ����� ����, NULL�̶�� �ݺ����� ���´�(tail�� ������ ��带 ����Ŵ)
		return tail; // ������ ��带 ����Ű�� tail�� ��ȯ��
	}

	void Display(char*meg = ""){ //��ũ�� ����Ʈ�� �׸��� ����ϴ� �Լ�
		if(IsEmpty()){ // ���� ��ũ�� ����Ʈ�� ����ִٸ�
			printf("[%s ��ü �׸� �� = %2d] \n",meg,GetLength());
			printf("����Ʈ�� ����ֽ��ϴ�\n\n");
		}
		else{  // ���� ��ũ�� ����Ʈ�� ������� �ʴٸ�
			printf("[%s ��ü �׸� �� = %2d] \n",meg,GetLength());

			for(CCebItemNode *p = GetHead(); p != NULL ; p=p->Next())
				// ���� ó���� �������� ������ ������ �ݺ����� ���鼭
				p->Display(); // p�� ����Ű�� ����� �����͸� ���
			printf("\n\n");
		}
	}

	void AddHead(CCebItemNode* n){ // ��ũ�� ����Ʈ���� ���� �տ� ��带 �߰��ϴ� �Լ�
		if(IsEmpty()) // ��ũ�� ����Ʈ�� ����ִ� ���
		{
			m_org.AddNext(n); // m_org�� AddNext �Լ��� ȣ���Ͽ� �μ��� ���� n�� ���� �߰��Ѵ�
		}

		else // ��ũ�� ����Ʈ�� ������� ���� ���
		{
			//n->SetNext(m_org.Next()); // �μ��� ���� n�� SetNext �Լ��� ȣ���Ͽ� n�� ��ũ ���� ��� ����� ��ũ ���� �������ش�
			//m_org.SetNext(n); // m_org�� AddNext �Լ��� ȣ���Ͽ� �μ��� ���� n�� ���� �߰��Ѵ�
			m_org.AddNext(n); // �μ��� ���� ��� ���� ��� ��� �ڿ� AddNext �Լ��� ȣ���Ͽ� �߰��Ѵ�
		}
		cnt ++; // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ������Ų��
	}

	void AddTail(CCebItemNode* n){ // ��ũ�� ����Ʈ���� ���� �ڿ� ��带 �߰��ϴ� �Լ�
		if(IsEmpty())  // ��ũ�� ����Ʈ�� ����ִ� ���
		{
			m_org.AddNext(n); // m_org�� AddNext �Լ��� ȣ���Ͽ� �μ��� ���� n�� ���� �߰��Ѵ�
		}

		else // ��ũ�� ����Ʈ�� ������� ���� ���
		{
			//n->AddNext(GetTail()->Next());
			GetTail()->AddNext(n); // �μ��� ���� ��� ���� ���� ������ ��忡 AddNext �Լ��� ȣ���Ͽ� �߰��Ѵ�
		}
		cnt ++; // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ������Ų�� 
	}

	void AddNext(CCebItemNode *p, CCebItemNode *n){ // ��ũ�� ����Ʈ���� �μ��� ���� p �� �ڿ� ��� n�� �߰��Ѵ�
		if(IsEmpty())  // ��ũ�� ����Ʈ�� ����ִ� ���
		{
			m_org.AddNext(n); // m_org�� AddNext �Լ��� ȣ���Ͽ� �μ��� ���� n�� ���� �߰��Ѵ�
		}

		else
		{
			n->SetNext(p->Next()); // �߰��� ��� n�� ��ũ ���� p�� ���� ����� �ּҸ� �����Ѵ�
			p->AddNext(n); // �μ��� ���� p�� ���� ��带 n���� �߰��Ѵ�
		}
		cnt ++; // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ������Ų��
	}

	void RemoveHead(){ // ��ũ�� ����Ʈ���� ���� �տ� ��带 �����ϴ� �Լ�
		if(!IsEmpty()){ // ��ũ�� ����Ʈ�� ������� ���� ���
			CCebItemNode* t = m_org.Next(); // CCebItemNode* �� �ӽ� ���� t�� ������ �ڿ� �� ���� ��� ����� ��ũ��(������� ���� ��带 �����ϴ� �ּ�)�� �����Ѵ�
			m_org.SetNext(t->Next()); // �� ��° ��带 ù ��° ���� ����(ù��° ��尡 ������)
			delete t; // �ӽú����� ����� t�� ������ ������ delete �� ���� ������Ų��
		}
		cnt--; // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ���ҽ�Ų��
	}
	void Remove(CCebItemNode *n){ // ��ũ�� ����Ʈ���� ��带 �����ϴ� �Լ�
		if(IsEmpty()) return; // ���� ��ũ�� ����Ʈ�� ����ִٸ� ��带 ������ �� �����Ƿ� return�� ���� �Լ� ����
		if(n == GetHead()){ // ���� �μ��� ���� n�� ���� ó���� �����  
			m_org.SetNext(n->Next()); // �� ��° ��带 ù ��° ���� ����(ù��° ��尡 ������)
			delete n; // �ӽú����� ����� t�� ������ ������ delete �� ���� ������Ų��
			cnt--; // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ���ҽ�Ų��
		}
		else{ // ���� �μ��� ���� n�� ���� ó���� ��尡 �ƴ϶��
			for(CCebItemNode *p = GetHead(); p != NULL ; p=p->Next())
				// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
			{
				if(p->Next() == n)
				{ // ���� p ����� ���� ��尡 �μ��� ���� n�� �������ٸ�
					p->SetNext(n->Next()); // p�� ��ũ���� �μ��� ���� n�� ��ũ������ ����(�߰��� �ִ� n ��尡 ������)
					delete n; // n�� delete �� ���� ������Ų��
					cnt--; // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ���ҽ�Ų��
				}
			}
		}
	} 
	void Clear(){ // ��ũ�� ����Ʈ�� ��� �׸��� �����ϴ� �Լ�
		CCebItemNode* t; // CCebItemNode* �� �ӽ� ���� t�� ���� 
		t = GetHead();  // �ӽú��� t�� ���� ó���� ��带 �����Ѵ�

		if(GetHead()!=NULL){ // ���� ���� ó���� ����� ��ũ ���� NULL�� �ƴϸ�
			for(CCebItemNode *p = GetHead()->Next(); p != NULL ; p=p->Next())
				// ���� ó���� ����� ���� ������ ������ ������ �ݺ����� ���鼭
			{
				delete t; // �ӽú��� t�� delete�� ���ؼ� �����Ѵ�
				t = p; // �ӽú��� t�� p�� ���� �����Ѵ�
			}
			delete t; // ������ �������� ���� ���� delete�� ���ؼ� �����Ѵ�
			m_org.SetNext(NULL); // ��� ����� ��ũ ���� NULL�� ����
			cnt = 0; // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ 0���� ����
		}
	}

	CCebItemNode *FindPrev(CCebItemNode *n){ // �μ��� ���� ���� ���� ��ġ�� ã�� �Լ�(�� �Լ��� ��ȯ���� CCebItemNode*�̴�)
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->Next())
			// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
		{
			if(p->Next() == n){ // ���� p�� ���� ��尡 n�̶��
				return p; // p�� ���� ��ȯ�Ѵ�
			}
		}
		return NULL; // �׷��� �ʴٸ� NULL ���� ��ȯ�Ѵ�
	}


	CCebItemNode *FindNodePriority(int val) // �μ��� ���� ���� ��ġ�ϴ� �켱������ ���� ����� ��ġ�� ã�� �Լ�(�� �Լ��� ��ȯ���� CCebItemNode*�̴�)
	{
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->Next())
			// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
		{
			if(p->getPriority() == val) // ���� p���� getPriority() �Լ��� ȣ������ �� �켱���� ���� �μ��� ���� val ���� ������
				return p; // p ���� ��ȯ�Ѵ�

		}
		return NULL; // �׷��� �ʴٸ� NULL ���� ��ȯ�Ѵ�
	}

	CCebItemNode *FindNodeName(char* val) // �μ��� ���� ���� ��ġ�ϴ� �̸��� ���� ����� ��ġ�� ã�� �Լ�(�� �Լ��� ��ȯ���� CCebItemNode*�̴�)
	{
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->Next())
			// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
		{
			if(*(p->getName()) == *val) // ���� p���� getName() �Լ��� ȣ������ �� �켱���� ���� �μ��� ���� val ���� ������
				return p; // p ���� ��ȯ�Ѵ�

		}
		return NULL; // �׷��� �ʴٸ� NULL ���� ��ȯ�Ѵ�
	}

	CCebItemNode *FindNodePrice(int val) // �μ��� ���� ���� ��ġ�ϴ� ������ ���� ����� ��ġ�� ã�� �Լ�(�� �Լ��� ��ȯ���� CCebItemNode*�̴�)
	{
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->Next())
			// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
		{
			if(p->getPrice() == val) // ���� p���� getPrice() �Լ��� ȣ������ �� �켱���� ���� �μ��� ���� val ���� ������
				return p; // p ���� ��ȯ�Ѵ�

		}
		return NULL; // �׷��� �ʴٸ� NULL ���� ��ȯ�Ѵ�
	}

	CCebItemNode *FindNodeMethod(char* val) // �μ��� ���� ���� ��ġ�ϴ� ��¹���� ���� ����� ��ġ�� ã�� �Լ�(�� �Լ��� ��ȯ���� CCebItemNode*�̴�)
	{
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->Next())
			// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
		{
			if(*(p->getMethod()) == *val) // ���� p���� getMethod() �Լ��� ȣ������ �� �켱���� ���� �μ��� ���� val ���� ������
				return p; // p ���� ��ȯ�Ѵ�

		}
		return NULL; // �׷��� �ʴٸ� NULL ���� ��ȯ�Ѵ�
	}

	void PrintPriceRange(int min, int max){ // �μ��� ���� ������ �ּҰ��� �ִ밪 ���̿� �ִ� ������ ���� ��带 ����ϴ� �Լ�
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->Next())
			// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
		{
			if((p->getPrice() >= min) && (p->getPrice() <= max)) // getPrice �Լ��� �ҷ��� �� �ּҰ� �ִ밪 ���̿� �ִٸ� 
				p->Display(); // �� ����� �����͸� ����Ѵ�

		}
	}

	void Merge(CCebLinkedList &list2){ // �� ���� ��ũ�� ����Ʈ�� �����ϴ� �Լ�

		if(IsEmpty()) // ���� ���� ��ũ�� ����Ʈ�� ����ִٸ�
		{
			m_org.SetNext(list2.GetHead()); // ��� ����� ���� ��ũ ���� list2�� ���� ó�� ����� ������ �����Ѵ�
		}

		else // ��ũ�� ����Ʈ�� ������� ���� ���
		{
			GetTail()->SetNext(list2.GetHead()); // ���� ��ũ�� ����Ʈ�� ���� ������ ����� ���� ��ũ���� list2�� ���� ó�� ��� ������ �����Ѵ�

		}
		cnt += list2.GetLength(); // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ list2.GetLength �Լ��� �ҷ� list2�� ������ŭ �߰����ش�

		// list1�� �ڿ� list2�� ���ܵΰ� list2�� ��������
		list2.m_org.SetNext(NULL);  // list2�� ������� ���� ��ũ ��(���� ó���� ���)�� NULL���� �����Ѵ�
		list2.cnt = 0; // list2�� cnt ���� 0���� �ʱ�ȭ�Ѵ�
	}


	void HeadMerge(CCebLinkedList &list2){ // �� ���� ��ũ�� ����Ʈ�� �����ϴ� �Լ�(�տ��� ���� ����)

		if(IsEmpty()) // ���� ���� ��ũ�� ����Ʈ�� ����ִٸ�
		{
			m_org.SetNext(list2.GetHead()); // ��� ����� ���� ���� list2�� ó�� ���� �����Ѵ�  

		}
		else // ��ũ�� ����Ʈ�� ������� ���� ���
		{
			if(!list2.IsEmpty()){ // ���� list2�� ������� ������
				list2.GetTail()->SetNext(this->GetHead()); // list2�� ������ ����� ��ũ���� ���� ��ü�� ó�� ���� �����Ѵ�
				this->m_org.SetNext(list2.GetHead());  // ������� ��ũ���� list2�� ó�� ��� ������ ����
			}
		}
		cnt += list2.GetLength(); // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ list2.GetLength �Լ��� �ҷ� list2�� ������ŭ �߰����ش�

		list2.m_org.SetNext(NULL); // list2�� ������� ���� ��ũ ��(���� ó���� ���)�� NULL���� �����Ѵ�  
		list2.cnt = 0; // list2�� cnt ���� 0���� �ʱ�ȭ�Ѵ�
	}

	void  Reverse(){ // ��ũ�� ����Ʈ�� �������� ����� �Լ�
		CCebItemNode *p,*q, *r; // CCebItemNode* �� �ӽú��� p,q(���� ����� ��ġ),r(���� ����� ��ġ)�� �����Ѵ�
		p = GetHead(); // p�� ���� ó���� ��带 ������
		q = NULL; // q�� NULL�� ������

		while(p != NULL){ // p�� NULL�� �ƴ� ������ �ݺ����� ���鼭
			r = q; // r�� q�� ���� �����ϰ�
			q = p; // q�� p�� ���� �����ϰ�
			p = p->Next(); // p�� p�� ���� ��忡 �����Ѵ�
			q->SetNext(r); // q�� ��ũ ���� r�� �������ش�
		}
		m_org.SetNext(q);  // ��� ����� ��ũ ���� q�� �������ش�
	}


	void PriorityArrange(){ // �켱���� ������� �����ϴ� �Լ�
		int* priorityArray = new int[GetLength()]; // ��ũ�� ����Ʈ�� �켱 ���� ���� �޾ƿ��� �迭
		int i,j; // �ݺ����� �������� ����
		int min; // ���� ���� ���� ����
		int index; // ���� ���� ���� �ε����� ����
		int temp; // �ӽú���
		CCebItemNode *p; // �ݺ����� ���� ���� �ӽú���


		for(i = 0,p = GetHead() ; i < GetLength()&&p!=NULL; i ++,p=p->Next()){
			// �ݺ����� ���鼭
			priorityArray[i] = p->getPriority(); // �迭�� ��ü�� �켱���� ���� �����Ѵ�

		} 

		for(i=0;i<GetLength()-1;i++) // �ݺ����� ���鼭 �迭�� ���� ���� �����Ѵ�
		{
			min = priorityArray[i]; // ���� ���� ���� priorityArray �迭�� i �ε����� �ִ� ���̶�� ����
			index = i; // ���� ���� ���̶�� ������ i�� �ε��� ����

			for(j=i+1;j<GetLength();j++){ // min�̶�� �������� �迭�� ���Ұ� �������� �迭 ������ �ݺ��ϸ鼭
				if(min >priorityArray[j]){ // ���� �� ���� ���� ������
					min = priorityArray[j]; // �� ���� min���� �����ϰ�
					index  =j; // min���� ������ �ε��� ���� index�� ����
				}
			}

			// �� ���� swap ��Ű�� �κ�
			temp=priorityArray[i]; 
			priorityArray[i]=priorityArray[index];
			priorityArray[index]=temp;

		}

		int x = GetLength()-1;
		for(int i = 0 ; i < x ; i++) { // �ݺ����� ���鼭 

			CCebItemNode *t = FindNodePriority(priorityArray[i+1]); // �ڿ� ���� ��� Ž���� �ӽú��� t�� ����
			CCebItemNode *t1 = FindPrev(t); // �ڿ� ���� ����� �� ��带 ã�� �ӽú��� t1�� ����

			if(t1 != NULL) // ���� t1�� NULL�� �ƴϸ�
				t1->SetNext(t->Next());   // t1�� ��ũ���� t�� ��ũ������ ����(��������)
			else{ // NULL�̸�
				this->m_org.SetNext(t->Next()) ;
				// t�� ���� ó���� ����� ���̹Ƿ� ����尡 ����Ű�� ���� �ӽú��� t�� ��ũ������ ����
			}

			CCebItemNode* n = FindNodePriority(priorityArray[i]); // i��°�� �ִ� �켱���� ���� ������ ��带 Ž����
			n->AddNext(t);   // n�� ���� ��忡 t ������ �߰����ش�
		}

	}


};

