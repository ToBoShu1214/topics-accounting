#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>//Sleep


#define USER_MAX 20
#define LIST_MAX 100

char* incometxt = "income.txt";
char* expendtxt = "expend.txt";

typedef struct
{
	char name[20];
	char password[20];
}
User;//定義一個存放使用者的結構體

typedef struct
{
	char date[20];//日期
	char category[20];//種類
	char amount[20];//金額
}
ListItem;//定義一個存放帳目的結構體

User list[USER_MAX];//定義一個全域性陣列(登入註冊系統)
ListItem income[LIST_MAX];//定義一個全域性陣列(記帳系統.支出)
ListItem expend[LIST_MAX];//定義一個全域性陣列(記帳系統.收入)

User login()//登入函式
{
	char name[20];
	char password[20];
	User lg;
	printf(" ＿＿＿\n");
	printf("| 登入 |\n");
	printf(" ￣￣￣\n");
	printf("輸入使用者名稱:");
	scanf("%s", name);
	strcpy(lg.name, name);
	printf("輸入使用者密碼:");
	scanf("%s", password);
	strcpy(lg.password, password);
	return lg;
}

void writeToFile(User u)//寫入txt檔案，每一行存在一個使用者
{
	FILE* fw = fopen("user.txt", "a+");
	fprintf(fw, u.name);
	fprintf(fw, "\t");
	fprintf(fw, u.password);
	fprintf(fw, "\n");
	fclose(fw);
}

int exist(User u)//判斷是否存在該使用者
{
	int i;
	for (i = 0; i < USER_MAX; i++)
	{
		if (0 == strcmp(list[i].name, u.name) && 0 == strcmp(list[i].password, u.password))
		{
			return 1;
		}
	}
	return -1;
}

void registerUser()//註冊使用者
{
	char name[20];
	char password[20];
	User user;
	int i;

	printf(" ＿＿＿\n");
	printf("| 註冊 |\n");
	printf(" ￣￣￣\n");
	printf("輸入使用者名稱:");
	scanf("%s", name);
	strcpy(user.name, name);//複製字串

	for (i = 0; i < USER_MAX; i++)//判斷註冊的使用者是否已存在
	{
		if (0 == strcmp(list[i].name, name))
		{
			printf("使用者名稱已經存在\n");
			return;
		}
	}

	printf("輸入使用者密碼:");
	scanf("%s", password);
	strcpy(user.password, password);
	writeToFile(user);
	printf("註冊成功\n");
}

int login_menu()
{
	int choice;

	printf(" ＿＿＿＿＿＿\n");
	printf("| 登入、註冊 |\n");
	printf(" ￣￣￣￣￣￣\n");
	printf("1.登入\n");
	printf("2.註冊\n");
	printf("#.離開\n");
	printf("輸入你的選擇:");
	scanf("%d", &choice);
	return choice;
}

int prog_menu()
{
	printf(" ＿＿＿＿\n");
	printf("| 主選單 |\n");
	printf(" ￣￣￣￣\n");
	rewind(stdin);
	int choice = 0;
	printf("1.記帳\n");
	printf("2.查帳\n");
	printf("3.記收入\n");
	printf("4.查收入\n");
	printf("5.查詢收益\n");
	printf("#.登出\n");
	printf("輸入你的選擇:");
	scanf("%d", &choice);
	return choice;
}

ListItem account(int pchoice)//鍵入data
{
	while (1)
	{
		char date[20];
		char category[20];
		char amount[20];
		char choice;
		ListItem ac;
		system("cls");
		printf(" ＿＿＿\n");
		printf("| 記帳 |\n");
		printf(" ￣￣￣\n");
		printf("輸入日期(mmdd):");
		scanf("%s", date);
		strcpy(ac.date, date);
		printf("輸入類別:");
		scanf("%s", category);
		strcpy(ac.category, category);
		printf("輸入金額:");
		scanf("%s", &amount);
		rewind(stdin);//消除enter
		strcpy(ac.amount, amount);
		writetoFile(ac, pchoice);
		printf("是否離開(Y):");
		scanf("%c", &choice);
		if (choice == 'Y' || choice == 'y')
			return;
		system("cls");
	}
}

int writetoFile(ListItem wf, int choice)//將data寫入檔案
{
	char cmd[20];
	if (choice == 1)
		strcpy(cmd, expendtxt);
	else if (choice == 3)
		strcpy(cmd, incometxt);
	else
		return -1;

	FILE* fw1 = fopen(cmd, "a+");
	fprintf(fw1, wf.date);
	fprintf(fw1, "\t");
	fprintf(fw1, wf.category);
	fprintf(fw1, "\t");
	fprintf(fw1, wf.amount);
	fprintf(fw1, "\n");
	fclose(fw1);
	return;
}

void scantoarray()//抓檔案data至陣列
{
	int i, j, ROW = LIST_MAX, COL = 3;

	FILE* fe = fopen(expendtxt, "r");
	FILE* fi = fopen(incometxt, "r");
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (j == 0)
			{
				fscanf(fe, "%s", &expend[i].date);
				fscanf(fi, "%s", &income[i].date);
			}
			else if (j == 1)
			{
				fscanf(fe, "%s", &expend[i].category);
				fscanf(fi, "%s", &income[i].category);
			}
			else if (j == 2)
			{
				fscanf(fe, "%s", &expend[i].amount);
				fscanf(fi, "%s", &income[i].amount);
			}
		}
	}
	fclose(fe);
	fclose(fi);
	return;
}

void output(int choice, char search[20])
{
	int i, cmd = 0, tmp, total = 0, mtotal = 0; ;
	char null[1] = { '\0' };
	if (choice == 1)//查日期
	{
		printf("-----%s支出-----\n", search);
		for (i = 0; i < LIST_MAX; i++)
		{
			if (strcmp(search, expend[i].date) == 0)
			{
				printf("%s\t", expend[i].category);
				printf("%s\n", expend[i].amount);
			}
		}
		printf("--------------------\n\n");
		return;
	}

	else if (choice == 2)//查類別
	{
		printf("-----%s支出-----\n", search);
		for (i = 0; i < LIST_MAX; i++)
		{
			if (strcmp(search, expend[i].category) == 0)
			{
				printf("%s\t", expend[i].date);
				printf("%s\n", expend[i].amount);
			}
		}
		printf("------------------\n\n");
		return;
	}

	else if (choice == 3)//查月支出
	{
		for (i = 0; i < LIST_MAX; i++)
		{
			cmd = atoi(search);
			tmp = atoi(expend[i].date);//atoi為將字元陣列強制轉換為整數
			tmp /= 100;
			if (tmp == cmd)
				total += atoi(expend[i].amount);
		}
		printf("%s月份總支出為%d元\n\n", search, total);
		return;
	}
	else if (choice == 4)//查全部支出
	{
		printf("-----總支出-----\n");
		for (i = 0; i < LIST_MAX; i++)
		{
			if (strcmp(null, expend[i].date) == 0)
				break;
			printf("%s\t", expend[i].date);
			printf("%s\t", expend[i].category);
			printf("%s\n", expend[i].amount);
		}
		printf("---------------\n\n");
		return;
	}

	else if (choice == 5)//查收入
	{
		printf("-----總收入-----\n");
		for (i = 0; i < LIST_MAX; i++)
		{
			if (strcmp(null, income[i].date) == 0)
				break;
			printf("%s\t", income[i].date);
			printf("%s\t", income[i].category);
			printf("%s\n", income[i].amount);
		}
		printf("---------------\n\n");
		return;
	}
	else if (choice == 6)//查月收支
	{
		cmd = atoi(search);
		mtotal = 0;
		total = 0;
		for (i = 0; i < LIST_MAX; i++)
		{
			tmp = atoi(expend[i].date);//atoi為將字元陣列強制轉換為整數
			tmp /= 100;
			if (tmp == cmd)
				mtotal += -(atoi(expend[i].amount));

			tmp = atoi(income[i].date);//atoi為將字元陣列強制轉換為整數
			tmp /= 100;
			if (tmp == cmd)
				total += atoi(income[i].amount);
		}
		printf("%s月份總收支為%d元\n\n", search, total + mtotal);
		return;
	}
	else if (choice == 7)//查總收支
	{
		mtotal = 0;
		total = 0;
		for (i = 0; i < LIST_MAX; i++)
		{
			if (strcmp(null, expend[i].date) == 0)
				break;
			mtotal += -(atoi(expend[i].amount));

		}
		for (i = 0; i < LIST_MAX; i++)
		{
			if (strcmp(null, income[i].date) == 0)
				break;
			total += atoi(income[i].amount);
		}

		printf("總收支為%d元\n\n", total + mtotal);
		return;
	}

}

int main()
{

	FILE* fu = fopen("user.txt", "r");
	int i = 0;
	User u;
	if (NULL == fu)
	{
		printf("FILE NOT FOUND(u)");
		return -1;
	}
	
	while (1)
	{
		for (i = 0; i < USER_MAX; i++)
		{
			char uname[20];
			char upassword[20];
			fscanf(fu, "%s%s", uname, upassword);

			strcpy(list[i].name, uname);
			strcpy(list[i].password, upassword);
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
		int  choice;
		int i = 0;
		char search[20];
		while (1)
		{
			scantoarray();
			int choice = 0;
			choice = prog_menu();

			if (choice == 1)//記帳
			{
				account(choice);
				system("cls");//clear
			}
			else if (choice == 2)//查帳
			{
				system("cls");//clear
				while (1)
				{
					printf(" ＿＿＿\n");
					printf("| 查帳 |\n");
					printf(" ￣￣￣\n");
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
				account(choice);
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
