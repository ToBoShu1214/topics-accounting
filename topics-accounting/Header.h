// Header.h
#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  

static char* incometxt = "income.txt";
static char* expendtxt = "expend.txt";

#define USER_MAX 20
#define LIST_MAX 100

typedef struct {
    char name[20];
    char password[20];
} User;

typedef struct {
    char date[20];
    char category[20];
    char amount[20];
} ListItem;

User list[USER_MAX];//﹚竡办┦皚(祅爹╰参)
ListItem income[LIST_MAX];//﹚竡办┦皚(癘眀╰参.や)
ListItem expend[LIST_MAX];//﹚竡办┦皚(癘眀╰参.Μ)

User login();
void writeToFile(User u);
int exist(User u);
void registerUser();
int login_menu();

int prog_menu();
ListItem account(int choice, int count);
int writetoFile(ListItem wf, int choice);
void scantoarray();
int JudgmentDate(char date[20], int choice, int count);
void output(int choice, char search[20]);

#endif // HEADER_H