#include "Monster.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
}

void CMonster::Initailize()
{
	m_iAtt = 20;
	m_iDef = 7;
	m_iHp = 300;
	m_iMp = 150;

	m_iMoney = 5'000'000;
}

void CMonster::Output()
{
	//CGameObj::Output();
	__super::Output();
	cout << "몬스터가 가진 돈 : " << m_iMoney << endl;
}
