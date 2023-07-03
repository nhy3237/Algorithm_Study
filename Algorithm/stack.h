#pragma once

class Stack
{
private:
	int max, ptr;
	double *stk;

public:
	// ���� �ʱ�ȭ
	int Initialize(int max);

	// ���ÿ� �����͸� Ǫ��
	int Push(double x);

	// ���ÿ��� �����͸� ��
	int Pop(double* x);

	// ���ÿ��� �����͸� ��ũ
	int Peek(double* x);

	// ���� ����
	void Clear();

	// ������ �ִ� �뷮
	int Capacity();

	// ������ ������ ����
	int Size();

	// ������ ��� �ֳ���?
	int IsEmpty();

	// ������ ���� á����?
	int IsFull();

	// ���ÿ��� �˻�
	int Search(double x);

	// ��� ������ ���
	void Print();

	int getS(int cnt);

	// ���� ���� 
	void Terminate();
};