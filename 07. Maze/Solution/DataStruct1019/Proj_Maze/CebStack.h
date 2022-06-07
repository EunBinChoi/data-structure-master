#pragma once  
#include <stdio.h>
#include "CebPoint2D.h"
#define MAX_STACK_SIZE 100 // MAX_STACK_SIZE 는 100으로 설정	

typedef CCebPoint2D		CElement;// CCebPoint2D 이라는 데이터 자료형을 CElement로 변환

class CCebStack // 스택의 구현을 담당하는 클래스
{

	CElement m_data[MAX_STACK_SIZE]; // 스택에 담기는 문자나 숫자를 담는 배열, 여기에는 원소 x,y가 존재
	int m_top; 
	// 스택의 가장 높은 자리의 값을 담고 있는 인덱스 값 + 1
	// 여기서는 다음에 들어올 값의 인덱스를 지정해준다고 생각하면 쉽다

public:

	CCebStack(void) // 생성자 
	{
		Reset(); // 생성자에서는 Reset의 함수를 호출
	}

	~CCebStack(void) // 소멸자
	{
	}
	
	void Reset(){m_top  = 0;} // m_top을 0으로 설정

	bool IsEmpty(){ // 스택의 배열이 비어있는지 확인하는 함수
		return m_top == 0; // 만약 m_top(다음에 들어올 값의 인덱스)가 0 이라면 참, 0이 아니라면 거짓
		/*if(m_top == 0) return true;
		else return false;*/
	}
	
	bool IsFull(){ // 스택의 배열이 꽉 차있는지 확인하는 함수
		return m_top == MAX_STACK_SIZE; // 만약 m_top(다음에 들어올 값의 인덱스)가 최대치인 MAX_STACK_SIZE라면 참, 아니면 거짓
	}

	void Push(CElement e){ // 스택의 배열에 값을 집어넣는 함수
		if(IsFull())  // 만약 스택의 배열이 꽉 차있다면..
		{
			printf("Error : 스택 포화 에러 \n"); // 스택 포화 에러라는 메세지를 출력
			return ;
		}
		m_data[m_top++] = e; // 배열이 꽉 차있지 않다면, 스택의 배열에 함수의 인수로 받은 값을 대입한다
	}
	
	CElement Pop(){  // 스택의 배열에 값을 하나씩 뺴서 확인하는 함수
		if(IsEmpty())  // 만약 스택의 배열이 비어있다면..
		{
			printf("Error : 스택 공백 에러 \n"); // 스택 공백 에러라는 메세지를 출력
			return 0;
		}
		return m_data[--m_top]; // 배열이 비어있지 않다면, 스택의 배열에 최고 값부터 하나씩 빼서 확인한다
	}

	CElement Peek(){  // 스택의 배열에 값을 하나씩 빼지 않고, 단순히 값이 무엇인지 확인하는 함수
		if(IsEmpty()) // 만약 스택의 배열이 비어있다면..
		{
			printf("Error : 스택 공백 에러 \n"); // 스택 공백 에러라는 메세지 출력
			return 0;
		}
		return m_data[m_top-1]; 
		// 배열이 부어있지 않다면, 스택의 배열에 최고 값이 얼마인지 확인
		// 여기서 조심해야할 것은 m_top의 값 자체를 변화시키지 않고, m_top은 그대로 두고 그것의 하나 직은 수를 반환한다는 것이다
	}

	void Display(){ // 스택의 배열의 값을 출력하는 함수
		printf("[스택 항목의 수 = %2d] ==>\n", m_top); // 스택의 항목의 수를 출력하고,
		for(int i = 0 ; i < m_top ; i++) // 0부터 배열의 최고값을 저장하는 인덱스 - 1까지 돌면서
		{
			printf("<%d %d >", m_data[i].x ,m_data[i].y); // 배열의 값을 출력
			printf("\n");
		}
	}

};


