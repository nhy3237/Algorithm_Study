#pragma once
#include <iostream>

class Queue
{
private:
	int max, num, front, rear;
	double *que;

public:
	// ť �ʱ�ȭ
	int Initialize(int max);

	// ť�� �����͸� ��ť
	int Enque(double x);

	// ť���� �����͸� ��ť
	int Deque(double* x);

	// ť���� �����͸� ��ũ
	int Peek(double* x);

	// ��� ������ ����
	void Clear();

	// ť�� �ִ� �뷮
	int Capacity();

	// ť�� ����� ������ ����
	int Size();

	// ť�� ��� �ִ°�?
	int IsEmpty();

	// ť�� ���� á�°�?
	int IsFull();

	// ť���� �˻�
	int Search(double x);

	// ��� ������ ���
	void Print();

	// ť ����
	void Terminate();
};