#include "Player.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initailize()
{
	m_iAtt = 10;
	m_iDef = 5;
	m_iHp = 200;
	m_iMp = 100;

	m_iCash = 10'000'000;

}

void CPlayer::Output()
{
	//CGameObj::Output();
	__super::Output();
	cout << "플레이어가 가진 캐쉬 : " << m_iCash << endl;
}


