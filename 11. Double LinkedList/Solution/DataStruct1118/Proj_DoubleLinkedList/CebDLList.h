// �����Ḯ��Ʈ�� ���� �ּҵ� ����Ǿ��ֱ� ������ ������ �ٲ㼭 ����ϴ°ų� �׷��� ������
#pragma once 
#include "CebItemNode.h" // ��ũ�� ����Ʈ���� ��带 �����ϴ� Ŭ������ ����Ǿ��ִ� ������� ����

class CCebDLList // ���� ��ũ�� ����Ʈ�� �����ϴ� Ŭ���� ����
{
	int cnt; // ���� ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ���� ����
	CCebItemNode m_org; // ���� ��ũ�� ����Ʈ���� ��� ��带 ����  
	// �̹� Node Ŭ�������� ����������� �� �ʱ�ȭ�߱� ������ �� ��ü�� ���� �ʱ�ȭ���� �ʾƵ� ��

public:  // ��𼭵� ������ �� �ֵ��� public ���� ����
	CCebDLList(void) : m_org(""){cnt = 0;} // ������, CCebItemNode�� ��ü m_org�� ""���� �ʱ�ȭ����Ʈ�� ���� �ʱ�ȭ ���ְ�, �׸� ���� ������ �����ϴ� ������ 0���� �ʱ�ȭ
	~CCebDLList(void){Clear();} // �Ҹ���, Clear �Լ��� ȣ���Ѵ�
	CCebItemNode* GetHead() {return m_org.GetNext();} 
	// CCebItemNode ��ü(m_org)�� ���� ó���� ��带 ��ȯ�ϴ� �Լ�

	bool IsEmpty(){return GetHead() == NULL; } 
	// ���� ��ũ�� ����Ʈ�� ����ִ��� Ȯ���ϴ� �Լ�(���� GetHead �Լ�(��ũ��)�� NULL�̸� ��ũ�� ����Ʈ�� ����ִٴ� �ǹ�)
	int GetLength(){return cnt;}
	// ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ���� cnt�� ��ȯ�ϴ� �Լ�

	CCebItemNode* GetTail(){ // ��ũ�� ����Ʈ���� ���� ������ ��带 ��ȯ�ϴ� �Լ�
		CCebItemNode* tail = &m_org; // CCebItemNode* ��ü�� �ϳ� ������ �� �� ������ ���� ó���� ����� �ּҸ� �������ش�
		for(; tail->GetNext() != NULL ; tail = tail->GetNext()); // �ݺ����� ���鼭 tail�� ��ũ ���� ���� ��ũ ������ ����ؼ� �������ְ�, ���� tail�� ��ũ���� NULL�̸� tail�� ������ ����� �ǹ��̴�
		// �ݺ����� tail�� ��ũ���� NULL�� �ƴ� �������� �ݺ����� ����, NULL�̶�� �ݺ����� ���´�(tail�� ������ ��带 ����Ŵ)
		return tail; // ������ ��带 ����Ű�� tail�� ��ȯ��
	}

	void Display(char*meg = ""){ // ���� ��ũ�� ����Ʈ�� �׸��� ����ϴ� �Լ�
		if(IsEmpty()){ // ���� ���� ��ũ�� ����Ʈ�� ����ִٸ�
			printf("[%s ��ü �׸� �� = %2d] \n",meg,GetLength());
			printf("����Ʈ�� ����ֽ��ϴ�\n\n"); // ������ ���� �޼��� ���
		}else{  // ���� ��ũ�� ����Ʈ�� ������� �ʴٸ�
			printf("[%s ��ü �׸� �� = %2d] \n",meg,GetLength()); // ���� ��ũ�� ����Ʈ�� �׸� ���� ���

			for(CCebItemNode *p = GetHead(); p != NULL ; p=p->GetNext())
			{	// ���� ó���� �������� ������ ������ �ݺ����� ���鼭
				p->Display(); // p�� ����Ű�� ����� �����͸� ���
			}
			printf("\n\n");
		}
	}

	void AddHead(CCebItemNode* n){ // ���� ��ũ�� ����Ʈ���� ���� �տ� ��带 �߰��ϴ� �Լ�
		m_org.AddNext(n); // �μ��� ���� ��� ���� ��� ��� �ڿ� AddNext �Լ��� ȣ���Ͽ� �߰��Ѵ�
		cnt ++; // ���� ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ������Ų��
	}

	void AddTail(CCebItemNode* n){ // ���� ��ũ�� ����Ʈ���� ���� �ڿ� ��带 �߰��ϴ� �Լ�
		if(IsEmpty())  // ��ũ�� ����Ʈ�� ����ִ� ���
		{
			m_org.AddNext(n); // m_org�� AddNext �Լ��� ȣ���Ͽ� �μ��� ���� n�� ���� �߰��Ѵ�
		}

		else // ��ũ�� ����Ʈ�� ������� ���� ���
		{
			GetTail()->AddNext(n); // �μ��� ���� ��� ���� ���� ������ ��忡 AddNext �Լ��� ȣ���Ͽ� �߰��Ѵ�
		}
		cnt ++; // ���� ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ������Ų�� 
	}

	void AddNext(CCebItemNode *p, CCebItemNode *n){ // ���� ��ũ�� ����Ʈ���� �μ��� ���� p �� �ڿ� ��� n�� �߰��Ѵ�
		if(IsEmpty())  // ���� ��ũ�� ����Ʈ�� ����ִ� ���
		{
			m_org.AddNext(n); // m_org�� AddNext �Լ��� ȣ���Ͽ� �μ��� ���� n�� ���� �߰��Ѵ�
		}

		else
		{
			n->SetNext(p->GetNext()); // �߰��� ��� n�� ��ũ ���� p�� ���� ����� �ּҸ� �����Ѵ�
			p->AddNext(n); // �μ��� ���� p�� ���� ��带 n���� �߰��Ѵ�
			n->GetNext()->SetPrev(n); // n�� ���� ���(���� �ڵ忡�� p ������ ��尡 n���� �ٲ�����Ƿ�)�� ���� �ּҸ� n���� �����Ѵ�
		}
		cnt ++; // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ������Ų��
	}

	void RemoveHead(){ // ���� ��ũ�� ����Ʈ���� ���� �տ� ��带 �����ϴ� �Լ�
		if(!IsEmpty()){ // ���� ��ũ�� ����Ʈ�� ������� ���� ���
			CCebItemNode* t = m_org.GetNext(); // CCebItemNode* �� �ӽ� ���� t�� ������ �ڿ� �� ���� ��� ����� ��ũ��(������� ���� ��带 �����ϴ� �ּ�)�� �����Ѵ�
			m_org.SetNext(t->GetNext()); // �� ��° ��带 ù ��° ���� ���� (ù��° ��尡 ������)

			if(t->GetNext() != NULL){ // ���� �� ��° ��尡 NULL�� �ƴϸ�
				t->GetNext()->SetPrev(&m_org); // �� ��° ����� ���� ��ũ ���� �����ϴ� ������ ������� �ּҸ� ����ִ´�
			}
			delete t; // �ӽú����� ����� t�� ������ ������ delete �� ���� ������Ų��
		}
		cnt--; // ���� ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ���ҽ�Ų��
	}

	void RemoveTail(){ // ���� ��ũ�� ����Ʈ���� ���� ������ ��带 �����ϴ� �Լ�
		if(!IsEmpty()){ // ���� ��ũ�� ����Ʈ�� ������� ���� ���
			CCebItemNode* t = GetTail(); // CCebItemNode* �� �ӽ� ���� t�� ������ �ڿ� �� ������ ������ ����� �ּҸ� ����ִ´�
			if(t->GetPrev()!=NULL) // ���� ������ ����� ���� �ּҰ� NULL�� �ƴϸ�
				t->GetPrev()->SetNext(NULL); // ������ ����� ���� �ּ��� ���� �ּ�(���������)�� NULL�� ����
			delete t; // ������ ��尡 ������ ������ delete �� ���� ������Ų��
		}


		cnt--; // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ���ҽ�Ų��

	}
	void Remove(CCebItemNode *n){ // ���� ��ũ�� ����Ʈ���� ��带 �����ϴ� �Լ�
		if(IsEmpty()) return; // ���� ���� ��ũ�� ����Ʈ�� ����ִٸ� ��带 ������ �� �����Ƿ� return�� ���� �Լ� ����
		if(n == GetHead()){ // ���� �μ��� ���� n�� ���� ó���� �����  
			this->RemoveHead(); // RemoveHead �Լ��� ȣ���Ͽ� ó�� ��带 �����Ѵ�
		}
		else{ // ���� �μ��� ���� n�� ���� ó���� ��尡 �ƴ϶��
			for(CCebItemNode *p = GetHead(); p != NULL ; p=p->GetNext())
				// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
			{
				if(p->GetNext() == n)
				{ // ���� p ����� ���� ��尡 �μ��� ���� n�� �������ٸ�(p�� ���� ��带 �����ؾ��ϹǷ�)
					p->SetNext(n->GetNext()); // p�� ���� ���� �μ��� ���� n�� ���� ������ ����(�߰��� �ִ� n ��尡 ������)

					if(n->GetNext() != NULL) // ���� �����Ϸ��� �ϴ� ����� ���� ��尡 NULL�� �ƴϸ�
						n->GetNext()->SetPrev(p); // ���� ����� ���� ����� ��ġ�� p�� ����
					delete n; // n�� delete �� ���� ������Ų��
					cnt--; // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ���ҽ�Ų��
				}
			}
		}
	} 

	// PriorityArrange() �Լ��� �����ϱ� ���� �Լ�����
	// �� �Լ��� ������ ���� ��ȯ�ϴ� �Լ��̴�
	// ���� Remove�� �ٸ� ���� �� �Լ��� ������ ���� ��ȯ������ �ʴ´�
	CCebItemNode* ThisRemove(CCebItemNode *n){ // ���� ��ũ�� ����Ʈ���� ��带 ������ �� ������ ���� ��ȯ�ϴ� �Լ�
		if(IsEmpty()) return NULL; // ���� ���� ��ũ�� ����Ʈ�� ����ִٸ� ��带 ������ �� �����Ƿ� return�� ���� �Լ� ����
		if(n == GetHead()){ // ���� �μ��� ���� n�� ���� ó���� �����  
			m_org.SetNext(n->GetNext()); // �� ��° ��带 ù ��° ���� ����(ù��° ��尡 ������)

			if(n->GetNext() != NULL){ // ���� �����Ϸ��� �ϴ� ����� ���� �ּ� ���� NULL�� �ƴϸ�
				n->GetNext()->SetPrev(&m_org); // �����Ϸ��� �ϴ� ����� ���� �ּ� ���� ���� ����� ��ġ�� �����ϴ� ��ũ ���� ������� �ּ� ���� ����ִ´�
			}
			// cnt--;// ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ���ҽ�Ų��
			// ���� �ڵ尡 �ʿ���� ������ ������ �� ��ġ���� ��带 ���� ���߿� �ٽ� �������̹Ƿ� cnt���� ����
			return n; // ������ �� ���� ��ȯ�Ѵ�
		}
		else{ // ���� �μ��� ���� n�� ���� ó���� ��尡 �ƴ϶��
			for(CCebItemNode *p = GetHead(); p != NULL ; p=p->GetNext())
				// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
			{
				if(p->GetNext() == n)
				{ // ���� p ����� ���� ��尡 �μ��� ���� n�� �������ٸ�
					p->SetNext(n->GetNext()); // p�� ��ũ���� �μ��� ���� n�� ���� ������ ����(�߰��� �ִ� n ��尡 ������)

					if(n->GetNext() != NULL) // ���� �����Ϸ��� �ϴ� ����� ���� ��尡 NULL�� �ƴϸ�
						n->GetNext()->SetPrev(p); // �� ����� ���� ��带 �����ϴ� ������ p�� �����Ѵ�
					return n; // ������ �� ���� ��ȯ�Ѵ�
					//cnt--; // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ���ҽ�Ų��
					// ���� �ڵ尡 �ʿ���� ������ ������ �� ��ġ���� ��带 ���� ���߿� �ٽ� �������̹Ƿ� cnt���� ����

				}
			}
		}

	} 
	void Clear(){ // ���� ��ũ�� ����Ʈ�� ��� �׸��� �����ϴ� �Լ�

		while(m_org.GetNext() != NULL){// ��� ����� ���� ���(���� ó���� ���)�� NULL�� �ƴϸ�
			this->RemoveHead(); // ���� ��忡�� RemoveHead �Լ��� ȣ���Ͽ� ���� ó���� ��� ����
		}


	}

	CCebItemNode *FindPrev(CCebItemNode *n){ // �μ��� ���� ���� ���� ��ġ�� ã�� �Լ�(�� �Լ��� ��ȯ���� CCebItemNode*�̴�)
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->GetNext())
			// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
		{
			if(p->GetNext() == n){ // ���� p�� ���� ��尡 n�̶��
				return p; // p�� ���� ��ȯ�Ѵ�
			}
		}
		return NULL; // �׷��� �ʴٸ� NULL ���� ��ȯ�Ѵ�
	}


	CCebItemNode *FindNodePriority(int val) // �μ��� ���� ���� ��ġ�ϴ� �켱������ ���� ����� ��ġ�� ã�� �Լ�(�� �Լ��� ��ȯ���� CCebItemNode*�̴�)
	{
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->GetNext())
			// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
		{
			if(p->getPriority() == val) // ���� p���� getPriority() �Լ��� ȣ������ �� �켱���� ���� �μ��� ���� val ���� ������
				return p; // p ���� ��ȯ�Ѵ�

		}
		return NULL; // �׷��� �ʴٸ� NULL ���� ��ȯ�Ѵ�
	}

	CCebItemNode *FindNodeName(char* val) // �μ��� ���� ���� ��ġ�ϴ� �̸��� ���� ����� ��ġ�� ã�� �Լ�(�� �Լ��� ��ȯ���� CCebItemNode*�̴�)
	{
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->GetNext())
			// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
		{
			if(*(p->getName()) == *val) // ���� p���� getName() �Լ��� ȣ������ �� �켱���� ���� �μ��� ���� val ���� ������
				return p; // p ���� ��ȯ�Ѵ�
		}
		return NULL; // �׷��� �ʴٸ� NULL ���� ��ȯ�Ѵ�
	}

	CCebItemNode *FindNodePrice(int val) // �μ��� ���� ���� ��ġ�ϴ� ������ ���� ����� ��ġ�� ã�� �Լ�(�� �Լ��� ��ȯ���� CCebItemNode*�̴�)
	{
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->GetNext())
			// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
		{
			if(p->getPrice() == val) // ���� p���� getPrice() �Լ��� ȣ������ �� �켱���� ���� �μ��� ���� val ���� ������
				return p; // p ���� ��ȯ�Ѵ�

		}
		return NULL; // �׷��� �ʴٸ� NULL ���� ��ȯ�Ѵ�
	}

	CCebItemNode *FindNodeMethod(char* val) // �μ��� ���� ���� ��ġ�ϴ� ��¹���� ���� ����� ��ġ�� ã�� �Լ�(�� �Լ��� ��ȯ���� CCebItemNode*�̴�)
	{
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->GetNext())
			// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
		{
			if(*(p->getMethod()) == *val) // ���� p���� getMethod() �Լ��� ȣ������ �� �켱���� ���� �μ��� ���� val ���� ������
				return p; // p ���� ��ȯ�Ѵ�

		}
		return NULL; // �׷��� �ʴٸ� NULL ���� ��ȯ�Ѵ�
	}


	void PrintPriceRange(int min, int max){ // �μ��� ���� ������ �ּҰ��� �ִ밪 ���̿� �ִ� ������ ���� ��带 ����ϴ� �Լ�
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->GetNext())
			// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
		{
			if((p->getPrice() >= min) && (p->getPrice() <= max)) // getPrice �Լ��� �ҷ��� �� �ּҰ� �ִ밪 ���̿� �ִٸ� 
				p->Display(); // �� ����� �����͸� ����Ѵ�

		}
	}


	void DisplayRev(char*meg = ""){ // ��带 ������ ������ ó�� ������ �Ųٷ� ����ϴ� �Լ�(�ݺ����� ���)

		if(IsEmpty()){ // ���� ��ũ�� ����Ʈ�� ����ִٸ�
			printf("[%s ��ü �׸� �� = %2d] \n",meg,GetLength());
			printf("����Ʈ�� ����ֽ��ϴ�\n\n");
		}
		else{  // ���� ��ũ�� ����Ʈ�� ������� �ʴٸ�
			printf("[%s ��ü �׸� �� = %2d] \n",meg,GetLength());

			for(CCebItemNode *p = GetTail(); p != &m_org; p=p->GetPrev())
				// ���� ó���� ������ ������ ó�� ������ �ݺ����� ���鼭
				p->Display(); // p�� ����Ű�� ����� �����͸� ���
			printf("\n\n");
		}
	}
	void DisplayRevRecur(char*meg = ""){ // ��带 ������ ������ ó�� ������ �Ųٷ� ����ϴ� �Լ�(��ȯ���� ���)
		if(IsEmpty()){ // ���� ��ũ�� ����Ʈ�� ����ִٸ�
			printf("[%s ��ü �׸� �� = %2d] \n",meg,GetLength());
			printf("����Ʈ�� ����ֽ��ϴ�\n\n");
		}
		else{ // ���� ��ũ�� ����Ʈ�� ������� �ʴٸ�
			printf("[%s ��ü �׸� �� = %2d] \n",meg,GetLength());

			m_org.GetNext()->DisplayNodeRevRecur(); // ��� ����� ���� ���(ó�� ���)�� �ڱ� �ڽ��� �Լ��� ȣ��
			printf("\n\n");
		}
	}



	void Merge(CCebDLList &list2){ // �� ���� ��ũ�� ����Ʈ�� �����ϴ� �Լ� // this(list1) + list2 ������ ����

		if(IsEmpty()) // ���� ���� ���� ��ũ�� ����Ʈ�� ����ִٸ�(m_org�� �����ϰ� ����Ʈ ��ü�� �������)
		{

			m_org.SetNext(list2.GetHead()); // ��� ����� ���� ��ũ ���� list2�� ���� ó�� ����� ������ �����Ѵ�
			list2.GetHead()->SetPrev(&m_org); // list2�� ���� ó�� ����� ���� ��带 m_org(��� ���)�� �����Ѵ�
		}

		else // ���� ��ũ�� ����Ʈ�� ������� ���� ���
		{
			CCebItemNode* p = GetTail(); // ���� ���� ��ũ�� ����Ʈ�� ������ ��带 �ӽú��� p�� ����
			GetTail()->SetNext(list2.GetHead()); // ���� ��ũ�� ����Ʈ�� ���� ������ ����� ���� ��ũ���� list2�� ���� ó�� ��� ������ �����Ѵ�
			list2.GetHead()->SetPrev(p); // list2�� ���� ó�� ����� ���� ��带 p�� ����

		}
		cnt += list2.GetLength(); // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ list2.GetLength �Լ��� �ҷ� list2�� ������ŭ �߰����ش�

		// list1�� �ڿ� list2�� ���ܵΰ� list2�� ��������
		list2.m_org.SetNext(NULL);  // list2�� ��� ����� ���� ��ũ ��(���� ó���� ���)�� NULL���� �����Ѵ�
		list2.cnt = 0; // list2�� cnt ���� 0���� �ʱ�ȭ�Ѵ�
	}

	void HeadMerge(CCebDLList &list2){ // �� ���� ��ũ�� ����Ʈ�� �����ϴ� �Լ�(�տ��� ���� ����)
		//  list2 + this(list1)  ������ ����
		if(IsEmpty()) // ���� ���� ���� ��ũ�� ����Ʈ�� ����ִٸ�
		{
			m_org.SetNext(list2.GetHead()); // ��� ����� ���� ��ũ ���� list2�� ���� ó�� ����� ������ �����Ѵ�
			list2.GetHead()->SetPrev(&m_org); // list2�� ���� ó�� ����� ���� ��带 m_org(��� ���)�� �����Ѵ�
		}
		else // ���� ��ũ�� ����Ʈ�� ������� ���� ���
		{
			if(!list2.IsEmpty()){ // ���� list2�� ������� ������
				CCebItemNode* p = list2.GetTail(); // list2�� ���� ������ ��带 �ӽú��� p�� �����Ѵ�
				p->SetNext(this->GetHead()); // list2�� ������ ����� ���� ���� ���� ��ü�� ó�� ���� �����Ѵ�
				this->GetHead()->SetPrev(p); // ���� list1�� ó�� ����� ���� ��带 �����ϴ� ������ p(list2�� ������ ���)�� ����

				this->m_org.SetNext(list2.GetHead());  // ���� ������� ���� ���� list2�� ó�� ���� ����
				list2.GetHead()->SetPrev(&m_org); // list2�� ó�� ����� ���� ���� ������� �ּҷ� ����
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
			p = p->GetNext(); // p�� p�� ���� ��忡 �����Ѵ�
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
		int x = GetLength()-1; 

		for(i = 0,p = GetHead() ; i < GetLength()&&p!=NULL; i ++,p=p->GetNext()){
			// �ݺ����� ���鼭
			priorityArray[i] = p->getPriority(); // �迭�� ��ü�� �켱���� ���� �����Ѵ�

		} 

		for(i=0;i < x ;i++) // �ݺ����� ���鼭 �迭�� ���� ���� �����Ѵ�
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


		for(int i = 0 ; i < x ; i++) { // �迭�� �ε��� 0~�迭�� ũ�� -1���� �ݺ����� ���鼭 

			CCebItemNode* t = FindNodePriority(priorityArray[i+1]); // �ڿ� ���� ��� Ž���� �ӽú��� t�� ����
			CCebItemNode* tmp; // CCebItemNode* �� �ӽú��� ����
			tmp = this->ThisRemove(t); // �ӽú����� ���� ��ü�� ThisRemove �Լ��� ȣ���Ͽ� �μ��� ���� t�� ���� �����ϰ�, ������ ���� ��ȯ�� �ӽú��� tmp�� ����

			CCebItemNode* n = FindNodePriority(priorityArray[i]); // i��°�� �ִ� �켱���� ���� ������ ��带 Ž����
			n->AddNext(tmp); // n�� ���� ��忡 ������ �� ��ȯ�� tmp ������ �߰����ش�
		}
		//printf("%d",GetLength());
	}	

	//void Replace(CCebItemNode* n){
	//	if(!IsEmpty()){
	//		CCebItemNode* tmp =(new CCebItemNode("���ڽð�", 7000000, 11, "������������"));
	//		
	//		n->GetPrev()->AddNext(tmp);
	//		tmp->AddNext(n->GetNext());
	//		//n->Remove();
	//	}

	//}
	void Replace(int val, CCebItemNode* n){
		if(!IsEmpty()){
			CCebItemNode* tmp = FindNodePriority(val);
			if(tmp->GetPrev()!=NULL){
				n->SetPrev(tmp->GetPrev());
				tmp->GetPrev()->SetNext(n);
			}
			if(tmp->GetNext()!=NULL){
				n->SetNext(tmp->GetNext());
				tmp->GetNext()->SetPrev(n);
			}
			delete tmp;      
		}

	}
};

