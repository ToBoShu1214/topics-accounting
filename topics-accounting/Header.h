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

User login();
void writeToFile(User u);
int exist(User u);
void registerUser();
int login_menu();

int prog_menu();
ListItem account(int choice, int count);//鍵入data
int writetoFile(ListItem wf, int choice);//將data寫入檔案
void scantoarray();//抓檔案data至陣列
int JudgmentDate(char date[20], int choice, int count);//判斷使用者輸入時間的合法性
void output(int choice, char search[20]);