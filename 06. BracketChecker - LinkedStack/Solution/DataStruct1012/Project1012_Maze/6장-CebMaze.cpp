#include "CebMaze.h" // �̷��� ����� �������ִ� Ŭ������ ������ ������� ����

void main()
{
	CCebMaze maze; // CCebMaze Ŭ������ ��ü�� �����
	maze.Load("maze1.txt"); // ��ü maze�� ����Լ��� ���� maze1.txt ������ �ε��Ѵ�
	maze.Print(); // ��ü maze�� ����Լ��� ���� ������ ����Ѵ�

	getchar();
	getchar(); // �������Ͽ��� �ٷ� ������ �ʵ��� �ϱ� ���� getchar
}