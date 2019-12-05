#include<stdio.h>

void update(char newmsg[50])
{
    FILE *fp;
    int count;
    //char newmsg[50];
    
    //fp = fopen("abc.txt", "r");

    //fscanf("%s\n", &newmsg);

    //fclose(fp);

    fp = fopen("mainchat.txt", "a");

    fprintf(fp, "%s\n", newmsg);

    fclose(fp);

    fp = fopen("messagecount.txt", "r");
    fscanf(fp, "%d\n", &count);
    count++;
    fclose(fp);

    fp = fopen("messagecount.txt", "w");
    fprintf(fp, "%d\n", count);
    fclose(fp);

}

void wholechat()
{
    FILE *fp;
    int i, count;
    char chat[50];

    fp = fopen("messagecount.txt", "r");
    fscanf(fp, "%d\n", &count);
    fclose(fp);

    fp = fopen("mainchat.txt", "r");

    for(i = 0; i < count; i++)
    {
        fscanf(fp, "%s\n", &chat);
        printf("%s\n", chat);
    }

    fclose(fp);
}

void lastmsg(void)
{
    FILE *fp;

    char temp[50];
    fp = fopen("abc.txt", "r");
 
    fscanf(fp, "%s\n", &temp);
    printf("%s\n", temp);

    fclose(fp);    
}

void type(void)
{
    FILE *fp;
    char eingabe[50];
    printf("Nachricht eingeben:\n");
    scanf("%49s", &eingabe);

    update(eingabe);

    fp = fopen("abc.txt", "w");

    /*if(fp == NULL) {
	    printf("Datei konnte nicht geoeffnet werden.\n");
    }else {
	    
		printf(fp, "%s\n", eingabe);
	    
	    fclose(fp);
    }*/

    printf(fp, "%s\n", eingabe);
    fclose(fp);
}

void main(void)
{
    /*printf("last msg:\n");
    lastmsg();
    printf("whole chat:\n");
    wholechat();
    printf("new msg:\n");
    type();
    printf("new whole chat:\n");
    wholechat();
    printf("last msg:\n");
    lastmsg();*/

    int choice;

    while(1)
    {
        printf("Letze Nachricht ausgeben ('1') / Ganzen Chat ausgeben ('2') / Neue Nachricht schreiben ('3')\n");
        scanf("%d", &choice);
        
        if(choice == 1)
        {
            lastmsg();
        }
        else if(choice == 2)
        {
            wholechat();
        }
        else if(choice == 3)
        {
            type();
        }

    }

}
