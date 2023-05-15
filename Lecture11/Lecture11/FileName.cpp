#include<iostream>
#include<vector>
//#include<string>
#include "MGameLoop.hpp"
using namespace std;

namespace MuSoeun {
	class Scene {
		int width;
		int height;
		vector<Object>objList;

		//screenBuf[width +(width * height)];

		char* screenBuf;

		void InitScreenBuf() 
		{
			screenBuf = new char[(width+1)*height+5];
			for (int i = 0; i < height; i++)
			{
				screenBuf[(width + 1) * (width +1) * i-1]='\n';

			}
			screenBuf[(width + 1) * (width + 1) * (height-1) - 1] = '\0';

		}

		void ReleaseScreenBuf()
		{
			if (screenBuf != nullptr) {
				delete(screenBuf);
			}
		}


		void DrawScreenBuf() {
			std::cout << screenBuf;
		}

	};

	class Object {
		void Render();
	};

	class Component //Unity MonoBehavior
	{
		void Start();
		void Update();
	};
}

int main() {
	/*
	MuSoeun::MGameLoop gameLoop;
	gameLoop.Run();
	*/
	while (1)
	{

	}

	return 0;
}