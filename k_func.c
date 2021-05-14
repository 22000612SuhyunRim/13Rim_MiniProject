#include "product.h"
int selectMenu()
{
    int menu;
    printf("\n*** 디저트 자판기 프로그램 ***\n");
    printf("1. 메뉴 조회\n");
    printf("2. 메뉴 추가\n");
    printf("3. 메뉴 수정\n");
    printf("4. 메뉴 삭제\n");
    printf("5. 메뉴 저장\n");
    printf("6. 가격 검색\n");
    printf("7. 이름 검색\n");
    printf("8. 점수 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);

    return menu;
}
int updateMenu(VM *p)
{
    printf("디저트 이름은? ");
    scanf(" %[^\n]", p->name);
    printf("디저트 종류는? (Coffee/Juice/Cake) ");
    scanf(" %[^\n]", p->type);
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
        printf("=>검색된 데이터 없음!");
    printf("\n");
}
void searchVMByRank(VM *p[], int count)
{
    int check = 0;
    int searchScore = 0;

    printf("검색할 디저트 점수? ");
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
        printf("=> 검색된 데이터 없음!!\n");
    printf("\n");
}
