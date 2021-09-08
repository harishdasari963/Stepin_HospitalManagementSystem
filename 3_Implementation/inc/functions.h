#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include<stdio.h>                   //contains printf,scanfetc
#include<conio.h>                   //contains delay(),getch(),gotoxy(),etc.
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include <windows.h>
#include<time.h>
#include <ctype.h>
//list of function prototype
void id_valid_check(void);
void add(void);
void remove_record(void);
void admin(void);
void login(void);
void welcome(void);
void edit(void);
char* exitt(void);
void menu(void);
void id_valid(void);
void p_list(void);
void name_valid_check();
void find(void);
void times();
void room(void);


#endif
