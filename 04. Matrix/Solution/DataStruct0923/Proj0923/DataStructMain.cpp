#include"CebMatrix.h" // CCebMatrix Ŭ������ ���ǵ� ��������� ���Խ�Ų��

void main()
{
	
	printf("\n************* [ 2015�⵵ 2�б� �ڷᱸ�� �ǽ����� 4 ] *************\n\n");
	printf("                         1. ����� ����\n\n");
	
	CCebMatrix a,b,c; // CCebMatrix Ŭ������ ��ü a,b,c�� �����
	a.Read("���A"); // ��ü a�� ����� ũ��� ���� �о���δ�
	b.Read("���B"); // ��ü b�� ����� ũ��� ���� �о���δ�
	c.Add(a,b); // ��ü a,b ����� ���ؼ� Add �Լ��� ȣ���Ų c �ෲ�� ���� ���� �־��ش�
	a.Print(" A "); // ��ü a�� ������ ���� ���� ����Ѵ�
	b.Print(" B "); // ��ü b�� ������ ���� ���� ����Ѵ�
	c.Print("A+B"); // ��ü c�� ������ ���� ���� ����Ѵ�
	

	getchar();
	getchar(); // ���������� �Ȳ����� ����


}