#include <iostream>
using namespace std;

class Player
{
public:
	Player()
	{
		cout << "Player()" << endl;
	}
	virtual ~Player()
	{
		cout << "~Player()" << endl;
	}
};

class Pet { };

class Archer : public Player
{
public:
	Archer()
	{
		_pet = new Pet();
		cout << "Archer()" << endl;
	}

	virtual ~Archer()
	{
		cout << "~Archer()" << endl;
		delete _pet;
	}

private:
	// Pet _pet 으로 구현하면 archer가 pet의 메모리를 같이 붙여서 다닌다
	Pet* _pet;
};


int main()
{
	// 자식 클래스를 부모 클래스로 간주할 때 -> 자식의 소멸자가 실행되지 않음
	// 가상함수 -> 어떤 타입의 포인터를 가리키고 있든 무조건 원본의 타입에 따라 해당하는 타입의 함수를 호출
	// 즉 부모클래스의 소멸자를 가상함수로 구현해야 자식의 소멸자도 잘 실행해서 메모리 누수를 막을 수 있음 (자식 클래스에도 소멸자라면 virtual 붙이는 습관)
	// 만약 자식클래스의 소멸자에 메모리를 정리하는 코드가 구현되어있었다면 메모리 삭제가 계속해서 안될수 있다.
	
	// 생성자 호출
	// Archer* archer = new Archer();
	Player* archer = new Archer();

	// 소멸자 호출
	delete archer;
	archer = nullptr;
}