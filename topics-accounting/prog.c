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
User;//�w�q�@�Ӧs��ϥΪ̪����c��

typedef struct
{
	char date[20];//���
	char category[20];//����
	char amount[20];//���B
}
ListItem;//�w�q�@�Ӧs��b�ت����c��

User list[USER_MAX];//�w�q�@�ӥ���ʰ}�C(�n�J���U�t��)
ListItem income[LIST_MAX];//�w�q�@�ӥ���ʰ}�C(�O�b�t��.��X)
ListItem expend[LIST_MAX];//�w�q�@�ӥ���ʰ}�C(�O�b�t��.���J)

User login()//�n�J�禡
{
	char name[20];
	char password[20];
	User lg;
	printf(" �ġġ�\n");
	printf("| �n�J |\n");
	printf(" �áá�\n");
	printf("��J�ϥΪ̦W��:");
	scanf("%s", name);
	strcpy(lg.name, name);
	printf("��J�ϥΪ̱K�X:");
	scanf("%s", password);
	strcpy(lg.password, password);
	return lg;
}

void writeToFile(User u)//�g�Jtxt�ɮסA�C�@��s�b�@�ӨϥΪ�
{
	FILE* fw = fopen("user.txt", "a+");
	fprintf(fw, u.name);
	fprintf(fw, "\t");
	fprintf(fw, u.password);
	fprintf(fw, "\n");
	fclose(fw);
}

int exist(User u)//�P�_�O�_�s�b�ӨϥΪ�
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

void registerUser()//���U�ϥΪ�
{
	char name[20];
	char password[20];
	User user;
	int i;

	printf(" �ġġ�\n");
	printf("| ���U |\n");
	printf(" �áá�\n");
	printf("��J�ϥΪ̦W��:");
	scanf("%s", name);
	strcpy(user.name, name);//�ƻs�r��

	for (i = 0; i < USER_MAX; i++)//�P�_���U���ϥΪ̬O�_�w�s�b
	{
		if (0 == strcmp(list[i].name, name))
		{
			printf("�ϥΪ̦W�٤w�g�s�b\n");
			return;
		}
	}

	printf("��J�ϥΪ̱K�X:");
	scanf("%s", password);
	strcpy(user.password, password);
	writeToFile(user);
	printf("���U���\\n");
}

int login_menu()
{
	int choice;

	printf(" �ġġġġġ�\n");
	printf("| �n�J�B���U |\n");
	printf(" �ááááá�\n");
	printf("1.�n�J\n");
	printf("2.���U\n");
	printf("#.���}\n");
	printf("��J�A�����:");
	scanf("%d", &choice);
	return choice;
}

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

ListItem account(int pchoice)//��Jdata
{
	while (1)
	{
		char date[20];
		char category[20];
		char amount[20];
		char choice;
		ListItem ac;
		system("cls");
		printf(" �ġġ�\n");
		printf("| �O�b |\n");
		printf(" �áá�\n");
		printf("��J���(mmdd):");
		scanf("%s", date);
		strcpy(ac.date, date);
		printf("��J���O:");
		scanf("%s", category);
		strcpy(ac.category, category);
		printf("��J���B:");
		scanf("%s", &amount);
		rewind(stdin);//����enter
		strcpy(ac.amount, amount);
		writetoFile(ac, pchoice);
		printf("�O�_���}(Y):");
		scanf("%c", &choice);
		if (choice == 'Y' || choice == 'y')
			return;
		system("cls");
	}
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

void output(int choice, char search[20])
{
	int i, cmd = 0, tmp, total = 0, mtotal = 0; ;
	char null[1] = { '\0' };
	if (choice == 1)//�d���
	{
		printf("-----%s��X-----\n", search);
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

	else if (choice == 2)//�d���O
	{
		printf("-----%s��X-----\n", search);
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
			printf("%s\t", expend[i].date);
			printf("%s\t", expend[i].category);
			printf("%s\n", expend[i].amount);
		}
		printf("---------------\n\n");
		return;
	}

	else if (choice == 5)//�d���J
	{
		printf("-----�`���J-----\n");
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

		printf("�`���䬰%d��\n\n", total + mtotal);
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
	for (i = 0; i < USER_MAX; i++)
	{
		char uname[20];
		char upassword[20];
		fscanf(fu, "%s%s", uname, upassword);

		strcpy(list[i].name, uname);
		strcpy(list[i].password, upassword);
	}
	while (1)
	{
		int choice = login_menu();

		if (1 == choice)
		{
			system("cls");
			u = login();
			if (1 == exist(u))
			{
				printf("�n�J���\");
				Sleep(1000);
				system("cls");//clear
				break;
			}
			else
			{
				printf("���~���ϥΪ̩αK�X\n");
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
prog://�O�b�{���϶�
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

			if (choice == 1)//�O�b
			{
				account(choice);
				system("cls");//clear
			}
			else if (choice == 2)//�d�b
			{
				system("cls");//clear
				while (1)
				{
					printf(" �ġġ�\n");
					printf("| �d�b |\n");
					printf(" �áá�\n");
					choice = 0;
					printf("1.�d�ߤ��\n");
					printf("2.�d�����O\n");
					printf("3.�d�ߪ�����`��X\n");
					printf("4.�d�ߥ�����X\n");
					printf("5.�^�D���\n");
					printf("#.�n�X\n");
					printf("��J�A�����:");
					scanf("%d", &choice);
					if (choice == 1)//�d���
					{
						system("cls");//clear
						printf("��J�Q�d�ߪ����(mmdd):");
						scanf("%s", search);
						output(choice, search);
					}
					else if (choice == 2)//�d���O
					{
						system("cls");//clear
						printf("��J�Q�d�ߪ����O:");
						scanf("%s", search);
						output(choice, search);
					}
					else if (choice == 3)//�d���X
					{
						system("cls");//clear
						printf("��J�Q�d�ߪ�����`��X:");
						scanf("%s", search);
						output(choice, search);
					}
					else if (choice == 4)
					{
						system("cls");//clear
						output(choice, search);
					}
					else if (choice == 5)//�^���
					{
						system("cls");//clear
						break;
					}
					else
					{
						system("cls");//clear
						printf("�w�n�X");
						exit(0);
					}
				}
			}
			else if (choice == 3)//�O���J
			{
				account(choice);
				system("cls");//clear
			}
			else if (choice == 4)//�d���J
			{
				system("cls");//clear
				choice++;//�boutput�̬�5����
				output(choice, search);
			}
			else if (choice == 5)//���q
			{
				while (1)
				{
					choice = 0;
					rewind(stdin);
					printf("1.�d�ߤ리��\n");
					printf("2.�d���`����\n");
					printf("��J�A�����:");
					scanf("%d", &choice);
					if (choice == 1)//�d�리�q
					{
						system("cls");//clear
						printf("��J�Q�d�ߪ�����`����:");
						scanf("%s", search);
						choice += 5;//�boutput�̬�6����
						output(choice, search);
						break;
					}
					else if (choice == 2)//�d�`���q
					{
						system("cls");//clear
						choice += 5;//�boutput�̬�7����
						output(choice, search);
						break;
					}
					else
					{
						printf("��J���~");
						Sleep(1000);
						system("cls");
						continue;
					}
				}
			}
			else
			{
				system("cls");//clear
				printf("�w�n�X");
				exit(0);
			}
		}
	}
}