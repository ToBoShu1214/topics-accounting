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
		int  choice,count;
		int i = 0;
		char search[20];
		while (1)
		{
			scantoarray();
			int choice = 0;
			choice = prog_menu();

			if (choice == 1)//�O�b
			{
				system("cls");//clear
				printf(" �ġġġ�\n");
				printf("| �O��X |\n");
				printf(" �ááá�\n");
				printf("�п�J�n�O�X�����:");
				scanf("%d", &count);
				account(choice,count);
			}
			else if (choice == 2)//�d�b
			{
				system("cls");//clear
				while (1)
				{
					printf(" �ġġġ�\n");
					printf("| �d��X |\n");
					printf(" �ááá�\n");
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
				count = 1;
				account(choice, count);
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
					system("cls");//clear
					printf(" �ġġġ�\n");
					printf("| �d���� |\n");
					printf(" �ááá�\n");
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
