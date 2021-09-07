#include<stdio.h>                   //contains printf,scanfetc
#include "functions.h"
char password[20]={"harish"};  //for changing the password just change "home" to any new word to set as password..


int main(void)
{
	welcome();
	
}



void welcome()
{
				system("cls");

printf("\n**********||     WELCOME TO HOSPITAL MANAGEMENT SYSTEM    ||***********");
printf("\n**********||                                              ||***********");
                
			getch();
			login();
}


void login() //for password option
{

	system("cls");
	char d[25]="    LOGGING IN   ";
char ch;
char pass[10];
int a=0,p;
printf(" \n\n");
for(p=0;p<5;p++)
    {
printf(" \xDB ");
    }
for(p=0;p<20;p++)
   {

printf("%c",d[p]);
   }
for(p=0;p<5;p++)
   {

printf(" \xDB ");
   }
printf(" \n\n");
printf(" ENTER PASSWORD : ");

while(ch!=13)
   {
	ch=getch();

	if(ch!=13 &&ch!=8){
	putch('*');
	pass[a] = ch;
	a++;
	}
   }
pass[a] = '\0';
if(strcmp(pass,password)==0)
   {

	printf("\n\n PASSWORD ACCEPTED");
	printf("\n Press any key to continue.....");
	printf("\n \xDB\xDB\xDB\xDB\xDB\xDB  @_@  >_<>_o  o_<  *_*  @_@  \xDB\xDB\xDB\xDB\xDB\xDB");
	getch();
	menu();
	}
else
   {
	printf("\n\n");
	printf("\a \xDB\xDB\xDB\xDB\xDB  o_<  *_*  @_@  PASSWORD  DENIED  @_@  >_<>_o  \xDB\xDB\xDB\xDB\xDB\xDB");
	getch();
	login();

	}
}


