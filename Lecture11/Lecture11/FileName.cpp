#include "MGameLoop.hpp"
using namespace std;

namespace MuSoeun
{
    class Scene
    {
    public:
        int width = 30;
        int height = 10;
        vector<string> objList;
        //vector<bool> objListcheck;

        //screenBuf[width + (width * height)];

        char* screenBuf;

        //���콺 �̵�
        void gotoxy(int x, int y) {
            //x, y ��ǥ ����
            COORD pos = { x,y };
            //Ŀ�� �̵�
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        }


        //ȭ�� �迭 ����
        void InitScreenBuf()
        {
            screenBuf = new char[(width + 5) * (height + 2)];
            //��������
            for (size_t i = 0; i < (width + 5) * (height + 2); i++)
            {
                screenBuf[i] = '*';
            }

            //�������� ����
            
            //����
            for (int i=1; i < (height + 2); i++)
            {
                screenBuf[(width+5)*i-1] = '\n';
            }

            //�迭�� ��
            screenBuf[(width + 5) * (height + 2)-1] = '\0';
            
            
        }

        //ȭ�� �迭 ��ü
        void ReleaseScreenBuf()
        {
            if (screenBuf != nullptr)
            {
               delete(screenBuf);
            }
        }


        //���� �������� ����
        
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
        
        void Draw() {
            gotoxy(5, 4);
            cout << "***";
            gotoxy(5, 5);
            cout << "* *";
            gotoxy(5, 6);
            cout << "***";
        }
       


        //ȭ�� �迭 �׸�
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
    

    scene.InitScreenBuf();
    scene.DrawScreenBuf();
    scene.DrawStage();
    scene.objList.push_back("Sqaure");
    scene.Draw();

    /*
    while (1)
    {

    }
    */
    
    
    scene.ReleaseScreenBuf();



    return 0;
}