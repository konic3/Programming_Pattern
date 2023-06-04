#include"GameLoop.hpp"
using namespace std;

int main() {
	Running::Loop loop;

	loop.CursorView(false);
	loop.Run();

	return 0;
}