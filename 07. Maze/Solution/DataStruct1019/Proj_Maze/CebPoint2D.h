#pragma once
class CCebPoint2D // ��ġ�� �������ִ� Ŭ����
{
public:
	int x; // ���� ��ġ�� ���� ���� �������� ���� ���� 
	int y; // ���� ��ġ�� ���� ���� �������� ���� ����

	CCebPoint2D (int xx=0, int yy=0)  // ������
	{
		x = xx; // ���� xx�� ���� yy�� ���� ���� x,y�� ����
		y = yy;
	}

	~CCebPoint2D(void) // �Ҹ���
	{
	}
};

