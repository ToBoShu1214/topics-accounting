#include "Header.h"

static void writeToFile(User u) 
{
    FILE* fw = fopen("user.txt", "a+");
    fprintf(fw, u.name);
    fprintf(fw, "\t");
    fprintf(fw, u.password);
    fprintf(fw, "\n");
    fclose(fw);
}

int exist(User u) 
{
    int i;
    for (i = 0; i < USER_MAX; i++) {
        if (0 == strcmp(list[i].name, u.name) && 0 == strcmp(list[i].password, u.password)) {
            return 1;
        }
    }
    return -1;
}

void registerUser() 
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
    strcpy(user.name, name);

    for (i = 0; i < USER_MAX; i++) 
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