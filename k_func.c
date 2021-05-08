#include "product.h";
int updateMenu(VM *p)
{
    getchar();
    printf("디저트 이름은? ");
    fgets(p->name, 100, stdin);
    printf("디저트 종류는? ");
    scanf("%c", &p->type);
    getchar();
    printf("디저트 가격은? ");
    scanf("%d", &p->price);
    printf("디저트 점수는? (0 ~ 100) ");
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
    printf("번호는 (취소: 0)? ");
    scanf("%d", &no);
    return no;
}
void searchVMByName(VM *p[], int count)
{
    int scnt = 0;
    char searchName[30];

    printf("검색할 디저트 이름?");
    scanf("%s", searchName);

    printf("\n No     DessertName     type     Price    Score\n");
    printf("===================================================");
    for (int i = 0; i < count; i++)
    {
        if (p[i] == NULL)
            continue;
        if (strstr(p[i]->name, searchName))
        {
            printf("%d ", i + 1);
            readProduct(p[i]);
            scnt++;
        }
    }
    if (scnt == 0)
        printf("=>검색된 데이터 없음!");
    printf("\n");
}
void searchVMByRank(VM *p[], int count)
{
    int check = 0;
    int score = 0;

    printf("검색할 디저트 점수? ");
    scanf("%d", score);
    printf("\n No     DessertName     type     Price    Score\n");
    printf("===================================================");
    for (int i = 0; i < count; ++i)
    {
        if (p[i]->score == -1)
            continue;
        if (strstr(p[i]->score, score) != NULL)
        {
            printf("%d", i + 1);
            readMenu(p[i]);
            check++;
        }
    }
    if (check == 0)
        printf("=> 검색된 데이터 없음!\n");
    printf("\n");
}
