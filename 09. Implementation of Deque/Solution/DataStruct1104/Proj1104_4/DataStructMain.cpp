// ������Ʈ 3�� ���ĺ��ʹ� �߰��� ������ ���α׷�
// 4. ��ũ�� ������ ���� �� ���α׷�

#include "CebLinkedDeque.h"  // ���� ���� �����ϱ� ���� Ŭ������ ����Ǿ��ִ� ��������� ���Խ�Ų��

void main(){ 

	printf("\n***************** [ 2015�⵵ 2�б� �ڷᱸ�� �ǽ����� 9 ] *****************\n\n");
	printf("                       4. (�߰�) ��������ͷ� ������ ���� �� ���α׷�   \n\n");

	CCebLinkedDeque que; // ���� ���� �����ϱ� ���� Ŭ������ ��ü ����

	printf(" CCebLinkedDeque �Ĵ� ���� 8�� ���� => ");

	for( int i = 9 ; i < 17 ; i++){
		que.AddRear(new CCebNode(i)); // CCebLinkedDequeŬ������ AddRear �Լ��� ȣ���Ͽ� �Ĵܻ����� �Ѵ�
	}
	que.Display(); // Display �Լ��� ȣ���Ͽ� ���� ���� ����Ѵ�
	printf("\n");


	printf(" CCebLinkedDeque ���� ���� 8�� ���� => ");

	for( int i = 1 ; i < 9 ; i++){
		que.AddFront(new CCebNode(i)); // CCebLinkedDequeŬ������ AddFront �Լ��� ȣ���Ͽ� ���ܻ����� �Ѵ�
	}
	que.Display(); // Display �Լ��� ȣ���Ͽ� ���� ���� ����Ѵ�
	printf("\n");

	printf(" CCebLinkedDeque ���� ���� 3�� ���� => ");
	CCebNode* n; // CCebNode*�� ������ �ϳ� ������ ��
	n = que.DeleteFront();  delete n; // CCebLinkedDequeŬ������ DeleteFront �Լ��� ȣ���Ͽ� ���ܻ����� �ϰ� �� ��ȯ���� delete �� ���� �����Ѵ�
	n = que.DeleteFront();  delete n; // CCebLinkedDequeŬ������ DeleteFront �Լ��� ȣ���Ͽ� ���ܻ����� �ϰ� �� ��ȯ���� delete �� ���� �����Ѵ�
	n = que.DeleteFront();  delete n; // CCebLinkedDequeŬ������ DeleteFront �Լ��� ȣ���Ͽ� ���ܻ����� �ϰ� �� ��ȯ���� delete �� ���� �����Ѵ�

	que.Display(); // Display �Լ��� ȣ���Ͽ� ���� ���� ����Ѵ�
	printf("\n");

	printf(" CCebLinkedDeque �Ĵ� ���� 3�� ���� => ");
	n = que.DeleteRear();  delete n; // CCebLinkedDequeŬ������ DeleteRear �Լ��� ȣ���Ͽ� �Ĵܻ����� �ϰ� �� ��ȯ���� delete �� ���� �����Ѵ�
	n = que.DeleteRear();  delete n; // CCebLinkedDequeŬ������ DeleteRear �Լ��� ȣ���Ͽ� �Ĵܻ����� �ϰ� �� ��ȯ���� delete �� ���� �����Ѵ�
	n = que.DeleteRear();  delete n; // CCebLinkedDequeŬ������ DeleteRear �Լ��� ȣ���Ͽ� �Ĵܻ����� �ϰ� �� ��ȯ���� delete �� ���� �����Ѵ�

	que.Display(); // Display �Լ��� ȣ���Ͽ� ���� ���� ����Ѵ�
	printf("\n");
	
	getchar();
	getchar(); // exe ���������� ������ �ʰ� �ϱ⸦ ����
}