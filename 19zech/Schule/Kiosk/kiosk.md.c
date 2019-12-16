#include <stdio.h>

char article[5][25] = {"\nEraser\n", "Writing Pad\n", "Folder\n", "Mini Calculator\n", "Pencil\n"};
int table[5] = {0};
double kiosk[5][5] = {{1, 2, 3, 4, 5}, {0, 3, 0, 0, 0}, {1.23, 0.99, 1.99, 4.49, 0.30}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
char table_header[5][11] = {"Article |", " Stock |", " Price |", " Sold |", " Sales \n"};

void show_table_header();
void show_table();
void show_article();
void change_article();
void article_info();
void buy();
void menu();

int main()
{
    menu();
}

void menu()
{
    int menu_option;
    int item_ID;
    printf("\nPlease choose an option:\nShow Items [1]\nShow Logs [2]\nChange Stock/Price [3]\nSell an Item [4]\n");
    scanf("%d", &menu_option);
    switch (menu_option)
    {
    case 1:
        show_article();
        break;
    case 2:
        show_table_header();
        break;
    case 3:
        
        printf("Which Article??\n");
        scanf("%d", &item_ID);
        change_article(item_ID);
        break;
    case 4:
        buy();
        break;
    default:
        printf("Please input a valid option");
        break;
    }
}

void show_table_header()
{
    for (int i = 0; i < 5; i++)
    {
        printf(table_header[i]);
    }
    show_table();
}

void show_table()
{
    article_info();
    menu();
}

void show_article()
{
    for (int i = 0; i < 5; i++)
    {
        printf(article[i]);
    }
    menu();
}

void buy() {
    int option;
    double sold;
    printf("Which item was sold?\n");
    scanf("%d", &option);
    option--;
    printf("Input the number of Items sold: ");
    scanf("%lf", &sold);
    if(option<=sizeof(kiosk)/sizeof(kiosk[0]) && kiosk[1][option]>=sold) {  
        kiosk[3][option] += sold;
        kiosk[1][option] = kiosk[1][option] - sold;
        kiosk[4][option] = kiosk[4][option] + (sold * kiosk[2][option]);
        menu();
    }
    else {
        printf("Please input a valid number, or sell less, you twat.\n");
        buy();
    }
}

void article_info() {
    for(int i=0; i<5; i++){
        printf(" %.2lf\t", kiosk[i][0]);        
    }
    printf("\n");
    for(int i=0; i<5; i++){
        printf(" %.2lf\t", kiosk[i][1]);
    }
    printf("\n");
    for(int i=0; i<5; i++){
        printf(" %.2lf\t", kiosk[i][2]);
    }
    printf("\n");
    for(int i=0; i<5; i++){
        printf(" %.2lf\t", kiosk[i][3]);
    }
    printf("\n");
    for(int i=0; i<5; i++){
        printf(" %.2lf\t", kiosk[i][4]);
    }
}
void change_article(int a) {
    int item_ID;
    double stock;
    int column;
    item_ID = a -1;
    printf("Change Stock [1]\nChange Price [2]\n");
    scanf("%d", &column);
    switch (column)
    {
    case 1:
        printf("Please input the new stock: ");
        scanf("%lf", &stock);
        kiosk[column][item_ID] = stock;
        menu();
        break;
    case 2:
        printf("Please input the new price: ");
        scanf("%lf", &stock);
        kiosk[column][item_ID] = stock;
        menu();
        break;
    default: 
        printf("Choose one or two you fool.");
        menu();
        break;
    }    
}