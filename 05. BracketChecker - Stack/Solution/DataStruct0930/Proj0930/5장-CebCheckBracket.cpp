/*이 헤더파일은 괄호에 대한 별다른 조건이 없으므로, 괄호가 정상적으로 닫힘*/

#include "CebBracketChecker.h" // 파일에서 괄호 닫기가 정상적으로 이루어지는 지 확인하고, 문제점을 해결하는 헤더 선언
#include "CebStack.h" // 스택에서 기본적인 기능을 구현하는 헤더 선언

void main(){

	
	printf("\n************* [ 2015년도 2학기 자료구조 실습과제 5 ] *************\n\n");
	printf("                         1. 괄호 닫기 프로그램\n\n");

	CCebBracketChecker checker; // CCebBracketChecker 클래스의 객체를 하나 만든다(이 클래스의 정의에서 CCebStack의 객체를 선언한다)
	
	/*다음과 같은 파일이름을 가진 것을 Check 함수를 호출하여 괄호가 정상으로 닫히는 지 판단하는 프로그램을 호출*/
	checker.Check("CebStack.h");  
	checker.Check("CebBracketChecker.h");
	checker.Check("5장-CebCheckBracket.cpp");
	checker.Check("test.txt");

	/*다음과 같은 파일이름을 가진 것을 Check2 함수를 호출하여 위에서 호출된 Check의 문제점을 해결*/
	printf("\n********************* [ 괄호닫기 문제 해결 ] *********************\n\n");
	checker.Check2("CebStack.h"); 
	checker.Check2("CebBracketChecker.h");
	checker.Check2("5장-CebCheckBracket.cpp");
	checker.Check2("test.txt");


	getchar();
	getchar();
	
	return;
}