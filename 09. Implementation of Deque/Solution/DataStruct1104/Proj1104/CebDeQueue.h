#pragma once
#include "CebQueue.h"
class CCebDeQueue : // ����� �̿��� CCebDeQueue Ŭ����(�ڽ� Ŭ����)
   public CCebQueue // CCebQueue Ŭ����(ť�� �����ϴµ� �ʿ��� �⺻���� �Լ��� ������ ��� Ŭ����)�� ��ӹ޴´�(�θ� Ŭ����)
{
public:

   CCebDeQueue(void){} // ������
   ~CCebDeQueue(void){} // �Ҹ���

   void AddRear(int i ) { EnQueue(i);} // ��ũ�� �����ϴ� �迭�� �ڿ� ���(i)�� �߰�(���⼭�� �迭�� ��Ҹ� �߰��ϴ� �Լ��� EnQueue ȣ��(CCebQueue�� ���ǵǾ�����))
   bool AddFront(int i) { // ��ũ�� �����ϴ� �迭�� �տ� ���(i)�� �߰�(�迭�� �տ� �߰��ϴ� �Լ��� CCebQueue �� Ŭ�������� ���ǵǾ� ���� ����)
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

   int DelFront() // ��ũ�� �����ϴ� �迭�� ���� �տ� ��Ҹ� ���� 
   {
	   return DeQueue(); // ��ũ�� �����ϴ� �迭�� �տ� ��Ҹ� ����(���⼭�� �迭�� ��Ҹ� �����ϴ� �Լ��� DeQueue ȣ��(CCebQueue�� ���ǵǾ�����))
   } 

   int DelRear() { // ��ũ�� �����ϴ� �迭�� ���� �ڿ� ��Ҹ� ����
      if(IsEmpty()) { // ���� ��ũ�� ��� �ִٸ�
         printf("���� ��� �ֽ��ϴ�.\n");
         return -1 ;
      }

	  int ret = m_data[m_rear]; // ���� �ֱٿ� ���Ե� ��ġ�� m_rear ��ġ�� �ش��ϴ� ���� ���� ret�� �����ϰ�
      m_rear = (m_rear-1+MaxQueueSize) % MaxQueueSize; // ���� �ֱٿ� ���Ե� ��ġ m_rear�� �ٽ� �������� ����

      return ret; // �� ���� ���� ��ȯ
   }

   int GetFront() {return Peek();} // ��ũ�� �����ϴ� �迭�� ���� �տ� ��Ҹ� ��ȯ
   // (���⼭�� �迭�� ��Ҹ� ��ȯ�ϴ� �Լ��� Peek ȣ��(CCebQueue�� ���ǵǾ�����))

  
   int GerRear() { // ��ũ�� �����ϴ� �迭�� ���� �ڿ� ��Ҹ� ��ȯ
   if(IsEmpty()) { // ���� ��ũ�� ��� �ִٸ�
         printf("���� ��� �ֽ��ϴ�.\n");
         return -1 ;
      }
      return m_data[m_rear]; // ���� �ֱٿ� ���Ե� ��ġ�� ����Ű�� m_rear�� ��ġ�� �ش��ϴ� ���Ұ��� ��ȯ
   }
};
