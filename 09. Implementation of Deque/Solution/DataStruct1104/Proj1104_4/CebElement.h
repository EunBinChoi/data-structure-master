#pragma once
#include <stdio.h>

class CCebElement // 연결된 덱의 노드(노드 안에는 데이터와 링크의 값이 존재)에 값(정수)에 해당하는 것을 읽어들이는 클래스
{
	int m_char; // 정수를 저장할 수 있는 변수 선언
public:
	CCebElement(int ch =  0) : m_char(ch){} // 생성자(멤버 변수 m_char에 읽어드린 ch 값을 대입)
	~CCebElement(void){} // 소멸자
	int getInt(){return m_char;} // 정수형 변수(멤버 변수)를 반환하는 함수
	void Display(){printf("%d ", m_char);} // 정수형 변수(멤버 변수)를 출력해주는 함수
	
};

