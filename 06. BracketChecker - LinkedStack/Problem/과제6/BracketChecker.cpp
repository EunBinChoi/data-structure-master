/*�� ��������� ��ȣ�� ���� ���ٸ� ������ �����Ƿ�, ��ȣ�� ���������� ����*/

#include "CebBracketChecker.h" // ���Ͽ��� ��ȣ �ݱⰡ ���������� �̷������ �� Ȯ���ϰ�, �������� �ذ��ϴ� ��� ����
#include<stdio.h>
void main(){

	
	printf("\n************* [ 2015�⵵ 2�б� �ڷᱸ�� �ǽ����� 6 ] *************\n\n");
	printf("                         2. ��ȣ �ݱ� ���α׷�\n\n");

	CCebBracketChecker checker; // CCebBracketChecker Ŭ������ ��ü�� �ϳ� �����(�� Ŭ������ ���ǿ��� CCebLinkedStack�� ��ü�� �����Ѵ�)
	
	/*������ ���� �����̸��� ���� ���� Check �Լ��� ȣ���Ͽ� ��ȣ�� �������� ������ �� �Ǵ��ϴ� ���α׷��� ȣ��*/
	checker.Check("CebBracketChecker.h");
	checker.Check("CebElement.h");  
	checker.Check("CebLinkedStack.h");
	checker.Check("CebNode.h");
	checker.Check("6��-CebCheckBracket.cpp");

	/*������ ���� �����̸��� ���� ���� Check2 �Լ��� ȣ���Ͽ� ������ ȣ��� Check�� �������� �ذ�*/
	printf("\n********************* [ ��ȣ�ݱ� ���� �ذ� ] *********************\n\n");
	checker.Check2("CebBracketChecker.h");
	checker.Check2("CebElement.h");  
	checker.Check2("CebLinkedStack.h");
	checker.Check2("CebNode.h");
	checker.Check2("6��-CebCheckBracket.cpp");

	getchar();
	getchar(); // �������Ͽ��� �ٷ� ������ �ʵ��� �ϱ� ���� getchar
	
	return;
}