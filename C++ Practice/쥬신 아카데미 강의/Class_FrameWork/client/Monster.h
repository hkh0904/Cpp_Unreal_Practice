#pragma once

#include "GameObj.h"

/* CMonster의 부모클래스로서 CGameObj를 정의한다. */
class CMonster : public CGameObj
{
public:
	CMonster();
	~CMonster();

public:
	void Initailize();
	void Output();

private:
	int		m_iMoney = { 0 };

};

