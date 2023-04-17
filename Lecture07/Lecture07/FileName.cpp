#include<iostream>

using namespace std;


class MobilePhone {
public:
	MobilePhone() {
		cout << "MobilePhone�� �����մϴ�" << endl;
	}
	~MobilePhone() {
		cout << "MobilePhone�� �Ҹ��ŵ�ϴ�" << endl;
	}

	void TurnON() {
		cout << "MobilePhone�� ŵ�ϴ�" << endl;
	}
	void TurnOFF() {
		cout << "MobilePhone�� ���ϴ�" << endl;
	}
};

class IPhone : public MobilePhone {
public:
	IPhone() {
		cout << "IPhone�� �����մϴ�" << endl;
	}
	~IPhone() {
		cout << "IPhone�� �Ҹ��ŵ�ϴ�" << endl;
	}

	void ApplePay() {
		cout << "ApplePay : ���� �Ǿ����ϴ�." << endl;
	}
	void Siri() {
		cout << "Siri : �� ������ ���͵帱���" << endl;
	}
};

class Galaxy : public MobilePhone {
public:
	Galaxy() {
		cout << "Galaxy�� �����մϴ�" << endl;
	}
	~Galaxy() {
		cout << "Galaxy�� �Ҹ��ŵ�ϴ�" << endl;
	}
	void SamsungPay() {
		cout << "SamsungPay : �����Ǿ����ϴ�." << endl;
	}
	void Bixby() {
		cout << "Bixby : ������� ���� �� ���� ���� ���Խ�..." << endl;
	}
};

void main() {
	cout << "MobilePhone�� ���� �����Դϴ�.\n" << endl;

	IPhone *i = new IPhone();
	Galaxy g;

	cout << endl;
	i->Siri();
	g.Bixby();
	cout << endl;

	delete(i);
}