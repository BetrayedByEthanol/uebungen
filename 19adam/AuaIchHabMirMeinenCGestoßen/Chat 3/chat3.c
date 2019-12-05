#include<stdio.h>
#include<string.h>

void createacc()
{
    FILE *fp;
    char accname[15], checkname[15], password[15], checkword[15];
    int acccnt, pwnumber, pwcount, i = 1, j;

    fp = fopen("accountcount.txt", "r");
    fscanf(fp, "%d\n", &acccnt);
    fclose(fp);

    while(i == 1)
    {
        i = 0;
        printf("Bitte geben Sie ihren gewuenschten Accountnamen (max. 15 Buchstaben) ein.\n");
        scanf("%14s", &accname);
        //printf("accname: %s checkname: %s acccnt: %d\n", accname, acccnt);
        fp = fopen("Accounts.txt", "r");
        for(j = acccnt; j > 0; j--)
        {
            fscanf(fp, "%s\n", &checkname);
            //printf("accname: %s checkname: %s\n", accname, checkname);
            if(strcmp(accname, checkname) == 0)
            {
                printf("Name vergeben, bitte anderen Namen auswaehlen.\n");
                i++;
            }
        }
    }
    fclose(fp);

    pwcount = acccnt * 2;
    //pwnumber = pwcount + 1;

    acccnt++;

    fp = fopen("accountcount.txt", "w");
    fprintf(fp, "%d\n", acccnt);
    fclose(fp);

    fp = fopen("accounts.txt", "a");
    fprintf(fp, "%s\n", accname);
    fclose(fp);

    /*while(i == 0)
    {
        i = 1;
        printf("Bitte geben Sie ihr gewuenschtes Passwort (max. 15 Zeichen) ein.\n");
        scanf("%14s", &password);
        printf("password: %s pwcount: %d\n", password, pwcount);
        fp = fopen("passwords.txt", "r");
        for(j = pwcount - 1; j > 0; j--)
        {
            //printf("schleife check");
            fscanf(fp, "%s\n", &checkword);
            if(strcmp(checkword, password) == 0)
            {
                printf("Passwort vergeben, bitte anderes Passwort auswaehlen.\n");
                i--;
            }
            j--;
        }
    }
    fclose(fp);*/

    printf("Bitte geben Sie ihr gewuenschtes Passwort (max. 15 Zeichen) ein.\n");
    scanf("%14s", &password);

    //printf("%d\n%s\n", acccnt, password);
    fp = fopen("passwords.txt", "a");
    fprintf(fp, "%d\n%s\n", acccnt, password);
    fclose(fp);

}

int acclogin(void)
{
    FILE *fp;
    int i = 1, j, exists = 0, acccnt, accnumber, pwbreak = 0, end;
    char name[15], checkname[15], password[15], checkword[15];
    //fflush(stdin);

    while(i == 1)
    {
        printf("Bitte Account-Namen eingeben:\n");
        fflush(stdin);
        //scanf("%*[^\n]");
        scanf("%14s", &name);
        fflush(stdin);
        //printf("name: %s", name);
        fp = fopen("accountcount.txt", "r");
        fscanf(fp, "%d\n", &acccnt);
        fclose(fp);

        //printf("acccnt: %d\n", acccnt);

        fp = fopen("Accounts.txt", "r");
        for(j = 0; j < acccnt; j++)
        {
            //scanf("%*[^\n]");
            fscanf(fp, "%s\n", &checkname);
            //printf("name: %s, checkname: %s, compare: %d\n", name, checkname, strcmp(name, checkname));
            if(strcmp(name, checkname) == 0)
            {
                accnumber = j + 1;
                exists = 1;
            }
            //fflush(stdin);
        }

        if(exists == 1)
        {
            i--;
        }
        else if(exists == 0)
        {
            printf("Name nicht gefunden.\n");
        }
        fclose(fp);
    }

    i = 1;
    fflush(stdin);

    while(i == 1)
    {
        printf("Passwort:\n");
        scanf("%*[^\n]");
        scanf("%14s", &password);
        //scanf("%*[^\n]");
        fflush(stdin);

        fp = fopen("passwords.txt", "r");

        for(j = 0; j < (accnumber * 2); j++)
        {
            scanf("%*[^\n]");
            fscanf(fp, "%s\n", &checkword);
            //scanf("%*[^\n]");
        }
        //printf("%s\n", checkword);

        fclose(fp);
        
        if(strcmp(password, checkword) == 0)
        {
            i--;
            fp = fopen("logged_in_accs.txt", "a");
            fprintf(fp, "%s\n", name);
            fclose(fp);
            end = 1;
        }

        else if(strcmp(password, checkword) != 0)
        {
            printf("Passwort inkorrekt :---(\n");
            pwbreak++;
        }

        if(pwbreak == 3)
        {
            i--;
            accnumber = 0;
            end = 1;
        }

        if(end == 1)
        {
            return accnumber;
        }
    
    }

}

/*void acclogout(void)
{

}

void deleteacc(void)
{
    
}*/

void login(char name[15])
{
    FILE *fp;
    int namecount;

    fp = fopen("namecount.txt", "r");
    fscanf(fp, "%d\n", &namecount);
    fclose(fp);

    namecount++;

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

void type(int accdata)
{
    FILE *fp;
    int i;
    char eingabe[50], account[15];
    printf("Nachricht eingeben:\n");
    scanf("%49s", &eingabe);

    update(eingabe);

    
    if(accdata == 0)
    {
        fp = fopen("newestmsg.txt", "w");
        fprintf(fp, "%s\n", eingabe);
        fclose(fp);
    }
    else if(accdata != 0)
    {
        fp = fopen("Accounts.txt", "r");
        for(i = 1; i <= accdata; i++)
        {
            fscanf(fp, "%s\n", &account); 
        }
        fclose(fp);

        fp = fopen("newestmsg.txt", "w");
        fprintf(fp, "%s:%s\n", account, eingabe);
        fclose(fp);
    }

}

void main(void)
{
    int choice, contin = 1, account = 0;
    char name[15];

    printf("Bitte Namen fuer Log-In eingeben:\n");
    scanf("%14s", &name);
    login(name);

    while(contin == 1)
    {
        printf("Letze Nachricht ausgeben ('1') / Ganzen Chat ausgeben ('2') / Neue Nachricht schreiben ('3')\nListe aktuell eingeloggter Namen ('4') / Create Account ('5') / Log into Account ('6') / Log-Out ('7')\n");
        scanf("%*[^\n]");
        scanf("%d", &choice);
        fflush(stdin);
        
        if(choice == 1)
        {
            fflush(stdin);
            lastmsg();
            //fflush(stdin);
        }
        else if(choice == 2)
        {
            fflush(stdin);
            wholechat();
            //fflush(stdin);
        }
        else if(choice == 3)
        {
            fflush(stdin);
            type(account);
            //fflush(stdin);
        }
        else if(choice == 4)
        {
            fflush(stdin);
            printnames();
            //fflush(stdin);
        }
        else if(choice == 5)
        {
            fflush(stdin);
            createacc();
        }
        else if(choice == 6)
        {
            fflush(stdin);
            account = acclogin();
            choice = 0;
        }
        else if(choice == 7)
        {
            //fflush(stdin);
            logout(name);
            contin++;
        }

    }

}
