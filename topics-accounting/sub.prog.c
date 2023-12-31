#include "Header.h"
#include <time.h>
int prog_menu()
{
	printf(" ＿＿＿＿\n");
	printf("| 主選單 |\n");
	printf(" ￣￣￣￣\n");
	rewind(stdin);
	int choice = 0;
	printf("1.記支出\n");
	printf("2.查支出\n");
	printf("3.記收入\n");
	printf("4.查收入\n");
	printf("5.查詢收益\n");
	printf("#.登出\n");
	printf("輸入你的選擇:");
	scanf("%d", &choice);
	return choice;
}

ListItem account(int choice, int count)//鍵入data
{
	int save;
	char date[20];
	char category[20];
	char amount[20];
	char cchoice;
	ListItem ac;
	save = count;
	do {
		system("cls");
		printf(" ＿＿＿＿\n");
		printf("| 記支出 |\n");
		printf(" ￣￣￣￣\n");
		printf("第%d筆資料\n\n", save + 1 - count);
		if (choice == 3)
		{
			system("cls");
			printf(" ＿＿＿＿\n");
			printf("| 記收入 |\n");
			printf(" ￣￣￣￣\n");
		}
		printf("輸入日期(mmdd):");
		scanf("%s", date);
		
		if (JudgmentDate(date, choice, count) == -1)
			continue;
		strcpy(ac.date, date);
		printf("輸入類別:");
		scanf("%s", category);
		strcpy(ac.category, category);
		printf("輸入金額:");
		scanf("%s", &amount);
		strcpy(ac.amount, amount);
		writetoFile(ac, choice);
		count--;
		system("cls");
	} while (count != 0);
	system("cls");
	printf("記帳結束，將返回主選單");
	Sleep(1500);
	system("cls");
	return;
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
	int si, sj, ROW = LIST_MAX, COL = 3;

	FILE* fe = fopen(expendtxt, "r");
	FILE* fi = fopen(incometxt, "r");
	for (si = 0; si < ROW; si++)
	{
		for (sj = 0; sj < COL; sj++)
		{
			if (sj == 0)
			{
				fscanf(fe, "%s", &expend[si].date);
				fscanf(fi, "%s", &income[si].date);
			}
			else if (sj == 1)
			{
				fscanf(fe, "%s", &expend[si].category);
				fscanf(fi, "%s", &income[si].category);
			}
			else if (sj == 2)
			{
				fscanf(fe, "%s", &expend[si].amount);
				fscanf(fi, "%s", &income[si].amount);
			}
		}
	}
	fclose(fe);
	fclose(fi);
	return;
}

int JudgmentDate(char date[20], int choice, int count)//判斷使用者輸入時間的合法性
{
	time_t currentTime;
	struct tm* localTime;

	time(&currentTime);
	localTime = localtime(&currentTime);
	int Leap = (localTime->tm_year + 1900 % 4 == 0 && localTime->tm_year + 1900 % 100 != 0) || (localTime->tm_year + 1900 % 400 == 0) ? 29 : 28;//判別是否為閏年
	int month, day;
	month = atoi(date) / 100;
	day = atoi(date) % 100;
	if (month > 12 || month <= 0)
	{
		printf("日期輸入錯誤\n");
		Sleep(1000);
		return -1;
	}
	switch (month)
	{
	case 4: case 6: case 9: case 11:
		if ((day <= 30) && (day % 100 > 0))
			break;
		else
		{
			printf("日期輸入錯誤\n");
			Sleep(1000);
			return -1;
		}
	case 2:
		if ((day <= Leap) && (day > 0))
			break;
		else
		{
			printf("日期輸入錯誤\n");
			Sleep(1000);
			return -1;
		}
	default:
		if ((day <= 31) && (day > 0))
			break;
		else
		{
			printf("日期輸入錯誤\n");
			Sleep(1000);
			return -1;
		}
	}
}

void output(int choice, char search[20])
{
	int oi, cmd = 0, tmp, total = 0, mtotal = 0, iFlag = 0; ;
	char null[1] = { '\0' };
	cmd = atoi(search);
	if (choice == 1)//查日期
	{
		printf("-----%02d/%02d支出-----\n", cmd / 100, cmd % 100);
		for (oi = 0; oi < LIST_MAX; oi++)
		{
			if (strcmp(search, expend[oi].date) == 0)
			{
				printf("%s\t", expend[oi].category);
				printf("%s\n", expend[oi].amount);
				iFlag = 1;
			}
		}
		printf("--------------------\n\n");
		if (iFlag == 0)
		{
			system("cls");
			printf("未查詢到%02d/%02d有任何支出\n\n", cmd / 100, cmd % 100);
		}
		return;
	}

	else if (choice == 2)//查類別
	{
		printf("-----%s支出-----\n", search);
		for (oi = 0; oi < LIST_MAX; oi++)
		{
			if (strcmp(search, expend[oi].category) == 0)
			{
				printf("%s\t", expend[oi].date);
				printf("%s\n", expend[oi].amount);
				iFlag = 1;
			}
		}
		printf("------------------\n\n");
		if (iFlag == 0)
		{
			system("cls");
			printf("未查詢到\"%s\"類別有任何支出\n\n", search);
		}
		return;
	}

	else if (choice == 3)//查月支出
	{
		printf("-----%02d月支出-----\n", cmd);
		for (oi = 0; oi < LIST_MAX; oi++)
		{
			cmd = atoi(search);
			tmp = atoi(expend[oi].date);//atoi為將字元陣列強制轉換為整數
			tmp /= 100;
			if (tmp == cmd)
			{
				printf("%s\t", expend[oi].category);
				printf("%s\n", expend[oi].amount);
				total += atoi(expend[oi].amount);
			}
		}
		printf("------------------\n\n");
		if (total == 0)
		{
			system("cls");
			printf("未查詢到%s月有任何支出\n\n", search);
			return;
		}
		printf("%s月份總支出為%d元\n\n", search, total);
		return;
	}
	else if (choice == 4)//查全部支出
	{
		printf("-----總支出-----\n");
		for (oi = 0; oi < LIST_MAX; oi++)
		{
			if (strcmp(null, expend[oi].date) == 0)
				break;
			printf("%04s\t", expend[oi].date);
			printf("%s\t", expend[oi].category);
			printf("%s\n", expend[oi].amount);
			total += atoi(expend[oi].amount);
			iFlag = 1;
		}
		printf("---------------\n\n");
		if (iFlag == 0)
		{
			system("cls");
			printf("未查詢到有任何支出\n\n");
			return;
		}
		printf("總支出為%d元\n\n", total);
	}

	else if (choice == 5)//查收入
	{
		printf("-----總收入-----\n");
		for (oi = 0; oi < LIST_MAX; oi++)
		{
			if (strcmp(null, income[oi].date) == 0)
				break;
			printf("%04s\t", income[oi].date);
			printf("%s\t", income[oi].category);
			printf("%s\n", income[oi].amount);
			iFlag = 1;
		}
		printf("---------------\n\n");
		if (iFlag == 0)
		{
			system("cls");
			printf("未查詢到有任何收入\n\n");
		}
		return;
	}
	else if (choice == 6)//查月收支
	{
		cmd = atoi(search);
		mtotal = 0;
		total = 0;
		for (oi = 0; oi < LIST_MAX; oi++)
		{
			tmp = atoi(expend[oi].date);//atoi為將字元陣列強制轉換為整數
			tmp /= 100;
			if (strcmp(null, expend[oi].date) == 0)//無資料就脫離迴圈
				break;
			if (tmp == cmd)
				mtotal += -(atoi(expend[oi].amount));
		}
		for (oi = 0; oi < LIST_MAX; oi++)
		{
			tmp = atoi(income[oi].date);//atoi為將字元陣列強制轉換為整數
			tmp /= 100;
			if (strcmp(null, income[oi].date) == 0)//無資料就脫離迴圈
				break;
			if (tmp == cmd)
				total += atoi(income[oi].amount);
		}
		if (total + mtotal == 0)
		{
			system("cls");
			printf("未查詢到%s月有任何收支\n\n", search);
			return;
		}
		printf("%s月份總收支為%d元\n\n", search, total + mtotal);
		return;
	}
	else if (choice == 7)//查總收支
	{
		mtotal = 0;
		total = 0;
		for (oi = 0; oi < LIST_MAX; oi++)
		{
			if (strcmp(null, expend[oi].date) == 0)//無資料就脫離迴圈
				break;
			mtotal += -(atoi(expend[oi].amount));

		}
		for (oi = 0; oi < LIST_MAX; oi++)
		{
			if (strcmp(null, income[oi].date) == 0)//無資料就脫離迴圈
				break;
			total += atoi(income[oi].amount);
		}
		if (total + mtotal == 0)
		{
			system("cls");
			printf("未查詢到有任何收支\n\n");
			return;
		}
		printf("總收支為%d元\n\n", total + mtotal);
		return;
	}
}