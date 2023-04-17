//#define DEBUG
#include <iostream>
#include <conio.h>
#include <Windows.h>

// game_state == 0 일때 화면
int print_title_screen()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*              지렁이 게임               *" << std::endl;
    std::cout << "*             (Snake  Bite)              *" << std::endl;

#ifdef DEBUG
    std::cout << "*            - 디버그 모드 -             *" << std::endl;
#else
    std::cout << "*                                        *" << std::endl;
#endif  
    std::cout << "*   1. 게임 시작                         *" << std::endl;
    std::cout << "*   2. 게임 설명                         *" << std::endl;
    std::cout << "*   3. 게임 랭킹 보기                    *" << std::endl;
    std::cout << "*   4. 게임 종료 (esc)                   *" << std::endl;
    std::cout << "******************************************" << std::endl;

    return 0;
}


void gotoxy(int x, int y) {
    //x, y 좌표 설정
    COORD pos = { x,y };
    //커서 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


//game_state == 1 일때 화면
int print_game_screen(int stage_width, int stage_height)
{
    //콘솔 창 비우기
    system("cls");

    //입력받은 stage_width만큼 *출력
    for (int j = 0; j < stage_width+2; j++)
    {
        std::cout << "*";
    }
    std::cout<<std::endl;

    //입력받은 stage_height만큼 *출력
    for (int u = 0; u < stage_height; u++)
    {
        std::cout << "*";
        for (int k = 0; k < stage_width; k++)
        {
            std::cout << " ";
        }
        std::cout << "*" << std::endl;
    }

    //입력받은 stage_width만큼 *출력
    for (int f = 0; f < stage_width+2; f++)
    {
        printf("*");
    }
    std::cout << std::endl;
    return 0;
}

// game_state == 2 일때 화면
int print_introduction_screen()
{
    std::cout << "\n******************************************" << std::endl;
    std::cout << "지렁이 게임은 플레이어가 지렁이를 조종하여\n먹이를 먹고 덩치를 키워 점수를 얻는 방식의\n게임입니다." << std::endl;
    std::cout << "타이틀화면으로 돌아갈까요? (Y/N)\n" << std::endl;
    return 0;
}

int main()
{
    int game_state = 0;
    int is_game_running = 1;
    int stage_width, stage_heigth;
    while (is_game_running)
    {
        char key_input = '0';
        switch (game_state)
        {
        case 0:
            print_title_screen();
            key_input = _getch();
            switch (key_input)
            {
            case '1':
                game_state = 1;
                break;
            case '2':
                game_state = 2;
                break;
            case '3':
                game_state = 3;
                break;
            case '4':
                is_game_running = 0;
                break;
            case 27:
                is_game_running = 0;
                break;
            default:
                break;
            }
            break;
        case 1:
            std::cout << "\n스테이지의 크기를 입력해주세요.\n가로 : ";
            std::cin >> stage_width;
            std::cout << "세로 : ";
            std::cin >> stage_heigth;
            print_game_screen(stage_width, stage_heigth);
            key_input = _getch();
            switch (key_input)
            {
            case 13:
                game_state = 0;
                break;
            default:
                break;
            }
            break;
        case 2:
            print_introduction_screen();
            key_input = _getch();
            switch (key_input)
            {
            case 'y':
                game_state = 0;
                break;
            case 'n':
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }


    }

    return 0;
}
