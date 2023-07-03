#include "stack.h"
#include <iostream>

using namespace std;

int Stack::Initialize(int max)
{
	ptr = 0;
	if ((stk = new double[max]) == NULL)
	{
		this->max = 0;
		return -1;
	}
	this->max = max;
	return 0;
}

int Stack::Push(double x)
{
	if (ptr == max)
	{
		return -1;
	}
	stk[ptr] = x;
	ptr++;
	return 0;
}

int Stack::Pop(double* x)
{
	if (ptr == 0)
	{
		return -1;
	}
	*x = stk[--ptr];
	return 0;
}

int Stack::Peek(double* x)
{
	if (ptr == max)
	{
		return -1;
	}
	*x = stk[ptr - 1];
}

void Stack::Clear()
{
	ptr = 0;
}

int Stack::Capacity()
{
	return max;
}

int Stack::Size()
{
	return ptr;
}

int Stack::IsEmpty()
{
	return ptr == 0;
}

int Stack::IsFull()
{
	return  ptr == max;
}

int Stack::Search(double x)
{
	for (int i = ptr - 1; i >= 0; i--)
	{
		if (stk[i] == x)
		{
			return i;
		}
		return -1;
	}
}

void Stack::Print()
{
	for (int i = 0; i < ptr; i++)
	{
		printf("%d ", (int)stk[i]);
	}
	printf("\n");
}

int Stack::getS(int cnt)
{
	if (cnt > ptr - 1)
	{
		return NULL;
	}
	return stk[cnt];
}

void Stack::Terminate()
{
	if (stk != NULL)
	{
		delete[] stk;
	}
	max = 0;
	ptr = 0;
}
