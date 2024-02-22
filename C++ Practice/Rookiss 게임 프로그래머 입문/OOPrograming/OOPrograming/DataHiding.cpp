#include <iostream>
using namespace std;

// 은닉성 Data hiding (캡슐화 encapsulation)

// 자동차
// - 핸들/페달/엔진/문/전기선/휘발유
// 구매자 입장에서 사용 : 핸들/페달/문
// 몰라도 되는 요소 : 엔진/전기선/휘발유

// 접근 지정자
// public(공개적), private(개인적->선언한 함수 내부에서만 사용가능), protected(보호받는->상속받은 자손도 사용가능)

class Car
{
public:
	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}
	void TurnKey()
	{
		// ...
		PutFuellneEngin();
		// ...
	}

protected:
	void Disassemble() {}	// 차를 분해시킨다(?)
	void PutFuellneEngin() {}
	void ConnectCircuit() {}

public:
	// 핸들
	// 페달
	// 엔진
	// 문
	// 전기선
};

// 상속 접근 지정자 : 다음 세대한테 부모님의 유산을 어떻게 물려줄지?
// public : 공개적 상속 -> 그대로 물려준다 (대부분은 public만 사용)
// protected : 보호받는 상속? 내 자손들에게만 물려준다. (public -> protected로 물려줌)
// private : 나까지만 꿀빤다 (이후에 물려줄 때 public, protected -> private로 물려줌)
class SuperCar : public Car
{
public:
	void Test()
	{
		MoveHandle();
		// protected에 선언했기 때문에 상속받은 자식도 사용가능
		Disassemble();
	}
};

class Knight
{
public:
	void SetHp(int hp)
	// 1. 이렇게 hp를 건드리는 부분을 함수로 만들어두면 braek를 걸어 어디서 hp를 건드리는지 쉽게 찾을 수 있음
	{
		m_hp = hp;
		// 2. hp가 변동되려면 해당 함수를 무조건 거쳐야하므로 hp가 변동될 때실행되어야 하는 동작들이 잘 실행될 수 있음
		if (m_hp <= 50)
		{
			// TODO
		}
	}

	int GetHp()
	{
		return m_hp;
	}

private:
	int m_hp = 100;
};

int main()
{
	Car Car1;

	Knight k1;
	// 이렇게 외부에서 아무나 고치는건 문제가 될 가능성이 크다
	// k1.m_hp = 200;

	k1.SetHp(100);
}