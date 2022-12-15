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
	printf("생성할 사용자 고유번호를 입력하세요.:");
	scanf("%d", &choice);
	while (fscanf(ptr, "%d %s %d %d %d %d %d %d\n", &character.id, &character.name, &character.hair, &character.top, &character.bottoms, &character.shoes, &character.money, &character.happy) != EOF)
	{
		if (choice == character.id)
		{
			printf("\n이미 생성되었습니다.\n\n");
			fordelay(1000000000);
			goto character_no;

		}
	}
	character.id = choice;
	printf("\n이름을 입력하시오:");
	scanf("%s", character.name);
	character.hair = 0;
	character.top = 0;
	character.bottoms = 0;
	character.shoes = 0;
	character.money = 0;
	fprintf(ptr, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, character.bottoms, character.shoes, character.money, 100);
	fclose(ptr);
	printf("\n캐릭터가 생성 되었습니다.");
    ch:
	printf("\n\n\n\t\t 1번을 입력하면 메인메뉴 0번을 입력하면 종료:");
	scanf("%d", &main_exit);
	system("cls");
	if (main_exit == 1)
		menu();
	else if (main_exit == 0)
		close();
	else
	{
		printf("\n다시 입력하시오.\a");
		goto ch;
	}
}

void hair_shop()
{
	FILE* old, * newrec;
	int n = 0;
	old = fopen("record.dat", "r");
	newrec = fopen("new.dat", "w");
	printf("고유번호를 입력하시오:");
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
			printf("\n\n\t\t머리 스타일을 골라주세요:");
			scanf("%d", &hair);
			fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, hair, character.top, character.bottoms, character.shoes, character.money, character.happy);
			printf("\n원하시는 스타일로 바뀌었습니다.\n");
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
	printf("고유번호를 입력하시오:");
	scanf("%d", &n);
	while (fscanf(old, "%d %s %d %d %d %d %d %d\n", &character.id, &character.name, &character.hair, &character.top, &character.bottoms, &character.shoes, &character.money, &character.happy) != EOF)
	{
		if (n == character.id)
		{
			int top = 0;
			system("cls");
			printf("\n1.\n     ■■■■■■■\n     ■■■■■■■\n     ■  ■■■  ■\n     □  ■■■  □\n     ○  ■■■  ○\n");
			printf("\n2.\n     ■■■■■■■\n     ■■■♡■■■\n     ■  ■■■  ■\n     □  ■■■  □\n     ○  ■■■  ○\n");
			printf("\n3.\n     □□■□■□□\n     □□■■■□□\n     □  ■■■  □\n     □  ■■■  □\n     ○  ■■■  ○\n");
			printf("\n4.\n     □□■□■□□\n     □□■♡■□□\n     □  ■■■  □\n     □  ■■■  □\n     ○  ■■■  ○\n");
			printf("\n\n\n상의을 골라주세요:");
			scanf("%d", &top);
			fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair,top, character.bottoms, character.shoes, character.money, character.happy);
			printf("\n원하시는 스타일로 바뀌었습니다.\n");
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
	printf("고유번호를 입력하시오:");
	scanf("%d", &n);
	while (fscanf(old, "%d %s %d %d %d %d %d %d\n", &character.id, &character.name, &character.hair, &character.top, &character.bottoms, &character.shoes, &character.money, &character.happy) != EOF)
	{
		if (n == character.id)
		{
			int bottom = 0;
			system("cls");
			printf("\n1.\n       ■▤▤▤■\n       ■■  ■■\n       ■■  ■■\n       ■■  ■■   \n       ■■  ■■   \n");
			printf("\n2.\n       ■▤▤▤■\n       ■■  ■■\n       ▩▩  ▩▩\n       ■■  ■■   \n       ■■  ■■   \n");
			printf("\n3.\n       ■▤▤▤■\n       ■■  ■■\n       ■■  ■■\n       □□  □□   \n       □□  □□   \n");
			printf("\n\n\n하의을 골라주세요:");
			scanf("%d", &bottom);
			fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, bottom, character.shoes, character.money, character.happy);
			printf("\n원하시는 하의로 바뀌었습니다.\n");
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
	printf("고유번호를 입력하시오:");
	scanf("%d", &n);
	while (fscanf(old, "%d %s %d %d %d %d %d %d\n", &character.id, &character.name, &character.hair, &character.top, &character.bottoms, &character.shoes, &character.money, &character.happy) != EOF)
	{
		if (n == character.id)
		{
			int shoes = 0;
			system("cls");
			printf("\n1.\n       ▩▩  ▩▩\n     ▩▩▩  ▩▩▩\n");
			printf("\n2.\n       ▩♣  ♣▩\n     ▩♣▩  ▩♣▩\n");
			printf("\n3.\n       ▩♬  ♬▩\n     ▩♬▩  ▩♬▩\n");
			printf("\n\n\n신발을 골라주세요:");
			scanf("%d", &shoes);
			fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, character.bottoms, shoes, character.money, character.happy);
			printf("\n원하시는 신발로 바뀌었습니다.\n");
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
						printf("\n             ■■■■■■■\n             ■■■■■■■\n             ■  ■■■  ■\n             □  ■■■  □\n             ○  ■■■  ○\n");
						break;
					case 2:
						printf("\n             ■■■■■■■\n             ■■■♡■■■\n             ■  ■■■  ■\n             □  ■■■  □\n             ○  ■■■  ○\n");
						break;
					case 3:
						printf("\n             □□■□■□□\n             □□■■■□□\n             □  ■■■  □\n             □  ■■■  □\n             ○  ■■■  ○\n");
						break;
					case 4:
						printf("\n             □□■□■□□\n             □□■♡■□□\n             □  ■■■  □\n             □  ■■■  □\n             ○  ■■■  ○\n");
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
						printf("\n             ■■■■■■■");
						printf("\n           ■  ■■■■■  ■");
						printf("\n         ■      ■■■      ■");
						printf("\n       □        ■■■       □");
						printf("\n     ○          ■■■         ○\n");
						break;
					case 2:
						printf("\n             ■■■■■■■");
						printf("\n           ■  ■■♡■■  ■");
						printf("\n         ■      ■■■      ■");
						printf("\n       □        ■■■       □");
						printf("\n     ○          ■■■         ○\n");
						break;
					case 3:
						printf("\n             □□■□■□□");
						printf("\n           □  □■■■□  □");
						printf("\n         □      ■■■      □");
						printf("\n       □        ■■■       □");
						printf("\n     ○          ■■■         ○\n");
						break;
					case 4:
						printf("\n             □□■□■□□");
						printf("\n           □  □■♡■□  □");
						printf("\n         □      ■■■      □");
						printf("\n       □        ■■■       □");
						printf("\n     ○          ■■■         ○\n");
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
	int bonus = 0; //게임 후 번 돈
	printf("사용자 고유 번호를 입력하시오:");
	scanf("%d", &n);
	while (fscanf(ptr, "%d %s %d %d %d %d %d %d\n", &character.id, &character.name, &character.hair, &character.top, &character.bottoms, &character.shoes, &character.money, &character.happy) != EOF)
	{
		if (n == character.id)
		{
			printf("\n\n행복도: %d 소유한 돈: %d", character.happy, character.money);
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
				printf("\n             ■■■■■■■\n             ■■■■■■■\n             ■  ■■■  ■\n             □  ■■■  □\n             ○  ■■■  ○\n");
				break;
			case 2:
				printf("\n             ■■■■■■■\n             ■■■♡■■■\n             ■  ■■■  ■\n             □  ■■■  □\n             ○  ■■■  ○\n");
				break;
			case 3:
				printf("\n             □□■□■□□\n             □□■■■□□\n             □  ■■■  □\n             □  ■■■  □\n             ○  ■■■  ○\n");
				break;
			case 4:
				printf("\n             □□■□■□□\n             □□■♡■□□\n             □  ■■■  □\n             □  ■■■  □\n             ○  ■■■  ○\n");
				break;
			default:
				break;
			}
			switch (character.bottoms)
			{
			case 1:
				printf("               ■▤▤▤■\n               ■■  ■■\n               ■■  ■■\n               ■■  ■■   \n               ■■  ■■   \n");
				break;
			case 2:
				printf("               ■▤▤▤■\n               ■■  ■■\n               ▩▩  ▩▩\n               ■■  ■■   \n               ■■  ■■   \n");
				break;
			case 3:
				printf("               ■▤▤▤■\n               ■■  ■■\n               ■■  ■■\n               □□  □□   \n               □□  □□   \n");
				break;
			default:
				break;
			}
			switch (character.shoes)
			{
			case 1:
				printf("               ▩▩  ▩▩\n             ▩▩▩  ▩▩▩\n");
				break;
			case 2:
				printf("               ▩♣  ♣▩\n             ▩♣▩  ▩♣▩\n");
				break;
			case 3:
				printf("               ▩♬  ♬▩\n             ▩♬▩  ▩♬▩\n");
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
			printf("\n\n\n선택하시오: 1.대화하기    2.노래부르기    3.미니 게임하기: ");
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
						printf("\n             ■■■■■■■\n             ■■■■■■■\n             ■  ■■■  ■\n             □  ■■■  □\n             ○  ■■■  ○\n");
						break;
					case 2:
						printf("\n             ■■■■■■■\n             ■■■♡■■■\n             ■  ■■■  ■\n             □  ■■■  □\n             ○  ■■■  ○\n");
						break;
					case 3:
						printf("\n             □□■□■□□\n             □□■■■□□\n             □  ■■■  □\n             □  ■■■  □\n             ○  ■■■  ○\n");
						break;
					case 4:
						printf("\n             □□■□■□□\n             □□■♡■□□\n             □  ■■■  □\n             □  ■■■  □\n             ○  ■■■  ○\n");
						break;
					default:
						break;
					}
					printf("입력:");
					scanf("%s", chat);
					if (chat == 'END')
						break;
					else
					{
						if (strcmp(chat, "hi") == 0 || strcmp(chat, "hello") == 0)
							printf("답변:안녕!\n");
						else if (strcmp(chat, "Howaboutyou?") == 0)
						{
							srand(time(NULL));
							switch (rand() % 4 + 1)
							{
							case 1:
								printf("답변:기분 좋아!\n");
								break;
							case 2:
								printf("답변:그저 그래.\n");
								break;
							case 3:
								printf("답변:좋지 않아...\n");
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
								printf("짜장면을 제일 좋아해!\n");
								break;
							case 2:
								printf("돈까스를 제일 좋아해!\n");
								break;
							case 3:
								printf("너무 많아서 고르기 어려워!\n");
								break;
							case 4:
								printf("딱히 좋아하는게 없는거 같애..\n");
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
								printf("나는 웨이트 운동을 좋아해!\n");
								break;
							case 2:
								printf("나는 축구를 좋아해!\n");
								break;
							case 3:
								printf("나는 야구를 좋아해!\n");
								break;
							case 4:
								printf("나는 배구를 좋아해!\n");
							default:
								break;
							}
						}
					}////else문
					int num;
					printf("\n\n새로운 질문을 원한다면 1아니면 0을 입력하시오:");
					scanf("%d", &num);
					if (num == 1)
						system("cls");
					if (num == 0)
						break;
				}
				break;
			case 2:
				system("cls");
				printf("\n\n\t\t노래재생을 원하시면 1번을 입력해주세요: ");
				scanf("%d", &song);
				if (song == 1)
				{
					dance(n, 2);
					Beep(480, 1000); //시
					dance(n, 1);
					Beep(420, 500);// 라
					dance(n, 2);
					Beep(380, 500); //솔
					dance(n, 1);
					Beep(420, 800); //라
					dance(n, 2);
					Beep(480, 500); //시
					dance(n, 1);
					Beep(480, 500); //시
					dance(n, 2);
					Beep(480, 500); //시
					dance(n, 1);
					Beep(420, 500); //라
					dance(n, 2);
					Beep(420, 500); //라
					dance(n, 1);
					Beep(420, 500); //라
					dance(n, 2);
					Beep(480, 500); //시
					dance(n, 1);
					Beep(480, 500);// 시
					dance(n, 2);
					Beep(480, 500); //시
					dance(n, 1);
					Beep(480, 800); //시
					dance(n, 2);
					Beep(420, 500); //라
					dance(n, 1);
					Beep(380, 500); //솔
					dance(n, 2);
					Beep(420, 800); //라
					dance(n, 1);
					Beep(480, 500); //시
					dance(n, 2);
					Beep(480, 500); //시
					dance(n, 1);
					Beep(480, 500); //시
					dance(n, 2);
					Beep(420, 500); //라
					dance(n, 1);
					Beep(420, 500); //라
					dance(n, 2);
					Beep(480, 800); //시
					dance(n, 1);
					Beep(420, 500); //라
					dance(n, 2);
					Beep(380, 800); //솔
					dance(n, 1);
				}
				break;
			case 3:
				system("cls");
				printf("영어단어 이어 말하기!\n\n");
				while (1)
				{
					printf("사용자: ");
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
								printf("\n\n게임에서 지셨습니다.\n\n");
								goto lose;
							}
						}
						strcpy(overlap[t], talk);
						t++;  //사용자 중복 단어 검사
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
								printf("캐릭터: %s\n", word[i]);
								count = 0;
								t++;
								f++;
								break;
							}
						}
					}
					if (f == 0)
					{
						printf("당신의 승리입니다.\n\n");
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
	char article[20]; //등록할 물건 이름
	int price = 0;
	char intu[50];
	ptr = fopen("market.dat", "a+");
	system("cls");
	printf("\n\n\n\t\t등록할 사용자의 고유번호를 입력하세요.:");
	scanf("%d", &number);
	printf("\n\n\n\t\t등록할 물건 이름:");
	scanf("%s",article);
	printf("\n\n\n\t\t그 물건의 가격과 간단한 소개글을 적으시오:");
	scanf("%d %s", &price, intu);
	fprintf(ptr, "%d %s %d %s\n",number,article,price,intu);
	fclose(ptr);
	printf("\n\n\n\t\t등록이 완료 되었습니다.");
ch:
	printf("\n\n\n\t\t 1번을 입력하면 메인메뉴 0번을 입력하면 종료:");
	scanf("%d", &main_exit);
	system("cls");
	if (main_exit == 1)
		menu();
	else if (main_exit == 0)
		close();
	else
	{
		printf("\n다시 입력하시오.\a");
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
	char article[20]; //등록할 물건 이름
	int price = 0;
	char intu[50];
	int buy_price = 0;
	char buy[20];
	while(fscanf(ptr, "%d %s %d %s\n", &number, article, &price, intu)!=EOF)
	{
		printf("\n\n\t\t판매자 고유 번호:%d 등록할 물건:%s 가격:%d 소개글:%s\n\n\t\t", number, article, price, intu);
	}
	fclose(ptr);
	printf("\n\n\n\t\t구매하는 자의 고유번호를 입력하시오: ");
	scanf("%d", &n);
	FILE* old, * newrec;
	old = fopen("record.dat", "r");
	newrec = fopen("new.dat", "w");
	while (fscanf(old, "%d %s %d %d %d %d %d %d\n", &character.id, &character.name, &character.hair, &character.top, &character.bottoms, &character.shoes, &character.money, &character.happy) != EOF)
	{
		if (n == character.id)
		{
			printf("\n\n\n\t\t판매자 고유번호와 구매할 상품과 가격을 입력하시오: ");
			scanf("%d %s %d",&number, buy, &buy_price);
			if (buy_price < character.money)
			{
				printf("\n\t\t %s을 구매 하였습니다.", buy);
				fprintf(newrec, "%d %s %d %d %d %d %d %d\n", character.id, character.name, character.hair, character.top, character.bottoms, character.shoes, character.money - buy_price, character.happy + rand() % 5+1);
				check++;
			}
			else
			{
				printf("\n\t\t %s을 구매 하지 못 하였습니다.", buy);
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
	printf("\n\n\n\t\t 1번을 입력하면 메인메뉴 0번을 입력하면 종료:");
	scanf("%d", &main_exit);
	system("cls");
	if (main_exit == 1)
		menu();
	else if (main_exit == 0)
		close();
	else
	{
		printf("\n다시 입력하시오.\a");
		goto ch;
	}
}
void market()
{
	int choice;
	printf("\n\n\n\t\t1.물품 등록하기   2.물품구매하기:  ");
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
	printf("\n\n\n\n프로그램을 종료합니다.");
}
void menu(void)
{
	int ch;
	system("cls");
	printf("\n\n\t\t\t\t메타버스 속 캐릭터 키우기에 오실 걸 환영합니다.");
	printf("\n\n\n\n\t\t\t\t\t\t1.사용자 등록\n\n\t\t\t\t\t\t2.머리 고르기\n\n\t\t\t\t\t\t3.상의 고르기\n\n\t\t\t\t\t\t4.하의 고르기\n\n\t\t\t\t\t\t5.신발 고르기\n\n\t\t\t\t\t\t6.홈\n\n\t\t\t\t\t\t7.시장\n\n\t\t\t\t\t\t8.종료하기\n\n\n\n\n\t\t\t\t번호를 입력하시오:");
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