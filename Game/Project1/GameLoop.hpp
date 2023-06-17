#pragma once 
#include "MainMenu.hpp"
//#include "Util.hpp"
#include "MainGame.hpp"

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
		int score = 0;
		int highscore = 0;
		//���� ����Ŭ
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
				maingame(stage_width, stage_height, Vercheck, &GameState, &score);
			}
			else {
				GameOver(&score, &highscore, &GameState);
			}
		}

		

		//���θ޴� ��ȯ
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
				cout << "\n���� ��带 �Է����ּ���.(�⺻�� �Ϲݸ��)" << endl;
				cout << "\n1.�Ϲ� ���    2.��Ż���" << endl;
				Vercheck = _getch();	
				if(Vercheck!='2') {
					Vercheck = '1';
				}
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