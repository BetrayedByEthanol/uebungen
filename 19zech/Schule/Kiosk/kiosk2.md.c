#include <stdio.h>
#include <strings.h>

struct table_header
{
    char table_header_array[5][11];
};

struct table_data
{
    int data[5][5];
};

void menu();
void initialise_header(struct table_data * data);

int main()
{
    menu();
}

void menu() {
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
        initialise_header();
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