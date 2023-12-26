#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"
#include <stdlib.h>
#include <string.h>
#include <windows.h>//Sleep

int main()
{
	FILE* fu = fopen("user.txt", "r");
	User u;
	char null[1] = { '\0' };
	if (NULL == fu)
	{
		printf("FILE NOT FOUND(u)");
		return -1;
	}
	time_t currentTime;
	struct tm* localTime;

	time(&currentTime);
	localTime = localtime(&currentTime);
	
	while (1)
	{
		for (int pi = 0; pi < USER_MAX; pi++)
		{
			fscanf(fu, "%s%s", list[pi].name, list[pi].password);
			if (strcmp(list[pi].name, list[pi - 1].name) == 0)
			{
				strcpy(list[pi].name, null);
				strcpy(list[pi].password, null);
				break;
			}
		}

		int choice = login_menu();

		if (1 == choice)
		{
			system("cls");
			u = login();
			if (1 == exist(u))
			{
				printf("登入成功");
				Sleep(1000);
				system("cls");//clear
				break;
			}
			else
			{
				printf("錯誤的使用者或密碼\n");
				Sleep(1000);
				system("cls");//clear
			}
		}
		else if (2 == choice)
		{
			system("cls");//clear
			registerUser();
		}
		else
		{
			system("pause");
			return 0;
		}
	}
	
prog://記帳程式區塊
	{
		FILE* fe = fopen(expendtxt, "r");
		FILE* fi = fopen(incometxt, "r");
		if (NULL == fi || NULL == fe)
		{
			printf("FILE NOT FOUND(e|i)");
			return -1;
		}
		int  choice,count;
		int i = 0;
		char search[20];
		while (1)
		{
			scantoarray();
			int choice = 0;
			choice = prog_menu();

			if (choice == 1)//記帳
			{
				system("cls");//clear
				printf(" ＿＿＿＿\n");
				printf("| 記支出 |\n");
				printf(" ￣￣￣￣\n");
				printf("請輸入要記幾筆資料:");
				scanf("%d", &count);
				account(choice,count);
			}
			else if (choice == 2)//查帳
			{
				system("cls");//clear
				while (1)
				{
					printf(" ＿＿＿＿\n");
					printf("| 查支出 |\n");
					printf(" ￣￣￣￣\n");
					choice = 0;
					printf("1.查詢日期\n");
					printf("2.查詢類別\n");
					printf("3.查詢的月份總支出\n");
					printf("4.查詢全部支出\n");
					printf("5.回主選單\n");
					printf("#.登出\n");
					printf("輸入你的選擇:");
					scanf("%d", &choice);
					if (choice == 1)//查日期
					{
						system("cls");//clear
						printf("輸入想查詢的日期(mmdd):");
						scanf("%s", search);
						output(choice, search);
					}
					else if (choice == 2)//查類別
					{
						system("cls");//clear
						printf("輸入想查詢的類別:");
						scanf("%s", search);
						output(choice, search);
					}
					else if (choice == 3)//查月支出
					{
						system("cls");//clear
						printf("輸入想查詢的月份總支出:");
						scanf("%s", search);
						output(choice, search);
					}
					else if (choice == 4)
					{
						system("cls");//clear
						output(choice, search);
					}
					else if (choice == 5)//回選單
					{
						system("cls");//clear
						break;
					}
					else
					{
						system("cls");//clear
						printf("已登出");
						exit(0);
					}
				}
			}
			else if (choice == 3)//記收入
			{
				count = 1;
				account(choice, count);
				system("cls");//clear
			}
			else if (choice == 4)//查收入
			{
				system("cls");//clear
				choice++;//在output裡為5執行
				output(choice, search);
			}
			else if (choice == 5)//收益
			{
				while (1)
				{
					system("cls");//clear
					printf(" ＿＿＿＿\n");
					printf("| 查收支 |\n");
					printf(" ￣￣￣￣\n");
					choice = 0;
					rewind(stdin);
					printf("1.查詢月收支\n");
					printf("2.查詢總收支\n");
					printf("輸入你的選擇:");
					scanf("%d", &choice);
					if (choice == 1)//查月收益
					{
						system("cls");//clear
						printf("輸入想查詢的月份總收支:");
						scanf("%s", search);
						choice += 5;//在output裡為6執行
						output(choice, search);
						break;
					}
					else if (choice == 2)//查總收益
					{
						system("cls");//clear
						choice += 5;//在output裡為7執行
						output(choice, search);
						break;
					}
					else
					{
						printf("輸入錯誤");
						Sleep(1000);
						system("cls");
						continue;
					}
				}
			}
			else
			{
				system("cls");//clear
				printf("已登出");
				exit(0);
			}
		}
	}
}
