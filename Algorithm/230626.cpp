#include <iostream>
using namespace std;

void shell(int* arr, int n); // 정렬 
void print(int* arr, int n);
void mark(int n, int sel, int change);

int main()
{
	int arr[8] = { 8,1,4,2,7,6,3,5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	shell(arr, n);
	print(arr, n);
}

void shell(int* arr, int n)
{
	int h;
	if (n % 2 == 1)
	{
		h = n / 2 + 1;
	}
	else
	{
		h = n / 2;
	}

	for (int i = h; i > 0; i = i / 2)
	{
		cout << "\n<" << i << "-정렬>\n";
		for (int j = 0; j < n; j++)
		{
			int cnt = j;
			print(arr, n);
			if (j + i >= n) break;
 			for (int k = j; k < n; k = k + i)
			{
				if (k + i >= n) break;
				else if (arr[cnt] < arr[k + i]) continue;
				else
				{
					int temp = arr[cnt];
					arr[cnt] = arr[k + i];
					arr[k + i] = temp;
					cnt = k + i;
				}
			}
			print(arr, n);
			cout << endl;
		}
	}
}

void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void mark(int n, int sel, int change)
{
	for (int i = 0; i < n; i++)
	{
		if (i == sel) cout << "+";
		else if (i == change) cout << "^-";
		else if (i < sel && i > change) cout << "--";
		else cout << "  ";
	}
	cout << endl;
}