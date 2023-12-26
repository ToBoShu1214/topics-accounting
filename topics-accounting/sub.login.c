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
    int ei;
    for (ei = 0; ei < USER_MAX; ei++) {
        if (0 == strcmp(list[ei].name, u.name) && 0 == strcmp(list[ei].password, u.password)) {
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
    int ri = 0;
    char null[1] = { '\0' };

    printf(" �ġġ�\n");
    printf("| ���U |\n");
    printf(" �áá�\n");
    printf("��J�ϥΪ̦W��:");
    scanf("%s", name);
    rewind(stdin);
    for (ri = 0; ri < USER_MAX; ri++) 
    {
        if (strcmp(list[ri].name, null) == 0)
            break;
        if (strcmp(list[ri].name, name) == 0)
        {
            printf("�ϥΪ̦W�٤w�g�s�b\n");
            return;
        }
    }
    strcpy(user.name, name);
    printf("��J�ϥΪ̱K�X:");
    scanf("%s", password);
    rewind(stdin);
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
    //rewind(stdin);
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
    //rewind(stdin);
    strcpy(lg.name, name);
    printf("��J�ϥΪ̱K�X:");
    scanf("%s", password);
    //rewind(stdin);
    strcpy(lg.password, password);
    return lg;
}