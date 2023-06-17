#include "Util.hpp"


//메인화면 
//GameState==0일때
void print_title_screen()
{
	cout << "┌───────────────────────────────────────┐" << endl;
	cout << "│                                       │" << endl;
	cout << "│                                       │" << endl;
	cout << "│               왕꿈틀이                │" << endl;
	cout << "│             (Snake  Bite)             │" << endl;
	cout << "│                                       │" << endl;
	cout << "│	      1. 게임 시작              │" << endl;
	cout << "│             2. 게임 설명              │" << endl;
	cout << "│             3. 게임 종료              │" << endl;
	cout << "│                                       │" << endl;
	cout << "└───────────────────────────────────────┘" << endl;


}

//GameState == 1 일때 화면
void print_game_screen(int stage_width, int stage_height)
{
	//콘솔 창 비우기
	system("cls");


	//입력받은 stage_width만큼 출력
	cout << "┌";
	for (int j = 0; j < stage_width; j++)
	{
		cout << "─";
	}
	cout << "┐";
	cout << endl;

	//입력받은 stage_height만큼 *출력
	for (int u = 0; u < stage_height; u++)
	{
		cout << "│";
		for (int k = 0; k < stage_width; k++)
		{
			cout << " ";
		}
		cout << "│" << endl;
	}

	//입력받은 stage_width만큼 출력
	cout << "└";
	for (int f = 0; f < stage_width ; f++)
	{
		printf("─");
	}
	cout << "┘";
	cout << endl;
}

// GameState == 2 일때 화면
int print_introduction_screen()
{
	//cout << "\n******************************************" << endl;
	cout << "\n\n지렁이 게임은 플레이어가 지렁이를 조종하여\n먹이를 먹고 덩치를 키워 점수를 얻는 방식의\n게임입니다." << endl;
	cout << "\nW A S D로 조종이 가능합니다.\n@ 을 먹으면 길이가 1칸 늘어납니다." << endl;
	cout << "\n타이틀화면으로 돌아갈까요? (Y/N)\n" << endl;
	return 0;
}

// GameState == 3 일때 화면
void ExitMenu(bool *isEsc,bool *isOut,bool *isGameRunning,int *GameState) {
	char key_input = '0';

	if (*isEsc == false)
	{
		system("cls");
		gotoxy(5, 5);
		cout << "종료하시겠습니까?\n\n" "     [ 예 ]   [아니오]" << endl;
		*isEsc = true;
	}
	key_input = _getch();
	switch (key_input)
	{
	case KEY_LEFT:
		if (*isEsc == true) {
			*isOut = true;
			gotoxy(5, 5);
			cout << "종료하시겠습니까?\n\n" ANSI_COLOR_YELLOW"     [ 예 ]   " ANSI_COLOR_RESET"[아니오]" << endl;
		}
		break;
	case KEY_RIGHT:
		if (*isEsc == true)
		{
			*isOut = false;
			gotoxy(5, 5);
			cout << "종료하시겠습니까?\n\n" ANSI_COLOR_RESET"     [ 예 ]   " ANSI_COLOR_YELLOW"[아니오]" ANSI_COLOR_RESET"" << endl;
		}
		break;
	case KEY_ENTER:
		if (*isOut == true) { *isGameRunning = false; }
		else {

			system("cls"); *isEsc = false; *GameState = 0;
		}
		break;
	default:
		*isGameRunning = true;
		break;
	}
}


