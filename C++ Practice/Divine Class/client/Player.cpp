#include "Player.h"

void CPlayer::Initialize()
{
	iAtt = 10;
	iDef = 10;
	iHp = 100;
	iMp = 100;
}

void CPlayer::Output()
{
	cout << "공격력 : " << iAtt << endl;
	cout << "방어력 : " << iDef << endl;
	cout << "생명력 : " << iHp << endl;
	cout << "정신력 : " << iMp << endl;
}