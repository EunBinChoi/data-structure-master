#include "CebQueue.h"
// ����ť�� �����ϱ� ���� �⺻������ �ʿ��� ����Լ��� ��������� ������ �ִ� Ŭ������ ���ǵǾ��ִ� ��� ����

void main()
{

	CCebQueue q; // ����ť�� �����ϱ� ���� �⺻������ �ʿ��� ����Լ��� ��������� ������ �ִ� Ŭ������ ��ü q�� ������ش�
	for(int i = 0 ; i < 10; i ++) // �ݺ����� 0~9���� ���鼭
	{
		q.EnQueue(i); // CCebQueue Ŭ������ ���ǵǾ��ִ� EnQueue �Լ��� �̿��� ���� �����Ѵ�
	}

	q.Display(); // CCebQueue Ŭ������ ���ǵǾ��ִ� Display �Լ��� �̿��� ���� ����Ѵ�
	// 0 1 2 3 4 5 6 7 8 
	q.DeQueue(); // CCebQueue Ŭ������ ���ǵǾ��ִ� DeQueue �Լ��� �̿��� ���� �����Ѵ�
	q.DeQueue();
	q.DeQueue();
	q.Display();
	// 3 4 5 6 7 8
	q.DeQueue(); // 3 ����
	q.DeQueue(); // 4 ����
	q.DeQueue(); // 5 ����
	q.DeQueue(); // 6 ����
	q.DeQueue(); // 7 ����
	q.DeQueue(); // 8 ����
	q.DeQueue();
	q.DeQueue();
	q.DeQueue();
	q.Display(); 
	// ����� ����ť�� ���Ұ� ����

	getchar();
	getchar(); // exe ������ ������ �ʰ� �ϱ� ����
}