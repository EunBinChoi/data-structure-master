#include "CebMaze.h" // 미로의 기능을 구현해주는 클래스가 구현된 헤더파일 포함

void main()
{
	CCebMaze maze; // CCebMaze 클래스의 객체를 만든다
	maze.Load("maze1.txt"); // 객체 maze의 멤버함수를 통해 maze1.txt 파일을 로드한다
	maze.Print(); // 객체 maze의 멤버함수를 통해 파일을 출력한다

	getchar();
	getchar(); // 실행파일에서 바로 닫히지 않도록 하기 위한 getchar
}