#include<iostream>

using namespace std;


class MobilePhone {
public:
	MobilePhone() {
		cout << "MobilePhone을 생성합니다" << endl;
	}
	~MobilePhone() {
		cout << "MobilePhone을 소멸시킵니다" << endl;
	}

	void TurnON() {
		cout << "MobilePhone을 킵니다" << endl;
	}
	void TurnOFF() {
		cout << "MobilePhone을 끕니다" << endl;
	}
};

class IPhone : public MobilePhone {
public:
	IPhone() {
		cout << "IPhone을 생성합니다" << endl;
	}
	~IPhone() {
		cout << "IPhone을 소멸시킵니다" << endl;
	}

	void ApplePay() {
		cout << "ApplePay : 결제 되었습니다." << endl;
	}
	void Siri() {
		cout << "Siri : 네 무엇을 도와드릴까요" << endl;
	}
};

class Galaxy : public MobilePhone {
public:
	Galaxy() {
		cout << "Galaxy를 생성합니다" << endl;
	}
	~Galaxy() {
		cout << "Galaxy를 소멸시킵니다" << endl;
	}
	void SamsungPay() {
		cout << "SamsungPay : 결제되었습니다." << endl;
	}
	void Bixby() {
		cout << "Bixby : 히어로즈 오브 더 스톰 지금 가입시..." << endl;
	}
};

void main() {
	cout << "MobilePhone에 대한 예제입니다.\n" << endl;

	IPhone *i = new IPhone();
	Galaxy g;

	cout << endl;
	i->Siri();
	g.Bixby();
	cout << endl;

	delete(i);
}