#include <iostream>
using namespace std;

// struct vs class
// 거의 비슷하지만 접근지정자 선언이 없을 때 기본적으로
// struct는 public / class는 private다

// static
class marine
{
public:
	// 특정 마린 객체와 연관
	void takedamage(int damage)
	{
		hp -= damage;
	}

	// 특정 마린 객체와 무관
	static void setattack(int value)
	{
		// hp = 40;
		attack = value;
	}

public:
	// static으로 선언하면 모든 마린의 개체가 하나의 데이터를 바라보고 있는 것
	// 100마리의 마린이어도 4byte 하나의 데이터 공간으로 사용 가능

	// 특정 마린 객체와 연관
	int hp;
	// 특정 마린 객체와 무관하다.
	static int attack;
};
 int marine::attack = 6;


 // static 활용
class Player
{
public:
	Player()
	{
		id = s_idGenerator++;
	}
public:
	int id;
	static int s_idGenerator;
};

int Player::s_idGenerator = 1;


// 디자인 패턴
// - 싱글톤, 옵저버, 컴포넌트, ...

// 싱글톤 활용 예시 : 정말 딱 1개만 존재하고 어디서든 사용할 수 있는 [매니저] 클래스
class UserManager
{
public:
	static UserManager* GetInstance()
	{
		static UserManager um;
		return &um;
	}

public:
	void AddUser() { _userCount++; }
	int GetUserCount() { return _userCount; }

private:
	int _userCount = 0;
};

#define GET_MANAGER (UserManager::GetInstance())

int main()
{
	Player p1;	// id 1
	Player p2;	// id 2	
	Player p3;	// id 3

	for (int i = 0; i < 10; i++)
		UserManager::GetInstance()->AddUser();

	cout << GET_MANAGER->GetUserCount() << endl;
}