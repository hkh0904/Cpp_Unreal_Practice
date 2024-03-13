#include <iostream>
using namespace std;

class Pet {};

class Knight
{
public:
	// 기본 생성자, 기본 소멸자
	// 복사 생성자
	// 복사 대입 연산자
	// 이동 생성자
	// 이동 대입 연산자
	int _hp;
	Pet _pet;
};

void TestKnight_Copy(Knight knight)
{
	knight._hp = 100;
}


// 원본 넘겨줄테니... 건드려도 됨
void TestKnight_LValueRef(Knight& knight)
{
	knight._hp = 100;
}

// 원본 넘겨줄테니... 건드릴 순 없어
void TestKnight_ConstValueRef(const Knight& knight)
{
	// knight._hp = 100;
}

// 원본 넘겨줄테니... 더이상 활용하지 않을테니 맘대로 해
void TestKnight_RValueRef(Knight&& knight)
{
	// knight._hp = 100;
}



int main()
{
	// 왼값(L-value) vs 오른값(r-value)

	// L-value : 단일시ㅣ을 넘어서 계속 지속되는 개체
	// R-value : L-value가 아닌 나머지

	int a = 3; // a = 왼값, 3 = 오른값

	Knight k1;
	k1._pet = new Pet();

	Knight k2;
	// k2 = static_cast<Knight&&>(k1);
	k2 = std::move(k1);	// rvalue_cast




	TestKnight_Copy(k1);

	TestKnight_RValueRef(static_cast<Knight&&>(k1));
}