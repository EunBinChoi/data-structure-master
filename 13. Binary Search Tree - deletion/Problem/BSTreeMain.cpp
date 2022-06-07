#include "BinSrchTree.h"

void main()
{
	printf("\n******************* [ 2015년도 2학기 자료구조 실습과제 13 ] *******************\n\n");
	printf("                             1. 이진탐색트리 프로그램   \n\n");

	CBinSrchTree t;

	t. AddNode(4);
	t. AddNode(5);
	t. AddNode(2);
	t. AddNode(1);
	t. AddNode(3);
	t. AddNode(6);
	t. AddNode(7);
	
	t.PrintPreOrder();
	t.PrintInOrder();
	t.PrintPostOrder();

	printf("------------------------         [ t.Find(7) ]         ------------------------\n\n");
	t.Find(7);

	printf("------------------------         [ t.Find(7) ]         ------------------------\n\n");
	t.Find(390);

		t.DeleteNode(4);
	t.PrintPreOrder();
	t.PrintInOrder();
	t.PrintPostOrder();	
	printf("------------------------      [ t.DeleteNode(3) ]      ------------------------\n\n");
	t.DeleteNode(3);
	t.PrintPreOrder();
	t.PrintInOrder();
	t.PrintPostOrder();	
	printf("------------------------      [ t.DeleteNode(5) ]      ------------------------\n\n");
	t.DeleteNode(5);
	t.PrintPreOrder();
	t.PrintInOrder();
	t.PrintPostOrder();	
	printf("------------------------      [ t.DeleteNode(2) ]      ------------------------\n\n");
	t.DeleteNode(2);
	t.PrintPreOrder();
	t.PrintInOrder();
	t.PrintPostOrder();	
	printf("------------------------      [ t.DeleteNode(1) ]      ------------------------\n\n");
	t.DeleteNode(1);
	t.PrintPreOrder();
	t.PrintInOrder();
	t.PrintPostOrder();	
	printf("------------------------      [ t.DeleteNode(7) ]      ------------------------\n\n");
	t.DeleteNode(7);
	t.PrintPreOrder();
	t.PrintInOrder();
	t.PrintPostOrder();
	printf("------------------------      [ t.DeleteNode(6) ]      ------------------------\n\n");
	t.DeleteNode(6);
	t.PrintPreOrder();
	t.PrintInOrder();
	t.PrintPostOrder();
	printf("------------------------      [ t.DeleteNode(4) ]      ------------------------\n\n");
	t.DeleteNode(4);
	t.PrintPreOrder();
	t.PrintInOrder();
	t.PrintPostOrder();


	getchar();
}
