#pragma once
#include "CebItemNode.h" // 링크드 리스트에서 노드를 지정하는 클래스가 선언되어있는 헤더파일 선언

class CCebLinkedList // 링크드 리스트를 구현하는 클래스 선언
{
	int cnt; // 링크드 리스트에서 항목 값의 개수를 저장하는 변수 선언
	CCebItemNode m_org; // 링크드 리스트에서 헤드 노드를 선언  

public:  // 어디서든 접근할 수 있도록 public 으로 지정
	CCebLinkedList(void) : m_org(""){cnt = 0;} // 생성자, CCebItemNode의 객체 m_org를 ""으로 초기화리스트를 통해 초기화 해주고, 항목 값의 개수를 저장하는 변수를 0으로 초기화
	~CCebLinkedList(void){Clear();} // 소멸자, Clear 함수를 호출한다
	CCebItemNode* GetHead() {return m_org.Next();} // CCebItemNode 객체(m_org)의 가장 처음의 노드를 반환하는 함수

	bool IsEmpty(){return GetHead() == NULL; } 
	// 링크드 리스트를 비어있는지 확인하는 함수(만약 GetHead 함수(링크값)이 NULL이면 링크드 리스트가 비어있음)
	int GetLength(){return cnt;}
	// 링크드 리스트에서 항목 값의 개수를 저장하는 변수 cnt를 반환하는 함수

	CCebItemNode* GetTail(){ // 링크드 리스트에서 가장 마지막 노드를 반환하는 함수
		CCebItemNode* tail = &m_org; // CCebItemNode* 객체를 하나 선언한 뒤 그 값에는 가장 처음의 노드의 주소를 저장해준다
		for(; tail->Next() != NULL ; tail = tail->Next()); // 반복문을 돌면서 tail의 링크 값을 다음 링크 값으로 계속해서 대입해주고, 만약 tail의 링크값이 NULL이면 tail이 마지막 노드라는 의미이다
		// 반복문을 tail의 링크값이 NULL이 아닐 때까지만 반복문을 돌고, NULL이라면 반복문을 나온다(tail이 마지막 노드를 가리킴)
		return tail; // 마지막 노드를 가리키는 tail을 반환함
	}

	void Display(char*meg = ""){ //링크드 리스트의 항목값을 출력하는 함수
		if(IsEmpty()){ // 만약 링크드 리스트가 비어있다면
			printf("[%s 전체 항목 수 = %2d] \n",meg,GetLength());
			printf("리스트가 비어있습니다\n\n");
		}
		else{  // 만약 링크드 리스트가 비어있지 않다면
			printf("[%s 전체 항목 수 = %2d] \n",meg,GetLength());

			for(CCebItemNode *p = GetHead(); p != NULL ; p=p->Next())
				// 가장 처음의 헤드노드부터 마지막 노드까지 반복문을 돌면서
				p->Display(); // p가 가리키는 노드의 데이터를 출력
			printf("\n\n");
		}
	}

	void AddHead(CCebItemNode* n){ // 링크드 리스트에서 가장 앞에 노드를 추가하는 함수
		if(IsEmpty()) // 링크드 리스트가 비어있는 경우
		{
			m_org.AddNext(n); // m_org의 AddNext 함수를 호출하여 인수로 들어온 n의 값을 추가한다
		}

		else // 링크드 리스트가 비어있지 않은 경우
		{
			//n->SetNext(m_org.Next()); // 인수로 들어온 n의 SetNext 함수를 호출하여 n의 링크 값을 헤드 노드의 링크 값에 설정해준다
			//m_org.SetNext(n); // m_org의 AddNext 함수를 호출하여 인수로 들어온 n의 값을 추가한다
			m_org.AddNext(n); // 인수로 들어온 노드 값을 헤드 노드 뒤에 AddNext 함수를 호출하여 추가한다
		}
		cnt ++; // 링크드 리스트에서 항목 값의 개수를 저장하는 변수를 하나 증가시킨다
	}

	void AddTail(CCebItemNode* n){ // 링크드 리스트에서 가장 뒤에 노드를 추가하는 함수
		if(IsEmpty())  // 링크드 리스트가 비어있는 경우
		{
			m_org.AddNext(n); // m_org의 AddNext 함수를 호출하여 인수로 들어온 n의 값을 추가한다
		}

		else // 링크드 리스트가 비어있지 않은 경우
		{
			//n->AddNext(GetTail()->Next());
			GetTail()->AddNext(n); // 인수로 들어온 노드 값을 가장 마지막 노드에 AddNext 함수를 호출하여 추가한다
		}
		cnt ++; // 링크드 리스트에서 항목 값의 개수를 저장하는 변수를 하나 증가시킨다 
	}

	void AddNext(CCebItemNode *p, CCebItemNode *n){ // 링크드 리스트에서 인수로 들어온 p 값 뒤에 노드 n을 추가한다
		if(IsEmpty())  // 링크드 리스트가 비어있는 경우
		{
			m_org.AddNext(n); // m_org의 AddNext 함수를 호출하여 인수로 들어온 n의 값을 추가한다
		}

		else
		{
			n->SetNext(p->Next()); // 추가할 노드 n에 링크 값에 p의 다음 노드의 주소를 설정한다
			p->AddNext(n); // 인수로 들어온 p의 다음 노드를 n으로 추가한다
		}
		cnt ++; // 링크드 리스트에서 항목 값의 개수를 저장하는 변수를 하나 증가시킨다
	}

	void RemoveHead(){ // 링크드 리스트에서 가장 앞에 노드를 삭제하는 함수
		if(!IsEmpty()){ // 링크드 리스트가 비어있지 않은 경우
			CCebItemNode* t = m_org.Next(); // CCebItemNode* 형 임시 변수 t를 선언한 뒤에 그 값에 헤드 노드의 링크값(헤드노드의 다음 노드를 저장하는 주소)을 저장한다
			m_org.SetNext(t->Next()); // 두 번째 노드를 첫 번째 노드로 만듦(첫번째 노드가 삭제됨)
			delete t; // 임시변수에 저장된 t가 삭제된 것으로 delete 를 통해 삭제시킨다
		}
		cnt--; // 링크드 리스트에서 항목 값의 개수를 저장하는 변수를 하나 감소시킨다
	}
	void Remove(CCebItemNode *n){ // 링크드 리스트에서 노드를 삭제하는 함수
		if(IsEmpty()) return; // 만약 링크드 리스트가 비어있다면 노드를 삭제할 수 없으므로 return을 통해 함수 종료
		if(n == GetHead()){ // 만약 인수로 받은 n이 가장 처음의 노드라면  
			m_org.SetNext(n->Next()); // 두 번째 노드를 첫 번째 노드로 만듦(첫번째 노드가 삭제됨)
			delete n; // 임시변수에 저장된 t가 삭제된 것으로 delete 를 통해 삭제시킨다
			cnt--; // 링크드 리스트에서 항목 값의 개수를 저장하는 변수를 하나 감소시킨다
		}
		else{ // 만약 인수로 받은 n이 가장 처음의 노드가 아니라면
			for(CCebItemNode *p = GetHead(); p != NULL ; p=p->Next())
				// 가장 처음의 노드부터 마지막 노드까지 반복문을 돌면서
			{
				if(p->Next() == n)
				{ // 만약 p 노드의 다음 노드가 인수로 받은 n과 같아진다면
					p->SetNext(n->Next()); // p의 링크값을 인수로 받은 n의 링크값으로 설정(중간에 있는 n 노드가 삭제됨)
					delete n; // n을 delete 를 통해 삭제시킨다
					cnt--; // 링크드 리스트에서 항목 값의 개수를 저장하는 변수를 하나 감소시킨다
				}
			}
		}
	} 
	void Clear(){ // 링크드 리스트의 모든 항목을 삭제하는 함수
		CCebItemNode* t; // CCebItemNode* 형 임시 변수 t를 선언 
		t = GetHead();  // 임시변수 t에 가장 처음의 노드를 저장한다

		if(GetHead()!=NULL){ // 만약 가장 처음의 노드의 링크 값이 NULL이 아니면
			for(CCebItemNode *p = GetHead()->Next(); p != NULL ; p=p->Next())
				// 가장 처음의 노드의 다음 노드부터 마지막 노드까지 반복문을 돌면서
			{
				delete t; // 임시변수 t를 delete를 통해서 삭제한다
				t = p; // 임시변수 t에 p의 값을 저장한다
			}
			delete t; // 마지막 삭제하지 못한 값을 delete를 통해서 삭제한다
			m_org.SetNext(NULL); // 헤드 노드의 링크 값을 NULL로 설정
			cnt = 0; // 링크드 리스트에서 항목 값의 개수를 저장하는 변수를 0으로 설정
		}
	}

	CCebItemNode *FindPrev(CCebItemNode *n){ // 인수로 받은 값의 이전 위치를 찾는 함수(이 함수의 반환형은 CCebItemNode*이다)
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->Next())
			// 가장 처음의 노드부터 마지막 노드까지 반복문을 돌면서
		{
			if(p->Next() == n){ // 만약 p의 다음 노드가 n이라면
				return p; // p의 값을 반환한다
			}
		}
		return NULL; // 그렇지 않다면 NULL 값을 반환한다
	}


	CCebItemNode *FindNodePriority(int val) // 인수로 받은 값과 일치하는 우선순위를 가진 노드의 위치를 찾는 함수(이 함수의 반환형은 CCebItemNode*이다)
	{
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->Next())
			// 가장 처음의 노드부터 마지막 노드까지 반복문을 돌면서
		{
			if(p->getPriority() == val) // 만약 p에서 getPriority() 함수를 호출했을 때 우선순위 값이 인수로 받은 val 값과 같으면
				return p; // p 값을 반환한다

		}
		return NULL; // 그렇지 않다면 NULL 값을 반환한다
	}

	CCebItemNode *FindNodeName(char* val) // 인수로 받은 값과 일치하는 이름을 가진 노드의 위치를 찾는 함수(이 함수의 반환형은 CCebItemNode*이다)
	{
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->Next())
			// 가장 처음의 노드부터 마지막 노드까지 반복문을 돌면서
		{
			if(*(p->getName()) == *val) // 만약 p에서 getName() 함수를 호출했을 때 우선순위 값이 인수로 받은 val 값과 같으면
				return p; // p 값을 반환한다

		}
		return NULL; // 그렇지 않다면 NULL 값을 반환한다
	}

	CCebItemNode *FindNodePrice(int val) // 인수로 받은 값과 일치하는 가격을 가진 노드의 위치를 찾는 함수(이 함수의 반환형은 CCebItemNode*이다)
	{
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->Next())
			// 가장 처음의 노드부터 마지막 노드까지 반복문을 돌면서
		{
			if(p->getPrice() == val) // 만약 p에서 getPrice() 함수를 호출했을 때 우선순위 값이 인수로 받은 val 값과 같으면
				return p; // p 값을 반환한다

		}
		return NULL; // 그렇지 않다면 NULL 값을 반환한다
	}

	CCebItemNode *FindNodeMethod(char* val) // 인수로 받은 값과 일치하는 사는방법을 가진 노드의 위치를 찾는 함수(이 함수의 반환형은 CCebItemNode*이다)
	{
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->Next())
			// 가장 처음의 노드부터 마지막 노드까지 반복문을 돌면서
		{
			if(*(p->getMethod()) == *val) // 만약 p에서 getMethod() 함수를 호출했을 때 우선순위 값이 인수로 받은 val 값과 같으면
				return p; // p 값을 반환한다

		}
		return NULL; // 그렇지 않다면 NULL 값을 반환한다
	}

	void PrintPriceRange(int min, int max){ // 인수로 받은 가격의 최소값과 최대값 사이에 있는 가격을 가진 노드를 출력하는 함수
		for(CCebItemNode *p = GetHead(); p != NULL ; p=p->Next())
			// 가장 처음의 노드부터 마지막 노드까지 반복문을 돌면서
		{
			if((p->getPrice() >= min) && (p->getPrice() <= max)) // getPrice 함수를 불렀을 때 최소값 최대값 사이에 있다면 
				p->Display(); // 그 노드의 데이터를 출력한다

		}
	}

	void Merge(CCebLinkedList &list2){ // 두 개의 링크드 리스트를 병합하는 함수

		if(IsEmpty()) // 만약 현재 링크드 리스트가 비어있다면
		{
			m_org.SetNext(list2.GetHead()); // 헤드 노드의 다음 링크 값을 list2의 가장 처음 노드의 값으로 설정한다
		}

		else // 링크드 리스트가 비어있지 않은 경우
		{
			GetTail()->SetNext(list2.GetHead()); // 현재 링크드 리스트의 가장 마지막 노드의 다음 링크값을 list2의 가장 처음 노드 값으로 설정한다

		}
		cnt += list2.GetLength(); // 링크드 리스트에서 항목 값의 개수를 저장하는 변수에 list2.GetLength 함수를 불러 list2의 갯수만큼 추가해준다

		// list1의 뒤에 list2를 남겨두고 list2를 날려버림
		list2.m_org.SetNext(NULL);  // list2의 헤드노드의 다음 링크 값(가장 처음의 노드)을 NULL으로 설정한다
		list2.cnt = 0; // list2의 cnt 값을 0으로 초기화한다
	}


	void HeadMerge(CCebLinkedList &list2){ // 두 개의 링크드 리스트를 병합하는 함수(앞에서 부터 병합)

		if(IsEmpty()) // 만약 현재 링크드 리스트가 비어있다면
		{
			m_org.SetNext(list2.GetHead()); // 헤드 노드의 다음 값을 list2의 처음 노드로 설정한다  

		}
		else // 링크드 리스트가 비어있지 않은 경우
		{
			if(!list2.IsEmpty()){ // 만약 list2가 비어있지 않으면
				list2.GetTail()->SetNext(this->GetHead()); // list2의 마지막 노드의 링크값을 현재 객체의 처음 노드로 설정한다
				this->m_org.SetNext(list2.GetHead());  // 헤드노드의 링크값을 list2의 처음 노드 값으로 설정
			}
		}
		cnt += list2.GetLength(); // 링크드 리스트에서 항목 값의 개수를 저장하는 변수에 list2.GetLength 함수를 불러 list2의 갯수만큼 추가해준다

		list2.m_org.SetNext(NULL); // list2의 헤드노드의 다음 링크 값(가장 처음의 노드)을 NULL으로 설정한다  
		list2.cnt = 0; // list2의 cnt 값을 0으로 초기화한다
	}

	void  Reverse(){ // 링크드 리스트를 역순으로 만드는 함수
		CCebItemNode *p,*q, *r; // CCebItemNode* 형 임시변수 p,q(현재 노드의 위치),r(이전 노드의 위치)을 선언한다
		p = GetHead(); // p에 가장 처음의 노드를 저장함
		q = NULL; // q에 NULL을 저장함

		while(p != NULL){ // p가 NULL이 아닐 때까지 반복문을 돌면서
			r = q; // r은 q의 값을 대입하고
			q = p; // q는 p의 값을 대입하고
			p = p->Next(); // p는 p의 다음 노드에 접근한다
			q->SetNext(r); // q의 링크 값을 r로 설정해준다
		}
		m_org.SetNext(q);  // 헤드 노드의 링크 값을 q로 설정해준다
	}


	void PriorityArrange(){ // 우선순위 순서대로 정렬하는 함수
		int* priorityArray = new int[GetLength()]; // 링크드 리스트의 우선 순위 값을 받아오는 배열
		int i,j; // 반복문을 돌기위한 변수
		int min; // 가장 작은 값을 저장
		int index; // 가장 작은 값의 인덱스를 저장
		int temp; // 임시변수
		CCebItemNode *p; // 반복문을 돌기 위한 임시변수


		for(i = 0,p = GetHead() ; i < GetLength()&&p!=NULL; i ++,p=p->Next()){
			// 반복문을 돌면서
			priorityArray[i] = p->getPriority(); // 배열에 객체의 우선순위 값을 대입한다

		} 

		for(i=0;i<GetLength()-1;i++) // 반복문을 돌면서 배열의 원소 값을 정렬한다
		{
			min = priorityArray[i]; // 가장 작은 값이 priorityArray 배열에 i 인덱스에 있는 값이라고 가정
			index = i; // 가장 작은 값이라고 가정한 i의 인덱스 저장

			for(j=i+1;j<GetLength();j++){ // min이라고 가정해준 배열의 원소값 다음부터 배열 끝까지 반복하면서
				if(min >priorityArray[j]){ // 만약 더 작은 값이 나오면
					min = priorityArray[j]; // 그 값을 min으로 설정하고
					index  =j; // min으로 설정한 인덱스 값을 index에 저장
				}
			}

			// 두 값을 swap 시키는 부분
			temp=priorityArray[i]; 
			priorityArray[i]=priorityArray[index];
			priorityArray[index]=temp;

		}

		int x = GetLength()-1;
		for(int i = 0 ; i < x ; i++) { // 반복문을 돌면서 

			CCebItemNode *t = FindNodePriority(priorityArray[i+1]); // 뒤에 붙일 노드 탐색해 임시변수 t에 저장
			CCebItemNode *t1 = FindPrev(t); // 뒤에 붙일 노드의 앞 노드를 찾아 임시변수 t1에 저장

			if(t1 != NULL) // 만약 t1이 NULL이 아니면
				t1->SetNext(t->Next());   // t1의 링크값을 t의 링크값으로 설정(연결해줌)
			else{ // NULL이면
				this->m_org.SetNext(t->Next()) ;
				// t가 가장 처음의 노드라는 것이므로 헤드노드가 가리키는 값을 임시변수 t의 링크값으로 설정
			}

			CCebItemNode* n = FindNodePriority(priorityArray[i]); // i번째에 있는 우선순위 값을 가지는 노드를 탐색해
			n->AddNext(t);   // n의 다음 노드에 t 변수를 추가해준다
		}

	}


};

