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
	count = loadData(plist); // ���� �ҷ�����
	idx = count;
	while (1)
	{
		menu = selectMenu();
		if (menu == 1 || menu == 3 || menu == 4)
		{
			if (count == 0)
			{
				printf("����� ��ǰ�� �����ϴ�.\n");
				continue;
			}
		}
		if (menu == 0)
		{
			printf("�����! \n");
			break;
		}
		else if (menu == 1) // 1. �޴� ��ȸ
		{
			if (count > 0)
				listMenu(plist, idx);
		}
		else if (menu == 2) // 2. �޴� �߰�
		{
			plist[idx] = (VM *)malloc(sizeof(VM));
			addMenu(plist[idx]);
			idx++;
			count++;
		}
		else if (menu == 3) // 3. �޴� ����
		{
			int no = selectNumber(plist, idx);
			if (no > 0)
			{
				updateMenu(plist[no - 1]);
				printf("=> ������!\n");
			}
		}
		else if (menu == 4) // 4. �޴� ����
		{
			int no = selectNumber(plist, idx);
			if (no > 0)
			{
				printf("������ �����Ͻðڽ��ϱ�? (1:����)");
				int delok;
				scanf("%d", &delok);
				if (delok == 1)
				{
					if (plist[no - 1])
						free(plist[no - 1]);
					plist[no - 1] = NULL;
					printf("=> ������!\n");
					count--;
				}
			}
		}
		else if (menu == 5) // 5. ���� ����
		{
			saveData(plist, idx);
		}
		else if (menu == 6) // 6. ���� �˻�
		{
			searchVMByPrice(plist, idx);
		}
		else if (menu == 7)
		{ // 7. �̸� �˻�
			searchVMByName(plist, idx);
		}
		else if (menu == 8)
		{ // 8. �α⵵ �˻�
			searchVMByRank(plist, idx);
		}
	}
	system("pause");
	return 0;
}
