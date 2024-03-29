#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "intQueue.h"

int main()
{
	IntQueue que;

	if (Initialize(&que, 64) == -1)
	{
		puts("큐의 생성에 실패하였습니다.");
		return 1;
	}
	while (1)
	{
		int m, x;

		printf("현재 데이터 수: %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (5) 비우기 (6) 검색 (0)종료 : ");
		scanf("%d", &m);

		if (m == 0)break;
		switch (m)
		{
		case 1:
			printf("데이터: "); scanf("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\a오류: 인큐에 실패하였습니다.");
			break;

		case 2:
			if (Deque(&que, &x) == -1)
				puts("\a오류: 디큐에 실패하였습니다.");
			else
				printf("디큐한 데이터는 %d입니다.\n", x);
			break;

		case 3:
			if (Peek(&que, &x) == -1)
				puts("\a오류: 피크에 실패하였습니다.");
			else
				printf("피크한 데이터는 %d입니다.\n", x);
			break;

		case 4:
			Print(&que);
			break;

		case 5:
			Clear(&que);
			printf("큐를 비웠습니다.\n");
			break;
		case 6:
			printf("검색할 데이터: "); scanf("%d", &x);
			if (Search(&que, x) == -1)
				puts("\a오류: 검색에 실패하였습니다.");
			else
				printf("검색한 데이터는 %d에 있습니다.\n", Search(&que, x));
			break;
		}
	}
	Terminate(&que);
	return 0;
}