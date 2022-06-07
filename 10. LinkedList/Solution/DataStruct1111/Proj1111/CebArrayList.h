#pragma once
#include<stdio.h>
#define MAX_LIST_SIZE 100 // �迭�� ũ�⸦ ����� ����
typedef int CebElement; // int �ڷ����� CebElement ���� ����

class CCebArrayList // �迭�� �̿��� ����Ʈ Ŭ���� ����
{
	CebElement m_data[MAX_LIST_SIZE]; // ���� �׸񰪵��� ����ִ� �迭
	int m_len; // ���� ����Ʈ ���� �׸���� ����

public: // ��𼭵� ������ �� �ֵ��� public ���� ����
	CCebArrayList(void){m_len = 0;} // ������, m_len�� �ʱ�ȭ
	~CCebArrayList(void){} // �Ҹ���

	bool IsEmpty(){return m_len == 0;} // ����Ʈ�� ����°� Ȯ���ϴ� �Լ�, ���� �׸��� ������ �����ϴ� ���� m_len�� 0�̸� ����Ʈ�� �������
	bool IsFull(){return m_len == MAX_LIST_SIZE;} // ����Ʈ�� ��á�°� Ȯ���ϴ� �Լ�, ���� �׸��� ������ �����ϴ� ���� m_len�� �迭�� �ִ� ũ��� ���ٸ� ����Ʈ�� �� �� �ִٴ� ����
	CebElement GetEntry(int pos){return m_data[pos];}
	// �μ��� ���� �ε����� ���� ��Ҹ� ��ȯ�ϴ� �Լ�

	int GetLength(){return m_len;} // ����Ʈ�� ���̸� ��ȯ�ϴ� �Լ�, ���� ����Ʈ ���� �׸���� ������ �����ϴ� ������ m_len�� ��ȯ�ϸ� �ȴ�
	void Clear(){m_len = 0;} // ����Ʈ�� �ִ� ��� �׸� ���� �ʱ�ȭ ��Ű�� �Լ�, ���� ����Ʈ ���� �׸���� ������ �����ϴ� ������ m_len�� 0���� �ʱ�ȭ
	void Replace(int pos,CebElement e){m_data[pos] = e;}
	// �μ��� �ε����� ���� �׸��� ���� �޾Ƽ� �� �ε����� �ش��ϴ� �迭 ���� �μ��� ���� ������ �ٲ۴�
	
	void Display(char*meg = ""){ // ����Ʈ�� �ִ� ������ ����ϴ� �Լ�
		printf("\t[%s ��ü �׸� �� = %2d] : ",meg ,m_len);
		for(int i = 0 ; i < m_len ; i ++) // �ݺ����� ����Ʈ�� ���̸�ŭ ���鼭
			printf("\t%2d ",m_data[i]);
		// �ݺ������� �ε����� ������Ű�鼭 �ε����� �ش��ϴ� �迭�� ���� ���

		printf("\n\n");
	}
	
	void Add(int pos,CebElement e){ // �׸� ���� �߰��ϴ� �Լ�
		if(!IsFull() && pos >= 0 && pos <= m_len)
			// ���� �迭�� �������� �ʰ�, �μ��� ���� �ε��� ���� 0~(����Ʈ�� ����) ���̶��
		{
			int i;
			for(i = m_len-1; i>= pos; i--) // �ݺ����� �ڿ������� �ε����� ���� pos ������ ���鼭
				m_data[i+1] = m_data[i]; // �迭�� ��ĭ�� �̷��ְ�
			m_data[pos] = e; // �μ��� ���� pos�� �ε����� �ش��ϴ� �׸� ���� �μ��� ���� �׸� e�� ����
			m_len++; // ����Ʈ�� ���̸� �����ϴ� ������ �ϳ� ������Ŵ
		}
		
	}
	void AddTail(CebElement e)// �迭�� ���� �ڿ� �׸� ���� �߰��ϴ� �Լ�
	{Add(m_len,e);} // Add�Լ��� �θ��µ�, �ε����� ���� ����Ʈ�� ������ m_len�̴� 

	void AddHead(CebElement e)// �迭�� ���� �տ� �׸� ���� �߰��ϴ� �Լ�
	{Add(0,e);}  // Add�Լ��� �θ��µ�, �ε����� ���� �迭�� ���� ó�� �ε����� 0�̴� 

	void Remove(int pos){ // �׸� ���� �����ϴ� �Լ�
	
		int i;
		CebElement item; // CebElement�� ������ �ϳ� ����

		if(pos < 0 || pos > m_len) printf("��ġ ����");
		// ���� pos�� 0���� �۰ų� m_len�� �̻��̸� ��ġ �����̹Ƿ�, �޼����� ���
		item = m_data[pos]; // �μ��� ���� �ε��� ���� �ش��ϴ� �׸��� ������ ���� item�� ����
		for(i = pos ; i< m_len-1 ; i ++) // �μ��� ���� �ε�����~����Ʈ�� ����-1���� �ݺ����� ���鼭
			m_data[i] = m_data[i+1]; // m_data�� ����ִ� �׸� ���� �մ���
		//m_data[pos] = item;
		m_len--; // ����Ʈ�� ���̸� �����ϴ� ������ �ϳ� ���ҽ�Ŵ
		
	}

	void RemoveHead() // �迭�� ���� �տ� �׸� ���� �����ϴ� �Լ�
	{Remove(0);} // Remove�Լ��� �θ��µ�, �ε����� ���� �ʱ� �ε����� 0�� 
	void RemoveTail() // �迭�� ���� �ڿ� �׸� ���� �����ϴ� �Լ�
	{Remove(m_len);} // Remove�Լ��� �θ��µ�, �ε����� ���� ����Ʈ�� ������ m_len�̴� 

};

