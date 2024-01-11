/* iostream, class모두 header파일에서 가져옴 */
#include "Defines.h"
#include "Player.h"
#include "Monster.h"

int main()
{
	CPlayer		Player;

	Player.Initialize();

	Player.Output();

	CMonster	Monster;

	Monster.Initialiae();

	Monster.Output();

}