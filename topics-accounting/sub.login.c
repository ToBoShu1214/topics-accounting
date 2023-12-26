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

    printf(" ＿＿＿\n");
    printf("| 註冊 |\n");
    printf(" ￣￣￣\n");
    printf("輸入使用者名稱:");
    scanf("%s", name);
    rewind(stdin);
    for (ri = 0; ri < USER_MAX; ri++) 
    {
        if (strcmp(list[ri].name, null) == 0)
            break;
        if (strcmp(list[ri].name, name) == 0)
        {
            printf("使用者名稱已經存在\n");
            return;
        }
    }
    strcpy(user.name, name);
    printf("輸入使用者密碼:");
    scanf("%s", password);
    rewind(stdin);
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
    //rewind(stdin);
    return choice;
}

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
    //rewind(stdin);
    strcpy(lg.name, name);
    printf("輸入使用者密碼:");
    scanf("%s", password);
    //rewind(stdin);
    strcpy(lg.password, password);
    return lg;
}