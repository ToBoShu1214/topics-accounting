// Header.h
#pragma once
//#ifndef HEADER_H
//#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  

static char* incometxt = "income.txt";
static char* expendtxt = "expend.txt";

#define USER_MAX 20
#define LIST_MAX 100

typedef struct {
    char name[20];
    char password[20];
}
User;

//User lg;
User list[USER_MAX];//�w�q�@�ӥ���ʰ}�C(�n�J���U�t��)

typedef struct {
    char date[20];
    char category[20];
    char amount[20];
} ListItem;


ListItem income[LIST_MAX];//�w�q�@�ӥ���ʰ}�C(�O�b�t��.��X)
ListItem expend[LIST_MAX];//�w�q�@�ӥ���ʰ}�C(�O�b�t��.���J)

User login();
void writeToFile(User );
int exist(User );
void registerUser();
int login_menu();

int prog_menu();
ListItem account(int , int);
int writetoFile(ListItem , int );
void scantoarray();
int JudgmentDate(char [20], int , int );
void output(int , char [20]);

//#endif // HEADER_H