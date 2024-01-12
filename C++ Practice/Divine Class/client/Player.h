/* 중복 인클루두(포함)되는 것을 방지한다. */
#pragma once
#include "Defines.h"

// 함수와 변수를 가진다. 중요도 = 함수 > 변수
class CPlayer
{
	/* 생성자 : 클래스를 메모리 할당하게 되면 반드시 호출되는 함수 */
	/* 디폴트 생성자. 내가 정의한 생성자. 복사 생성자. 이동 생성자. */
	/* 외부의 main.cpp파일에서 클래스 호출하므로 생성자함수도 public으로 정의필요 */
public:
	CPlayer();
	/* explicit : 명백한. 암묵적 형변환을 방지한다. */
	explicit CPlayer(int iData);
	CPlayer(int iAtt, int iDef, int iHp, int iMp);
	/* 소멸자 : 클래스의 메모리를 삭제하게 되면 반드시 호출되는 함수 */
	/* 소멸자는 종류가 하나 */
	~CPlayer();

public:
	/* inline 함수란? 헤더에 구현되어 있는 함수 중, inline화된 함수의 경우에는 함수의 호출이 일어나는 것이 아니라
	함수를 호출하는 위치에 함수의 기능을 붙여넣는 것과 같은 일을 수행하게 된다. */
	/* 결국엔 컴파일러가 스스로 판단하여 이 멤버함수를 인라인화 시킬지 안시킬지 결정한다. */


	void Initialize();
	// inline 함수 사용시 호출에 대한 비용 감소
	// 코드 양이 증가할 수 있음( 코드 길이가 너무 길지 않을때 사용하는게 유리 )
	inline void Output()
	{
		cout << "공격력 : " << m_iAtt << endl;
		cout << "방어력 : " << m_iDef << endl;
		cout << "생명력 : " << m_iHp << endl;
		cout << "정신력 : " << m_iMp << endl;
	}

private:
	int			m_iAtt = { 0 };
	int			m_iDef = { 0 };
	int			m_iHp = { 0 };
	int			m_iMp = { 0 };
	int*		m_pData = { nullptr };		// 정리가 필요한 멤버변수
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