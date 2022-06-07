#include "CebLinkedList.h"

void main() {

	printf("\n******************* [ 2015�⵵ 2�б� �ڷᱸ�� �ǽ����� 10 ] *******************\n\n");
	printf("                          2. Wish List ���� ���α׷�   \n\n");

	printf("-------------------         Addtail 2ȸ, AddHead 2ȸ        -------------------\n\n");
	
	CCebLinkedList list1; // CLinkedList Ŭ������ list1 ��ü ����
	list1.AddTail(new CCebItemNode("����", 8000000, 4, "����ī���")); // list1�� ������ ��ġ�� ����Ʈ �߰�
	list1.AddTail(new CCebItemNode("��Ʈ��", 9500000, 5, "���⿡")); // list1�� ������ ��ġ�� ����Ʈ �߰�
	list1.AddHead(new CCebItemNode("�Ȱ�", 150000, 2, "�����޿�"));	// list1�� �� ó�� ��ġ�� ����Ʈ �߰�
	list1.AddHead(new CCebItemNode("�Ź�", 100000, 1));	// list1�� �� ó�� ��ġ�� ����Ʈ �߰�
	list1.Display( "list1 " ); // list1�� ����Ʈ ��ü ���

	printf("-------------------   �켱�������� 2�� ��� Ž�� & AddNext  -------------------\n\n");
	CCebItemNode *n = list1.FindNodePriority( 2 ); // list1�� �켱�������� 2�� ��� Ž��
	list1.AddNext(n, new CCebItemNode("����", 100000, 3, "12�� ����"));	// list1�� �켱�������� 2�� ��� �ڿ� ���ο� ��� ����
	list1.Display( "list1 " ); // list1�� ����Ʈ ��ü ���		

	printf("-------------- RemoveHead() , �켱�������� 2�� ��� Ž�� & ���� ---------------\n\n");
	list1.RemoveHead();	// list1�� ����Ʈ �� �� ��� ����
	n = list1.FindNodePriority( 2 ); // list1�� �켱�������� 2�� ��� Ž��
	list1.Remove( n ); // list1�� Remove �Լ��� ȣ���Ͽ� �μ��� ���� n�� ��� ����
	list1.Display( "list1 " ); // list1�� ����Ʈ���� ȭ�����
	
	printf("-------------- Clear() , ����Ʈ Ŭ���� -----------------------------------------\n");
	list1.Clear(); // list1 ����Ʈ�� ��� ��� ����
	list1.Display( "list1 " ); // list1 ����Ʈ���� ȭ�����
	
	printf("-------------- (�߰�) Merge() , �μ��� ���� ���� ����Ʈ�� �ڿ��� �����ϱ� ---\n\n");
	CCebLinkedList list2; // CLinkedList Ŭ������ list2 ��ü ����
	list2.AddTail(new CCebItemNode("����2", 8000000, 6, "����ī���"));	// list2�� ������ ��ġ�� ����Ʈ �߰�
	list2.AddTail(new CCebItemNode("��Ʈ��2", 9500000, 7, "���⿡")); // list2�� ������ ��ġ�� ����Ʈ �߰�
	list2.AddHead(new CCebItemNode("�Ȱ�2", 150000, 2, "�����޿�")); // list2�� �� ó�� ��ġ�� ����Ʈ �߰�
	list2.AddHead(new CCebItemNode("�Ź�2", 100000, 1)); // list2�� �� ó�� ��ġ�� ����Ʈ �߰�	
	list2.Display( "list2 " ); // list2�� list2�� ����Ʈ���� ȭ�����

	list1.AddTail(new CCebItemNode("���콺", 700000, 8, "����ī���"));
	list1.Display( "list1 " ); // list2�� list2�� ����Ʈ���� ȭ�����
	list1.Merge(list2); // ����Ʈ list1�� list2�� ���ս�Ű�� �� �ڿ��� ���� ���ս�Ŵ
	list1.Display( "list1 " );	// list1���� list2�� ���ս�Ų ����Ʈ�� ��µ�
	list2.Display( "list2 " ); // list2�� ������ �� �ƹ��͵� ���� ���� ����Ʈ�� ��µ�
	printf("\n");
	

	printf("-------------- (�߰�) HeadMerge() , �μ��� ���� ���� ����Ʈ�� �տ��� �����ϱ� --\n\n");
	list2.AddTail(new CCebItemNode("����ȸ��", 8000000, 9, "�̹���������"));	// list2�� ������ ��ġ�� ����Ʈ �߰�
	list2.AddTail(new CCebItemNode("ħ��", 9500000, 10, "�����޿�")); // list2�� ������ ��ġ�� ����Ʈ �߰�
	list1.Display( "list1 " );	// list1 ����Ʈ �׸� ���
	list2.Display( "list2 " ); // list2 ����Ʈ �׸� ���
	list1.HeadMerge(list2); // ����Ʈ list1�� list2�� ���ս�Ű�� �� �տ������� ���ս�Ŵ
	list1.Display("list1 " ); // ���յ� list1�� ����Ʈ���� ȭ�����
	list2.Display( "list2 " ); // list2�� ������ �� �ƹ��͵� ���� ���� ����Ʈ�� ��µ�
	printf("\n");

	printf("-------------- (�߰�) Reverse() , �ܼ� ���� ����Ʈ �ݴ�� ����ϱ� -------------\n\n");
	list1.Reverse(); // list1�� �ݴ�� ����ϴ� �Լ� Reverse �Լ��� ���
	list1.Display("list1 " ); // list1�� ����Ʈ���� ȭ�����

	
	
	printf("-------------- (�߰�) PriorityArrange() , �켱������ ���� �ͺ��� ��� ---------\n\n");
	list1.PriorityArrange(); // �켱������ ���� �ͺ��� ����ϴ� �Լ�
	list1.Display("list1 " ); // list�� ����Ʈ ���� ȭ�� ���
	
	printf("--------------    (�߰�) FindNodeName() \n\t  �̸����� ��� Ž�� && �ش� ��� ���� --------------------------------\n\n");
	n = list1.FindNodeName( "��Ʈ��2" ); // list1�� �̸��� "��Ʈ��2"�� ��� Ž��
	list1.Remove( n ); // list1�� Remove �Լ��� ȣ���Ͽ� �μ��� ���� n�� ��� ����
	list1.Display( "list1 " ); // list1�� ����Ʈ���� ȭ�����
	
	printf("--------------    (�߰�) FindNodePrice() \n\t  �������� ��� Ž�� && �ش� ��� ���� --------------------------------\n\n");
	n = list1.FindNodePrice( 150000 ); // list1�� ������ 150000�� ��� Ž��
	list1.Remove( n ); // list1�� Remove �Լ��� ȣ���Ͽ� �μ��� ���� n�� ��� ����
	list1.Display( "list1 " ); // list1�� ����Ʈ���� ȭ�����

	printf("--------------    (�߰�) FindNodeMethod() \n\t  ��¹������ ��� Ž�� && �ش� ��� ���� -----------------------------\n\n");
	n = list1.FindNodeMethod( "..." ); // list1�� ��¹���� "����ī���"�� ��� Ž��
	list1.Remove( n ); // list1�� Remove �Լ��� ȣ���Ͽ� �μ��� ���� n�� ��� ����
	list1.Display( "list1 " ); // list1�� ����Ʈ���� ȭ�����

	printf("-------------- (�߰�) PrintPriceRange() , min max ���̿� ������ ��ǰ��� -------\n\n");
	list1.AddTail(new CCebItemNode("����", 300000, 2, "����ī���"));	// list1�� ������ ��ġ�� ����Ʈ �߰�
	list1.AddTail(new CCebItemNode("�ڵ���", 9500000, 3, "���⿡")); // list1�� ������ ��ġ�� ����Ʈ �߰�
	list1.Display( "list1 " ); // list1�� ����Ʈ���� ȭ�����

	int min,max; // �ּҿ� �ִ밪�� ������ ������ ��������
	printf("�ּ�, �ִ밪�� �Է��ϼ��� (��:<300000 500000>) : ");
	scanf("%d %d",&min,&max); // ����ڿ��� �ּҰ��� �ִ밪�� �Է¹���
	printf("\n");

	list1.PrintPriceRange(min,max); // �ּҰ��� �ִ밪 ���̿� �ִ� �׸���� ���

	getchar();
	getchar(); // exe ���������� ������ �ʱ� ����


}
