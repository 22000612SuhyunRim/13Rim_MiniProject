//manager.c
#include "product.h"
#include <string.h>

void addMenu(VM *p);
void readMenu(VM *p);
void listMenu(VM *p[], int count);

void saveData(VM *p[], int count) {
	FILE* fp;
	fp = fopen("VendingMachine.txt", "wt");
	for(int i=0;i<count;++i) {
		fprintf(fp, "%d %s %s\n", p[i]->price, p[i]->type, p[i]->name);
	}
	fclose(fp);
	printf("=> 저장됨!\n");

int loadData(VM *p[]) {
	FILE *fp;
	int i=0;
	fp = fopen("VendingMachine.txt", "rt");
	if(fp==NULL) {
		printf("=> 파일없음!\n");
		return 0;
	}
	for(i=0;i<20;++i) {
		fscanf(fp, "%d", &p[i]->price);
		fscanf(fp, "%s", p[i]->type);
		fgets(p[i]->name, 20, fp);
		p[i]->name[strlen(p[i]->name)-1]='\0';
		if(feof(fp)) break;
		count++;
	}
	fclose(fp);
	printf("=> 로딩성공!\n");
	return count;
}

void searchVMByPrice(VM *p[], int count) {
	int check=0;
	int price=0;

	printf("검색할 디저트 가격? ");
	scanf("%d", price);
	printf("\n No     DessertName     type     Price\n");
	printf("==========================================");
	for(int i=0;i<count;++i) {
		if(p[i].price==-1) continue;
		if(strstr(p[i].price, price)!=NULL) {
			printf("%d", i+1);
			readMenu(p[i]);
			check++;
		}
	}
	if(check==0) printf("=> 검색된 데이터 없음!\n");
	printf("\n");
}
