//main.c
#include "product.h"

int main()
{
	VM *plist[20];
	int idx = 0;
	int menu;
	int count = 0;
	for (int i = 0; i < 20; i++)
	{
		plist[i] = (VM *)malloc(sizeof(VM));
	}
	count = loadData(plist); // 파일 불러오기
	idx = count;
	while (1)
	{
		menu = selectMenu();
		if (menu == 1 || menu == 3 || menu == 4)
		{
			if (count == 0)
			{
				printf("저장된 상품이 없습니다.\n");
				continue;
			}
		}
		if (menu == 0)
		{
			printf("종료됨! \n");
			break;
		}
		else if (menu == 1) // 1. 메뉴 조회
		{
			if (count > 0)
				listMenu(plist, idx);
		}
		else if (menu == 2) // 2. 메뉴 추가
		{
			plist[idx] = (VM *)malloc(sizeof(VM));
			addMenu(plist[idx]);
			idx++;
			count++;
		}
		else if (menu == 3) // 3. 메뉴 수정
		{
			int no = selectNumber(plist, idx);
			if (no > 0)
			{
				updateMenu(plist[no - 1]);
				printf("=> 수정됨!\n");
			}
		}
		else if (menu == 4) // 4. 메뉴 삭제
		{
			int no = selectNumber(plist, idx);
			if (no > 0)
			{
				printf("정말로 삭제하시겠습니까? (1:삭제)");
				int delok;
				scanf("%d", &delok);
				if (delok == 1)
				{
					if (plist[no - 1])
						free(plist[no - 1]);
					plist[no - 1] = NULL;
					printf("=> 삭제됨!\n");
					count--;
				}
			}
		}
		else if (menu == 5) // 5. 파일 저장
		{
			saveData(plist, idx);
		}
		else if (menu == 6) // 6. 가격 검색
		{
			searchVMByPrice(plist, idx);
		}
		else if (menu == 7)
		{ // 7. 이름 검색
			searchVMByName(plist, idx);
		}
		else if (menu == 8)
		{ // 8. 인기도 검색
			searchVMByRank(plist, idx);
		}
	}
	system("pause");
	return 0;
}
