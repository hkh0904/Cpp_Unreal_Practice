#include "GameObj.h"

CGameObj::CGameObj()
{
}

CGameObj::~CGameObj()
{
}

void CGameObj::Output()
{
	cout << "공격력 : " << m_iAtt << endl;
	cout << "방어력 : " << m_iDef << endl;
	cout << "생명력 : " << m_iHp << endl;
	cout << "정신력 : " << m_iMp << endl;
}
