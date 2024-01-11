#include <iostream>
using namespace std;

/* 구조체 : 여러개의 데이터(변수)들을 묶어서 한번에 처리한다. */
struct tPlayer
{
	/* 구조체의 경우, 아무 설정을 하지 않고 선언한 멤버는 Default가 public하다. */
	int iAtt;
	int iDef;
	int iHp;
	int iMp;
};

/* 클래스 : 여러개의 함수를 묶어두기 위해서 */
class CPlayer
{
	/* 클래스의 경우, 아무 설정을 하지 않고 선언한 멤버는 Default가 private하다. */
	/* private: 외부에 있는 다른 함수에서는 절대 사용, 접근이 불가능한 멤버들. */
	/* 멤버를 사용하기 위한 방법 두가지 */
	// 첫번째. 멤버의 설정을 public하게 바꿔준다. 
	/* 접근 지시자 */
	// 1. public : 외부에 보여준다. 외부에 있는 다른함수에서 언제든 사용할 수 있는 멤버
	// 2. protected
	// 3. private : 외부에 안 보여준다. 외부에 있는 다른함수에서 절대 사용할 수 없는 멤버
	
	// 두번째
	/* 멤버함수 */
	/* 내부에 함수를 정의한다. */
	/* 같은 클래스 내부에 선언된 함수에서는 private멤버라도 접근하여 사용이 가능하다. */
public:
	// 채운다.
	void Initialize(int iAtt)
	{
		/* this : 이 멤버함수를 호출하기 위해 사용한 객체의 주소를 의미한다. */
		this->iAtt = iAtt;
		this->iDef = 7;
		this->iHp = 100;
		this->iMp = 100;
	}

	// 출력한다.
	void Output()
	{
		cout << "공격력 : " << iAtt << endl;
		cout << "방어력 : " << iDef << endl;
		cout << "생명력 : " << iHp << endl;
		cout << "정신력 : " << iMp << endl;
	}
private:	/* 멤버변수 */
	int iAtt;
	int iDef;
	int iHp;
	int iMp;
};

int main(void)
{
	tPlayer		Player_Structure;
	Player_Structure.iAtt = 10;
	Player_Structure.iDef = 7;
	Player_Structure.iHp = 100;
	Player_Structure.iMp = 100;

	cout << "공격력 : " << Player_Structure.iAtt << endl;
	cout << "방어력 : " << Player_Structure.iDef << endl;
	cout << "생명력 : " << Player_Structure.iHp << endl;
	cout << "정신력 : " << Player_Structure.iMp << endl;

	/* 클래스 <-> Player_Class객체 */
	CPlayer		Player_Class;

	Player_Class.Initialize(10);
	Player_Class.Output();

	CPlayer		Player_Special;
	Player_Special.Initialize(100);
	Player_Special.Output();
}