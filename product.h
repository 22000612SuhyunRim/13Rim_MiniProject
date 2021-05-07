#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char name[20];
    char type[20];
    int price;
} VM;

int selectMenu();
void addMenu(VM *p);
void readMenu(VM *p);
void listMenu(VM *p[], int count);
int updateMenu(VM *p);
int deleteMenu(VM *p);
int selectNumber(VM *p[], int count);
void saveData(VM *p[], int count);
int loadData(VM *p[]);
void searchVMByName(VM *p[], int count);
void searchVMByPrice(VM *p[], int count);
void searchVMByRank(VM *p[], int count);
