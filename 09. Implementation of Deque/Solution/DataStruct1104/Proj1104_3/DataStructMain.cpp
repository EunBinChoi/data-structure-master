// ������Ʈ 3�� ���ĺ��ʹ� �߰��� ������ ���α׷�
// 3. ���� ���� �������� ���� ť ���α׷�

#include "CebLinkedQueue.h"  // ���� ť�� �����ϱ� ���� Ŭ������ ����Ǿ��ִ� ��������� ���Խ�Ų��

void main(){ 

	printf("\n***************** [ 2015�⵵ 2�б� �ڷᱸ�� �ǽ����� 9 ] *****************\n\n");
	printf("                       3. (�߰�) ���� ���� �������� ���� ť ���α׷�   \n\n");

	CCebLinkedQueue que; // ���� ť�� �����ϱ� ���� Ŭ������ ��ü ����

	printf(" CCebLinkedQueue ���� 26�� ���� => ");
	for( char i='a' ; i <= 'z' ; i++){
		que.EnQueue(new CCebNode(i)); 
		// CCebLinkedQueueŬ������ EnQueue �Լ��� ȣ���Ͽ� ���� ť�� ��带 �߰��Ѵ�
		// ���⼭ �ݺ����� ���� a~z���� �����ϸ� ����� ������ ���� �������� ����
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
	printf(" CCebLinkedQueue ��ȯ Peek() ���� => %2c", que.Peek()->GetChar() );

	getchar();
	getchar(); // exe ���������� ������ �ʰ� �ϱ⸦ ����
}