#include "Util.hpp"


//����ȭ�� 
//GameState==0�϶�
void print_title_screen()
{
	cout << "����������������������������������������������������������������������������������" << endl;
	cout << "��                                       ��" << endl;
	cout << "��                                       ��" << endl;
	cout << "��               �ղ�Ʋ��                ��" << endl;
	cout << "��             (Snake  Bite)             ��" << endl;
	cout << "��                                       ��" << endl;
	cout << "��	      1. ���� ����              ��" << endl;
	cout << "��             2. ���� ����              ��" << endl;
	cout << "��             3. ���� ����              ��" << endl;
	cout << "��                                       ��" << endl;
	cout << "����������������������������������������������������������������������������������" << endl;


}

//GameState == 1 �϶� ȭ��
void print_game_screen(int stage_width, int stage_height)
{
	//�ܼ� â ����
	system("cls");


	//�Է¹��� stage_width��ŭ ���
	cout << "��";
	for (int j = 0; j < stage_width; j++)
	{
		cout << "��";
	}
	cout << "��";
	cout << endl;

	//�Է¹��� stage_height��ŭ *���
	for (int u = 0; u < stage_height; u++)
	{
		cout << "��";
		for (int k = 0; k < stage_width; k++)
		{
			cout << " ";
		}
		cout << "��" << endl;
	}

	//�Է¹��� stage_width��ŭ ���
	cout << "��";
	for (int f = 0; f < stage_width ; f++)
	{
		printf("��");
	}
	cout << "��";
	cout << endl;
}

// GameState == 2 �϶� ȭ��
int print_introduction_screen()
{
	//cout << "\n******************************************" << endl;
	cout << "\n\n������ ������ �÷��̾ �����̸� �����Ͽ�\n���̸� �԰� ��ġ�� Ű�� ������ ��� �����\n�����Դϴ�." << endl;
	cout << "\nW A S D�� ������ �����մϴ�.\n@ �� ������ ���̰� 1ĭ �þ�ϴ�." << endl;
	cout << "\nŸ��Ʋȭ������ ���ư����? (Y/N)\n" << endl;
	return 0;
}

// GameState == 3 �϶� ȭ��
void ExitMenu(bool *isEsc,bool *isOut,bool *isGameRunning,int *GameState) {
	char key_input = '0';

	if (*isEsc == false)
	{
		system("cls");
		gotoxy(5, 5);
		cout << "�����Ͻðڽ��ϱ�?\n\n" "     [ �� ]   [�ƴϿ�]" << endl;
		*isEsc = true;
	}
	key_input = _getch();
	switch (key_input)
	{
	case KEY_LEFT:
		if (*isEsc == true) {
			*isOut = true;
			gotoxy(5, 5);
			cout << "�����Ͻðڽ��ϱ�?\n\n" ANSI_COLOR_YELLOW"     [ �� ]   " ANSI_COLOR_RESET"[�ƴϿ�]" << endl;
		}
		break;
	case KEY_RIGHT:
		if (*isEsc == true)
		{
			*isOut = false;
			gotoxy(5, 5);
			cout << "�����Ͻðڽ��ϱ�?\n\n" ANSI_COLOR_RESET"     [ �� ]   " ANSI_COLOR_YELLOW"[�ƴϿ�]" ANSI_COLOR_RESET"" << endl;
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


