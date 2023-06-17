#include "Util.hpp"

using namespace std;

//테두리 그리기
void drawborder(int stage_width, int stage_height) {
	
	gotoxy(0, 0);
	std::cout << "┌";
	for (int j = 0; j < stage_width; j++)
	{
		std::cout << "─";
	}
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
	std::cout << std::endl;
}


//메인 게임
void maingame(int stage_width, int stage_height, char Vercheck,int *GameState,int *score) {
	
	//지렁이
	struct  WormBody {
		int x;
		int y;
		char body;
	};

	//방향 키
	char game_key = '0';
	bool isC = true;

	//스테이지 크기
	int x = 20;
	int y = 10;

	//처음 지렁이 배열 크기
	int len = 2;

	//꼬리 였던 공간 위치
	int lastX;
	int lastY;

	//아이템 위치
	int ItemX;
	int ItemY;

	//게임오버 트리거
	bool trigger = false;

	//지렁이 배열 생성
	struct WormBody arr[1000];

	//처음 시작시 정지
	bool start_pause = true;

	//WASD 확인
	char check_key;

	//아이템 변수
	bool isSpawn = false;
	bool Spawncheck = false;

	//시간
	long time_end = GetTickCount64();
	long time = GetTickCount64();


	//처음 지렁이 초기화
	for (int i = 0; i < len+1; i++)
	{
		arr[i].body = 'o';
		arr[i].x = x;
		arr[i].y = y;
		x--;
	}
	arr[0].body = '0';

	//처음 아이템 생성
	ItemX = (rand() % stage_width) + 1;
	ItemY = (rand() % stage_height) + 1;
	gotoxy(ItemX, ItemY);
	printf("@");

	//UI
	gotoxy(60, 10);
	cout << "score : " << *score;
	gotoxy(60, 11);
	cout << "ESC를 눌러 메인메뉴로 나가기.";


	while (*GameState < 6 && *GameState>1)
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
			system("cls");
			*GameState = 0;
			break;
		default:
			break;
		}

		//이동(렌더)
		for (size_t i = 0; i < len + 1; i++)
		{
			gotoxy(arr[i].x, arr[i].y);
			cout << arr[i].body;
		}

		//시작 정지
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

		//게임오버(자기 몸)
		for (size_t i = 1; i < len + 1; i++)
		{
			if (arr[0].x == arr[i].x && arr[0].y == arr[i].y) {
				trigger = true;
			}
		}

		//게임오버(스테이지)
		if (arr[0].x == 0 || arr[0].y == 0 || arr[0].x == stage_width + 1 || arr[0].y == stage_height + 1) {
			if (Vercheck == '1') {
				trigger = true;
			}
			else if (Vercheck == '2') {//벽 x모드
				if (arr[0].x == 0) {
					arr[0].x = stage_width+1;
				}
				else if (arr[0].y == 0) {
					arr[0].y = stage_height+1;
				}
				else if (arr[0].x == stage_width + 1) {
					arr[0].x = 1;
				}
				else if (arr[0].y == stage_height + 1) {
					arr[0].y = 1;
				}
				//게임 테두리 찍기
				//drawborder(stage_width, stage_height);
			}

		}
		
		//테두리 그리기
		drawborder(stage_width, stage_height);

		//게임오버
		if (trigger == true) {
			system("cls");
			*GameState = 7;
			break;
		}

		//방향 입력
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

		//아이템 생성
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
			cout << "@";

		}


		
		//시간
		time = GetTickCount64() - time_end;
		time_end = GetTickCount64();

		/*
		if (time <80) {
			Sleep(80 - time);
		}
		*/	
		Sleep(1000/21);
		if (time != 0) {
			gotoxy(60, 12);
			cout << "fps : " << 1000 / time<<endl;
		}
		
		

	}
	
	system("cls");
};


void GameOver(int *score,int * highscore,int *GameState) {
	system("cls");
	gotoxy(5, 5);
	cout << "	GAMEOVER" << endl;
	cout << "	점수 : " << *score << endl;
	if (*score > *highscore) {
		*highscore = *score;
	}
	cout << "	최고점수 : " << *highscore;
	gotoxy(0, 10);
	cout << "아무키를 눌러 메인메뉴로 돌아가기.";
	Sleep(500);
	_getch();
	*score = 0;
	*GameState = 0;
}
