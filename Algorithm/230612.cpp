#include "queue.h"
#include "stack.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	/*
	Q3. ���� ����
		[���� ǥ��� �����]
		1. ������ �켱������ ( ) < + - < *
		2. ���� ǥ������� �� ���ھ� �о���δ�.
		3. �о���� ���ڰ� �������̸�
			- ���� ��ȣ�̸� �׳� ���ÿ� �߰�(Operator Stack)
			- ������ ��ȣ�̸� ���ÿ��� ���� ��ȣ�� ���� ������ �ϳ��� ���� ť�� �Ű��ش�.
			  ���� ��ȣ�� ������ �� �� ������.
			- ������ ��Ģ ������ �� �����ڰ� ���ÿ��� ���� �����ں���
			  �켱������ ���ų� ���� ���ȿ��� ��� ť�� �Ű��ش�.
			  �׸��� �ڽ��� ���ÿ� �߰��Ѵ�.
		4. �о���� ���ڰ� �ǿ������̸� ť�� �ִ´�. (PostFix Queue)
		
		2~4�� ������ �ݺ��ؼ� ���� ǥ����� �����. (PostFix Queue)
		
		[��� ����]
		5. ť���� �����͸� �о� �������� �ű�� (Operand Stack)
			- ť���� ���� �ϳ��� �д´�.
			- �ǿ������̸� ���ÿ� ����
			- �������̸� ���ÿ��� ���� �� �� ������ �����ڿ� ���� ������ �ϰ�
			  �� ����� �ٽ� ���ÿ� ����
			 
		ť�� ���� ���� ������ 5�� ������ �ݺ��ؼ� ���� ��� ���� ���Ѵ�. */
	char c;
	ifstream file("Calc2.txt");

	if (!file.is_open())
	{
		cout << "������ �� �� �����ϴ�." << endl;
		cout << "���α׷��� �����մϴ�.\n";
		exit(EXIT_FAILURE);
	}

	Stack s1, s2; Queue q;
	int totSize = 0, numSize = 0;

	while (!file.eof())
	{
		c = file.get();
		totSize++;

		if (isdigit(c)) numSize++;
	}
	file.close();

	s1.Initialize(totSize); s2.Initialize(totSize); q.Initialize(totSize);

	file.open("calc2.txt");
	if (!file.is_open())
	{
		cout << "������ �� �� �����ϴ�." << endl;
		cout << "���α׷��� �����մϴ�.\n";
		exit(EXIT_FAILURE);
	}

	string str, str2;
	double temp;
	int i = 0, j = 0, dotcnt = 1, chkNum = 0;
	int* num = new int[sizeof(int) * (numSize+1)]; 

 	while (!file.eof())
	{
		c = file.get();
		str += c;
		
		if (!isdigit(c) && c != '.') // ����
		{
			if (chkNum)
			{
				temp = stod(str2);
				q.Enque(temp);
				chkNum = 0;
				str2.clear();

				cout << "queue : "; q.Print();
			}

			if (c == '(' || c == '*' || c == '/')
			{
				s1.Push(c);
			}
			else if (c == ')')
			{
				s1.Peek(&temp);
				while (temp != '(')
				{
					s1.Pop(&temp);
					q.Enque(temp);
					s1.Peek(&temp);
				}
				s1.Pop(&temp);
			}
			else
			{
				if (s1.Peek(&temp) == '*' || temp == '/')
				{
					s1.Pop(&temp);
					q.Enque(temp);
				}
				s1.Push(c);
			}
		}
		else // ���ڳ� �Ҽ���
		{
			chkNum = 1;
			if (c != '.')
			{
				str2 += c;
				/*if (j > 0 && (isdigit(str[i - 1]) || str[i-1] == '.'))
				{*/
					if (dotcnt > 1)
					{
						str[i - 1] = str[i - 1] * pow(0.1, dotcnt) + str[i];
					}
					else
					{
						str[i - 1] = str[i - 1] * 10 + str[i];
					}
					str[i--] = NULL;
				/*}
				j++;*/
			}
			else
			{
				dotcnt++;
			}
		}
		i++;

		cout << "\n" << i << "��° " << c << "\nstack : "; s1.Print();
		
	}
	cout << str;
	for (int k = 0; k < j; k++)
	{
		cout << num[k] << " ";
	}
	s1.Terminate(); s2.Terminate(); q.Terminate();
	file.close();

	delete[] num;

	return 0;
}