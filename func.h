// update, delete, selection, search(이름, 인기도(카운터))
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    int price;
} VM;

int updateMenu(VM *p);
int deleteMenu(VM *p);

int selectNumber(VM *p[], int count);
void searchProductByName(VM *p[], int count);
void searchProductByRank(VM *p[], int count);
