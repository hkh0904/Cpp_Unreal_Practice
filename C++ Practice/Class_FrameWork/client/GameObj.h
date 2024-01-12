#pragma once

#include "Defines.h"

class CGameObj
{
public:
	CGameObj();
	~CGameObj();

public:
	void Output();


protected: /* 부모에 있는 함수에서 사용가능 + 자식클래스에서도 사용할 수 있게한다. */
	int			m_iAtt = { 0 };
	int			m_iDef = { 0 };
	int			m_iHp = { 0 };
	int			m_iMp = { 0 };
};


