typedef struct {
    char name;
    char type;
    int price;
} Product;

int selectMenu();
void addProduct(Product *p);
void readProduct(Product *p);
void listProduct(Product *p[], int count);
void saveData(Product *p[]);
int loadData(Product *p[]);
void searchPrice(Product *p[], int count);
