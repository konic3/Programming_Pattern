#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	while(1){
		cout<<"*";

		if(kbhit()){
			if(getch()==27){break;}
		}
	}
	return 0;
}
