



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
	std::cout << "������ ������ �÷��̾ �����̸� �����Ͽ�\n���̸� �԰� ��ġ�� Ű�� ������ ��� �����\n�����Դϴ�." << std::endl;
	std::cout << "Ÿ��Ʋȭ������ ���ư����? (Y/N)\n" << std::endl;
	return 0;
}

