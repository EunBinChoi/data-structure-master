#pragma once
#include<stdio.h>
#include<string.h>

class CCebMaze // 미로의 기능을 구현해주는 클래스
{
	int m_w; // 미로의 width
	int m_h; // 미로의 height
	int** m_maze; // 미로의 각 항목 값을 저장하는 이차원 배열

public:
	CCebMaze(void) // 미로의 생성자
	{
		Init(0,0); // Init 함수를 호출
	}

	~CCebMaze(void) // 미로의 소멸자
	{
		Reset(); // Rect 함수를 호출
	}

	void Init(int w, int h) // 동적으로 할당
	{
		
		if(w <=0 || h <= 0) return; // 만약 w,h 둘 중 하나라도 0보다 작거나 같으면 return 
		
		// 위의 조건에 만족하지 않으면
		m_w = w;  // w로 받은 것을 멤버 함수 중 이차원 배열의 열의 길이를 저장하는 m_w에 저장
		m_h = h; // h로 받은 것을 멤버 함수 중 이차원 배열의 행의 길이를 저장하는 m_h에 저장
		
		// 이차원 배열을 동적할당 해준다
		m_maze = new int* [m_h]; // 이차원 배열의 행의 수만큼 동적할당을 하고 
		for(int i =0;i<m_h;i++) // 반복문을 돌면서
			m_maze[i] = new int[m_w]; // 각각의 행에 열의 수만큼 동적할당을 한다

	}

	void Reset(){ // 동적으로 해제
		if(m_maze != NULL){ // 만약 m_maze가 NULL이 아니라면
			
			for(int i = 0; i < m_h ; i++)  // 반복문을 m_h만큼 돌면서
			{
				delete []m_maze[i]; // double* 형 배열을 해제시킨다
			}
			delete []m_maze; // 그리고 double** 형 배열을 해제시킨다
			// 이차원 배열은 배열 자체를 가리키는 포인터와 배열 안에 행을 가리키는 포인터로, 이중 포인터를 사용해야한다.
			// 이 이중포인터를 해제시켜주려면 위와 같이 행을 가리키는 포인터를 먼저 해제시키고, 그 다음에 배열 자체를 가리키는 포인터를 해제시켜야한다
		}
	}

	void Load(char *fname = NULL){
		FILE *fp = fopen(fname,"r");  // 멤버 변수에 저장된 파일을 "r"(읽기허용) 형태로 open 한다

		if(fp == NULL) // 만약 fp에 아무것도 들어오지 않으면(파일이 정상적으로 열리지 않으면)
		{ 
			printf("Error :파일 존재하지 않음\n"); // 파일이 존재하지 않는다는 메세지를 출력한다
			return ;

		}

		int value; // 메모장에서 읽어들인 숫자를 저장할 변수 선언
		int w, h; // 메모장에서 가장 첫번째 줄에 있는 미로의 크기를 저장할 변수 선언
		fscanf(fp,"%d %d", &w, &h); // 파일의 가장 첫번 째 줄의 미로의 크기를 받아들인다. 각각 w,h에 정수형으로 받아온다.
		Init(w,h); // 미로의 크기에 맞는 이차원 배열을 동적으로 할당

		// 이중 반복문을 돌면서
		for(int i = 0 ; i < m_h ; i ++) 		{
			for(int j = 0 ; j < m_w ; j++) 
			{

				fscanf(fp,"%d",&value); // 파일에서 값을 읽어서 value에 저장한다
				m_maze[i][j] = value; // 이차원 배열에 받아온 value 값을 대입한다
				

			}
		
		}

	}

	void Print(){ // 보기 좋게 출력하는 함수
		printf("========================================\n");
		printf("    전체 미로의 크기 = %d %d\n",m_w,m_h); // 전체 미로의 크기를 출력
		printf("========================================\n");
		for(int i = 0 ; i < m_h ; i ++) // 이중 반복문을 돌면서
		{
			for(int j = 0 ; j < m_w ; j++)
			{
				if(m_maze[i][j] == 0) // 만약 0(벽)에 해당한다면
					printf("■"); // 내부가 채워져있는 네모 출력

				else if(m_maze[i][j] == 1) // 만약 1(길)에 해당한다면
					printf("  "); // 빈 칸을 출력

				else if(m_maze[i][j] == 5) // 만약 5(입구)에 해당한다면
					printf("○"); // 내부가 비워져있는 동그라미 출력

				else if(m_maze[i][j] == 9) // 만약 9(출구)에 해당한다면
					printf("◎"); // 도넛 모양의 기호를 출력

				else if(m_maze[i][j] == 8) // 만약 8(현재 위치)에 해당한다면
					printf("☆"); // 별표 모양의 기호를 출력

				else if(m_maze[i][j] == 2) // 만약 2(지나간 길)에 해당한다면
					printf("□"); // 내부가 비워져있는 네모를 출력
			}
			printf("\n");
		}
		printf("========================================\n");
		//Reset(); 이 함수를 Print 함수에서 부르게 되면 함수가 끝난 뒤 소멸자에서 메모리 동적 해제를 한번 더 해주므로 에러가 뜬다
	}

};

