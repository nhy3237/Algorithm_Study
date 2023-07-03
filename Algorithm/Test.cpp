#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T; // 테스트케이스 개수
	int N; // 수첩 1의 정수 개수
	int M; // 수첩 2의 정수 개수

	cin >> T;

	for (int j = 0; j < T; j++)
	{
		cin >> N;
		int* arr1 = new int[N];
		for (int i = 0; i < N; i++)
		{
			cin >> arr1[i];
		}
		sort(arr1, arr1 + N);

		cin >> M;
		int* arr2 = new int[M];
		for (int i = 0; i < M; i++)
		{
			cin >> arr2[i];
		}

		for (int i = 0; i < M; i++)
		{
			if (binary_search(arr1, arr1 + N, arr2[i]))
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		delete[] arr1;
		delete[] arr2;
	}

	return 0;
}