#include<stdio.h>

void login(char name[15])
{
    FILE *fp;
    int namecount;

    fp = fopen("namecount.txt", "r");
    fscanf(fp, "%d\n", &namecount);
    //printf("namecount: %d\n", namecount);
    fclose(fp);

    namecount++;
    //printf("namecount: %d\n", namecount);

    fp = fopen("namecount.txt", "w");
    fprintf(fp, "%d\n", namecount);
    fclose(fp);

    fp = fopen("namelist.txt", "a");
    fprintf(fp, "%s\n", name);
    fclose(fp);

}

void logout(char name[15])
{
    FILE *fp;
    int namecount, i, j;

    fp = fopen("namecount.txt", "r");
    fscanf(fp, "%d", &namecount);
    namecount--;
    fclose(fp);

    char namelist[namecount][15];

    fp = fopen("namecount.txt", "w");
    fprintf(fp, "%d", namecount);
    fclose(fp);

    fp = fopen("namelist.txt", "r");

    /*for(j = 0; j < namecount; j++)
    {
        for(i = 0; i < 15; i++)
        {
            fscanf(fp, "%s\n", &namelist[namecount]);
            if(namelist[namecount] == name[15])
            {
                namecount--;
            }
        }
    }*/

    for(j = namecount - 1; j >= 0; j--)
    {
        fscanf(fp, "%s\n", &namelist[j]);
        if(namelist[j] == name)
        {
            j++;
        }  
    }

    fclose(fp);

    fp = fopen("namelist.txt", "w");
    for(j = 0; j < namecount; j++)
    {
        fprintf(fp, "%s\n", namelist[j]);
    }

    fclose(fp);
}

void printnames(void)
{
    FILE *fp;
    int i, count;
    char name[15];

    fp = fopen("namecount.txt", "r");
    fscanf(fp, "%d", &count);
    fclose(fp);

    fp = fopen("namelist.txt", "r");

    for(i = 0; i < count; i++)
    {
        fscanf(fp, "%s\n", &name);
        printf("%s\n", name);
    }

    fclose(fp);
}

void update(char newmsg[50])
{
    FILE *fp;
    int count;

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
    fp = fopen("newestmsg.txt", "r");
 
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

    fp = fopen("newestmsg.txt", "w");

    /*if(fp == NULL) {
	    printf("Datei konnte nicht geoeffnet werden.\n");
    }else {
	    
		printf(fp, "%s\n", eingabe);
	    
	    fclose(fp);
    }*/

    //fprintf(fp, "\n");

    fprintf(fp, "%s\n", eingabe);
    fclose(fp);
}

void main(void)
{
    int choice, contin = 1;
    char name[15];

    printf("Bitte Namen fuer Log-In eingeben:\n");
    scanf("%14s", &name);
    login(name);

    while(contin == 1)
    {
        printf("Letze Nachricht ausgeben ('1') / Ganzen Chat ausgeben ('2') / Neue Nachricht schreiben ('3')\nListe aktuell eingeloggter Namen ('4') / Log-Out ('5')\n");
        scanf("%d", &choice);
        
        if(choice == 1)
        {
            lastmsg();
            //fflush(stdin);
        }
        else if(choice == 2)
        {
            wholechat();
            //fflush(stdin);
        }
        else if(choice == 3)
        {
            type();
            //fflush(stdin);
        }
        else if(choice == 4)
        {
            printnames();
            //fflush(stdin);
        }
        else if(choice == 5)
        {
            //fflush(stdin);
            logout(name);
            contin++;
        }

    }

}
