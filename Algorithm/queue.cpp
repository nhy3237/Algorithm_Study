#include "queue.h"
#include <iostream>

using namespace std;

int Queue::Initialize(int max)
{
    front = 0; num = 0; rear = 0;

    if ((que = new double[max]) == NULL)
    {
        this->max = 0;
        return -1;
    }
    this->max = max;
    return 0;
}

int Queue::Enque(double x)
{
    if (num == max)
    {
        return -1;
    }
    else
    {
        que[rear] = x;
        rear++;
        num++;
        if (rear == max)
        {
            rear = 0;
        }
        return 0;
    }
}

int Queue::Deque(double* x)
{
    if (num == 0)
    {
        return -1;
    }
    *x = que[front];
    front++;
    num--;
    if (front == max)
    {
        front = 0;
    }
    return 0;
}

int Queue::Peek(double* x)
{
    if (num == 0)
    {
        return -1;
    }
    *x = que[front];
    return 0;
}

void Queue::Clear()
{
    num = 0; front = 0; rear = 0;
}

int Queue::Capacity()
{
    return max;
}

int Queue::Size()
{
    return num;
}

int Queue::IsEmpty()
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Queue::IsFull()
{
    if (num == max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Queue::Search(double x)
{
    for (int i = 0; i < num; i++)
    {
        if (que[(front + i) % max] == x)
        {
            return (front + i) % max;
        }
    }
    return -1;
}

void Queue::Print()
{
    for (int i = 0; i < num; i++)
    {
        printf("%0.2lf ", que[(front + i) % max]);
    }
    printf("\n");
}

void Queue::Terminate()
{
    if (que != NULL)
    {
        delete[] que;
    }
    max = 0; num = 0; front = 0; rear = 0;
}
