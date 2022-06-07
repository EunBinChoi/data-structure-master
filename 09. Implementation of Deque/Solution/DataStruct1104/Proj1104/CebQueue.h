#pragma once
#include <stdio.h>
//const int MaxQueueSize = 10; //ť�� �ִ� ũ��
//#define MAX_QUEUE_SIZE 10 //���� ���� �ڵ�

class CCebQueue // ť�� �����ϴµ� �ʿ��� �⺻���� �Լ��� ������ ��� Ŭ����
{

protected:

   int m_front; // ���� �ֱٿ� ������ ��ġ
   int m_rear; // ���� �ֱٿ� ���Ե� ��ġ
   int m_data[MaxQueueSize]; // �迭�� ������ ť

public:

   CCebQueue(void)   {m_front = m_rear = 0;} // ������, ���� �ֱٿ� ������ ��ġ�� ���� �ֱٿ� ���Ե� ��ġ�� �����ϴ� front�� rear�� 0���� �ʱ�ȭ
   ~CCebQueue(void) {} // �Ҹ���
   bool IsEmpty() {return m_front == m_rear;} // ť�� ��� �ִ����� �˻��Ѵ�(front�� rear�� ���� ��ġ�� ����Ŵ -> �������)
   bool IsFull() {return m_front == (m_rear+1)%MaxQueueSize;} //ť�� ���� á������ �˻��Ѵ�(front�� rear���� �ϳ� �տ� ������ -> ��ȭ����)

   bool EnQueue(int i) { // ť�� ���� �ڿ� ���(i)�� �߰�
      if(IsFull()) { // ���� ť�� ���� ���ִٸ�
         printf("ť�� ���� �� �ֽ��ϴ�.\n");
         return false;
      }

      m_rear++; // ť�� ���� �ڿ� ��Ҹ� �߰��ϱ� ���ؼ� ���� �ֱٿ� ���Ե� ��ġ�� �����ϴ� m_rear �� �ϳ� ������Ų��
      m_rear = m_rear % MaxQueueSize; // ���� ť �迭�� �ִ� ũ�� �������
      m_data[m_rear] = i; // ���� �ֱٿ� ���Ե� ��ġ�� �����ϴ� m_rear�� �ϳ� ������Ų ��ġ�� �迭�� �μ��� �޾ƿ� i ���� ����
   }


   int DeQueue() { // ť�� ���� �տ� �ִ� ��Ҹ� ����
      if(IsEmpty()) { // ���� ť�� ��� �ִٸ�
         printf("ť�� ��� �ֽ��ϴ�.\n");
         return -1 ;
      }
      m_front++; // ���� �ֱٿ� ������ ��ġ�� m_front�� �ϳ� ������Ų��(�ֳ��ϸ� ť�� ���� �տ� �ִ� ��Ҹ� �����ϱ� ����// ���� ť �迭�� �ִ� ũ�� �������)
      m_front = m_front % MaxQueueSize; // ���� ť �迭�� �ִ� ũ�� �������
      return m_data[m_front]; // ���� �ֱٿ� ������ ��ġ�� �����ϴ� m_front�� �ϳ� ������Ų ��ġ�� �迭�� ���� ���� ��ȯ�Ѵ�
   }

   int Peek() { // ť���� �������� �ʰ� ���� �տ� �ִ� ���� ��ȯ
      if(IsEmpty()) { // ���� ť�� ��� �ִٸ�
         printf("ť�� ��� �ֽ��ϴ�.\n");
         return -1 ;
      }
      return m_data[(m_front+1)%MaxQueueSize]; // ���� �տ� �ִ� ���� ���� ���� �ʰ� ��ȯ(���⼭ DeQueue�� �ٸ� ���� m_front ���� ������ �ʴ´ٴ� ���̴�)
   }

   void Display() { // ���� ť ���� �����͸� ���
      if(!IsEmpty()) { // ���� ť�� ��� ���� �ʴٸ�
         int from = m_front+1; // ���� �ֱٿ� ������ ��ġ���� �ϳ� �տ�������
         int to = m_rear; // ���� �ֱٿ� ���Ե� ��ġ����
         if(from > to) to += MaxQueueSize; // ���� from�� to���� ū ���̶�� to�� �迭 �ִ� �ε��� ũ�⸦ ������
		 printf("  �� ���� : ");
		 for(; from <= to ; from++) // from���� to���� from�� ������Ű�鼭 
            printf("%2d ", m_data[from % MaxQueueSize]); // ť ���� ���(������) ���
      }
      printf("\n"); //�ٹٲ�
   }

};
