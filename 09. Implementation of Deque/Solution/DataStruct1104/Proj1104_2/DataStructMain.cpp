// ���� ť ����
#include "CebLinkedQueue.h"  // ���� ť�� �����ϱ� ���� Ŭ������ ����Ǿ��ִ� ��������� ���Խ�Ų��

void main(){ 

	printf("\n***************** [ 2015�⵵ 2�б� �ڷᱸ�� �ǽ����� 9 ] *****************\n\n");
	printf("                       2. ���� ť �׽�Ʈ ���α׷�   \n\n");

	CCebLinkedQueue que; // ���� ť�� �����ϱ� ���� Ŭ������ ��ü ����

	printf(" CCebLinkedQueue ���� 8�� ���� => ");
	for( int i=1 ; i < 9 ; i++){
		que.EnQueue(new CCebNode(i)); // CCebLinkedQueueŬ������ EnQueue �Լ��� ȣ���Ͽ� ���� ť�� ��带 �߰��Ѵ�
	}
	que.Display(); // Display �Լ��� ȣ���Ͽ� ���� ���� ����Ѵ�
	printf("\n");
	
	printf(" CCebLinkedQueue ���� 3�� ���� => ");
	CCebNode* n; // CCebNode* �� ������ �ϳ� �����Ѵ�(�̴� DeQueue �Լ����� ��ȯ�� ���� ����)
	n = que.DeQueue(); delete n; // DeQueue �Լ����� ��ȯ�� ���� n�� �����ϰ� �� ���� delete �Լ��� ����
	n = que.DeQueue(); delete n; // DeQueue �Լ����� ��ȯ�� ���� n�� �����ϰ� �� ���� delete �Լ��� ����
	n = que.DeQueue(); delete n; // DeQueue �Լ����� ��ȯ�� ���� n�� �����ϰ� �� ���� delete �Լ��� ����

	que.Display(); // Display �Լ��� ȣ���Ͽ� ���� ���� ����Ѵ�
	printf("\n");
	printf(" CCebLinkedQueue ��ȯ Peek() ���� => %2d", que.Peek()->GetInt() );

	getchar();
	getchar(); // exe ���������� ������ �ʰ� �ϱ⸦ ����
}