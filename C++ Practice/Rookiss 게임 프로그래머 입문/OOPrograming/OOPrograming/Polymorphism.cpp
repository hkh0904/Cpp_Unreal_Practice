#include <iostream>
using namespace std;

// 다형성 << polymorphism (poly + morphism)

// 오버로딩(overloading) = 함수 이름의 재사용
// 오버라이딩(overriding) = 부모 클래스의 함수를 자식 클래스에서 재정의

// 추상 클래스
class Player
{
public:
	// 가상 함수 -> 가상 함수 테이블이 생성됨 (vftable -> virtual function table)
	// .vftable [ 주소1 | 주소2 | 주소3 ]
	virtual void Move() { cout << "Player Move()" << endl; }

	virtual void OnDead() = 0;	// 순수 가상 함수 (상속받은 함수에서 구현해야함)
	// virtual void OnDead() abstract;

public:
	int m_hp;
};

class Knight : public Player
{
public:
	// 가상함수이지만 상속을 받은것 임을 알려주는 문법
	virtual void Move() override { cout << "Knight Move()" << endl; }
	// 순수 가상함수를 구현해주지 않으면 에러 발생
	virtual void OnDead() override { cout << "Dead()" << endl; }
};

// 바인딩(Binding) = 묶는다
// - 정적 바인딩 (static binding = 컴파일 시점 결정)
// - 동적 바인딩 (dynamic binding = 실행 시점 결정
void MovePlayer(Player* player)
{
	player->Move();
	player->OnDead();
}

int main()
{
	Knight k1;
	MovePlayer(&k1);
}