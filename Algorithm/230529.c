#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int card_conv(unsigned x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;

	if (x == 0)
	{
		d[digits++] = dchar[0];
	}
	else
	{
		while (x)
		{
			d[digits++] = dchar[x % n];
			x /= n;
		}
	}

	for (int i = 0; i < digits / 2; i++)
	{
		char t = d[i];
		d[i] = d[digits - i - 1];
		d[digits - i - 1] = t;
	}
	return digits;
}

int main()
{
	unsigned no;
	int cd;
	char cno[512];

	printf("���� �Է��Ͻÿ� : ");
	scanf("%u", &no);

	printf("�� ������ ��ȯ : ");
	scanf("%d", &cd);

	int dno = card_conv(no, cd, cno);

	printf("10���� %u(��)�� %d���� ", no, cd);
	for (int i = 0; i < dno; i++)
	{
		printf("%c", cno[i]);
	}
	printf("�Դϴ�.\n");

	return 0;
}
