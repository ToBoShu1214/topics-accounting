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

User login();
void writeToFile(User u);
int exist(User u);
void registerUser();
int login_menu();

int prog_menu();
ListItem account(int choice, int count);//��Jdata
int writetoFile(ListItem wf, int choice);//�Ndata�g�J�ɮ�
void scantoarray();//���ɮ�data�ܰ}�C
int JudgmentDate(char date[20], int choice, int count);//�P�_�ϥΪ̿�J�ɶ����X�k��
void output(int choice, char search[20]);