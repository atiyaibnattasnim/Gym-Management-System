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

