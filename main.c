#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#include<windows.h>
#define RETURNTIME 15



char catagories[][15]={"New Member","Coach","Staff"};
char password[10]={"project"};


void returnfunc();
void mainmenu();
void addMember();
void deleteMember();
void editMember();
void searchMember();
void viewMember();
void closeapplication();
int getdata();
int checkid(int);
int t(void);
void Password();
void issuerecord();
void loaderanim();


FILE *fp,*ft,*fs;

COORD coord = {0,0};

int s;

char findMember;

void gotoxy (int x, int y){
      coord.X = x; coord.Y = y;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct meroDate{
    int mm,dd,yy;
};

struct member{
    int id;
    char stname[20];
    char name[20];
    char Address[20];
    char membersince[10];
    int contact;
    int count;
    char *cat;
    struct meroDate issued;
    struct meroDate duedate;
};

struct member m;
void addMember(){
     system("cls");
     int i;
     gotoxy(20,5);
     printf("Choose category : ");
     gotoxy(20,7);
     printf("1. New Member");
     gotoxy(20,9);
     printf("2.Gym Coach");
     gotoxy(20,11);
     printf("3. Staff");
     gotoxy(20,13);
     printf("4. Back to main menu");
     gotoxy(20,21);

    printf("Enter your choice:");
    scanf("%d",&s);
    if(s==4)
       mainmenu() ;
    system("cls");
    fp=fopen("stf.dat","ab+");
    if(getdata()==1){
        m.cat=catagories[s-1];
    fseek(fp,0,SEEK_END);
    fwrite(&m,sizeof(m),1,fp);
    fclose(fp);
    gotoxy(21,14);
    printf("The record is saved");
    gotoxy(21,15);
    printf("Save any more?(Y / N):");
    if(getch()=='n')
    mainmenu();
    else
    system("cls");
    addMember();
    }
  }
  
void deleteMember()
{
    system("cls");
    int id;
    char another='y';
    while(another=='y')
    {
    system("cls");
    gotoxy(10,5);
    printf("Enter ID:");
    scanf("%d",&id);
    fp=fopen("stf.dat","rb+");
    rewind(fp);
    while(fread(&m,sizeof(m),1,fp)==1)
    {
        if(m.id==id)
        {
        gotoxy(10,7);
        printf("The ID is available");
        gotoxy(10,8);
        printf("Name is %s",m.name);
        gotoxy(10,9);
        findMember='t';
        }
    }
    if(findMember!='t')
    {
    gotoxy(10,10);
    printf("ID is not found");
    if(getch())
    mainmenu();
    }
    if(findMember=='t' )
    {
    gotoxy(10,9);
    printf("Do you want to delete it?(Y/N):");
    if(getch()=='y')
    {
    ft=fopen("test.dat","wb+");
    rewind(fp);
    while(fread(&m,sizeof(m),1,fp)==1)
    {
        if(m.id!=id)
        {
        fseek(ft,0,SEEK_CUR);
        fwrite(&m,sizeof(m),1,ft);
        }
    }
    fclose(ft);
    fclose(fp);
    remove("stf.dat");
    rename("test.dat","stf.dat");
    fp=fopen("stf.dat","rb+");
    if(findMember=='t')
    {
        gotoxy(10,10);
        printf("The record is sucessfully deleted");
        gotoxy(10,11);
        printf("\n\tDelete another record?(Y/N)");
    }
        }else
         mainmenu();
         fflush(stdin);
         another=getch();
        }
    }
    gotoxy(10,15);
    mainmenu();
}

void searchMember()
{
    system("cls");
    int id;
    gotoxy(20,10);
    printf("Search By ID");
    fp=fopen("stf.dat","rb+");
    rewind(fp);
    system("cls");
    gotoxy(25,4);
    printf("Enter the id:");
    scanf("%d",&id);
    gotoxy(20,7);
    while(fread(&m,sizeof(m),1,fp)==1)
    {
        if(m.id==id)
        {
            Sleep(2);
            gotoxy(20,6);
        printf("The Record is available\n");
              gotoxy(20,8);
        printf("ID:%d",m.id);
              gotoxy(20,9);
        printf("Category:%s",m.cat);
              gotoxy(20,10);
        printf("Name:%s",m.name);
              gotoxy(20,11);
        printf("Address:%s ",m.Address);
              gotoxy(20,12);
        printf("Contact:%i ",m.contact);
              gotoxy(20,13);
        printf("Member Since:%s",m.membersince);
        findMember='t';
        }
    
    if(findMember!='t')
    {
        printf("No Record Found");
    }
        gotoxy(20,17);
        printf("Try another search?(Y/N)");
    if(getch()=='y')
        searchMember();
    else
    {
        mainmenu();
        break;
    }
        getch();
        searchMember();
        close(fp);
    }
}
