#pragma once 
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "MainMenu.hpp"

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"


#define KEY_ESC 27
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEY_ENTER 13

using namespace std;


struct  WormBody {
	int x;
	int y;
	char body;
};
int score = 0;
int highscore = 0;


namespace Running {

	class Loop {
	public:
		int GameState = 0;
		bool isGameRunning = true;
		bool isEsc = false;
		bool isOut = false;
		int stage_width=50;
		int stage_height=20;
		char key_input = '0';
		
		
		//���� ����
		

		
		//Ŀ�� �̵�
		void gotoxy(int x, int y) {
			//x, y ��ǥ ����
			COORD pos = { x,y };
			//Ŀ�� �̵�
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}

		void CursorView(bool show)//Ŀ�� ������
		{
			HANDLE hConsole;
			CONSOLE_CURSOR_INFO ConsoleCursor;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			ConsoleCursor.bVisible = show;
			ConsoleCursor.dwSize = 1;
			SetConsoleCursorInfo(hConsole, &ConsoleCursor);
		}


		void KeyEvent(char KeyInput)
		{
			system("cls");
			switch (KeyInput)
			{
			case KEY_ESC:
				isEsc = true;
				gotoxy(5, 5);
				cout << "�����Ͻðڽ��ϱ�?\n\n" "     [ �� ]   [�ƴϿ�]" << endl;
				break;
			case '3':
				isEsc = true;
				gotoxy(5, 5);
				cout << "�����Ͻðڽ��ϱ�?\n\n" "     [ �� ]   [�ƴϿ�]" << endl;
				break;
			case KEY_LEFT:
				if (isEsc == true) {
					isOut = true;
					gotoxy(5, 5);
					cout << "�����Ͻðڽ��ϱ�?\n\n" ANSI_COLOR_YELLOW"     [ �� ]   " ANSI_COLOR_RESET"[�ƴϿ�]" << endl;
				}
				break;
			case KEY_RIGHT:
				if (isEsc == true)
				{
					isOut = false;
					gotoxy(5, 5);
					cout << "�����Ͻðڽ��ϱ�?\n\n" ANSI_COLOR_RESET"     [ �� ]   " ANSI_COLOR_YELLOW"[�ƴϿ�]" ANSI_COLOR_RESET"" << endl;
				}
				break;
			case KEY_ENTER:
				if (isOut == true) { isGameRunning = false; }
				else {

					system("cls"); isEsc = false; GameState = 0;
				}
				break;
			default:
				isGameRunning = true;
				break;
			}
		}


		void Update() {
			if (GameState < 6)
			{
				mainmenu();
			}
			else {
				system("cls");
				gotoxy(5, 5);
				cout << "	GAMEOVER"<<endl;
				cout << "	���� : " << score<<endl;
				if (score > highscore) {
					highscore = score;
				}
				cout << "	�ְ����� : " << highscore;
				gotoxy(0, 10);
				cout << "�ƹ�Ű�� ���� ���θ޴��� ���ư���.";
				_getch();
				score = 0;
				GameState = 0;
			}
		}


		void Run() {
			while (isGameRunning == true)
			{

				Update();

			}
		}



		void mainmenu() {
			switch (GameState)
			{
			case 0:
				system("cls");
				print_title_screen();
				key_input = _getch();
				switch (key_input)
				{
				case '1':
					GameState = 1;
					break;
				case '2':
					GameState = 2;
					break;
				case '3':
					GameState = 3;
					break;
				default:
					break;
				}
				break;
			case 1:
				print_game_screen(stage_width, stage_height);
				GameState = 5;
				

				break;
			case 2:
				system("cls");
				print_introduction_screen();
				key_input = _getch();
				switch (key_input)
				{
				case 'y':
					GameState = 0;
					break;
				case 'n':
					break;
				default:
					break;
				}
				break;
			case 3:
				if (isEsc == false)
				{
					system("cls");
					gotoxy(5, 5);
					cout << "�����Ͻðڽ��ϱ�?\n\n" "     [ �� ]   [�ƴϿ�]" << endl;
					isEsc = true;
				}
				key_input = _getch();
				switch (key_input)
				{
				case KEY_LEFT:
					if (isEsc == true) {
						isOut = true;
						gotoxy(5, 5);
						cout << "�����Ͻðڽ��ϱ�?\n\n" ANSI_COLOR_YELLOW"     [ �� ]   " ANSI_COLOR_RESET"[�ƴϿ�]" << endl;
					}
					break;
				case KEY_RIGHT:
					if (isEsc == true)
					{
						isOut = false;
						gotoxy(5, 5);
						cout << "�����Ͻðڽ��ϱ�?\n\n" ANSI_COLOR_RESET"     [ �� ]   " ANSI_COLOR_YELLOW"[�ƴϿ�]" ANSI_COLOR_RESET"" << endl;
					}
					break;
				case KEY_ENTER:
					if (isOut == true) { isGameRunning = false; }
					else {

						system("cls"); isEsc = false; GameState = 0;
					}
					break;
				default:
					isGameRunning = true;
					break;

				}
				//KeyEvent(_getch());
				break;
			case 5:
				//gotoxy(1, 1);

				maingame(stage_width, stage_height);
				break;
			default:
				break;
			}
		}

		int maingame(int stage_width,int stage_height) {
			char game_key = 'd';
			bool isC = true;
			int x = 20;
			int y = 5;
			int len = 2;
			int lastX;
			int lastY;
			int ItemX;
			int ItemY;
			bool trigger = false;
			struct WormBody arr[50];

			//ó�� ������ �ʱ�ȭ
			for (int i = 0; i < 3; i++)
			{
				arr[i].body = 'o';
				arr[i].x = x;
				arr[i].y = y;
				x--;
			}
			arr[0].body = '0';


			ItemX = (rand() % stage_width) + 1;
			ItemY = (rand() % stage_height) + 1;
			gotoxy(ItemX,ItemY);
			printf("@");


			while (1)
			{
				//����
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

				default:
					break;
				}

				//�̵�
				for (size_t i = 0; i < len + 1; i++)
				{
					gotoxy(arr[i].x, arr[i].y);
					cout << arr[i].body;
				}


				//���ӿ���(��������)
				if (arr[0].x == 0 || arr[0].y == 0||arr[0].x==stage_width+1||arr[0].y==stage_height+1) {
					trigger = true;
				}
				//���ӿ���(�ڱ� ��)
				for (size_t i = 1; i < len + 1; i++)
				{
					if (arr[0].x == arr[i].x && arr[0].y == arr[i].y) {
						trigger = true;
					}
				}
				if (trigger == true) {
					system("cls");
					GameState = 7;
					break;
				}

				//���� �Է�
				if (_kbhit())
				{
					isC = true;
					game_key = _getch();
				}

				//������ ����
				if (arr[0].x == ItemX && arr[0].y == ItemY) {
					score++;
					len++;
					arr[len].x = arr[len - 1].x;
					arr[len].y = arr[len - 1].y;
					arr[len].body = 'o';
					ItemX = (rand() % stage_width) + 1;
					ItemY = (rand() % stage_height) + 1;
					gotoxy(ItemX, ItemY);
					printf("@");
				}

				Sleep(150);
			}

			return 0;
		};



		
	};
}