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
