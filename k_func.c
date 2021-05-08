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
    getchar();
    printf("디저트 이름은? ");
    scanf("%[^\n]s", p->name);
    printf("디저트 종류는? (P/S/R)");
    scanf("%[^\n]s", p->type);
    getchar();
    printf("디저트 가격은? ");
    scanf("%d", &p->price);
    printf("디저트 점수는? (0 ~ 100) ");
    scanf("%d", &p->score);
    return 1;
}
