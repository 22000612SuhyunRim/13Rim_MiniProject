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
    getchar();
    printf("����Ʈ �̸���? ");
    scanf("%[^\n]s", p->name);
    printf("����Ʈ ������? (P/S/R)");
    scanf("%[^\n]s", p->type);
    getchar();
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
