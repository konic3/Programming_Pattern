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
		char Vercheck='1';
		
		//게임 변수
		

		
		//커서 이동
		void gotoxy(int x, int y) {
			//x, y 좌표 설정
			COORD pos = { x,y };
			//커서 이동
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}

		void CursorView(bool show)//커서 깜빡임
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
				cout << "종료하시겠습니까?\n\n" "     [ 예 ]   [아니오]" << endl;
				break;
			case '3':
				isEsc = true;
				gotoxy(5, 5);
				cout << "종료하시겠습니까?\n\n" "     [ 예 ]   [아니오]" << endl;
				break;
			case KEY_LEFT:
				if (isEsc == true) {
					isOut = true;
					gotoxy(5, 5);
					cout << "종료하시겠습니까?\n\n" ANSI_COLOR_YELLOW"     [ 예 ]   " ANSI_COLOR_RESET"[아니오]" << endl;
				}
				break;
			case KEY_RIGHT:
				if (isEsc == true)
				{
					isOut = false;
					gotoxy(5, 5);
					cout << "종료하시겠습니까?\n\n" ANSI_COLOR_RESET"     [ 예 ]   " ANSI_COLOR_YELLOW"[아니오]" ANSI_COLOR_RESET"" << endl;
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
				cout << "	점수 : " << score<<endl;
				if (score > highscore) {
					highscore = score;
				}
				cout << "	최고점수 : " << highscore;
				gotoxy(0, 10);
				cout << "아무키를 눌러 메인메뉴로 돌아가기.";
				Sleep(500);
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
				system("cls");
				cout << "게임 모드를 입력해주세요." << endl;
				cout << "1. 일반 모드	2.벽X모드" << endl;
				Vercheck = _getch();		
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
					cout << "종료하시겠습니까?\n\n" "     [ 예 ]   [아니오]" << endl;
					isEsc = true;
				}
				key_input = _getch();
				switch (key_input)
				{
				case KEY_LEFT:
					if (isEsc == true) {
						isOut = true;
						gotoxy(5, 5);
						cout << "종료하시겠습니까?\n\n" ANSI_COLOR_YELLOW"     [ 예 ]   " ANSI_COLOR_RESET"[아니오]" << endl;
					}
					break;
				case KEY_RIGHT:
					if (isEsc == true)
					{
						isOut = false;
						gotoxy(5, 5);
						cout << "종료하시겠습니까?\n\n" ANSI_COLOR_RESET"     [ 예 ]   " ANSI_COLOR_YELLOW"[아니오]" ANSI_COLOR_RESET"" << endl;
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
				break;
			case 5:
				if (Vercheck == '1') {
					maingame(stage_width, stage_height,true);
				}
				else if(Vercheck=='2') {
					maingame(stage_width, stage_height,false);
				}
				system("cls");
				break;
			default:
				break;
			}
		}

		int maingame(int stage_width,int stage_height,bool isOriginal) {
			char game_key = 'd';
			bool isC = true;
			int x = 20;
			int y = 10;
			int len = 2;
			int lastX;
			int lastY;
			int ItemX;
			int ItemY;
			bool trigger = false;
			struct WormBody arr[100];
			bool start_pause = true;
			char check_key;

			//처음 지렁이 초기화
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

			gotoxy(60, 10);
			cout << "score : " << score;
			gotoxy(60, 11);
			cout << "ESC를 눌러 메인메뉴로 나가기.";
			while (GameState<6&&GameState>1)
			{
				


				//제거&이동
				switch (game_key)
				{
				case 'w':

					//뒤에 제거
					lastX = arr[len].x;
					lastY = arr[len].y;
					gotoxy(lastX, lastY);
					cout << " ";

					//위치 증감
					for (int i = len; i > 0; i--)
					{
						arr[i].x = arr[i - 1].x;
						arr[i].y = arr[i - 1].y;
					}
					arr[0].y -= 1;
					break;

				case 'a':
					//뒤에 제거
					lastX = arr[len].x;
					lastY = arr[len].y;
					gotoxy(lastX, lastY);
					cout << " ";

					//위치 증감
					for (int i = len; i > 0; i--)
					{
						arr[i].x = arr[i - 1].x;
						arr[i].y = arr[i - 1].y;
					}
					arr[0].x -= 1;
					break;

				case 's':
					//뒤에 제거
					lastX = arr[len].x;
					lastY = arr[len].y;
					gotoxy(lastX, lastY);
					cout << " ";
					//위치 증감
					for (int i = len; i > 0; i--)
					{
						arr[i].x = arr[i - 1].x;
						arr[i].y = arr[i - 1].y;
					}
					arr[0].y += 1;
					break;

				case 'd':

					//뒤에 제거
					lastX = arr[len].x;
					lastY = arr[len].y;
					gotoxy(lastX, lastY);
					cout << " ";
					//위치 증감
					for (int i = len; i > 0; i--)
					{
						arr[i].x = arr[i - 1].x;
						arr[i].y = arr[i - 1].y;
					}
					arr[0].x += 1;
					break;
				case 27:
					GameState = 0;
					system("cls");
					break;
				default:
					break;
				}

				

				//이동
				for (size_t i = 0; i < len + 1; i++)
				{
					gotoxy(arr[i].x, arr[i].y);
					cout << arr[i].body;
				}

				//시작 정지
				if (start_pause == true)
				{
					game_key = _getch();
					start_pause = false;
				}

				//게임오버(자기 몸)
				for (size_t i = 1; i < len + 1; i++)
				{
					if (arr[0].x == arr[i].x && arr[0].y == arr[i].y) {
						trigger = true;
					}
				}

				//게임오버(스테이지)
				if (isOriginal == true) {
					if (arr[0].x == 0 || arr[0].y == 0 || arr[0].x == stage_width + 1 || arr[0].y == stage_height + 1) {
						trigger = true;
					}
				}else if(isOriginal==false){
					if (arr[0].x == 0){
						arr[0].x = stage_width+1;
					}
					else if (arr[0].y == 0) {
						arr[0].y = stage_height+1;
					}
					else if (arr[0].x == stage_width+1) {
						arr[0].x = 0;
					}
					else if (arr[0].y == stage_height+1) {
						arr[0].y = 0;
					}
				}
				if (trigger == true) {
					system("cls");
					GameState = 7;
					break;
				}


				//게임 테두리 계속 찍기
				gotoxy(0, 0);
				std::cout << "┌";
				for (int j = 0; j < stage_width; j++)
				{
					std::cout << "─";
				}
				std::cout << "┐";
				std::cout << std::endl;
				for (size_t i = 1; i < stage_height + 1; i++)
				{
					gotoxy(0, i);
					cout << "│";
					gotoxy(stage_width + 1, i);
					cout << "│";
				}
				gotoxy(0, stage_height + 1);
				cout << "└";
				for (int f = 0; f < stage_width; f++)
				{
					printf("─");
				}
				std::cout << "┘";
				std::cout << std::endl;

				//방향 입력
				if (_kbhit())
				{
					isC = true;
					check_key = _getch();
					if (check_key != 'w' && check_key != 'a' && check_key != 's' && check_key != 'd') {
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

				//아이템 생성
				if (arr[0].x == ItemX && arr[0].y == ItemY) {
					score++;
					gotoxy(60, 10);
					cout << "score : " << score;
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

			system("cls");
			return 0;
		};



		
	};
}