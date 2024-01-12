#pragma once

#include "GameObj.h"

/* CPlayer의 부모클래스로서 CGameObj를 정의한다. */
class CPlayer : public CGameObj
{
public:
	CPlayer();
	~CPlayer();

public:
	void Initailize();
	void Output();
 
private:
	int		m_iCash = { 0 };

};

