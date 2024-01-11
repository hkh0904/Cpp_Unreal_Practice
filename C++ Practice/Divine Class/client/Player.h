/* 중복 인클루두(포함)되는 것을 방지한다. */
#pragma once
#include "Defines.h"

// 함수와 변수를 가진다. 중요도 = 함수 > 변수
class CPlayer
{
public:
	void Initialize();
	void Output();

private:
	int		iAtt;
	int		iDef;
	int		iHp;
	int		iMp;
};

// 클래스이름:: -> 멤버변수 사용가능
//void CPlayer::Initialize()
//{
//	iAtt = 10;
//	iDef = 10;
//	iHp = 100;
//	iMp = 100;
//}
//
//void CPlayer::Output()
//{
//	cout << "공격력 : " << iAtt << endl;
//	cout << "방어력 : " << iDef << endl;
//	cout << "생명력 : " << iHp << endl;
//	cout << "정신력 : " << iMp << endl;
//}