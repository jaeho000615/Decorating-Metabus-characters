#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int main_exit;
void menu();
void close();
void new_character();
void hair_shop();
void market_upload();
void market_see();
void market();

struct {
	int id;
	char name[20];
	int hair;
	int top;
	int bottoms;
	int shoes;
	int money;
	int happy;
} character;

void fordelay(int j)
{
	int i, k;
	for (i = 0; i < j; i++)
		k = i;
}

void new_character()
{
	FILE* ptr;
	int choice;
	ptr = fopen("record.dat", "a+");
	system("cls");
    character_no:
	printf("������ ����� ������ȣ�� �Է��ϼ���.:");
	scanf("%d", &choice);
	while (fscanf(ptr, "%d %s %d %d %d %d %d %d\n", &character.id, &character.name, &character.hair, &character.top, &character.bottoms, &character.shoes, &character.money, &character.happy) != EOF)
	{
		if (choice == character.id)
		{
			printf("\n�̹� �����Ǿ����ϴ�.\n\n");
			fordelay(1000000000);
			goto character_no;

		}
	}
	character.id = choice;
	printf("\n�̸��� �Է��Ͻÿ�:");
	scanf("%s", character.name);
	character.hair = 0;
	character.top = 0;
	character.bottoms = 0;
	character.shoes = 0;
	character.money = 0;
	fprintf(ptr, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, character.bottoms, character.shoes, character.money, 100);
	fclose(ptr);
	printf("\nĳ���Ͱ� ���� �Ǿ����ϴ�.");
    ch:
	printf("\n\n\n\t\t 1���� �Է��ϸ� ���θ޴� 0���� �Է��ϸ� ����:");
	scanf("%d", &main_exit);
	system("cls");
	if (main_exit == 1)
		menu();
	else if (main_exit == 0)
		close();
	else
	{
		printf("\n�ٽ� �Է��Ͻÿ�.\a");
		goto ch;
	}
}

void hair_shop()
{
	FILE* old, * newrec;
	int n = 0;
	old = fopen("record.dat", "r");
	newrec = fopen("new.dat", "w");
	printf("������ȣ�� �Է��Ͻÿ�:");
	scanf("%d", &n);
	while (fscanf(old, "%d %s %d %d %d %d %d %d\n", &character.id, &character.name, &character.hair, &character.top, &character.bottoms, &character.shoes, &character.money, &character.happy) != EOF)
	{
		if (n == character.id)
		{
			int hair = 0;
			system("cls");
			printf("\t1.\n\t@@@@@@@\n\t@@@@@@@\n\t| 0 0 |\n\t|  |  |\n\t| --- |\n\t-------");
			printf("\n\t2.\n\tMMMMMMM\n\t|     |\n\t| 0 0 |\n\t|  |  |\n\t| --- |\n\t-------");
			printf("\n\t3.\n\t_______\n\t|     |\n\t| 0 0 |\n\t|  |  |\n\t| --- |\n\t-------");
			printf("\n\t4.\n\t   *   \n\t   |    \n\t___Y___\n\t| 0 0 |\n\t|  |  |\n\t| --- |\n\t-------");
			printf("\n\t5.\n\to-v^v-o\n\t|     |\n\t| 0 0 |\n\t|  |  |\n\t| --- |\n\t-------");
			printf("\n\t6.\n\t///////\n\t///////\n\t| 0 0 |\n\t|  |  |\n\t| --- |\n\t-------");
			printf("\n\n\t\t�Ӹ� ��Ÿ���� ����ּ���:");
			scanf("%d", &hair);
			fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, hair, character.top, character.bottoms, character.shoes, character.money, character.happy);
			printf("\n���Ͻô� ��Ÿ�Ϸ� �ٲ�����ϴ�.\n");
		}
		else
			fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, character.bottoms, character.shoes, character.money, character.happy);

	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat", "record.dat");
	printf("\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d", &main_exit);
	system("cls");
	if (main_exit == 1)
		menu();
	else
		close();
}

void top_shop()
{
	FILE* old, * newrec;
	int n = 0;
	old = fopen("record.dat", "r");
	newrec = fopen("new.dat", "w");
	printf("������ȣ�� �Է��Ͻÿ�:");
	scanf("%d", &n);
	while (fscanf(old, "%d %s %d %d %d %d %d %d\n", &character.id, &character.name, &character.hair, &character.top, &character.bottoms, &character.shoes, &character.money, &character.happy) != EOF)
	{
		if (n == character.id)
		{
			int top = 0;
			system("cls");
			printf("\n1.\n     ��������\n     ��������\n     ��  ����  ��\n     ��  ����  ��\n     ��  ����  ��\n");
			printf("\n2.\n     ��������\n     ���ᢽ����\n     ��  ����  ��\n     ��  ����  ��\n     ��  ����  ��\n");
			printf("\n3.\n     ��������\n     ��������\n     ��  ����  ��\n     ��  ����  ��\n     ��  ����  ��\n");
			printf("\n4.\n     ��������\n     ���ᢽ����\n     ��  ����  ��\n     ��  ����  ��\n     ��  ����  ��\n");
			printf("\n\n\n������ ����ּ���:");
			scanf("%d", &top);
			fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair,top, character.bottoms, character.shoes, character.money, character.happy);
			printf("\n���Ͻô� ��Ÿ�Ϸ� �ٲ�����ϴ�.\n");
		}
		else
			fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, character.bottoms, character.shoes, character.money, character.happy);

	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat", "record.dat");
	printf("\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d", &main_exit);
	system("cls");
	if (main_exit == 1)
		menu();
	else
		close();
}
void bottom_shop()
{
	FILE* old, * newrec;
	int n = 0;
	old = fopen("record.dat", "r");
	newrec = fopen("new.dat", "w");
	printf("������ȣ�� �Է��Ͻÿ�:");
	scanf("%d", &n);
	while (fscanf(old, "%d %s %d %d %d %d %d %d\n", &character.id, &character.name, &character.hair, &character.top, &character.bottoms, &character.shoes, &character.money, &character.happy) != EOF)
	{
		if (n == character.id)
		{
			int bottom = 0;
			system("cls");
			printf("\n1.\n       ��ǢǢǡ�\n       ���  ���\n       ���  ���\n       ���  ���   \n       ���  ���   \n");
			printf("\n2.\n       ��ǢǢǡ�\n       ���  ���\n       �̢�  �̢�\n       ���  ���   \n       ���  ���   \n");
			printf("\n3.\n       ��ǢǢǡ�\n       ���  ���\n       ���  ���\n       ���  ���   \n       ���  ���   \n");
			printf("\n\n\n������ ����ּ���:");
			scanf("%d", &bottom);
			fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, bottom, character.shoes, character.money, character.happy);
			printf("\n���Ͻô� ���Ƿ� �ٲ�����ϴ�.\n");
		}
		else
			fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, character.bottoms, character.shoes, character.money, character.happy);

	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat", "record.dat");
	printf("\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d", &main_exit);
	system("cls");
	if (main_exit == 1)
		menu();
	else
		close();
}
void shoes_market()
{
	FILE* old, * newrec;
	int n = 0;
	old = fopen("record.dat", "r");
	newrec = fopen("new.dat", "w");
	printf("������ȣ�� �Է��Ͻÿ�:");
	scanf("%d", &n);
	while (fscanf(old, "%d %s %d %d %d %d %d %d\n", &character.id, &character.name, &character.hair, &character.top, &character.bottoms, &character.shoes, &character.money, &character.happy) != EOF)
	{
		if (n == character.id)
		{
			int shoes = 0;
			system("cls");
			printf("\n1.\n       �̢�  �̢�\n     �̢̢�  �̢̢�\n");
			printf("\n2.\n       �̢�  ����\n     �̢���  �̢���\n");
			printf("\n3.\n       �̢�  �ݢ�\n     �̢ݢ�  �̢ݢ�\n");
			printf("\n\n\n�Ź��� ����ּ���:");
			scanf("%d", &shoes);
			fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, character.bottoms, shoes, character.money, character.happy);
			printf("\n���Ͻô� �Ź߷� �ٲ�����ϴ�.\n");
		}
		else
			fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, character.bottoms, character.shoes, character.money, character.happy);

	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat", "record.dat");
	printf("\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d", &main_exit);
	system("cls");
	if (main_exit == 1)
		menu();
	else
		close();
}

void dance(int nn,int mode)
{
	    system("cls");
		FILE* ptr;
		ptr = fopen("record.dat", "r");
		int a = nn;
		while (fscanf(ptr, "%d %s %d %d %d %d %d %d\n", &character.id, &character.name, &character.hair, &character.top, &character.bottoms, &character.shoes, &character.money, &character.happy) != EOF)
		{
			if (a == character.id)
			{
				printf("\n\n");
				if (mode == 1)
				{
					switch (character.hair)
					{
					case 1:printf("\n\t\t@@@@@@@\n\t\t@@@@@@@\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
						break;
					case 2:
						printf("\n\t\tMMMMMMM\n\t\t|     |\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
						break;
					case 3:
						printf("\n\t\t_______\n\t\t|     |\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
						break;
					case 4:
						printf("\n\t\t   *   \n\t\t   |    \n\t\t___Y___\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
						break;
					case 5:
						printf("\n\t\to-v^v-o\n\t\t|     |\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
						break;
					case 6:
						printf("\n\n\t\t///////\n\t\t///////\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
					default:
						break;
					}
					switch (character.top)
					{
					case 1:
						printf("\n             ��������\n             ��������\n             ��  ����  ��\n             ��  ����  ��\n             ��  ����  ��\n");
						break;
					case 2:
						printf("\n             ��������\n             ���ᢽ����\n             ��  ����  ��\n             ��  ����  ��\n             ��  ����  ��\n");
						break;
					case 3:
						printf("\n             ��������\n             ��������\n             ��  ����  ��\n             ��  ����  ��\n             ��  ����  ��\n");
						break;
					case 4:
						printf("\n             ��������\n             ���ᢽ����\n             ��  ����  ��\n             ��  ����  ��\n             ��  ����  ��\n");
						break;
					default:
						break;
					}
				}
				else if (mode == 2)
				{
					printf("\n\n");
					switch (character.hair)
					{
					case 1:printf("\n\t\t@@@@@@@\n\t\t@@@@@@@\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
						break;
					case 2:
						printf("\n\t\tMMMMMMM\n\t\t|     |\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
						break;
					case 3:
						printf("\n\t\t_______\n\t\t|     |\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
						break;
					case 4:
						printf("\n\t\t   *   \n\t\t   |    \n\t\t___Y___\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
						break;
					case 5:
						printf("\n\t\to-v^v-o\n\t\t|     |\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
						break;
					case 6:
						printf("\n\t\t///////\n\t\t///////\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
					default:
						break;
					}
					switch (character.top)
					{
					case 1:
						printf("\n             ��������");
						printf("\n           ��  ������  ��");
						printf("\n         ��      ����      ��");
						printf("\n       ��        ����       ��");
						printf("\n     ��          ����         ��\n");
						break;
					case 2:
						printf("\n             ��������");
						printf("\n           ��  ��ᢽ���  ��");
						printf("\n         ��      ����      ��");
						printf("\n       ��        ����       ��");
						printf("\n     ��          ����         ��\n");
						break;
					case 3:
						printf("\n             ��������");
						printf("\n           ��  ������  ��");
						printf("\n         ��      ����      ��");
						printf("\n       ��        ����       ��");
						printf("\n     ��          ����         ��\n");
						break;
					case 4:
						printf("\n             ��������");
						printf("\n           ��  ��ᢽ���  ��");
						printf("\n         ��      ����      ��");
						printf("\n       ��        ����       ��");
						printf("\n     ��          ����         ��\n");
						break;
					default:
						break;
					}
				}
			}
		}
		fclose(ptr);
}
void home()
{
	FILE* ptr;
	ptr = fopen("record.dat", "r");
	int n = 0;
	int bonus = 0; //���� �� �� ��
	printf("����� ���� ��ȣ�� �Է��Ͻÿ�:");
	scanf("%d", &n);
	while (fscanf(ptr, "%d %s %d %d %d %d %d %d\n", &character.id, &character.name, &character.hair, &character.top, &character.bottoms, &character.shoes, &character.money, &character.happy) != EOF)
	{
		if (n == character.id)
		{
			printf("\n\n�ູ��: %d ������ ��: %d", character.happy, character.money);
			switch (character.hair)
			{
			case 1:printf("\n\t\t@@@@@@@\n\t\t@@@@@@@\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
				break;
			case 2:
				printf("\n\t\tMMMMMMM\n\t\t|     |\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
				break;
			case 3:
				printf("\n\t\t_______\n\t\t|     |\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
				break;
			case 4:
				printf("\n\t\t   *   \n\t\t   |    \n\t\t___Y___\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
				break;
			case 5:
				printf("\n\t\to-v^v-o\n\t\t|     |\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
				break;
			case 6:
				printf("\n\n\t\t///////\n\t\t///////\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
			default:
				break;
			}
			switch (character.top)
			{
			case 1:
				printf("\n             ��������\n             ��������\n             ��  ����  ��\n             ��  ����  ��\n             ��  ����  ��\n");
				break;
			case 2:
				printf("\n             ��������\n             ���ᢽ����\n             ��  ����  ��\n             ��  ����  ��\n             ��  ����  ��\n");
				break;
			case 3:
				printf("\n             ��������\n             ��������\n             ��  ����  ��\n             ��  ����  ��\n             ��  ����  ��\n");
				break;
			case 4:
				printf("\n             ��������\n             ���ᢽ����\n             ��  ����  ��\n             ��  ����  ��\n             ��  ����  ��\n");
				break;
			default:
				break;
			}
			switch (character.bottoms)
			{
			case 1:
				printf("               ��ǢǢǡ�\n               ���  ���\n               ���  ���\n               ���  ���   \n               ���  ���   \n");
				break;
			case 2:
				printf("               ��ǢǢǡ�\n               ���  ���\n               �̢�  �̢�\n               ���  ���   \n               ���  ���   \n");
				break;
			case 3:
				printf("               ��ǢǢǡ�\n               ���  ���\n               ���  ���\n               ���  ���   \n               ���  ���   \n");
				break;
			default:
				break;
			}
			switch (character.shoes)
			{
			case 1:
				printf("               �̢�  �̢�\n             �̢̢�  �̢̢�\n");
				break;
			case 2:
				printf("               �̢�  ����\n             �̢���  �̢���\n");
				break;
			case 3:
				printf("               �̢�  �ݢ�\n             �̢ݢ�  �̢ݢ�\n");
				break;
			default:
				break;
			}
			int choice;
			char chat[100];
			int song;
			char word[28][15] = { "apple","latte","tomato","pear","soccer","baseball","bathub","hair","shampoo","mirror","towel","comb","soap","sink","toothpaste","rice","beef","salad","rice","fish","chiken","cookies","pie","chocolates","puddung","icecream","pizza","ent"};
			char overlap[30][15] = { 0 };
			char talk[15];
			int t=0,count = 0,f=0;
			printf("\n\n\n�����Ͻÿ�: 1.��ȭ�ϱ�    2.�뷡�θ���    3.�̴� �����ϱ�: ");
			scanf("%d", &choice);
			switch (choice)
			{
			case 1:
				system("cls");
				while (1)
				{
					printf("\n\n");
					switch (character.hair)
					{
					case 1:printf("\n\t\t@@@@@@@\n\t\t@@@@@@@\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
						break;
					case 2:
						printf("\n\t\tMMMMMMM\n\t\t|     |\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
						break;
					case 3:
						printf("\n\t\t_______\n\t\t|     |\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
						break;
					case 4:
						printf("\n\t\t   *   \n\t\t   |    \n\t\t___Y___\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
						break;
					case 5:
						printf("\n\t\to-v^v-o\n\t\t|     |\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
						break;
					case 6:
						printf("\n\n\t\t///////\n\t\t///////\n\t\t| 0 0 |\n\t\t|  |  |\n\t\t| --- |\n\t\t-------");
					default:
						break;
					}
					switch (character.top)
					{
					case 1:
						printf("\n             ��������\n             ��������\n             ��  ����  ��\n             ��  ����  ��\n             ��  ����  ��\n");
						break;
					case 2:
						printf("\n             ��������\n             ���ᢽ����\n             ��  ����  ��\n             ��  ����  ��\n             ��  ����  ��\n");
						break;
					case 3:
						printf("\n             ��������\n             ��������\n             ��  ����  ��\n             ��  ����  ��\n             ��  ����  ��\n");
						break;
					case 4:
						printf("\n             ��������\n             ���ᢽ����\n             ��  ����  ��\n             ��  ����  ��\n             ��  ����  ��\n");
						break;
					default:
						break;
					}
					printf("�Է�:");
					scanf("%s", chat);
					if (chat == 'END')
						break;
					else
					{
						if (strcmp(chat, "hi") == 0 || strcmp(chat, "hello") == 0)
							printf("�亯:�ȳ�!\n");
						else if (strcmp(chat, "Howaboutyou?") == 0)
						{
							srand(time(NULL));
							switch (rand() % 4 + 1)
							{
							case 1:
								printf("�亯:��� ����!\n");
								break;
							case 2:
								printf("�亯:���� �׷�.\n");
								break;
							case 3:
								printf("�亯:���� �ʾ�...\n");
								break;
							default:
								break;
							}
						}
						else if (strcmp(chat, "Whatkindoffooddoyoulike?") == 0)
						{
							srand(time(NULL));
							switch (rand() % 5 + 1)
							{
							case 1:
								printf("¥����� ���� ������!\n");
								break;
							case 2:
								printf("����� ���� ������!\n");
								break;
							case 3:
								printf("�ʹ� ���Ƽ� ���� �����!\n");
								break;
							case 4:
								printf("���� �����ϴ°� ���°� ����..\n");
							default:
								break;
							}
						}
						else if (strcmp(chat, "Whatkindofexercisedoyoulike?") == 0)
						{
							srand(time(NULL));
							switch (rand() % 5 + 1)
							{
							case 1:
								printf("���� ����Ʈ ��� ������!\n");
								break;
							case 2:
								printf("���� �౸�� ������!\n");
								break;
							case 3:
								printf("���� �߱��� ������!\n");
								break;
							case 4:
								printf("���� �豸�� ������!\n");
							default:
								break;
							}
						}
					}////else��
					int num;
					printf("\n\n���ο� ������ ���Ѵٸ� 1�ƴϸ� 0�� �Է��Ͻÿ�:");
					scanf("%d", &num);
					if (num == 1)
						system("cls");
					if (num == 0)
						break;
				}
				break;
			case 2:
				system("cls");
				printf("\n\n\t\t�뷡����� ���Ͻø� 1���� �Է����ּ���: ");
				scanf("%d", &song);
				if (song == 1)
				{
					dance(n, 2);
					Beep(480, 1000); //��
					dance(n, 1);
					Beep(420, 500);// ��
					dance(n, 2);
					Beep(380, 500); //��
					dance(n, 1);
					Beep(420, 800); //��
					dance(n, 2);
					Beep(480, 500); //��
					dance(n, 1);
					Beep(480, 500); //��
					dance(n, 2);
					Beep(480, 500); //��
					dance(n, 1);
					Beep(420, 500); //��
					dance(n, 2);
					Beep(420, 500); //��
					dance(n, 1);
					Beep(420, 500); //��
					dance(n, 2);
					Beep(480, 500); //��
					dance(n, 1);
					Beep(480, 500);// ��
					dance(n, 2);
					Beep(480, 500); //��
					dance(n, 1);
					Beep(480, 800); //��
					dance(n, 2);
					Beep(420, 500); //��
					dance(n, 1);
					Beep(380, 500); //��
					dance(n, 2);
					Beep(420, 800); //��
					dance(n, 1);
					Beep(480, 500); //��
					dance(n, 2);
					Beep(480, 500); //��
					dance(n, 1);
					Beep(480, 500); //��
					dance(n, 2);
					Beep(420, 500); //��
					dance(n, 1);
					Beep(420, 500); //��
					dance(n, 2);
					Beep(480, 800); //��
					dance(n, 1);
					Beep(420, 500); //��
					dance(n, 2);
					Beep(380, 800); //��
					dance(n, 1);
				}
				break;
			case 3:
				system("cls");
				printf("����ܾ� �̾� ���ϱ�!\n\n");
				while (1)
				{
					printf("�����: ");
					scanf("%s", talk);
					if (t == 0)
					{
						strcpy(overlap[t], talk);
						t++;
					}
					else
					{
						for (int i = 0; i < t; i++)
						{
							if (strcmp(overlap[i], talk) == 0)
							{
								printf("\n\n���ӿ��� ���̽��ϴ�.\n\n");
								goto lose;
							}
						}
						strcpy(overlap[t], talk);
						t++;  //����� �ߺ� �ܾ� �˻�
					}
					f = 0;
					count = 0;
					for (int i = 0; i < 29; i++)
					{
						if (word[i][0] == talk[strlen(talk) - 1])
						{
							for (int j = 0; j < t; j++)
							{
								if (strcmp(overlap[j], word[i]) == 0)
								{
									count++;
								}
							}
							if (count == 0)
							{
								strcpy(overlap[t], word[i]);
								printf("ĳ����: %s\n", word[i]);
								count = 0;
								t++;
								f++;
								break;
							}
						}
					}
					if (f == 0)
					{
						printf("����� �¸��Դϴ�.\n\n");
						bonus += 100;
						break;
					}
				}
				break;
			}
		}
	}
	lose:
	fclose(ptr);
	FILE* old, * newrec;
	old = fopen("record.dat", "r");
	newrec = fopen("new.dat", "w");
	while (fscanf(old, "%d %s %d %d %d %d %d %d\n", &character.id, &character.name, &character.hair, &character.top, &character.bottoms, &character.shoes, &character.money, &character.happy) != EOF)
	{
		if (n == character.id)
		{
			if (character.happy > 50)
			{
				character.happy -= rand() % 8;
			}
			fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, character.bottoms, character.shoes, character.money+bonus, character.happy);
		}
		else
			fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, character.bottoms, character.shoes, character.money, character.happy);

	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat", "record.dat");
	printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d", &main_exit);
	system("cls");
	if (main_exit == 1)
		menu();
	else
		close();
}

void market_upload()
{
	FILE* ptr;
	ptr = fopen("market.dat", "a+");
	system("cls");
	int number=0;
	char article[20]; //����� ���� �̸�
	int price = 0;
	char intu[50];
	ptr = fopen("market.dat", "a+");
	system("cls");
	printf("\n\n\n\t\t����� ������� ������ȣ�� �Է��ϼ���.:");
	scanf("%d", &number);
	printf("\n\n\n\t\t����� ���� �̸�:");
	scanf("%s",article);
	printf("\n\n\n\t\t�� ������ ���ݰ� ������ �Ұ����� �����ÿ�:");
	scanf("%d %s", &price, intu);
	fprintf(ptr, "%d %s %d %s\n",number,article,price,intu);
	fclose(ptr);
	printf("\n\n\n\t\t����� �Ϸ� �Ǿ����ϴ�.");
ch:
	printf("\n\n\n\t\t 1���� �Է��ϸ� ���θ޴� 0���� �Է��ϸ� ����:");
	scanf("%d", &main_exit);
	system("cls");
	if (main_exit == 1)
		menu();
	else if (main_exit == 0)
		close();
	else
	{
		printf("\n�ٽ� �Է��Ͻÿ�.\a");
		goto ch;
	}
}
void market_see()
{
	FILE* ptr;
	ptr = fopen("market.dat", "r");
	int n = 0;
	int check = 0;
	system("cls");
	int number;
	char article[20]; //����� ���� �̸�
	int price = 0;
	char intu[50];
	int buy_price = 0;
	char buy[20];
	while(fscanf(ptr, "%d %s %d %s\n", &number, article, &price, intu)!=EOF)
	{
		printf("\n\n\t\t�Ǹ��� ���� ��ȣ:%d ����� ����:%s ����:%d �Ұ���:%s\n\n\t\t", number, article, price, intu);
	}
	fclose(ptr);
	printf("\n\n\n\t\t�����ϴ� ���� ������ȣ�� �Է��Ͻÿ�: ");
	scanf("%d", &n);
	FILE* old, * newrec;
	old = fopen("record.dat", "r");
	newrec = fopen("new.dat", "w");
	while (fscanf(old, "%d %s %d %d %d %d %d %d\n", &character.id, &character.name, &character.hair, &character.top, &character.bottoms, &character.shoes, &character.money, &character.happy) != EOF)
	{
		if (n == character.id)
		{
			printf("\n\n\n\t\t�Ǹ��� ������ȣ�� ������ ��ǰ�� ������ �Է��Ͻÿ�: ");
			scanf("%d %s %d",&number, buy, &buy_price);
			if (buy_price < character.money)
			{
				printf("\n\t\t %s�� ���� �Ͽ����ϴ�.", buy);
				fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, character.bottoms, character.shoes, character.money - buy_price, character.happy + rand() % 5+1);
				check++;
			}
			else
			{
				printf("\n\t\t %s�� ���� ���� �� �Ͽ����ϴ�.", buy);
				fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, character.bottoms, character.shoes, character.money, character.happy);
			}
		}
		else
			fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, character.bottoms, character.shoes, character.money, character.happy);

	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat", "record.dat");
	if (check !=0)
	{
		FILE* old, * newrec;
		old = fopen("record.dat", "r");
		newrec = fopen("new.dat", "w");
		while (fscanf(old, "%d %s %d %d %d %d %d %d\n", &character.id, &character.name, &character.hair, &character.top, &character.bottoms, &character.shoes, &character.money, &character.happy) != EOF)
		{
			if (character.id==number)
			{
					fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, character.bottoms, character.shoes, character.money +buy_price, character.happy + rand() % 5 + 1);
			}
			else
				fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, character.bottoms, character.shoes, character.money, character.happy);
		}
		fclose(old);
		fclose(newrec);
		remove("record.dat");
		rename("new.dat", "record.dat");
	}
ch:
	printf("\n\n\n\t\t 1���� �Է��ϸ� ���θ޴� 0���� �Է��ϸ� ����:");
	scanf("%d", &main_exit);
	system("cls");
	if (main_exit == 1)
		menu();
	else if (main_exit == 0)
		close();
	else
	{
		printf("\n�ٽ� �Է��Ͻÿ�.\a");
		goto ch;
	}
}
void market()
{
	int choice;
	printf("\n\n\n\t\t1.��ǰ ����ϱ�   2.��ǰ�����ϱ�:  ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:market_upload();
		break;
	case 2:market_see();
		break;
	default:
		break;
	}
}
void close(void)
{
	printf("\n\n\n\n���α׷��� �����մϴ�.");
}
void menu(void)
{
	int ch;
	system("cls");
	printf("\n\n\t\t\t\t��Ÿ���� �� ĳ���� Ű��⿡ ���� �� ȯ���մϴ�.");
	printf("\n\n\n\n\t\t\t\t\t\t1.����� ���\n\n\t\t\t\t\t\t2.�Ӹ� ����\n\n\t\t\t\t\t\t3.���� ����\n\n\t\t\t\t\t\t4.���� ����\n\n\t\t\t\t\t\t5.�Ź� ����\n\n\t\t\t\t\t\t6.Ȩ\n\n\t\t\t\t\t\t7.����\n\n\t\t\t\t\t\t8.�����ϱ�\n\n\n\n\n\t\t\t\t��ȣ�� �Է��Ͻÿ�:");
	scanf("%d", &ch);
	system("cls");
	switch (ch)
	{
	case 1:new_character();
		break;
	case 2:hair_shop();
		break;
	case 3:top_shop();
		break;
	case 4:bottom_shop();
		break;
	case 5:shoes_market();
		break;
	case 6:home();
		break;
	case 7: market();
		break;
	case 8:close();
		break;
	default:
		break;
	}
	
}

int main()
{
	menu();
	return 0;
}