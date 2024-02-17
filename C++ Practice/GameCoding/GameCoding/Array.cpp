#include "Helper.h"
#include "RoguelikeMap.h"
#include "Player.h"

// 로그라이크 맵 실습

int main()
{
	SetCursorOnOff(false);
	
	// MovePlayer(3, 2);

	while (true)
	{
		// 입력
		HandleKeyInput();

		// 로직
		HandleMove();

		// 출력
		PrintMap2D();
	}
}