// �� �ҽ������� �̷�ã���� ������ ����ϴ� �Լ��� ���ǵǾ� �ִ�
 
#include <stdio.h> // ǥ�� ����� ���̺귯�� �Լ��� �ִ� ������� �߰�
#include "CebMaze.h" // �̷θ� �����ϴ� ������� �߰� 
#include "CebStack.h" // �̷��� ��ǥ���� �־��� ������ �����ϴ� ������� �߰�

void main(){ // ���� �Լ�

	CCebMaze maze; // CCebMaze�� ��ü maze�� �����Ѵ�
	maze.Load("maze4.txt"); // ���� �̸��� "maze1.txt"�� ���� �о���δ�
	// ����� �������� maze2.txt�� �����Ͽ����ϴ�
	maze.Print(); // ���� �̷λ���(maze)�� ����Ѵ�
	printf("  �Ա� �� --> �ⱸ �� ��� ã�� ���� [Enter]\n");  
	getchar();// ���� ����ڰ� ���� �޼����� �а� enter�� �����ٸ� �� enter�� getchar�� �޾��ش�
	maze.SearchExit(); // �̷� ã�⸦ �����ϴ� �Լ� SearchExit�� ȣ���Ѵ�
	printf("  ���� ��� �� ��� [Enter]\n");
	getchar(); // ���� ����ڰ� ���� �޼����� �а� enter�� �����ٸ� �� enter�� getchar�� �޾��ش�
	maze.ShortCut(); // ���� ��θ� �����ϴ� �Լ� ShortCut�� ȣ���Ѵ�
	printf("  ���� [Enter]\n");

	getchar(); 
	getchar(); // ���� ������ �ٷ� ������ ���� ���� ����
}