#include <iostream>
using namespace std;

void Bubble1(int* arr, int n);
void Print(int* arr, int n, int , bool chkChange);

int main()
{
	int n;

	cout << "요소의 개수 : ";
	cin >> n;
	int* arr = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		cout << "x[" << i << "] : ";
		cin >> arr[i];
	}
	
	Bubble1(arr, n);

	delete[]arr;

	return 0;
}

void Bubble1(int* arr, int n)
{
	int temp, count = 1;
	bool chkChange;

	for (int i = 0; i < n; i++)
	{
		cout << "패스" << count << ":" << endl;

		for (int j = n - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				chkChange = true;
			}
			else chkChange = false;

			Print(arr, n, j - 1, chkChange);
		}
		count++;
	}
}

void Print(int* arr, int n, int sign, bool chkChange)
{
	for (int i = 0; i < n; i++)
	{
		if (i == sign)
		{
			cout << arr
		}
		cout << arr[i];
	}
}
