#include "Util.hpp"

using namespace std;

//���� ����
void maingame(int stage_width, int stage_height, bool isOriginal,int *GameState,int *score) {
	//���� ����
	struct  WormBody {
		int x;
		int y;
		char body;
	};

	char game_key = '0';
	bool isC = true;
	int x = 20;
	int y = 10;
	int len = 2;
	int lastX;
	int lastY;
	int ItemX;
	int ItemY;
	bool trigger = false;
	struct WormBody arr[1000];
	bool start_pause = true;
	char check_key;
	bool isSpawn = false;
	bool Spawncheck = false;

	long time_end = clock();
	long time = clock();


	//ó�� ������ �ʱ�ȭ
	for (int i = 0; i < 3; i++)
	{
		arr[i].body = 'o';
		arr[i].x = x;
		arr[i].y = y;
		x--;
	}
	arr[0].body = '0';

	//ó�� ������ ����
	ItemX = (rand() % stage_width) + 1;
	ItemY = (rand() % stage_height) + 1;
	gotoxy(ItemX, ItemY);
	printf("@");

	gotoxy(60, 10);
	cout << "score : " << *score;
	gotoxy(60, 11);
	cout << "ESC�� ���� ���θ޴��� ������.";

	while (*GameState < 6 && *GameState>1)
	{
		//����&�̵�
		switch (game_key)
		{
		case 'w':
			//�ڿ� ����
			lastX = arr[len].x;
			lastY = arr[len].y;
			gotoxy(lastX, lastY);
			cout << " ";

			//��ġ ����
			for (int i = len; i > 0; i--)
			{
				arr[i].x = arr[i - 1].x;
				arr[i].y = arr[i - 1].y;
			}
			arr[0].y -= 1;
			break;

		case 'a':
			//�ڿ� ����
			lastX = arr[len].x;
			lastY = arr[len].y;
			gotoxy(lastX, lastY);
			cout << " ";

			//��ġ ����
			for (int i = len; i > 0; i--)
			{
				arr[i].x = arr[i - 1].x;
				arr[i].y = arr[i - 1].y;
			}
			arr[0].x -= 1;
			break;

		case 's':
			//�ڿ� ����
			lastX = arr[len].x;
			lastY = arr[len].y;
			gotoxy(lastX, lastY);
			cout << " ";
			//��ġ ����
			for (int i = len; i > 0; i--)
			{
				arr[i].x = arr[i - 1].x;
				arr[i].y = arr[i - 1].y;
			}
			arr[0].y += 1;
			break;

		case 'd':

			//�ڿ� ����
			lastX = arr[len].x;
			lastY = arr[len].y;
			gotoxy(lastX, lastY);
			cout << " ";
			//��ġ ����
			for (int i = len; i > 0; i--)
			{
				arr[i].x = arr[i - 1].x;
				arr[i].y = arr[i - 1].y;
			}
			arr[0].x += 1;
			break;
		case 27:
			system("cls");
			*GameState = 0;
			break;
		default:
			break;
		}

		//�̵�
		for (size_t i = 0; i < len + 1; i++)
		{
			gotoxy(arr[i].x, arr[i].y);
			cout << arr[i].body;
		}

		//���� ����
		if (start_pause == true)
		{
			check_key = _getch();
			if (check_key != 'a') {
				game_key = 'd';
				start_pause = false;
			}
			else {

			}
		}

		//���ӿ���(�ڱ� ��)
		for (size_t i = 1; i < len + 1; i++)
		{
			if (arr[0].x == arr[i].x && arr[0].y == arr[i].y) {
				trigger = true;
			}
		}

		//���ӿ���(��������)
		if (isOriginal == true) {
			if (arr[0].x == 0 || arr[0].y == 0 || arr[0].x == stage_width + 1 || arr[0].y == stage_height + 1) {
				trigger = true;
			}
		}
		else if (isOriginal == false) {
			if (arr[0].x == 0) {
				arr[0].x = stage_width + 1;
			}
			else if (arr[0].y == 0) {
				arr[0].y = stage_height + 1;
			}
			else if (arr[0].x == stage_width + 1) {
				arr[0].x = 0;
			}
			else if (arr[0].y == stage_height + 1) {
				arr[0].y = 0;
			}
		}

		//���ӿ���
		if (trigger == true) {
			system("cls");
			*GameState = 7;
			break;
		}

		//���� �׵θ� ��� ���
		gotoxy(0, 0);
		std::cout << "��";
		for (int j = 0; j < stage_width; j++)
		{
			std::cout << "��";
		}
		std::cout << "��";
		std::cout << std::endl;
		for (size_t i = 1; i < stage_height + 1; i++)
		{
			gotoxy(0, i);
			cout << "��";
			gotoxy(stage_width + 1, i);
			cout << "��";
		}
		gotoxy(0, stage_height + 1);
		cout << "��";
		for (int f = 0; f < stage_width; f++)
		{
			printf("��");
		}
		std::cout << "��";
		std::cout << std::endl;

		//���� �Է�
		if (_kbhit())
		{
			isC = true;
			check_key = _getch();
			if (check_key != 'w' && check_key != 'a' && check_key != 's' && check_key != 'd') {
				if (check_key == 27) {
					game_key = check_key;
				}
			}
			else if (game_key == 'd' && check_key != 'a')
			{
				game_key = check_key;
			}
			else if (game_key == 'a' && check_key != 'd') {
				game_key = check_key;
			}
			else if (game_key == 'w' && check_key != 's') {
				game_key = check_key;
			}
			else if (game_key == 's' && check_key != 'w') {
				game_key = check_key;
			}

		}

		//������ ����
		if (arr[0].x == ItemX && arr[0].y == ItemY) {
			*score+=1;
			gotoxy(60, 10);
			cout << "score : " << *score;
			len++;
			arr[len].x = arr[len - 1].x;
			arr[len].y = arr[len - 1].y;
			arr[len].body = 'o';
			Spawncheck = false;

			while (Spawncheck == false)
			{
				ItemX = (rand() % stage_width) + 1;
				ItemY = (rand() % stage_height) + 1;
				for (int i = 0; i < len; i++)
				{
					if (ItemX == arr[i].x && ItemY == arr[i].y) {
						isSpawn = false;
						break;
					}
					else {
						isSpawn = true;
					}
				}
				if (isSpawn == true) {
					Spawncheck = true;
				}
			}

			gotoxy(ItemX, ItemY);
			printf("@");
		}

		gotoxy(60, 12);

		//�ð�
		/*
		time = clock() - time_end;
		time_end = clock();



		cout << "fps : " << 1000 / time;
		*/

		Sleep(120);
	}
	
	system("cls");
};
