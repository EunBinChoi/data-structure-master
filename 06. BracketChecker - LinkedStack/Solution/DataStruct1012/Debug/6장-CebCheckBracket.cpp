/*�� ��������� ��ȣ�� ���� ���ٸ� ������ �����Ƿ�, ��ȣ�� ���������� ����*/

#include "CebBracketChecker.h" // ���Ͽ��� ��ȣ �ݱⰡ ���������� �̷������ �� Ȯ���ϰ�, �������� �ذ��ϴ� ��� ����
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void main(){

	
	printf("\n************* [ 2015�⵵ 2�б� �ڷᱸ�� �ǽ����� 6 ] *************\n\n");
	printf("                         2. ��ȣ �ݱ� ���α׷�\n\n");

	CCebBracketChecker checker; // CCebBracketChecker Ŭ������ ��ü�� �ϳ� �����(�� Ŭ������ ���ǿ��� CCebLinkedStack�� ��ü�� �����Ѵ�)
	

	/*������ ���� �����̸��� ���� ���� Check2 �Լ��� ȣ���Ͽ� ������ ȣ��� Check�� �������� �ذ�*/
	checker.Check2("CebBracketChecker.h"); 
	printf("\n\n*************************�����Ϸ��� Enter ��������*************************\n\n");
	system("pause");
	system("cls");
	checker.Check2("CebLinkedStack.h");
	printf("\n\n*************************�����Ϸ��� Enter ��������*************************\n\n");
	system("pause");
	system("cls");
	checker.Check2("6��-CebCheckBracket.cpp");
	printf("\n\n*************************�����Ϸ��� Enter ��������*************************\n\n");
	system("pause");
	system("cls");
	getchar();
	getchar(); // �������Ͽ��� �ٷ� ������ �ʵ��� �ϱ� ���� getchar
	
	return;
}