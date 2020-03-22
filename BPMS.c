#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

FILE *file;

struct laptop {
	char pcname[100];
	char price[100];
	char regularPrice[100];
	char status[100];
	char productCode[100];
	char ram[100];
	char processor[100];
	char hdd[100];
	char gpu[100];
	char warranty[100];
} lap;

void screen()
{
    system("cls");
    printf(" ");
    for(int i=0;i<40;i++)
        printf(":");
    printf("DIU Soft Solution");
    for(int i=0;i<40;i++)
        printf(":");

    printf("\n \n \n");
}

void customer()
{
    char name[100];
    int choice;
    screen();
    file = fopen("syntal.txt","r");
    while(fread(&lap,sizeof(lap),1,file)==1)
    {
        printf("\n\n Menu Shown: ");
        printf("\n\n Brand PC Company Name: ");
        printf("%s\n",lap.pcname);
        printf(" Price: ");
        printf("%s\n",lap.price);
        printf(" Regular Price: ");
        printf("%s\n",lap.regularPrice);
        printf(" Status: ");
        printf("%s\n",lap.status);
        printf(" Product Code: ");
        printf("%s\n",lap.productCode);
        printf(" Features of Brand PC:\n");
        printf("      RAM: ");
        printf("%s\n",lap.ram);
        printf("      Processor: ");
        printf("%s\n",lap.processor);
        printf("      HDD: ");
        printf("%s\n",lap.hdd);
        printf("      GPU: ");
        printf("%s\n",lap.gpu);
        printf(" Warranty: ");
        printf("%s\n",lap.warranty);
        for(int i=0;i<100;i++)
            printf(".");
    }
    rewind(file);
    printf("\n \n Enter the Brand PC Company and name you want to buy:\n( Or press '0' if you do not want to purchase: ");
    scanf("%s",name);
    while(fread(&lap,sizeof(lap),1,file)==1)
    {
        if(strcmp(lap.pcname, name) == 0)
        {
            printf("\n\n Menu Shown: ");
            printf("\n\n Brand PC Company Name: ");
            printf("%s\n",lap.pcname);
            printf(" Price: ");
            printf("%s\n",lap.price);
            printf(" Regular Price: ");
            printf("%s\n",lap.regularPrice);
            printf(" Status: ");
            printf("%s\n",lap.status);
            printf(" Product Code: ");
            printf("%s\n",lap.productCode);
            printf(" Features of Brand PC:\n");
            printf("      RAM: ");
            printf("%s\n",lap.ram);
            printf("      Processor: ");
            printf("%s\n",lap.processor);
            printf("      HDD: ");
            printf("%s\n",lap.hdd);
            printf("      GPU: ");
            printf("%s\n",lap.gpu);
            printf(" Warranty: ");
            printf("%s\n",lap.warranty);
            for(int i=0;i<100;i++)
                printf(".");
        }
    }
    fclose(file);
    printf("\n \n Press '1' to return to the main menu. \n Press '2' to quit the program.\n Choice : ");
    scanf("%d",&choice);
    if(choice == 1)
        main();
    else if(choice == 2)
        return;
}

void addproduct()
{
    screen();
    file = fopen("syntal.txt","a+");
    printf("\n\n Menu Shown: ");
    printf("\n\n Brand PC Company Name: ");
    scanf("%s",lap.pcname);
    printf(" Price: ");
    scanf("%s",lap.price);
    printf(" Regular Price: ");
    scanf("%s",lap.regularPrice);
    printf(" Status: ");
    scanf("%s",lap.status);
    printf(" Product Code: ");
    scanf("%s",lap.productCode);
    printf(" Features of Brand PC:\n");
    printf("      RAM: ");
    scanf("%s",lap.ram);
    printf("      Processor: ");
    scanf("%s",lap.processor);
    printf("      HDD: ");
    scanf("%s",lap.hdd);
    printf("      GPU: ");
    scanf("%s",lap.gpu);
    printf(" Warranty: ");
    scanf("%s",lap.warranty);
    fwrite(&lap,sizeof(lap),1,file);
    fclose(file);
    menuview();
}

void viewproduct()
{
    screen();
    file = fopen("syntal.txt","r");
    while(fread(&lap,sizeof(lap),1,file)==1)
    {
        printf("\n\n Menu Shown: ");
        printf("\n\n Brand PC Company Name: ");
        printf("%s\n",lap.pcname);
        printf(" Price: ");
        printf("%s\n",lap.price);
        printf(" Regular Price: ");
        printf("%s\n",lap.regularPrice);
        printf(" Status: ");
        printf("%s\n",lap.status);
        printf(" Product Code: ");
        printf("%s\n",lap.productCode);
        printf(" Features of Brand PC:\n");
        printf("      RAM: ");
        printf("%s\n",lap.ram);
        printf("      Processor: ");
        printf("%s\n",lap.processor);
        printf("      HDD: ");
        printf("%s\n",lap.hdd);
        printf("      GPU: ");
        printf("%s\n",lap.gpu);
        printf(" Warranty: ");
        printf("%s\n",lap.warranty);
        for(int i=0;i<100;i++)
            printf(".");
    }
    fclose(file);
    printf(" \n Press any key to return back.");
    getch();
    menuview();
}

void modifyproduct()
{
    screen();
    fflush(stdin);
    here:;
    file = fopen("syntal.txt","r");
    int count=0,choice;
    char name[100];
    printf(" Modify Product: \n \n Brand PC Company Name: ");
    scanf("%s",name);
    while(fread(&lap,sizeof(lap),1,file)==1)
    {
        if(strcmp(lap.pcname, name) == 0)
        {
            count++;
            printf("\n\n Menu Shown: ");
            printf("\n\n Brand PC Company Name: ");
            printf("%s\n",lap.pcname);
            printf(" Price: ");
            printf("%s\n",lap.price);
            printf(" Regular Price: ");
            printf("%s\n",lap.regularPrice);
            printf(" Status: ");
            printf("%s\n",lap.status);
            printf(" Product Code: ");
            printf("%s\n",lap.productCode);
            printf(" Features of Brand PC:\n");
            printf("      RAM: ");
            printf("%s\n",lap.ram);
            printf("      Processor: ");
            printf("%s\n",lap.processor);
            printf("      HDD: ");
            printf("%s\n",lap.hdd);
            printf("      GPU: ");
            printf("%s\n",lap.gpu);
            printf(" Warranty: ");
            printf("%s\n",lap.warranty);
            for(int i=0;i<100;i++)
                printf(".");
            break;
        }
    }
    if(count == 0)
    {
        printf("\n \n Record doesn't exist!\n Try again?\n    [1] Yes      [0] No");
        scanf("%d",&choice);
        if(choice == 0)
        {
            menuview();
            fclose(file);
        }
        else if(choice == 1)
        {
            fclose(file);
            goto here;
        }
    }
    rewind(file);
    FILE *tile;
    tile = fopen("temporary.txt","w+");
    count = 0;

    while(fread(&lap,sizeof(lap),1,file)==1)
    {
        if(strcmp(lap.pcname, name) == 0 && count == 0)
        {
            count++;
            printf("\n\n New Brand PC Company Name: ");
            scanf("%s",lap.pcname);
            printf(" New Price: ");
            scanf("%s",lap.price);
            printf(" New Regular Price: ");
            scanf("%s",lap.regularPrice);
            printf(" New Status: ");
            scanf("%s",lap.status);
            printf(" New Product Code: ");
            scanf("%s",lap.productCode);
            printf(" New Features of Brand PC:\n");
            printf("      RAM: ");
            scanf("%s",lap.ram);
            printf("      Processor: ");
            scanf("%s",lap.processor);
            printf("      HDD: ");
            scanf("%s",lap.hdd);
            printf("      GPU: ");
            scanf("%s",lap.gpu);
            printf(" New Warranty: ");
            scanf("%s",lap.warranty);
            fwrite(&lap,sizeof(lap),1,tile);
        }
        else
        {
            fwrite(&lap,sizeof(lap),1,tile);
        }
    }
    fclose(tile);
    fclose(file);
    remove("syntal.txt");
    rename("temporary.txt","syntal.txt");
    fflush(stdin);
    menuview();
}

void deleteproduct()
{
    screen();
    fflush(stdin);
    here:;
    file = fopen("syntal.txt","r");
    int count=0,choice;
    char name[100];
    printf(" Delete Product: \n \n Brand PC Company Name: ");
    scanf("%s",name);
    while(fread(&lap,sizeof(lap),1,file)==1)
    {
        if(strcmp(lap.pcname, name) == 0)
        {
            count++;
            printf("\n\n Menu Shown: ");
            printf("\n\n Brand PC Company Name: ");
            printf("%s\n",lap.pcname);
            printf(" Price: ");
            printf("%s\n",lap.price);
            printf(" Regular Price: ");
            printf("%s\n",lap.regularPrice);
            printf(" Status: ");
            printf("%s\n",lap.status);
            printf(" Product Code: ");
            printf("%s\n",lap.productCode);
            printf(" Features of Brand PC:\n");
            printf("      RAM: ");
            printf("%s\n",lap.ram);
            printf("      Processor: ");
            printf("%s\n",lap.processor);
            printf("      HDD: ");
            printf("%s\n",lap.hdd);
            printf("      GPU: ");
            printf("%s\n",lap.gpu);
            printf(" Warranty: ");
            printf("%s\n",lap.warranty);
            for(int i=0;i<100;i++)
                printf(".");
            break;
        }
    }
    if(count == 0)
    {
        printf("\n \n Record doesn't exist!\n Try again?\n    [1] Yes      [0] No");
        scanf("%d",&choice);
        if(choice == 0)
        {
            fclose(file);
            menuview();
        }
        else if(choice == 1)
        {
            fclose(file);
            goto here;
        }
    }
    rewind(file);
    FILE *tile;
    tile = fopen("temporary.txt","w+");
    count = 0;

    while(fread(&lap,sizeof(lap),1,file)==1)
    {
        if(strcmp(lap.pcname, name) == 0 && count == 0)
        {
            count++;
            printf("\n Record successfully Deleted!");
            getch();
            continue;
        }
        else
        {
            fwrite(&lap,sizeof(lap),1,tile);
        }
    }
    fclose(tile);
    fclose(file);
    remove("syntal.txt");
    rename("temporary.txt","syntal.txt");
    fflush(stdin);
    menuview();
}

void searchproduct()
{
    screen();
    here:;
    file = fopen("syntal.txt","r");
    int count=0,choice;
    char name[100];
    printf(" Search Product: \n \n Brand PC Company Name: ");
    scanf("%s",name);
    while(fread(&lap,sizeof(lap),1,file)==1)
    {
        if(strcmp(lap.pcname, name) == 0)
        {
            count++;
            printf("\n\n Menu Shown: ");
            printf("\n\n Brand PC Company Name: ");
            printf("%s\n",lap.pcname);
            printf(" Price: ");
            printf("%s\n",lap.price);
            printf(" Regular Price: ");
            printf("%s\n",lap.regularPrice);
            printf(" Status: ");
            printf("%s\n",lap.status);
            printf(" Product Code: ");
            printf("%s\n",lap.productCode);
            printf(" Features of Brand PC:\n");
            printf("      RAM: ");
            printf("%s\n",lap.ram);
            printf("      Processor: ");
            printf("%s\n",lap.processor);
            printf("      HDD: ");
            printf("%s\n",lap.hdd);
            printf("      GPU: ");
            printf("%s\n",lap.gpu);
            printf(" Warranty: ");
            printf("%s\n",lap.warranty);
            for(int i=0;i<100;i++)
                printf(".");
        }
    }
    fclose(file);
    if(count == 0)
    {
        printf("\n \n Record doesn't exist! Try again...\n");
        goto here;
    }
    else
    {
        printf("\n \n Press '1' to return to back. \n Press '2' to quit the program.\n Choice : ");
        scanf("%d",&choice);
        if(choice == 1)
            menuview();
        else if(choice == 2)
            return ;
    }
}

void login()
{
    screen();

    FILE *filepointer;

    char username[] = "Admin";
    char *inUsername;
    char *inPassword;
    char password[60];

    inUsername = malloc(100 * sizeof(char));
    inPassword = malloc(100 * sizeof(char));

    printf("\n ");
    for(int i=0;i<50;i++)
        printf(":");
    printf(" LOGIN PAGE ");
    for(int i=0;i<50;i++)
        printf(":");

    printf("\n\n Enter Username:");
    scanf("%s",inUsername);
    if(strcmp(username, inUsername) != 0) // if username incorrect
    {
        printf("\n  ***** Invalid USERNAME! ***** ");
        getch();
    }
    else // if username is correct
    {
        printf("\n Enter Password:");
        scanf("%s",inPassword); // password taken from user

        filepointer = fopen("Authentication.txt","r");
        fgets(password,60,filepointer); // password taken from file
        fclose(filepointer);

        if(strcmp(inPassword, password) != 0) // password matching
        {
            printf("\n  ***** Invalid PASSWORD! ***** "); // if password is incorrect
            getch();
        }
        else // if password is correct
        {
            menuview();
        }
    }
}

void menuview()
{
        screen();
        int choice;
        printf("\n  ********** Welcomme to Syntal Brand PC Management System ********** \n\n\n");
        for(int i=0;i<50;i++)
            printf(":");
        printf(" MAIN MENU ");
        for(int i=0;i<50;i++)
            printf(":");

        printf("\n\n Enter the Choice: \n "); // main menu page
        printf("[1] Add new Brand PC stock \n ");
        printf("[2] View available stock \n ");
        printf("[3] Modify existing Brand PC models \n ");
        printf("[4] Search for an existing Brand PC model \n ");
        printf("[5] Delete models out of stock \n ");
        printf("[6] Return to previous screen");
        printf("\n \n Enter your choice: ");

        scanf("%d",&choice);

        if(choice == 1)
            addproduct();
        else if(choice == 2)
            viewproduct();
        else if(choice == 3)
            modifyproduct();
        else if(choice == 4)
            searchproduct();
        else if(choice == 5)
            deleteproduct();
        else if(choice == 6)
        {
            printf("\n \n");
            main();
        }
}

void main()
{
    int choice;

    screen();

    printf("\n\n 1. Wish to purchase computer as a customer\n ");
    printf("2. Login as Administrator \n ");
    printf("3. Exit \n\n Enter your choice: ");


    scanf("%d",&choice);

    if(choice == 1)
    {
        customer();
    }
    else if(choice == 2)
    {
        login();
    }
    else
        return ;


    return ;
}
