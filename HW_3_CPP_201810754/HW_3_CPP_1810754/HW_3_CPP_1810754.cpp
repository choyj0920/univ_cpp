#include "pch.h"

int main()
{
	bool regame= true;
	srand((unsigned)time(0));
	while (regame)
	{
		Cell::playGame();
		setCursorView(true);
		cout << "\n종료하시려면 0을 입력하세요(숫자만 입력, 0이 아닌 수 재시작)\n";
		regame = get_num();
	}
}
