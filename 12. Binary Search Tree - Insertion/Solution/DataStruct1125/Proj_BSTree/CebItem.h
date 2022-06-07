#pragma once
#include <string.h> // 문자열을 구현하는 헤더파일 선언
#include <stdio.h> // 표준 라이브러리 함수가 들어있는 헤더파일 선언

class CCebItem // 이진 트리에서 데이터를 구현하는 클래스 선언
{
	char m_name[40]; // 물건의 이름을 저장하는 문자열
	int m_price; // 물건의 가격을 저장하는 정수형 변수
	int m_priority; // 물건의 우선순위를 저장하는 정수형 변수
	char m_method[40]; // 물건을 사는 방법을 저장하는 문자열
	
public: // 어디서든 접근할 수 있도록 public 으로 지정

	CCebItem( int priority = 0,char* name = "",int price = 0 ,  char* method="..."){ // 생성자
		
		strcpy(m_name, name); // 인수로 받아온 이름을 저장하는 문자열을 멤버변수로 지정
		m_price = price; // 인수로 받아온 가격을 저장하는 정수형 변수를 멤버변수로 지정 
		m_priority = priority; // 인수로 받아온 우선순위를 저장하는 정수형 변수를 멤버변수로 지정
		strcpy(m_method,method); // 인수로 받아온 물건사는 방법을 저장하는 문자열을 멤버변수로 지정
	}
	~CCebItem(void){} // 소멸자
	
	void Display(){ printf(" [우선순위] : %2d [물건] : %8s  [가격] : %5d  [메세지] : %s\n", m_priority,m_name, m_price,m_method); }
	// 멤버변수를 출력하는 함수
	// 문자열과 정수를 출력할 때 간격을 맞추어 출력한다

	bool HasName(char* name){return strcmp(name,m_name)==0;} 
	// 인수로 받은 name과 멤버변수 m_name이 같은지 비교
	// 만약 두 문자열이 같다면 strcmp 함수가 0을 반환함
	
	bool IsPriceRange(int min,int max){ // 인수로  min max 값을 받아 만약 멤버변수인 m_price 값 사이에 있으면 true를 return
		return (m_price >=min && m_price <= max);
	
	} 

	char* getName(){return m_name;} // 멤버변수의 이름을 저장하는 문자열을 반환하는 함수
	int getPrice(){return m_price;} // 멤버변수의 가격을 저장하는 정수형 변수를 반환하는 함수
	int getPriority(){return m_priority;} // 멤버변수의 우선순위을 저장하는 정수형 변수를 반환하는 함수
	char* getMethod(){return m_method;} // 멤버변수의 사는 방법을 저장하는 문자열을 반환하는 함수
};