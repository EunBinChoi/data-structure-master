#pragma once
#include <stdio.h>

class CCebElement // 연결된 스택의 노드(노드 안에는 데이터와 링크의 값이 존재)에 값(문자)에 해당하는 것을 읽어들이는 클래스
{
	char m_char; // 문자를 저장할 수 있는 변수 선언
public:
	CCebElement(char ch =  0) : m_char(ch){} // 생성자(멤버 변수 m_char에 읽어드린 ch 값을 대입)
	~CCebElement(void){} // 소멸자
	char getChar(){return m_char;} // 문자(멤버 변수)를 반환하는 함수
	void Display(){printf("%c ", m_char);} // 문자(멤버 변수)를 출력해주는 함수
};

