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

    printf(" ＿＿＿\n");
    printf("| 註冊 |\n");
    printf(" ￣￣￣\n");
    printf("輸入使用者名稱:");
    scanf("%s", name);
    strcpy(user.name, name);

    for (i = 0; i < USER_MAX; i++) 
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