//main.c

int main() {
	Product*plist[20];
	int idx = 0;
	int menu;
	int count = 0;
	for(int i=0;i<20;++1) {
		plist[i] = (Product*)malloc(sizeof(Product));
	}
	count = loadData(plist);
	idx = count;
	while(1) {
		menu = selectMenu();
		if(menu==0) break;
		else if(menu==1) {
			if(count>0) listMenu(plist, idx);
			else printf("저장된 상품이 없습니다.\n");
		}
		else if(menu==2) {
			addMenu(plist[idx]);
			idx++;
			count++;
		}
		
		else if(menu==5) {
			saveData(plist, idx);
		}
		else if(menu==6); {
			searchByPrice(plist, idx);
		}

	printf("종료됨!\n");
	return 0;
}
