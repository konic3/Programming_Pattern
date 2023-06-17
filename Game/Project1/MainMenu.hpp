#include "Util.hpp"


//����ȭ�� 
//GameState==0�϶�
void print_title_screen()
{
	std::cout << "����������������������������������������������������������������������������������" << std::endl;
	std::cout << "��                                       ��" << std::endl;
	std::cout << "��                                       ��" << std::endl;
	std::cout << "��              ������ ����              ��" << std::endl;
	std::cout << "��             (Snake  Bite)             ��" << std::endl;
	std::cout << "��                                       ��" << std::endl;
	std::cout << "��	      1. ���� ����              ��" << std::endl;
	std::cout << "��             2. ���� ����              ��" << std::endl;
	std::cout << "��             3. ���� ����              ��" << std::endl;
	std::cout << "��                                       ��" << std::endl;
	std::cout << "����������������������������������������������������������������������������������" << std::endl;


}

//GameState == 1 �϶� ȭ��
void print_game_screen(int stage_width, int stage_height)
{
	//�ܼ� â ����
	system("cls");


	//�Է¹��� stage_width��ŭ ���
	std::cout << "��";
	for (int j = 0; j < stage_width; j++)
	{
		std::cout << "��";
	}
	std::cout << "��";
	std::cout << std::endl;

	//�Է¹��� stage_height��ŭ *���
	for (int u = 0; u < stage_height; u++)
	{
		std::cout << "��";
		for (int k = 0; k < stage_width; k++)
		{
			std::cout << " ";
		}
		std::cout << "��" << std::endl;
	}

	//�Է¹��� stage_width��ŭ ���
	std::cout << "��";
	for (int f = 0; f < stage_width ; f++)
	{
		printf("��");
	}
	std::cout << "��";
	std::cout << std::endl;
}

// GameState == 2 �϶� ȭ��
int print_introduction_screen()
{
	//std::cout << "\n******************************************" << std::endl;
	std::cout << "\n\n������ ������ �÷��̾ �����̸� �����Ͽ�\n���̸� �԰� ��ġ�� Ű�� ������ ��� �����\n�����Դϴ�." << std::endl;
	std::cout << "\nW A S D�� ������ �����մϴ�.\n@ �� ������ ���̰� 1ĭ �þ�ϴ�." << std::endl;
	std::cout << "\nŸ��Ʋȭ������ ���ư����? (Y/N)\n" << std::endl;
	return 0;
}

// GameState == 3 �϶� ȭ��
void ExitMenu(bool *isEsc,bool *isOut,bool *isGameRunning,int *GameState) {
	char key_input = '0';

	if (*isEsc == false)
	{
		system("cls");
		gotoxy(5, 5);
		std::cout << "�����Ͻðڽ��ϱ�?\n\n" "     [ �� ]   [�ƴϿ�]" << std::endl;
		*isEsc = true;
	}
	key_input = _getch();
	switch (key_input)
	{
	case KEY_LEFT:
		if (*isEsc == true) {
			*isOut = true;
			gotoxy(5, 5);
			std::cout << "�����Ͻðڽ��ϱ�?\n\n" ANSI_COLOR_YELLOW"     [ �� ]   " ANSI_COLOR_RESET"[�ƴϿ�]" << std::endl;
		}
		break;
	case KEY_RIGHT:
		if (*isEsc == true)
		{
			*isOut = false;
			gotoxy(5, 5);
			std::cout << "�����Ͻðڽ��ϱ�?\n\n" ANSI_COLOR_RESET"     [ �� ]   " ANSI_COLOR_YELLOW"[�ƴϿ�]" ANSI_COLOR_RESET"" << std::endl;
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


