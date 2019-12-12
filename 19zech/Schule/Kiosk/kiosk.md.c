#include <stdio.h>

char article[5][25] = {"\nEraser\n", "Writing Pad\n", "Folder\n", "Mini Calculator\n", "Pencil\n"};
int table[5] = {0};
double kiosk[5][5] = {{1, 2, 3, 4, 5}, {0, 3, 0, 0, 0}, {1.23, 0.99, 1.99, 4.49, 0.30}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
char table_header[5][11] = {"Article |", " Stock |", " Price |", " Sold |", " Profit \n"};

void show_table_header();
void show_table();
void show_article();
void change_article1();

int main()
{
    menu();
}

void menu()
{
    int menu_option;
    printf("\nPlease choose an option:\nShow Items [1]\nShow Stock [2]\nShow Price [3]\nShow Amount Sold [4]\nShow Profits [5]\nChange Stock/Price [6]\n");
    scanf("%d", &menu_option);
    switch (menu_option)
    {
    case 1:
        show_article();
        break;
    case 2:
        show_table_header();
        break;
    case 6:
        initialise_array();
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

void initialise_array()
{
    int item_ID;
    printf("Please choose an Item you want to see, or update:");
    scanf("%d", &item_ID);
    switch (item_ID)
    {
    case 1:
        change_article1();
        break;
    /*case 2:
        change_article2();
        break;
    case 3:
        change_article3();
        break;
    case 4:
        change_article4();
        break;
    case 5:
        change_article5();
        break;*/
    default:
        break;
    }
}

void change_article1()
{
    int option;
    double stock_article1;
    printf("Please choose whether you want to change the Stock [1] or the Price [2]");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        printf("\nPlease input the new stock: ");
        scanf("%lf", &stock_article1);
        kiosk[1][0] = stock_article1;
        break;

    default:
        printf("Please input a number you fool.");
        break;
    }
    menu();
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