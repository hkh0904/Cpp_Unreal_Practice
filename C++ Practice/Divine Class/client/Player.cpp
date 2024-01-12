#include "Player.h"

/* 생성자 : 클래스를 메모리 할당하게 되면 반드시 호출되는 함수 */
/* 디폴트 생성자. 내가 정의한 생성자. 복사 생성자. 이동 생성자. */
/* 외부의 main.cpp파일에서 클래스 호출하므로 생성자함수도 public으로 정의필요 */
CPlayer::CPlayer()
	/* 초기화 목록. (Initialize List) */
	: m_iAtt{ 0 }, m_iDef{ 0 }, m_iHp{ 0 }, m_iMp{ 0 }, m_pData{ nullptr }
{
	/* 플레이어 클래스가 생성될 때 해야할 기능 */
	m_pData = new int(1000);

}

CPlayer::CPlayer(int iData)
/* 초기화 목록. (Initialize List) */
	: m_iAtt{ iData }, m_iDef{ 0 }, m_iHp{ 0 }, m_iMp{ 0 }
{
	/* 플레이어 클래스가 생성될 때 해야할 기능 */
	m_pData = new int(1000);

}


CPlayer::CPlayer(int iAtt, int iDef, int iHp, int iMp)
	/* 초기화 목록. (Initialize List) */
	: m_iAtt(iAtt), m_iDef(iDef), m_iHp(iHp), m_iMp(iMp)
{
	/* 플레이어 클래스가 생성될 때 해야할 기능 */
}


/* 소멸자 : 클래스의 메모리를 삭제하게 되면 반드시 호출되는 함수 */
/* 소멸자는 종류가 하나 */
CPlayer::~CPlayer()
{
	/* 클래스의 멤버변수를 정리한다. */
	delete m_pData;
	m_pData = nullptr;
}


void CPlayer::Initialize()
{
	m_iAtt = 10;
	m_iDef = 7;
	m_iHp = 100;
	m_iMp = 100;
}

