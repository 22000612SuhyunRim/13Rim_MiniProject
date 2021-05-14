#include "product.h"
int selectMenu()
{
    int menu;
    printf("\n*** ����Ʈ ���Ǳ� ���α׷� ***\n");
    printf("1. �޴� ��ȸ\n");
    printf("2. �޴� �߰�\n");
    printf("3. �޴� ����\n");
    printf("4. �޴� ����\n");
    printf("5. �޴� ����\n");
    printf("6. ���� �˻�\n");
    printf("7. �̸� �˻�\n");
    printf("8. ���� �˻�\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);

    return menu;
}
int updateMenu(VM *p)
{
    printf("����Ʈ �̸���? ");
    scanf(" %[^\n]", p->name);
    printf("����Ʈ ������? (Coffee/Juice/Cake) ");
    scanf(" %[^\n]", p->type);
    printf("����Ʈ ������? ");
    scanf("%d", &p->price);
    printf("����Ʈ ������? (0 ~ 100) ");
    scanf("%d", &p->score);
    return 1;
}
int deleteMenu(VM *p)
{
    p->price = -1;
    p->score = -1;
    return 1;
}
int selectNumber(VM *p[], int count)
{
    int no;
    listMenu(p, count);
    printf("��ȣ�� (���: 0)? ");
    scanf("%d", &no);
    return no;
}
void searchVMByName(VM *p[], int count)
{
    int scnt = 0;
    char searchName[30];

    printf("�˻��� ����Ʈ �̸�?");
    scanf("%s", searchName);

    printf("\n No     DessertName     type     Price    Score\n");
    printf("===================================================\n");
    for (int i = 0; i < count; i++)
    {
        if (p[i] == NULL)
            continue;
        if (strstr(p[i]->name, searchName))
        {
            printf("%d ", i + 1);
            readMenu(p[i]);
            scnt++;
        }
    }
    if (scnt == 0)
        printf("=>�˻��� ������ ����!");
    printf("\n");
}
void searchVMByRank(VM *p[], int count)
{
    int check = 0;
    int searchScore = 0;

    printf("�˻��� ����Ʈ ����? ");
    scanf("%d", &searchScore);
    printf("\n No     DessertName     type     Price    Score\n");
    printf("===================================================\n");
    for (int i = 0; i < count; ++i)
    {
        if (p[i]->score == -1)
            continue;
        if (p[i]->score == searchScore)
        {
            printf("%d", i + 1);
            readMenu(p[i]);
            check++;
        }
    }
    if (check == 0)
        printf("=> �˻��� ������ ����!!\n");
    printf("\n");
}
