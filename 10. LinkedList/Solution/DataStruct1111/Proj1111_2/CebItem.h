#pragma once
#include <string.h> // 문자열을 구현하는 헤더파일 선언
#include <stdio.h> // 표준 라이브러리 함수가 들어있는 헤더파일 선언

class CCebItem // 링크드 리스트에서 데이터를 저장하는 클래스 선언
{

protected: // 자식에게 접근할 수 있도록 protected로 지정

	char m_name[40]; // 물건의 이름을 저장하는 문자열
	int m_price; // 물건의 가격을 저장하는 정수형 변수
	int m_priority; // 물건의 우선순위를 저장하는 정수형 변수
	char m_method[40]; // 물건을 사는 방법을 저장하는 문자열
	
public: // 어디서든 접근할 수 있도록 public 으로 지정

	CCebItem(char* name = "", int price = 0 , int priority = 0, char* method="..."){ // 생성자
		
		strcpy(m_name, name); // 인수로 받아온 이름을 저장하는 문자열을 멤버변수로 지정
		m_price = price; // 인수로 받아온 가격을 저장하는 정수형 변수를 멤버변수로 지정 
		m_priority = priority; // 인수로 받아온 우선순위를 저장하는 정수형 변수를 멤버변수로 지정
		strcpy(m_method,method); // 인수로 받아온 물건사는 방법을 저장하는 문자열을 멤버변수로 지정
	}
	~CCebItem(void){} // 소멸자
	
	void Display(){ printf("[물건] : %8s  [가격] : %7d  [우선순위] : %2d  [메세지] : %s\n", m_name, m_price,m_priority,m_method); }
	// 멤버변수를 출력하는 함수
	// 문자열과 정수를 출력할 때 간격을 맞추어 출력한다
};