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
int main(){
   Password();
   getch();
   return 0;
}

void mainmenu(){
    system("cls");
    int i;
    gotoxy(20,3);
    printf(" \t\tMAIN MENU \n ");
    gotoxy(20,5);
    printf("1. Add Members");
    gotoxy(20,7);
    printf("2. Delete Members");
    gotoxy(20,9);
    printf("3. Search Members");
    gotoxy(20,11);
    printf("4. Display Member's list");
    gotoxy(20,13);
    printf("5. Edit Members information");
    gotoxy(20,15);
    printf("6. Close Application");
    gotoxy(20,22);
    t();
    gotoxy(20,18);
    printf("Enter your choice:");

  switch(getch()){
     case '1':
         addMember();
         break;
     case '2':
         deleteMember();
         break;
     case '3':
         searchMember();
         break;
     case '4':
         viewMember();
         break;
     case '5':
         editMember();
         break;
     case '6':
{
    system("cls");
    gotoxy(16,3);
    printf("\tGYM Management System");
    exit(0);
}
    default:
{
    gotoxy(10,25);
    printf("Invalid option.");
    if(getch())
    mainmenu();
  }
 }
}
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
void viewMember(){
      int i=0,j;
      system("cls");
      gotoxy(2,2);
      printf("\n CATEGORY === ID ==== NAME ======== ADDRESS ===== CONTACT ===== JOINING DATE ");
      j=4;
      fp=fopen("stf.dat","rb");
      while(fread(&m,sizeof(m),1,fp)==1){
      gotoxy(1,j);
      printf("%s",m.cat);
      gotoxy(14,j);
      printf("%d",m.id);
      gotoxy(22,j);
      printf("%s",m.name);
      gotoxy(36,j);
      printf("%s",m.Address);
      gotoxy(50,j);
      printf("%i",m.contact);
      gotoxy(67,j);
      printf("%s",m.membersince);
      gotoxy(68,j);
      printf("\n\n");
      j++;
   }
     fclose(fp);
     gotoxy(35,25);
     returnfunc();
  }

void editMember(){
     system("cls");
      int c=0;
      int d,e;
      char another='y';
      while(another=='y'){
          system("cls");
          gotoxy(15,6);
      printf("Enter Id to be edited:");
      scanf("%d",&d);
      fp=fopen("stf.dat","rb+");
      while(fread(&m,sizeof(m),1,fp)==1){
           if(checkid(d)==0){
           gotoxy(15,7);
      printf("This Member is available");
           gotoxy(15,8);
      printf("The ID:%d",m.id);
           gotoxy(15,9);
      printf("Enter new name:");
      scanf("%s",m.name);
           gotoxy(15,10);
      printf("Enter new Address:");
      scanf("%s",m.Address);
           gotoxy(15,11);
      printf("Enter new Contact:");
      scanf("%i",&m.contact);
           gotoxy(15,12);
      printf("Enter New Membership date:");
      scanf("%s",&m.membersince);
           gotoxy(15,13);
      printf("The record is edited");
      fseek(fp,ftell(fp)-sizeof(m),0);
      fwrite(&m,sizeof(m),1,fp);
      fclose(fp);
           c=1;
        }
       if(c==0){
           gotoxy(15,9);
       printf("No record found");
     }
   }
           gotoxy(15,16);
       printf("Modify another Record?(Y/N)");
       fflush(stdin);
          another=getch() ;
        }
returnfunc();
}

void returnfunc(){
{    gotoxy(15,20);
     printf("Press ENTER to return to main menu");
}
     m:
     if(getch()==13)
     mainmenu();
     else
     goto m;
}

int getdata(){
         int t;
         gotoxy(20,3);
         printf("Enter Information");
         gotoxy(20,4);
         printf("Category:");
         gotoxy(31,5);
         printf("%s",catagories[s-1]);
         gotoxy(21,6);
         printf("ID:\t");
         gotoxy(30,6);
         scanf("%d",&t);
     if(checkid(t) == 0){
         gotoxy(21,13);
     printf("The id already exists");
         getch();
     mainmenu();
   return 0;
}
   m.id=t;
        gotoxy(21,7);
        printf("Name:");
        gotoxy(33,7);
        scanf("%s",m.name);
        gotoxy(21,8);
        printf("Address:");
        gotoxy(30,8);
        scanf("%s",m.Address);
        gotoxy(21,9);
        printf("Contact:");
        gotoxy(31,9);
        scanf("%i",&m.contact);
        gotoxy(21,10);
        printf("Joining date:");
        scanf("%s",&m.membersince);
        gotoxy(31,17);
     return 1;
 }

int checkid(int t){
        rewind(fp);
    while(fread(&m,sizeof(m),1,fp)==1)
        if(m.id==t)
         return 0;
         return 1;
   }

int t(void){
     time_t t;
     time(&t);
     printf("Date and time:%s\n",ctime(&t));
   return 0 ;
}

void Password(){
     system("cls");
     char d[25]="Password Protected";
     char ch,pass[10];
     int i=0,j;
     gotoxy(10,5);
     printf("ENTER SYSTEM");
     printf("\n\nEnter Password:");
     while(ch!=13){
            ch=getch();
        if(ch!=13 && ch!=8){
        putch('*');
        pass[i] = ch;
        i++;
     }
   }
     pass[i] = '\0';
     if(strcmp(pass,password)==0){
     printf("\n\n\n\t\tPassword matched!!");
     printf("\n\n\tPress any key to countinue.....");
     getch();
     mainmenu();
   }else{
     printf("\n\n\n\t\t\aWarning!! \n\t   Incorrect Password");
     getch();
     Password();
   }
 }
