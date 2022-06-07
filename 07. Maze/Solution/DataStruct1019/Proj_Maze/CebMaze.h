#pragma once
#include "CebStack.h"
#include <stdio.h>
#include <windows.h>

class CCebMaze // 미로의 기능을 구현해주는 클래스
{

	int m_w; // 미로의 width
	int m_h; // 미로의 height
	int** m_maze; // 미로의 각 항목 값을 저장하는 이차원 배열
	CCebStack m_stack; // 미로의 탐색을 위한 스택
	CCebStack m_o_stack; // 갈림길 저장을 위한 스택
	CCebStack m_path_stack; // 최적 경로 저장을 위한 스택

	CElement m_start; // 미로의 입구
	CElement m_exit; // 미로의 출구
public:
	CCebMaze(void) // 미로의 생성자
	{
		Init(0,0); // Init 함수를 호출
	}

	~CCebMaze(void) // 미로의 소멸자
	{
		Reset(); // Reset 함수를 호출
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
				delete []m_maze[i]; // int* 형 배열을 해제시킨다
			}
			delete []m_maze; // 그리고 int** 형 배열을 해제시킨다
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
		for(int i = 0 ; i < m_h ; i ++) 		
		{
			for(int j = 0 ; j < m_w ; j++) 
			{

				fscanf(fp,"%d",&value); // 파일에서 값을 읽어서 value에 저장한다
				m_maze[i][j] = value; // 이차원 배열에 받아온 value 값을 대입한다

				if(value == 5){ // value 값이 5이면
					m_start.x = i; // 미로의 입구의 x 원소를 i로 저장
					m_start.y = j; // 미로의 입구의 y 원소를 j로 저장
				}
				else if(value == 9){ // value값이 9이면
					m_exit.x = i; // 미로의 출구의 x 원소를 i로 저장
					m_exit.y = j; // 미로의 출구의 y 원소를 j로 저장
				}


			}

		}
	}

	void Print(){ // 미로를 보기 좋게 출력하는 함수

		system("cls"); // 실행 파일의 화면을 모두 지워준다(windows.h 헤더에 정의 되어있음)
		printf("========================================\n");
		printf("    전체 미로의 크기 = %d %d\n",m_w,m_h); // 전체 미로의 크기를 출력함
		printf("========================================\n");
		for(int i = 0 ; i < m_h ; i ++) // 이중 반복문을 돌면서
		{
			for(int j = 0 ; j < m_w ; j++)
			{

				if(m_maze[i][j] == 0) // 만약 0(벽)에 해당한다면
					printf("■"); // 내부가 채워져있는 네모 출력

				else if(m_maze[i][j] == 1) // 만약 1(길)에 해당한다면
					printf("  "); // 빈 칸을 출력

				else if(m_maze[i][j] == 5){ // 만약 5(입구)에 해당한다면
					printf("○"); // 내부가 비워져있는 동그라미 출력

				}
				else if(m_maze[i][j] == 9) // 만약 9(출구)에 해당한다면
					printf("◎"); // 도넛 모양의 기호를 출력

				else if(m_maze[i][j] == 8) // 만약 8(최적 위치)에 해당한다면
					printf("☆"); // 별표 모양의 기호를 출력

				else if(m_maze[i][j] == 2) // 만약 2(지나간 길)에 해당한다면
					printf("□"); // 내부가 비워져있는 네모를 출력
			}
			printf("\n");
		}
		printf("========================================\n");
		//Reset(); 이 함수를 Print 함수에서 부르게 되면 함수가 끝난 뒤 소멸자에서 메모리 동적 해제를 한번 더 해주므로 에러가 뜬다
	}

	void Push(int x, int y) // 텍스트 파일을 읽어들이면서 갈 수 있는 위치를 저장해주는 함수
	{  

		CElement c; // CElement의 객체를 하나 만든다
		c.x = x; // 객체의 x의 값을 Push의 인수로 받은 x로 대입하고
		c.y = y; // 객체의 y의 값을 Push의 인수로 받은 y로 대입한다

		m_stack.Push(c); // 이 값을 CCebStack의 객체인 m_stack에 저장한다
		m_path_stack.Push(c); 
		// 이 값을 CCebStack의 객체인 m_path_stack(갈 수 있는 모든 길을 저장한 후, 최적경로가 아닌 값은 Pop 시키고 최적경로인 값만 남게하는 스택)에 저장한다

	}
	void Push_1(int x, int y) // 텍스트 파일을 읽어들이면서 갈림길을 만나게 되면 갈림길에서 갈 수 있는 위치를 저장해주는 함수
	{  

		CElement c; // CElement의 객체를 하나 만든다
		c.x = x; // 객체의 x의 값을 Push의 인수로 받은 x로 대입하고
		c.y = y; // 객체의 y의 값을 Push의 인수로 받은 y로 대입한다

		m_o_stack.Push(c); // 이 값을 CCebStack의 객체인 m_o_stack(갈림길을 저장하는 스택)에 저장한다
	}

	void SearchExit() // 미로찾기를 실질적으로 시작하는 함수
	{
		CElement here; // 현재 미로찾기를 시행할 기준이 되는 CElement형 변수
		CElement here2; // 이전의 미로찾기를 시행할 기준이 되었던 값을 저장하는 CElement형 변수
		here = m_start; // 먼저 here을 미로의 입구의 위치를 대입하고,
		here2 = m_start; // here2(이전의 미로찾기를 했던 값)도 미로의 위치로 대입한다
		int w,h; // 미로찾기의 현재위치의 행과 열을 저장할 변수 

		while(m_maze[here.x][here.y]!=9){
			int cnt = 0; 
			// 미로찾기를 할 때 상우하좌를 검색하면서 길이거나 출구인 곳이 있으면 이동할 수 있는 자리이므로 cnt의 값을 증가시킨다
			// 즉, cnt에는 미로찾기 시, 현재 기준의 위치에서 이동할 수 있는 위치가 몇 개있는지 저장하는 변수이다.
			// 이 값은 반복문을 돌면서 0으로 계속 초기화한다.(기준 위치가 바뀌면 움직일 수 있는 위치도 변하므로)
			Print(); // 현재 미로 상태를 출력한다
			printf("  현재 상황 : [%d %d] == [%d %d]\n",here2.x,here2.y,m_exit.x, m_exit.y);
			// 현재의 미로의 위치를 출력해준다.
			// 여기서 위치로 here2를 해준 이유는 출력했을 때 현재의 위치(변한 위치)가 아니라 이전의 위치로 출력해줘야 하기 때문이다
			Sleep(100); // 시간 지연을 시키는 함수 인수 안에 1000이 1초가 된다.
			h = here.x; // 현재 위치의 x를 현재 위치의 행을 저장하는 h에 대입하고
			w = here.y; // 현재 위치의 y를 현재 위치의 열을 저장하는 w에 대입한다
			m_maze[h][w] = 2; // 현재 위치의 m_maze 값을 2로 준다(지나간 길 표시)
			// 조건문을 돌면서
			if(h > 0){ // 만약 h가 0보다 크면(현재 maze가 자리하고 있는 곳의 행이 0보다 크다는 의미)
				if(m_maze[h-1][w] == 1 ||m_maze[h-1][w] == 9) // 기준 위치보다 위의 값이 1이나 9이면(길이나 출구)
				{
					cnt++; // 이동할 수 있는 위치 값을 하나 증가시키고
					Push(h-1, w); // 기준 위치의 위의 값을 Push 함수로 스택에 저장한다
				}
			}
			if(m_maze[h][w+1] == 1 || m_maze[h][w+1] == 9)	// 기준 위치보다 오른쪽의 값이 1이나 9이면(길이나 출구)
			{
				cnt++; // 이동할 수 있는 위치 값을 하나 증가시키고
				Push(h, w+1);// 기준 위치의 오른쪽의 값을 Push 함수로 스택에 저장한다
			}
			if(m_maze[h+1][w] == 1 || m_maze[h+1][w] == 9)	// 기준 위치보다 아래의 값이 1이나 9이면(길이나 출구)
			{
				cnt++; // 이동할 수 있는 위치 값을 하나 증가시키고
				Push(h+1,w); // 기준 위치의 아래의 값을 Push 함수로 스택에 저장한다
			}
			if(w > 0) // 만약 w가 0보다 크면(현재 maze가 자리하고 있는 곳의 열이 0보다 크다는 의미)
			{
				if(m_maze[h][w-1] == 1 || m_maze[h][w-1] == 9)	// 기준 위치보다 왼쪽의 값이 1이나 9이면(길이나 출구)
				{
					cnt++;	 // 이동할 수 있는 위치 값을 하나 증가시키고
					Push(h,w-1); // 기준 위치의 왼쪽의 값을 Push 함수로 스택에 저장한다

				}
			}					

			if(cnt > 1){	// 만약 cnt이 1보다 크다는 것은 움직일 수 있는 것이 1개보다 많다(즉, 갈림길이다)라는 말이므로
				if(m_maze[h-1][w] == 1 ||m_maze[h-1][w] == 9) // 기준 위치보다 위의 값이 1이나 9이면(길이나 출구)
				{
					Push_1(h-1, w); // 기준 위치의 위의 값을 m_o_stack에 저장한다
				}
				if(m_maze[h][w+1] == 1 || m_maze[h][w+1] == 9)	// 기준 위치보다 오른쪽의 값이 1이나 9이면(길이나 출구)
				{
					Push_1(h, w+1); // 기준 위치의 오른쪽의 값을 m_o_stack에 저장한다
				}
				if(m_maze[h+1][w] == 1 || m_maze[h+1][w] == 9)	// 기준 위치보다 아래의 값이 1이나 9이면(길이나 출구)
				{
					Push_1(h+1,w); // 기준 위치의 아래의 값을 m_o_stack에 저장한다
				}
				if(w > 0)
				{
					if(m_maze[h][w-1] == 1 || m_maze[h][w-1] == 9)	// 기준 위치보다 왼쪽의 값이 1이나 9이면(길이나 출구)
					{
						Push_1(h,w-1); // 기준 위치의 왼쪽의 값을 m_o_stack에 저장한다			
					}
				}
			}

			if(cnt == 0){	// 막다른 길을 만나면 지름길이 아니라는 것이므로		
				CElement t = m_o_stack.Pop(); // CElement의 객체 t에는 m_o_stack에 맨 위의 값을 Pop한 것을 저장하고
				
				while(m_maze[t.x][t.y] == 2 ){ // 만약 그 값에 해당되는 배열 값이 2(지나간 길)이라면
					t = m_o_stack.Pop(); // 계속 Pop을 통해 값을 빼준다

				}
				// while 문이 끝난 후에는 2가 아닐 때(지나간 길이 아닐 때)의 위치가 나온다
				m_o_stack.Push(t); 
				// 그 값까지 Pop으로 빼주면 안되니까 마지막값은 Push로 집어넣는다
				
				CElement t2 = m_stack.Pop(); // CElement의 객체 t2에는 m_stack에 맨 위의 값을 Pop한 것을 저장하고
				while(m_maze[t2.x][t2.y] == 2 ){ // 만약 그 값에 해당되는 배열 값이 2(지나간 길)이라면
					t2 = m_stack.Pop(); // 계속 Pop을 통해 값을 빼준다

				}
				// while 문이 끝난 후에는 2가 아닐 때(지나간 길이 아닐 때)의 위치가 나온다
				m_stack.Push(t2);
				// 그 값까지 Pop으로 빼주면 안되니까 마지막값은 Push로 집어넣는다
			

				while(!m_path_stack.IsEmpty() &&!m_o_stack.IsEmpty()){	// m_path_stack과 m_o_stack 둘다 비어있지 않을 때까지
					if(m_path_stack.Peek().x == m_o_stack.Peek().x &&  // 만약 두 stack을 Peek 함수로 마지막 값을 확인했을 때 같다면
						m_path_stack.Peek().y == m_o_stack.Peek().y)
					{
						break; // break문으로 while문 종료
					}
					else // 다르다면
					{
						m_path_stack.Pop(); 
						// 지나간 경로를 모두 저장한 m_path_stack에서 최적 경로만 저장하기 위해 두 stack의 마지막 수가 다르면 계속 Pop해줌
					}

				}				
			}


			if(m_stack.IsEmpty()){ // 만약 m_stack이 비어있다면
				printf("  Fail!!!"); // 실패
				return; // return 해준다
			} 
			else{ // 비어있지 않으면 (경로가 저장되어있으면)
				
				here = m_stack.Pop(); // 다음 위치로 가기 위해 here을 다음 값으로 업데이트한다
				here2.x = h; // 현재 값 h을 here2에 저장
				here2.y = w; // 현재 값 w를 here2에 저장
				// here2는 이전 위치를 저장하는 변수
				continue; // 다시 while 문으로 돌아가서 미로탐색을 해준다
			}		
		}
		Print(); // 미로 탐색을 출력
	}

	void ShortCut(){ // 지름길을 저장해주는 함수
		m_maze[m_start.x][m_start.y] = 8; // 처음 위치의 값은 지름길에 해당한다(출발점)
		while(!m_path_stack.IsEmpty()) // m_path_stack이 비어있지 않으면
		{
			CElement t = m_path_stack.Pop(); // 계속 한 값씩 꺼내면서 t에 저장하고
			m_maze[t.x][t.y] = 8; // 그것에 해당하는 배열 값을 8로 저장한다(8은 최적 길을 의미)
		}
		while(!m_stack.IsEmpty()) // m_stack이 비어있지 않으면
		{
			CElement t = m_stack.Pop(); // 계속 Pop하면서
			m_maze[t.x][t.y] = 1;
			// stack 안에는 들어갔지만 Pop해주지 않아 스택에 남아있는 것을 그냥 빈칸으로 저장
		}
		Print(); // 미로 탐색을 출력
		printf("  Success!!\n");
	}

};
