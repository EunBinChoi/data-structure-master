#pragma once
#include<stdio.h>
#define MAX_LIST_SIZE 100 // 배열의 크기를 상수로 선언
typedef int CebElement; // int 자료형을 CebElement 으로 지정

class CCebArrayList // 배열을 이용한 리스트 클래스 구현
{
	CebElement m_data[MAX_LIST_SIZE]; // 실제 항목값들이 들어있는 배열
	int m_len; // 현재 리스트 내의 항목들의 개수

public: // 어디서든 접근할 수 있도록 public 으로 지정
	CCebArrayList(void){m_len = 0;} // 생성자, m_len을 초기화
	~CCebArrayList(void){} // 소멸자

	bool IsEmpty(){return m_len == 0;} // 리스트가 비었는가 확인하는 함수, 만약 항목의 개수를 저장하는 변수 m_len이 0이면 리스트가 비어있음
	bool IsFull(){return m_len == MAX_LIST_SIZE;} // 리스트가 꽉찼는가 확인하는 함수, 만약 항목의 개수를 저장하는 변수 m_len이 배열의 최대 크기와 같다면 리스트가 꽉 차 있다는 것임
	CebElement GetEntry(int pos){return m_data[pos];}
	// 인수로 받은 인덱스의 값의 요소를 반환하는 함수

	int GetLength(){return m_len;} // 리스트의 길이를 반환하는 함수, 현재 리스트 내의 항목들의 개수를 저장하는 변수인 m_len을 반환하면 된다
	void Clear(){m_len = 0;} // 리스트에 있는 모든 항목 값을 초기화 시키는 함수, 현재 리스트 내의 항목들의 개수를 저장하는 변수인 m_len을 0으로 초기화
	void Replace(int pos,CebElement e){m_data[pos] = e;}
	// 인수로 인덱스의 값과 항목의 값을 받아서 그 인덱스에 해당하는 배열 값을 인수로 받은 값으로 바꾼다
	
	void Display(char*meg = ""){ // 리스트에 있는 값들을 출력하는 함수
		printf("\t[%s 전체 항목 수 = %2d] : ",meg ,m_len);
		for(int i = 0 ; i < m_len ; i ++) // 반복문을 리스트의 길이만큼 돌면서
			printf("\t%2d ",m_data[i]);
		// 반복문으로 인덱스를 증가시키면서 인덱스에 해당하는 배열의 값을 출력

		printf("\n\n");
	}
	
	void Add(int pos,CebElement e){ // 항목 값을 추가하는 함수
		if(!IsFull() && pos >= 0 && pos <= m_len)
			// 만약 배열이 꽉차있지 않고, 인수로 받은 인덱스 값은 0~(리스트의 길이) 사이라면
		{
			int i;
			for(i = m_len-1; i>= pos; i--) // 반복문을 뒤에서부터 인덱스로 받은 pos 값까지 돌면서
				m_data[i+1] = m_data[i]; // 배열을 한칸씩 미뤄주고
			m_data[pos] = e; // 인수로 받은 pos의 인덱스에 해당하는 항목 값에 인수로 받은 항목값 e를 대입
			m_len++; // 리스트의 길이를 저장하는 변수를 하나 증가시킴
		}
		
	}
	void AddTail(CebElement e)// 배열의 가장 뒤에 항목 값을 추가하는 함수
	{Add(m_len,e);} // Add함수를 부르는데, 인덱스의 값은 리스트의 길이인 m_len이다 

	void AddHead(CebElement e)// 배열의 가장 앞에 항목 값을 추가하는 함수
	{Add(0,e);}  // Add함수를 부르는데, 인덱스의 값은 배열의 가장 처음 인덱스인 0이다 

	void Remove(int pos){ // 항목 값을 삭제하는 함수
	
		int i;
		CebElement item; // CebElement형 변수를 하나 선언

		if(pos < 0 || pos > m_len) printf("위치 오류");
		// 만약 pos가 0보다 작거나 m_len의 이상이면 위치 오류이므로, 메세지를 출력
		item = m_data[pos]; // 인수로 받은 인덱스 값에 해당하는 항목값을 위에서 만든 item에 저장
		for(i = pos ; i< m_len-1 ; i ++) // 인수로 받은 인덱스값~리스트의 길이-1까지 반복문을 돌면서
			m_data[i] = m_data[i+1]; // m_data에 들어있는 항목 값을 앞당긴다
		//m_data[pos] = item;
		m_len--; // 리스트의 길이를 저장하는 변수를 하나 감소시킴
		
	}

	void RemoveHead() // 배열의 가장 앞에 항목 값을 삭제하는 함수
	{Remove(0);} // Remove함수를 부르는데, 인덱스의 값은 초기 인덱스인 0다 
	void RemoveTail() // 배열의 가장 뒤에 항목 값을 삭제하는 함수
	{Remove(m_len);} // Remove함수를 부르는데, 인덱스의 값은 리스트의 길이인 m_len이다 

};

