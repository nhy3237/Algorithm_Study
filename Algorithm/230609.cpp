#include <iostream>
#include <string>

using namespace std;

void reverseDisplay(int value);
void reverseDisplay(const string &s);

int cnt = 1;

int main()
{
	/*
	Q3. ���� �Լ��� ����Ͽ� ���� ������ ȭ�鿡 ����ϴ� �ڵ带 �ۼ��϶�.
		���ȣ���� �̿��϶�.

		void reverseDisplay(int value)
		void reverseDisplay(const string &s)

		ex > reverseDisplay(12345)
		��� > 54321
		
		ex > reverseDisplay("abcd")
		��� > dcba */

	reverseDisplay(123456789);
	reverseDisplay("abcdefghi");

	return 0;
}

void reverseDisplay(int value)
{
	cout << value % 10;
	if (value / 10 > 0) return reverseDisplay(value /= 10);
	cout << "\n";
}

void reverseDisplay(const string& s)
{
	cout << s[s.size() - cnt++];
	if (s.size() >= cnt) return reverseDisplay(s);
	cout << "\n";
}