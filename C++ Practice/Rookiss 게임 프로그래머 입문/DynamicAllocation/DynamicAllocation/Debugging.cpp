#include <iostream>
using namespace std;

// NULL 크래시 -> 가장 빈번한 오류(95%)
// 정수 오버플로우(언더플로우) -> (0.0001%)
// 메모리 릭 -> 감사한 상황, 찾기도 쉽다 (0.1%)
// 메모리 오염
// - 잘못된 캐스팅 << 
// - 버퍼 오버플로우 int arr[100]; -> arr[101] 사용 -> 잘못된 주소값 사용 
// - Use-After-Free 참조하고 있는 주소값이 삭제되었는데도 그 주소를 계속 잘못 건드림

class Player
{
public:
	int _hp = 0; 
};

Player* FindPlayer(int id)
{
	// TODE
	return nullptr;
}

void Test(Player* p)
{
	// null체크
	if (p == nullptr)
		return;
	p->_hp = 10;
}

int main()
{
	Player* p = FindPlayer(100);
	// 100 id 플레이어를 못찾아서 nullptr인 상태	
	// p->_hp = 100;
	Test(nullptr);


	// 정수 오버플로우(언더플로우)
	short hp = 30000;

	while (true)
	{
		// short의 범위 초과 -> 플레이어가 힐을 받았는데 죽어버림
		hp += 100;
	}

}