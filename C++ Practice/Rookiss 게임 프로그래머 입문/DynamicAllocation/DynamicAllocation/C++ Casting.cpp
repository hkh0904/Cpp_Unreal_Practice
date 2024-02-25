#include <iostream>
using namespace std;

// 캐스팅 4총사
// static_cast  << 중요
// dynamic_cast  << 중요
// const_cast
// reinterpret_cast

class Player
{
public:
	virtual ~Player() {};
};

class Knight : public Player
{
public:
	virtual ~Knight() {};
};

class Archer : public Player
{};

class Dog
{};

int main()
{
	// static_cast : 타입 원칙에 비춰볼 때 상식적인 캐스팅만 허용해준다
	// 1) int <-> float
	// 2) Player* -> Knight*

	int hp = 100;
	int maxHp = 200;
	float ratio = static_cast<float>(hp) / maxHp;

	Knight* k = new Knight();
	Player* p = k;
	Knight* k2 = static_cast<Knight*>(p);

	// dynamic_cast : 상속 관계에서의 안전 변환
	// 다형성을 활용하는 방식 (virtual)
	// RTTI (RunTime Type Information)
	Archer* a = new Archer();
	Player* p = a;
	Knight* k3 = dynamic_cast<Knight*>(p);	// C# as
	if (k2 != nullptr)
	{
		// 기사 맞았네?
	}

	// const_cast -> 사용할 일이 사실상 없다.
	const char* name = "Rookiss";
	char* name2 = const_cast<char*>(name);

	// reinterpret_cast
	// 위험하고, 강력한 형태
	// re-interpret 다시 생각하다? 다시 간주하다?
	// 포인터 -> 전혀 관계없는 다른 포인터로 변환
	Dog* dog = reinterpret_cast<Dog*>(k);
	 

}