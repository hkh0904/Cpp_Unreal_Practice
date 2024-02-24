#include <iostream>
using namespace std;

// MMO RPG 동접 1만, 몬스터 50만

// - 스택 영역
// - 메모리 영역

// 동적 할당 : 실시간으로 요청을 해서 메모리를 할당받아 사용한다.

class Monster
{
public:
	Monster() { cout << "Monster()" << endl; }

	~Monster() { cout << "~Monster()" << endl; }

public:
	int _hp = 0;
};

class Player
{
public:
	Monster* _target;
};


Player* FindPlayer(int id)
{
	// TODO

	return nullptr;
}


int main()
{
	// 아래와 같은 구현은 사용할 수 있는 스택메모리 초과
	// Monster monsters[100 * 10000];

	// C에서 사용하는 방식
	// malloc() 을 통해 메모리 요청 + free 로 메모리 반환 -> 생성자 소멸자를 호출하지 않음
	/*void* ptr = malloc(1000);

	Monster* m = (Monster*)ptr;
	m->_hp = 100;

	free(ptr);*/

	// C++에서 사용되는 방식
	// new + delete 

	Monster* m1 = new Monster();
	m1->_hp = 100;
	// new 이후에 delete로 지워주지않으면 메모리 누수로 crash위험이 있다.

	Player* player = new Player();

	player->_target = m1;

	delete m1;
	delete player;

	// null체크를 꼭 해라
	Player* chkPlayer = FindPlayer(0);
	if (player != nullptr)
	{

	}

	// ?? 1) 크래시 2) 그냥 된다? -> 그냥 실행된다.
	// new delete가 진짜 실시간으로 동작하는게 아님 -> 물리적으로는 남아있음
	// Use-After-Free
	// 예방하는 방법 -> nullptr
	m1 = nullptr;

	// 아래처럼 다른데서 가리킨다면 또 문제가 안날수있음
	player->_target->_hp = 100;
	// m1->_hp = 200;

}