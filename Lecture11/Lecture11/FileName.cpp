#include "MGameLoop.hpp"
using namespace std;

namespace MuSoeun
{
    class Scene
    {
    public:
        int width;
        int height;
        vector<string> objList;
        //vector<bool> objListcheck;

        //screenBuf[width + (width * height)];

        char* screenBuf;

        //마우스 이동
        void gotoxy(int x, int y) {
            //x, y 좌표 설정
            COORD pos = { x,y };
            //커서 이동
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        }


        //화면 배열 생성
        void InitScreenBuf()
        {
            screenBuf = new char[(width + 5) * (height + 2)];
            //스테이지 구현 실험
          
            for (size_t i = 0; i < (width + 5) * (height + 2); i++)
            {
                screenBuf[i] = '*';
            }
           

            //스테이지 비우기
            
            //개행
            for (int i=1; i < (height + 2); i++)
            {
                screenBuf[(width+5)*i-1] = '\n';
            }

            //배열의 끝
            screenBuf[(width + 5) * (height + 2)-1] = '\0';
            
            
        }

        //화면 배열 해체
        void ReleaseScreenBuf()
        {
            if (screenBuf != nullptr)
            {
               delete(screenBuf);
            }
        }


        //게임 스테이지 생성
        
        void DrawStage() {
            for (size_t i = 1; i < height+1; i++)
            {
                gotoxy(2, i);
                for (size_t i = 0; i < width; i++)
                {
                    cout << ' ';
                }
                cout << '\n';
            }
        }
        
        //오브젝트 그리기
        void Draw() {
            gotoxy(5, 4);
            cout << "***";
            gotoxy(5, 5);
            cout << "* *";
            gotoxy(5, 6);
            cout << "***";
        }
       


        //화면 배열 그림
        void DrawScreenBuf()
        {
            std::cout << screenBuf;

          
        }
    };

    class Object : Scene
    {
    public :
        int x = 5, y=4;

        void Render() {
            gotoxy(x, y);
        }
    };

    class Component //Unity MonoBehavior
    {
        void Start();
        void Update();
    };
}

int main()
{
    MuSoeun::Scene scene;
    MuSoeun::Object object;
    
    cout << "가로를 입력하세요" << endl;
    cin >> scene.width;
    cout << "세로를 입력하세요" << endl;
    cin >> scene.height;
    system("cls");

    scene.InitScreenBuf();
    scene.DrawScreenBuf();
    scene.DrawStage();
    scene.objList.push_back("Sqaure");
    scene.Draw();

    
    while (1)
    {

    }
    
    
    
    scene.ReleaseScreenBuf();



    return 0;
}