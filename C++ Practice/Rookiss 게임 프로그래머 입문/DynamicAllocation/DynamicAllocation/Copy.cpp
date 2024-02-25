#include <iostream>
using namespace std;

// 얕은 복사 vs 깊은 복사
class Pet
{
public:
	Pet() { cout << "Pet()" << endl; }
	~Pet() { cout << "~Pet()" << endl; }

	Pet(const Pet& pet) { cout << "Pet(const Pet&)" << endl; }
};


class Knight
{
public:
	Knight()
	{
		_pet = new Pet();
	}

	~Knight()
	{
		delete _pet;
	}

	Knight(const Knight& k)
	{
		_hp = k._hp;
		// 새로 동적할당을 해야 깊은 복사
		_pet = new Pet(*(k._pet));
	}

public:
	int _hp = 100;
	// 포인터로 선언했을때 복사하면
	// k1, k2나이트가 동일한 펫을 가지게된다.
	// 두 기사중 하나가 소멸하는 순간 소멸자에서 펫을 소멸시키면?
	// 나머지 기사가 소멸해서 펫을 소멸하러갔을떄 -> 이미 펫이 소멸되어있음..
		
	// 같은 포인터를 가리키게 하지말자 
	Pet* _pet;
};


int main()
{
	Knight k1;
	k1._hp = 200;

	Knight k2(k1); // == Knight k2 = k1; (복사 생성자의 개입)

	Knight k3;	// 기본 생성자
	k3 = k1		// 복사 연산자

}