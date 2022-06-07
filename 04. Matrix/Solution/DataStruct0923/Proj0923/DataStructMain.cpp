#include"CebMatrix.h" // CCebMatrix 클래스가 정의된 헤더파일을 포함시킨다

void main()
{
	
	printf("\n************* [ 2015년도 2학기 자료구조 실습과제 4 ] *************\n\n");
	printf("                         1. 행렬의 덧셈\n\n");
	
	CCebMatrix a,b,c; // CCebMatrix 클래스의 객체 a,b,c를 만든다
	a.Read("행렬A"); // 객체 a의 행렬의 크기와 값을 읽어들인다
	b.Read("행렬B"); // 객체 b의 행렬의 크기와 값을 읽어들인다
	c.Add(a,b); // 객체 a,b 행렬을 더해서 Add 함수를 호출시킨 c 행럴에 더한 값을 넣어준다
	a.Print(" A "); // 객체 a의 값들을 보기 좋게 출력한다
	b.Print(" B "); // 객체 b의 값들을 보기 좋게 출력한다
	c.Print("A+B"); // 객체 c의 값들을 보기 좋게 출력한다
	

	getchar();
	getchar(); // 실행파일이 안꺼지기 위함


}