#pragma once // ���� �����Ḯ��Ʈ�� ������ �ٲ㼭 ����ϴ°ų� �׷��� ��������!!!!!!!!!!
#include "CebItemNode.h" // ���� ��ũ�� ����Ʈ���� ��带 �����ϴ� Ŭ������ ����Ǿ��ִ� ������� ����

class CCebDLList // ���� ��ũ�� ����Ʈ�� �����ϴ� Ŭ���� ����
{
	int cnt; // ���� ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ���� ����
	CCebItemNode* m_org; // ���� ��ũ�� ����Ʈ���� ��� �����͸� ����  
	// �̹� Node Ŭ�������� ����������� �� �ʱ�ȭ�߱� ������ �� ��ü�� ���� �������ʾƵ��ȴ�

public:  // ��𼭵� ������ �� �ֵ��� public ���� ����
	CCebDLList(void) : m_org(NULL){cnt = 0;} // ������, CCebItemNode�� ��ü m_org�� NULL���� �ʱ�ȭ����Ʈ�� ���� �ʱ�ȭ ���ְ�, �׸� ���� ������ �����ϴ� ������ 0���� �ʱ�ȭ
	~CCebDLList(void){Clear();} // �Ҹ���, Clear �Լ��� ȣ���Ѵ�
	//CCebItemNode* GetHead() {return m_org;} // CCebItemNode ��ü(m_org)�� ���� ó���� ��带 ��ȯ�ϴ� �Լ�
	// �� �Լ��� m_org ��ü�� ���� ù��° ����̹Ƿ� �� �Լ��� �ʿ����

	bool IsEmpty(){return m_org == NULL; } 
	// ���� ��ũ�� ����Ʈ�� ����ִ��� Ȯ���ϴ� �Լ�(���� m_org�� NULL�̸� ��ũ�� ����Ʈ�� �������)
	int GetLength(){return cnt;}
	// ���� ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ���� cnt�� ��ȯ�ϴ� �Լ�

	CCebItemNode* GetTail(){ // ���� ��ũ�� ����Ʈ���� ���� ������ ��带 ��ȯ�ϴ� �Լ�
		CCebItemNode* tail = m_org; // CCebItemNode* ��ü�� �ϳ� ������ �� �� ������ ���� ó���� ����� �ּҸ� �������ش�
		for(; tail->GetNext() != NULL ; tail = tail->GetNext()); // �ݺ����� ���鼭 tail�� ��ũ ���� ���� ��ũ ������ ����ؼ� �������ְ�, ���� tail�� ��ũ���� NULL�̸� tail�� ������ ����� �ǹ��̴�
		// �ݺ����� tail�� ��ũ���� NULL�� �ƴ� �������� �ݺ����� ����, NULL�̶�� �ݺ����� ���´�(tail�� ������ ��带 ����Ŵ)
		return tail; // ������ ��带 ����Ű�� tail�� ��ȯ��
	}

	void Display(char*meg = ""){ // ��ũ�� ����Ʈ�� �׸��� ����ϴ� �Լ�
		if(IsEmpty()){ // ���� ���� ��ũ�� ����Ʈ�� ����ִٸ�
			printf("[%s ��ü �׸� �� = %2d] \n",meg,GetLength());
			printf("����Ʈ�� ����ֽ��ϴ�\n\n");
		}else{  // ���� ���� ��ũ�� ����Ʈ�� ������� �ʴٸ�
			printf("[%s ��ü �׸� �� = %2d] \n",meg,GetLength());

			for(CCebItemNode *p =m_org; p != NULL ; p=p->GetNext())
			{	// ���� ó���� ��� �����ͺ��� ������ ������ �ݺ����� ���鼭
				p->Display(); // p�� ����Ű�� ����� �����͸� ���
				//printf("s %d\n",p);	
			}
			printf("\n\n");
		}
	}

	void AddHead(CCebItemNode* n){ // ���� ��ũ�� ����Ʈ���� ���� �տ� ��带 �߰��ϴ� �Լ�
		if(IsEmpty()) // ���� ��ũ�� ����Ʈ�� ����ִ� ���
		{
			m_org = n; // ��� �������� ���� �μ��� ���� n���� ����
			// ��� �����Ͱ� �ᱹ ������ �ִ� ���� ���� ó���� ����̹Ƿ�

		}

		else // ���� ��ũ�� ����Ʈ�� ������� ���� ���
		{	
			n->SetNext(m_org); // �μ��� ���� n�� ��� ���� ��忡 m_org�� �߰�
			m_org->SetPrev(n); // m_org�� ���� ��带 n���� ����
			m_org = n; // m_org�� n���� ����
		}
		cnt ++; // ���� ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ������Ų��
	}

	void AddTail(CCebItemNode* n){ // ���� ��ũ�� ����Ʈ���� ���� �ڿ� ��带 �߰��ϴ� �Լ�
		if(IsEmpty())  // ���� ��ũ�� ����Ʈ�� ����ִ� ���
		{
			m_org = n; // ��� �������� ���� �μ��� ���� n���� ����
			// ��� �����Ͱ� �ᱹ ������ �ִ� ���� ���� ó���� ����̹Ƿ�

		}

		else // ���� ��ũ�� ����Ʈ�� ������� ���� ���
		{

			GetTail()->AddNext(n); // �μ��� ���� ��� ���� ���� ������ ��忡 AddNext �Լ��� ȣ���Ͽ� �߰��Ѵ�

		}
		cnt ++; // ���� ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ������Ų�� 
	}


	void AddNext(CCebItemNode *p, CCebItemNode *n){ // ��ũ�� ����Ʈ���� �μ��� ���� p �� �ڿ� ��� n�� �߰��Ѵ�
		if(IsEmpty())  // ��ũ�� ����Ʈ�� ����ִ� ���
		{
			m_org = n; // m_org�� AddNext �Լ��� ȣ���Ͽ� �μ��� ���� n�� ���� �߰��Ѵ�
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
			CCebItemNode* t = m_org; // CCebItemNode* �� �ӽ� ���� t�� ������ �ڿ� �� ���� ��� ������ ���� �����Ѵ�
			m_org = t->GetNext(); // �� ��° ��带 ù ��° ���� ����(ù��° ��尡 ������)
			if(m_org != NULL) // ���� m_org(���������)�� NULL�� �ƴ϶��
				m_org->SetPrev(NULL); // m_org�� ���� ���� NULL�� ���� 
			delete t; // �ӽú����� ����� t�� ������ ������ delete �� ���� ������Ų��
		}
		cnt--; // ���� ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ���ҽ�Ų��
	}

	void RemoveTail(){ // ���� ��ũ�� ����Ʈ���� ���� ���� ��带 �����ϴ� �Լ�
		if(!IsEmpty()){ // ��ũ�� ����Ʈ�� ������� ���� ���
			CCebItemNode* t = GetTail(); // CCebItemNode* �� �ӽ� ���� t�� ������ �ڿ� �� ���� ���� ������ ����� ���� �����Ѵ�
			if(t->GetPrev()!=NULL) // ���� ���� ������ ����� ���� ���� NULL�� �ƴ϶��
				t->GetPrev()->SetNext(NULL); // ���� ������ ����� ���� ���� ���� ���� NULL�� ����(������ ��尡 ������)
			delete t; // �ӽú����� ����� t�� ������ ������ delete �� ���� ������Ų��
		}
		cnt--; // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ���ҽ�Ų��

	}
	void Remove(CCebItemNode *n){ // ���� ��ũ�� ����Ʈ���� ��带 �����ϴ� �Լ�
		if(IsEmpty()) return; // ���� ���� ��ũ�� ����Ʈ�� ����ִٸ� ��带 ������ �� �����Ƿ� return�� ���� �Լ� ����
		if(n == m_org){ // ���� �μ��� ���� n�� ���� ó���� �����  
			this->RemoveHead();  // RemoveHead �Լ��� ȣ���Ͽ� ó�� ��带 �����Ѵ�
		}
		else{ // ���� �μ��� ���� n�� ���� ó���� ��尡 �ƴ϶��
			for(CCebItemNode *p = m_org; p != NULL ; p=p->GetNext())
				// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
			{
				if(p->GetNext() == n)
				{ // ���� p ����� ���� ��尡 �μ��� ���� n�� �������ٸ�
					p->SetNext(n->GetNext()); // p�� ���� ���� �μ��� ���� n�� ��ũ������ ����(�߰��� �ִ� n ��尡 ������)

					if(n->GetNext() != NULL) // ���� �����Ϸ��� �ϴ� ����� ���� ��尡 NULL�� �ƴϸ�
						n->GetNext()->SetPrev(p); // ���� ����� ���� ����� ��ġ�� p�� ����
					delete n; // n�� delete �� ���� ������Ų��
					cnt--; // ���� ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ���ҽ�Ų��
				}
			}
		}
	} 

	// PriorityArrange() �Լ��� �����ϱ� ���� �Լ�����
	// �� �Լ��� ������ ���� ��ȯ�ϴ� �Լ��̴�
	// ���� Remove�� �ٸ� ���� �� �Լ��� ������ ���� ��ȯ������ �ʴ´�
	CCebItemNode* ThisRemove(CCebItemNode *n){ // ��ũ�� ����Ʈ���� ��带 �����ϴ� �Լ�
		if(IsEmpty()) return NULL; // ���� ��ũ�� ����Ʈ�� ����ִٸ� ��带 ������ �� �����Ƿ� return�� ���� �Լ� ����
		if(n == m_org){ // ���� �μ��� ���� n�� ���� ó���� �����  
			//	CCebItemNode* t = m_org.GetNext(); // CCebItemNode* �� �ӽ� ���� t�� ������ �ڿ� �� ���� ��� ����� ��ũ��(������� ���� ��带 �����ϴ� �ּ�)�� �����Ѵ�
			m_org = n->GetNext(); // ���� ó���� ��带 �����ϴ� ��� �����͸� �μ��� ���� n�� ���� ���� ����

			if(m_org != NULL) // ���� m_org�� NULL�� �ƴϸ�
				m_org->SetPrev(NULL); // m_org�� ���� ���� NULL�� ����
			//cnt--;// ���� ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ���ҽ�Ų��
			return n; // ������ ���� ��ȯ�Ѵ�
		}
		else{ // ���� �μ��� ���� n�� ���� ó���� ��尡 �ƴ϶��
			for(CCebItemNode *p = m_org; p != NULL ; p=p->GetNext())
				// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
			{
				if(p->GetNext() == n)
				{ // ���� p ����� ���� ��尡 �μ��� ���� n�� �������ٸ�
					p->SetNext(n->GetNext()); // p�� ��ũ���� �μ��� ���� n�� ���� ������ ����(�߰��� �ִ� n ��尡 ������)

					if(n->GetNext() != NULL) // ���� �����Ϸ��� �ϴ� ����� ���� ��尡 NULL�� �ƴϸ�
						n->GetNext()->SetPrev(p); // �� ����� ���� ��带 �����ϴ� ������ p�� �����Ѵ�
					return n; // ������ �� ���� ��ȯ�Ѵ�
					//cnt--; // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ �ϳ� ���ҽ�Ų��

				}
			}
		}

	} 
	void Clear(){ // ���� ��ũ�� ����Ʈ�� ��� �׸��� �����ϴ� �Լ�
		//CCebItemNode* t; // CCebItemNode* �� �ӽ� ���� t�� ���� 
		//t = m_org;  // �ӽú��� t�� ���� ó���� ��带 �����Ѵ�

		//if(m_org!=NULL){ // ���� ���� ó���� ����� ��ũ ���� NULL�� �ƴϸ�
		//	for(CCebItemNode *p = m_org; p != NULL ; p=p->GetNext())
		//		// ���� ó���� ����� ���� ������ ������ ������ �ݺ����� ���鼭
		//	{
		//		delete t; // �ӽú��� t�� delete�� ���ؼ� �����Ѵ�
		//		t = p; // �ӽú��� t�� p�� ���� �����Ѵ�
		//	}
		//	delete t; // ������ �������� ���� ���� delete�� ���ؼ� �����Ѵ�
		//	m_org = NULL; // ��� ����� ��ũ ���� NULL�� ����
		//	cnt = 0; // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ 0���� ����
		//}

		while(m_org != NULL){ // ó�� ��尡 NULL�� �ƴ� ������
			this->RemoveHead(); // ���� ��忡�� RemoveHead �Լ��� ȣ���Ͽ� ���� ó���� ��� ����
		}



	}

	CCebItemNode *FindPrev(CCebItemNode *n){ // �μ��� ���� ���� ���� ��ġ�� ã�� �Լ�(�� �Լ��� ��ȯ���� CCebItemNode*�̴�)
		for(CCebItemNode *p = m_org; p != NULL ; p=p->GetNext())
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
		for(CCebItemNode *p = m_org; p != NULL ; p=p->GetNext())
			// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
		{
			if(p->getPriority() == val) // ���� p���� getPriority() �Լ��� ȣ������ �� �켱���� ���� �μ��� ���� val ���� ������
				return p; // p ���� ��ȯ�Ѵ�

		}
		return NULL; // �׷��� �ʴٸ� NULL ���� ��ȯ�Ѵ�
	}

	CCebItemNode *FindNodeName(char* val) // �μ��� ���� ���� ��ġ�ϴ� �̸��� ���� ����� ��ġ�� ã�� �Լ�(�� �Լ��� ��ȯ���� CCebItemNode*�̴�)
	{
		for(CCebItemNode *p = m_org; p != NULL ; p=p->GetNext())
			// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
		{
			if(*(p->getName()) == *val) // ���� p���� getName() �Լ��� ȣ������ �� �̸��� �μ��� ���� val ���� ������
				return p; // p ���� ��ȯ�Ѵ�
		}
		return NULL; // �׷��� �ʴٸ� NULL ���� ��ȯ�Ѵ�
	}

	CCebItemNode *FindNodePrice(int val) // �μ��� ���� ���� ��ġ�ϴ� ������ ���� ����� ��ġ�� ã�� �Լ�(�� �Լ��� ��ȯ���� CCebItemNode*�̴�)
	{
		for(CCebItemNode *p = m_org; p != NULL ; p=p->GetNext())
			// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
		{
			if(p->getPrice() == val) // ���� p���� getPrice() �Լ��� ȣ������ �� �켱���� ���� �μ��� ���� val ���� ������
				return p; // p ���� ��ȯ�Ѵ�

		}
		return NULL; // �׷��� �ʴٸ� NULL ���� ��ȯ�Ѵ�
	}

	CCebItemNode *FindNodeMethod(char* val) // �μ��� ���� ���� ��ġ�ϴ� ��¹���� ���� ����� ��ġ�� ã�� �Լ�(�� �Լ��� ��ȯ���� CCebItemNode*�̴�)
	{
		for(CCebItemNode *p = m_org; p != NULL ; p=p->GetNext())
			// ���� ó���� ������ ������ ������ �ݺ����� ���鼭
		{
			if(*(p->getMethod()) == *val) // ���� p���� getMethod() �Լ��� ȣ������ �� �켱���� ���� �μ��� ���� val ���� ������
				return p; // p ���� ��ȯ�Ѵ�

		}
		return NULL; // �׷��� �ʴٸ� NULL ���� ��ȯ�Ѵ�
	}


	void PrintPriceRange(int min, int max){ // �μ��� ���� ������ �ּҰ��� �ִ밪 ���̿� �ִ� ������ ���� ��带 ����ϴ� �Լ�
		for(CCebItemNode *p = m_org; p != NULL ; p=p->GetNext())
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

			for(CCebItemNode *p = GetTail(); p != NULL; p=p->GetPrev())
				// ���� ó���� ������ ������ NULL�� �ƴ� ������ �ݺ����� ���鼭
				p->Display(); // p�� ����Ű�� ����� �����͸� ���
			printf("\n\n");
		}
	}
	void DisplayRevRecur(char*meg = ""){ // ��带 ������ ������ ó�� ������ �Ųٷ� ����ϴ� �Լ�(��ȯ���� ���)
		if(IsEmpty()){ // ���� ��ũ�� ����Ʈ�� ����ִٸ�
			printf("[%s ��ü �׸� �� = %2d] \n",meg,GetLength());
			printf("����Ʈ�� ����ֽ��ϴ�\n\n");
		}
		else{  // ���� ��ũ�� ����Ʈ�� ������� �ʴٸ�

			printf("[%s ��ü �׸� �� = %2d] \n",meg,GetLength());

			m_org->DisplayNodeRevRecur();
			// ��� �����Ͱ� �ڱ� �ڽ��� �Լ��� ȣ��
			printf("\n\n");
		}
	}



	void Merge(CCebDLList &list2){ // �� ���� ��ũ�� ����Ʈ�� �����ϴ� �Լ� // this(list1) + list2 ������ ����

		if(IsEmpty()) // ���� ���� ���� ��ũ�� ����Ʈ�� ����ִٸ�(m_org�� �����ϰ� ����Ʈ ��ü�� �������)
		{
			m_org = list2.m_org; // ��� ����� ���� ��ũ ���� list2�� ���� ó�� ����� ������ �����Ѵ�

		}

		else // ���� ��ũ�� ����Ʈ�� ������� ���� ���
		{
			CCebItemNode* p = GetTail();  // ���� ���� ��ũ�� ����Ʈ�� ������ ��带 �ӽú��� p�� ����
			GetTail()->SetNext(list2.m_org); // ���� ��ũ�� ����Ʈ�� ���� ������ ����� ���� ��ũ���� list2�� ���� ó�� ��� ������ �����Ѵ�
			list2.m_org->SetPrev(p); // list2�� ���� ó�� ����� ���� ��带 p�� ����

		}
		cnt += list2.GetLength(); // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ list2.GetLength �Լ��� �ҷ� list2�� ������ŭ �߰����ش�

		// list1�� �ڿ� list2�� ���ܵΰ� list2�� ��������
		list2.m_org = NULL;  // list2�� ������� ���� ��ũ ��(���� ó���� ���)�� NULL���� �����Ѵ�
		list2.cnt = 0; // list2�� cnt ���� 0���� �ʱ�ȭ�Ѵ�
	}

	void HeadMerge(CCebDLList &list2){ // �� ���� ��ũ�� ����Ʈ�� �����ϴ� �Լ�(�տ��� ���� ����)
		//  list2 + this(list1)  ������ ����
		if(IsEmpty()) // ���� ���� ��ũ�� ����Ʈ�� ����ִٸ�
		{
			m_org = list2.m_org; // ��� �������� ���� ���� list2�� ó�� ���� �����Ѵ�  
		}
		else // ���� ��ũ�� ����Ʈ�� ������� ���� ���
		{
			if(!list2.IsEmpty()){ // ���� list2�� ������� ������
				CCebItemNode* p = list2.GetTail();// list2�� ���� ������ ��带 �ӽú��� p�� �����Ѵ�

				p->SetNext(this->m_org); // list2�� ������ ����� ��ũ���� ���� ��ü�� ó�� ���� �����Ѵ�
				this->m_org->SetPrev(p); // list1�� ��� ������ ���� ���� ��带 p�� ������ �����Ѵ�

				this->m_org = list2.m_org;  // ��������� ���� list2�� ó�� ��� �����ͷ� ����
			}
		}
		cnt += list2.GetLength(); // ��ũ�� ����Ʈ���� �׸� ���� ������ �����ϴ� ������ list2.GetLength �Լ��� �ҷ� list2�� ������ŭ �߰����ش�

		list2.m_org = NULL; // list2�� ��� �������� ���� ��ũ ��(���� ó���� ���)�� NULL���� �����Ѵ�  
		list2.cnt = 0; // list2�� cnt ���� 0���� �ʱ�ȭ�Ѵ�
	}
	//void  Reverse(){ // ��ũ�� ����Ʈ�� �������� ����� �Լ�
	//	CCebItemNode *p,*q, *r; // CCebItemNode* �� �ӽú��� p,q(���� ����� ��ġ),r(���� ����� ��ġ)�� �����Ѵ�
	//	p = GetHead(); // p�� ���� ó���� ��带 ������
	//	q = NULL; // q�� NULL�� ������

	//	while(p != NULL){ // p�� NULL�� �ƴ� ������ �ݺ����� ���鼭
	//		r = q; // r�� q�� ���� �����ϰ�
	//		q = p; // q�� p�� ���� �����ϰ�
	//		p = p->GetNext(); // p�� p�� ���� ��忡 �����Ѵ�
	//		q->SetNext(r); // q�� ��ũ ���� r�� �������ش�
	//	}
	//	m_org.SetNext(q);  // ��� ����� ��ũ ���� q�� �������ش�
	//}
	void Reverse(){ // ���� ��ũ�� ����Ʈ�� �������� ����� �Լ�
		CCebItemNode *p,*q, *r; // CCebItemNode* �� �ӽú��� p,q(���� ����� ��ġ),r(���� ����� ��ġ)�� �����Ѵ�
		p = m_org; // p�� ���� ó���� ��带 ������
		q = NULL; // q�� NULL�� ������

		while(p != NULL){ // p�� NULL�� �ƴ� ������ �ݺ����� ���鼭
			r = q; // r�� q�� ���� �����ϰ�
			q = p; // q�� p�� ���� �����ϰ�
			p = p->GetNext(); // p�� p�� ���� ��忡 �����Ѵ�
			q->SetNext(r); // q�� ��ũ ���� r�� �������ش�
		}
		// m_org->SetNext(q); 
		m_org = q; // ��� �����͸� q�� �������ش�
	}

	void PriorityArrange(){ // �켱���� ������� �����ϴ� �Լ�
		int* priorityArray = new int[GetLength()]; // ��ũ�� ����Ʈ�� �켱 ���� ���� �޾ƿ��� �迭
		int i,j; // �ݺ����� �������� ����
		int min; // ���� ���� ���� ����
		int index; // ���� ���� ���� �ε����� ����
		int temp; // �ӽú���
		CCebItemNode *p; // �ݺ����� ���� ���� �ӽú���


		for(i = 0,p = m_org; i < GetLength()&&p!=NULL; i ++,p=p->GetNext()){
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

			CCebItemNode* t = FindNodePriority(priorityArray[i+1]); // �ڿ� ���� ��� Ž���� �ӽú��� t�� ����
			//	CCebItemNode* t1 = FindPrev(t); // �ڿ� ���� ����� �� ��带 ã�� �ӽú��� t1�� ����
			CCebItemNode* tmp;
			tmp = this->ThisRemove(t);

			CCebItemNode* n = FindNodePriority(priorityArray[i]); // i��°�� �ִ� �켱���� ���� ������ ��带 Ž����
			n->AddNext(tmp);   // n�� ���� ��忡 t ������ �߰����ش�
		}

	}	

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

