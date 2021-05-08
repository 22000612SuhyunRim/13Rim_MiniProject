//manager.c
#include "product.h"
#include <string.h>

void addMenu(VM *p)
{
	printf("����Ʈ �̸���? ");
	scanf("%[^\n]", p->name);
	printf("����Ʈ ������? (P/S/R)");
	scanf("%[^\n]", p->type);
	printf("����Ʈ ������? ");
	scanf("%d", &p->price);
	printf("����Ʈ ������? (0 ~ 100) ");
	scanf("%d", &p->score);
	printf("=> �߰���!\n");
}

void readMenu(VM *p)
{
	printf("   %8s %6s %5d %5d\n", p->name, p->type, p->price, p->score);
}

void listMenu(VM *p[], int count)
{
	printf("\n No     DessertName     type     Price    Score\n");
	printf("===================================================\n");
	int check = 0;
	for (int i = 0; i < count; ++i)
	{
		if (p[i]->price == -1)
			continue;
		else
		{
			printf("%d", check + 1);
			readMenu(p[i]);
			check++;
		}
	}
}

void saveData(VM *p[], int count)
{
	FILE *fp;
	fp = fopen("VendingMachine.txt", "wt");
	for (int i = 0; i < count; ++i)
	{
		fprintf(fp, "%d %d %s %s\n", p[i]->price, p[i]->score, p[i]->type, p[i]->name);
	}
	fclose(fp);
	printf("=> �����!\n");
}

int loadData(VM *p[])
{
	FILE *fp;
	int i = 0;
	fp = fopen("VendingMachine.txt", "rt");
	if (fp == NULL)
	{
		printf("=> ���Ͼ���!\n");
		return 0;
	}
	for (i = 0; i < 20; i++)
	{
		fscanf(fp, "%d", &p[i]->price);
		fscanf(fp, "%d", &p[i]->score);
		fscanf(fp, "%s", p[i]->type);
		fgets(p[i]->name, 20, fp);
		p[i]->name[strlen(p[i]->name) - 1] = '\0';
		if (feof(fp))
			break;
	}
	fclose(fp);
	printf("=> �ε�����!\n");
	return i;
}

void searchVMByPrice(VM *p[], int count)
{
	int check = 0;
	int searchPrice = 0;

	printf("�˻��� ����Ʈ ����? ");
	scanf("%d", &searchPrice);
	printf("\n No     DessertName     type     Price\n");
	printf("==========================================");
	for (int i = 0; i < count; ++i)
	{
		if (p[i]->price == -1)
			continue;
		if (p[i]->price == searchPrice)
		{
			printf("%d", i + 1);
			readMenu(p[i]);
			check++;
		}
	}
	if (check == 0)
		printf("=> �˻��� ������ ����!\n");
	printf("\n");
}
