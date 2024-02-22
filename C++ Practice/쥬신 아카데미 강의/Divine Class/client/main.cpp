/* iostream, class모두 header파일에서 가져옴 */
/* .h 어떤 무언가의 정의를 가진다. */
#include "Defines.h"
#include "Player.h"
#include "Monster.h"

int main()
{
	/* 생성자 : 클래스에 대한 공간을 할당하면 호출된다.*/
	/* 내가 따로 생성자를 정의하지 않아도 void형 생성자는 기본으로 정의된다. */
	/* 함수이기 때문에 오버로딩이 가능하다.(생성자의 인자를 다르게 정의하는 것도 가능하다.) */
	/* 인자 값을 받는 생성자를 정의한다면 void형 생성자의 기본 생성은 하지 않는다. */
	/* 생성자 안에서는 초기화목록을 통해서 멤버변수의 초기화가 가능  */
	CPlayer*	pPlayer = new CPlayer{ 10, 5, 200, 100 };	// 유니폼 초기화

	pPlayer->Initialize();
	pPlayer->Output();


	delete pPlayer;
	pPlayer = nullptr;

	CPlayer		Player = {};
	Player.Output();

	//==========================================
	//CPlayer		Player(10, 5, 200, 100);

	//Player.Initialize();

	//Player.Output();

	//CMonster	Monster;

	//Monster.Initialiae();

	//Monster.Output();

}