// 이 소스파일은 미로찾기의 메인을 담당하는 함수가 정의되어 있다
 
#include <stdio.h> // 표준 입출력 라이브러리 함수가 있는 헤더파일 추가
#include "CebMaze.h" // 미로를 구현하는 헤더파일 추가 
#include "CebStack.h" // 미로의 좌표들을 넣어줄 스택을 구현하는 헤더파일 추가

void main(){ // 메인 함수

	CCebMaze maze; // CCebMaze의 객체 maze을 생성한다
	maze.Load("maze4.txt"); // 파일 이름이 "maze1.txt"인 것을 읽어들인다
	// 사용자 지정파일 maze2.txt로 저장하였습니다
	maze.Print(); // 현재 미로상태(maze)를 출력한다
	printf("  입구 ○ --> 출구 ◎ 경로 찾기 시작 [Enter]\n");  
	getchar();// 만약 사용자가 위의 메세지를 읽고 enter를 누른다면 그 enter를 getchar가 받아준다
	maze.SearchExit(); // 미로 찾기를 시작하는 함수 SearchExit를 호출한다
	printf("  최적 경로 ☆ 출력 [Enter]\n");
	getchar(); // 만약 사용자가 위의 메세지를 읽고 enter를 누른다면 그 enter를 getchar가 받아준다
	maze.ShortCut(); // 최적 경로를 저장하는 함수 ShortCut을 호출한다
	printf("  종료 [Enter]\n");

	getchar(); 
	getchar(); // 실행 파일이 바로 꺼지는 것을 막기 위함
}