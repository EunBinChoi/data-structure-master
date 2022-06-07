#pragma once
class CCebPoint2D // 위치를 저장해주는 클래스
{
public:
	int x; // 현재 위치의 행의 값을 저장해줄 변수 선언 
	int y; // 현재 위치의 열의 값을 저장해줄 변수 선언

	CCebPoint2D (int xx=0, int yy=0)  // 생성자
	{
		x = xx; // 받은 xx의 값과 yy의 값을 각자 x,y에 대입
		y = yy;
	}

	~CCebPoint2D(void) // 소멸자
	{
	}
};

