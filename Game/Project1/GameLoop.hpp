#pragma once 

#include "MainMenu.hpp"
//#include "Util.hpp"
#include "MainGame.hpp"




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
		
		

		


		//메인메뉴 
		/*
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
		*/


		//게임 싸이클
		void Run() {
			while (isGameRunning == true)
			{
				Update();
			}
		}


		void Update() {
			if (GameState < 6&&GameState!=5)
			{
				mainmenu();
			}
			else if (GameState == 5) {
				if (Vercheck == '2') {
					maingame(stage_width, stage_height, false, &GameState, &score);//일반모드
				}
				else {
					maingame(stage_width, stage_height, true, &GameState, &score);//벽X모드
				}
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

		

		//메인메뉴 전환
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
				cout << "\n게임 모드를 입력해주세요.(기본은 일반모드)" << endl;
				cout << "\n1.일반 모드    2.벽X모드" << endl;
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
				ExitMenu(&isEsc, &isOut, &isGameRunning, &GameState);
				break;
			case 5:
				system("cls");
				break;
			default:
				break;
			}
		}




		
	};
}