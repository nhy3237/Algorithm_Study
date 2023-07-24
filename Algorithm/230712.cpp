#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Boyer(string& str, string& fStr, int n);
void print(string& str, int n, int pin);

int main()
{
	string str, fStr;

	cout << "�ؽ�Ʈ : ";
	getline(cin, str);
	cout << "�˻� : ";
	getline(cin, fStr);
	cout << endl;

	int n = fStr.length();
	Boyer(str, fStr, n);

	return 0;
}

void Boyer(string& str, string& fStr, int n)
{
	string chk = fStr;
	int cnt1 = 0, cnt2 = 0;
	int pin = 0;
	bool match = false;

	while (match == false)
	{
		cout << cnt2 << endl;
		for (int i = 0; i < n; i++)
		{
			cout << str << endl;
			cnt1++;
			if (str[pin + i] != fStr[i])
			{
				for (int j = 0; j <= pin + i; j++)
				{
					if (j != pin + i) cout << ' ';
					else cout << '|';
				}
				cout << endl;
				match = false;
				break;
			}
			else
			{
				for (int j = 0; j <= pin + i; j++)
				{
					if (j < pin) cout << ' ';
					else cout << '+';
				}
				cout << endl;
				if (i == n - 1)
				{
					match = true;
				}
			}
			print(fStr, n, pin);
		}

		if (match == 0)
		{
			print(fStr, n, pin);
			cout << endl;
		}

		pin++;
		cnt2++;
	}

	cout << "\n�񱳸� " << cnt1 << "�� �õ��մϴ�.\n";
	cout << cnt2 << "��°�� ��ġ�մϴ�.\n";
}

void print(string& str, int n, int pin)
{
	for (int i = 0; i < pin + n; i++)
	{
		if (i < pin)
		{
			cout << " ";
		}
		else
		{
			cout << str[i - pin];
		}
	}
	cout << endl;
}