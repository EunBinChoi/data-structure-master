/*�� ��������� ��ȣ�� ���� ���ٸ� ������ �����Ƿ�, ��ȣ�� ���������� ����*/

#include "CebBracketChecker.h" // ���Ͽ��� ��ȣ �ݱⰡ ���������� �̷������ �� Ȯ���ϰ�, �������� �ذ��ϴ� ��� ����
#include "CebStack.h" // ���ÿ��� �⺻���� ����� �����ϴ� ��� ����

void main(){

	
	printf("\n************* [ 2015�⵵ 2�б� �ڷᱸ�� �ǽ����� 5 ] *************\n\n");
	printf("                         1. ��ȣ �ݱ� ���α׷�\n\n");

	CCebBracketChecker checker; // CCebBracketChecker Ŭ������ ��ü�� �ϳ� �����(�� Ŭ������ ���ǿ��� CCebStack�� ��ü�� �����Ѵ�)
	
	/*������ ���� �����̸��� ���� ���� Check �Լ��� ȣ���Ͽ� ��ȣ�� �������� ������ �� �Ǵ��ϴ� ���α׷��� ȣ��*/
	checker.Check("CebStack.h");  
	checker.Check("CebBracketChecker.h");
	checker.Check("5��-CebCheckBracket.cpp");
	checker.Check("test.txt");

	/*������ ���� �����̸��� ���� ���� Check2 �Լ��� ȣ���Ͽ� ������ ȣ��� Check�� �������� �ذ�*/
	printf("\n********************* [ ��ȣ�ݱ� ���� �ذ� ] *********************\n\n");
	checker.Check2("CebStack.h"); 
	checker.Check2("CebBracketChecker.h");
	checker.Check2("5��-CebCheckBracket.cpp");
	checker.Check2("test.txt");


	getchar();
	getchar();
	
	return;
}