#pragma once
#include <stdio.h>
const int MaxQueueSize = 10; // ��ũ�� �ִ� ũ��
class CCebDeque // ����� �̿����� ���� ��ũ CCebDeque Ŭ����
{
	int m_front; // ���� �ֱٿ� ������ ��ġ
	int m_rear; // ���� �ֱٿ� ���Ե� ��ġ
	int m_data[MaxQueueSize]; // �迭�� ������ ��ũ
public:

	CCebDeque(void)   {m_front = m_rear = 0;} // ������, ���� �ֱٿ� ������ ��ġ�� ���� �ֱٿ� ���Ե� ��ġ�� 0���� �ʱ�ȭ
	~CCebDeque(void) {} // �Ҹ���

	bool IsEmpty() {return m_front == m_rear;} // ��ũ�� �����ϴ� �迭�� ��� �ִ����� �˻��Ѵ�(front�� rear�� ���� ��ġ�� ����Ŵ -> �������)
	bool IsFull() {return m_front == (m_rear+1) % MaxQueueSize;} // ��ũ�� �����ϴ� �迭�� ���� á������ �˻��Ѵ�(front�� rear���� �ϳ� �տ� ������ -> ��ȭ����)

	void Display() { // ���� ��ũ ���� ������ ���
		if(!IsEmpty()) { // ���� ��ũ�� ��� ���� �ʴٸ�
			int from = m_front+1; // ���� �ֱٿ� ������ ��ġ���� �ϳ� �տ�������
			int to = m_rear; // ���� �ֱٿ� ���Ե� ��ġ����
			if(from > to) to += MaxQueueSize; // ���� from�� to���� ū ���̶�� to�� �迭 �ִ� �ε��� ũ�⸦ ������
			printf("  �� ���� : ");
			for(; from <= to ; from++) // from���� to����
				printf("%2d ", m_data[from % MaxQueueSize]); // ��ũ ���� ������ ���
		}
		printf("\n"); // �ٹٲ�
	}

	bool AddRear(int i) { // ��ũ�� �����ϴ� �迭�� �ڿ� ���(i)�� �߰�
		if(IsFull()) { // ���� ��ũ�� ���� ���ִٸ�
			printf("���� ���� �� �ֽ��ϴ�.\n");
			return false;
		}
		m_rear++; // ��ũ�� �����ϴ� �迭�� �ڿ� ��Ҹ� �߰��ϴ� ���̹Ƿ�, ���� �ֱٿ� ���Ե� ��ġ�� m_rear�� �ϳ� ����
		m_rear = m_rear % MaxQueueSize; // ���� �迭�� �ִ�ũ�⺸�� �Ѿ �� �����Ƿ� �ִ� ũ�⸦ �������
		m_data[m_rear] = i; // �� ��ġ�� �μ��� �޾ƿ� ���(i)�� ����
	}

	bool AddFront(int i) { // ��ũ�� �����ϴ� �迭�� �տ� ���(i)�� �߰�
		if(IsFull()) { // ���� ��ũ�� ���� ���ִٸ�
			printf("���� ���� �� �ֽ��ϴ�.\n");
			return false;
		}
		m_data[m_front] = i; // ���� �ֱٿ� ������ ��ġ�� m_front���� �迭�� ��������Ƿ� �� ���� �μ��� �޾ƿ� ���(i)�� �߰�
		m_front = (m_front-1+MaxQueueSize) % MaxQueueSize;
		// �׸��� ���� �ֱٿ� ������ ��ġ�� ���� �ٲ��ش�. ���� 1�� ���ҽ�Ų ��, �̰� ���� ���� �� �����Ƿ� �迭�� ũ�⸦ ������ش�

		// ���� ���� �ڵ�
		// m_front--; //���Ե� ��ġ ī��Ʈ
		// if( m_front < 0 ) m_front = MaxQueueSize - 1;

	}

	int DelFront() { // ��ũ�� �����ϴ� �迭�� ���� �տ� ��Ҹ� ���� (���蹮��)
		if(IsEmpty()) { //���� ��ũ�� ��� �ִٸ�
			printf("���� ��� �ֽ��ϴ�.\n");
			return -1 ;
		}
		m_front++; // �迭�� ���� �տ� ��� ��ġ�� ��������
		m_front = m_front % MaxQueueSize; // ���� ť �迭�� �ִ� ũ�� �������
		return m_data[m_front]; // �� ��ġ�� �ش�Ǵ� ���� ���� ��ȯ
	}

	int DelRear() { // ��ũ�� �����ϴ� �迭�� ���� �ڿ� ��Ҹ� ���� (���蹮��)
		if(IsEmpty()) { // ���� ��ũ�� ��� �ִٸ�
			printf("���� ��� �ֽ��ϴ�.\n");
			return -1 ;
		}

		int ret = m_data[m_rear]; // ���� �ֱٿ� ���Ե� ��ġ�� m_rear ��ġ�� �ش��ϴ� ���� ���� ret�� �����ϰ�
		m_rear = (m_rear-1+MaxQueueSize) % MaxQueueSize; // ���� �ֱٿ� ���Ե� ��ġ m_rear�� �ٽ� �������� ����

		return ret; // �� ���� ���� ��ȯ
	}

	int GetFront() { // ��ũ�� �����ϴ� �迭�� ���� �տ� ��Ҹ� ��ȯ
		if(IsEmpty()) { // ���� ��ũ�� ��� �ִٸ�
			printf("���� ��� �ֽ��ϴ�.\n");
			return -1 ;
		}
		return m_data[(m_front+1)%MaxQueueSize]; // ���� �տ� ��Ҹ� ����ų �� �ֵ��� �ε����� ���� ���� �ѵ�, �� �ε����� �ش��ϴ� ���Ҹ� ��ȯ
		// ���⼭ ���� DelFront�� �ٸ� ���� �� ���� m_front �� ��ü�� �ٲ��� �ʴ´ٴ� ���̴�
	}

	int GerRear() { // ��ũ�� �����ϴ� �迭�� ���� �ڿ� ��Ҹ� ��ȯ
		if(IsEmpty()) { // ���� ��ũ�� ��� �ִٸ�
			printf("���� ��� �ֽ��ϴ�.\n");
			return -1 ;
		}
		return m_data[m_rear]; // ���� �ֱٿ� ���Ե� ��ġ�� ����Ű�� m_rear�� ��ġ�� �ش��ϴ� ���Ұ��� ��ȯ
	}
};
