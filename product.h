#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char name[20];
    char type[20];
    int price;
} VM;

int selectMenu();
void addVM(VM *p);
void readVM(VM *p);
void listVM(VM *p[], int count);
int updateMenu(VM *p);
int deleteMenu(VM *p);
int selectNumber(VM *p[], int count);
void saveData(VM *p[]);
int loadData(VM *p[]);
void searchPrice(VM *p[], int count);
void searchVMByName(VM *p[], int count);
void searchVMByRank(VM *p[], int count);
