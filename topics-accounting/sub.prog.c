#include "Header.h"
#include <time.h>
int prog_menu()
{
	printf(" �ġġġ�\n");
	printf("| �D��� |\n");
	printf(" �ááá�\n");
	rewind(stdin);
	int choice = 0;
	printf("1.�O�b\n");
	printf("2.�d�b\n");
	printf("3.�O���J\n");
	printf("4.�d���J\n");
	printf("5.�d�ߦ��q\n");
	printf("#.�n�X\n");
	printf("��J�A�����:");
	scanf("%d", &choice);
	return choice;
}

ListItem account(int choice, int count)//��Jdata
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
		printf(" �ġġ�\n");
		printf("| �O�b |\n");
		printf(" �áá�\n");
		printf("��%d�����\n\n", save + 1 - count);
		printf("��J���(mmdd):");
		scanf("%s", date);
		if (JudgmentDate(date, choice, count) == -1)
			continue;
		strcpy(ac.date, date);
		printf("��J���O:");
		scanf("%s", category);
		strcpy(ac.category, category);
		printf("��J���B:");
		scanf("%s", &amount);
		strcpy(ac.amount, amount);
		writetoFile(ac, choice);
		count--;
		system("cls");
	} while (count != 0);
	system("cls");
	printf("�O�b�����A�N��^�D���");
	Sleep(1500);
	system("cls");
	return;
}

int writetoFile(ListItem wf, int choice)//�Ndata�g�J�ɮ�
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

void scantoarray()//���ɮ�data�ܰ}�C
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

int JudgmentDate(char date[20], int choice, int count)//�P�_�ϥΪ̿�J�ɶ����X�k��
{
	time_t currentTime;
	struct tm* localTime;

	time(&currentTime);
	localTime = localtime(&currentTime);
	int Leap = (localTime->tm_year + 1900 % 4 == 0 && localTime->tm_year + 1900 % 100 != 0) || (localTime->tm_year + 1900 % 400 == 0) ? 29 : 28;//�P�O�O�_���|�~
	int month, day;
	month = atoi(date) / 100;
	day = atoi(date) % 100;
	if (month > 12 || month <= 0)
	{
		printf("�����J���~\n");
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
			printf("�����J���~\n");
			Sleep(1000);
			return -1;
		}
	case 2:
		if ((day <= Leap) && (day > 0))
			break;
		else
		{
			printf("�����J���~\n");
			Sleep(1000);
			return -1;
		}
	default:
		if ((day <= 31) && (day > 0))
			break;
		else
		{
			printf("�����J���~\n");
			Sleep(1000);
			return -1;
		}
	}
}

void output(int choice, char search[20])
{
	int i, cmd = 0, tmp, total = 0, mtotal = 0, iFlag = 0; ;
	char null[1] = { '\0' };
	cmd = atoi(search);
	if (choice == 1)//�d���
	{
		printf("-----%02d/%02d��X-----\n", cmd / 100, cmd % 100);
		for (i = 0; i < LIST_MAX; i++)
		{
			if (strcmp(search, expend[i].date) == 0)
			{
				printf("%s\t", expend[i].category);
				printf("%s\n", expend[i].amount);
				iFlag = 1;
			}
		}
		printf("--------------------\n\n");
		if (iFlag == 0)
		{
			system("cls");
			printf("���d�ߨ�%02d/%02d�������X\n\n", cmd / 100, cmd % 100);
		}
		return;
	}

	else if (choice == 2)//�d���O
	{
		printf("-----%s��X-----\n", search);
		for (i = 0; i < LIST_MAX; i++)
		{
			if (strcmp(search, expend[i].category) == 0)
			{
				printf("%s\t", expend[i].date);
				printf("%s\n", expend[i].amount);
				iFlag = 1;
			}
		}
		printf("------------------\n\n");
		if (iFlag == 0)
		{
			system("cls");
			printf("���d�ߨ�\"%s\"���O�������X\n\n", search);
		}
		return;
	}

	else if (choice == 3)//�d���X
	{
		for (i = 0; i < LIST_MAX; i++)
		{
			cmd = atoi(search);
			tmp = atoi(expend[i].date);//atoi���N�r���}�C�j���ഫ�����
			tmp /= 100;
			if (tmp == cmd)
				total += atoi(expend[i].amount);
		}
		if (total == 0)
		{
			system("cls");
			printf("���d�ߨ�%s�릳�����X\n\n", search);
			return;
		}
		printf("%s����`��X��%d��\n\n", search, total);
		return;
	}
	else if (choice == 4)//�d������X
	{
		printf("-----�`��X-----\n");
		for (i = 0; i < LIST_MAX; i++)
		{
			if (strcmp(null, expend[i].date) == 0)
				break;
			printf("%04s\t", expend[i].date);
			printf("%s\t", expend[i].category);
			printf("%s\n", expend[i].amount);
			iFlag = 1;
		}
		printf("---------------\n\n");
		if (iFlag == 0)
		{
			system("cls");
			printf("���d�ߨ즳�����X\n\n");
		}
		return;
	}

	else if (choice == 5)//�d���J
	{
		printf("-----�`���J-----\n");
		for (i = 0; i < LIST_MAX; i++)
		{
			if (strcmp(null, income[i].date) == 0)
				break;
			printf("%04s\t", income[i].date);
			printf("%s\t", income[i].category);
			printf("%s\n", income[i].amount);
			iFlag = 1;
		}
		printf("---------------\n\n");
		if (iFlag == 0)
		{
			system("cls");
			printf("���d�ߨ즳���󦬤J\n\n");
		}
		return;
	}
	else if (choice == 6)//�d�리��
	{
		cmd = atoi(search);
		mtotal = 0;
		total = 0;
		for (i = 0; i < LIST_MAX; i++)
		{
			tmp = atoi(expend[i].date);//atoi���N�r���}�C�j���ഫ�����
			tmp /= 100;
			if (tmp == cmd)
				mtotal += -(atoi(expend[i].amount));

			tmp = atoi(income[i].date);//atoi���N�r���}�C�j���ഫ�����
			tmp /= 100;
			if (tmp == cmd)
				total += atoi(income[i].amount);
		}
		if (total == 0)
		{
			system("cls");
			printf("���d�ߨ�%s�릳���󦬤�\n\n", search);
			return;
		}
		printf("%s����`���䬰%d��\n\n", search, total + mtotal);
		return;
	}
	else if (choice == 7)//�d�`����
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
		if (total + mtotal == 0)
		{
			system("cls");
			printf("���d�ߨ즳���󦬤�\n\n");
			return;
		}
		printf("�`���䬰%d��\n\n", total + mtotal);
		return;
	}
}