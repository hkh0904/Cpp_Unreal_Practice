#include <iostream>
using namespace std;

// NULL ũ���� -> ���� ����� ����(95%)
// ���� �����÷ο�(����÷ο�) -> (0.0001%)
// �޸� �� -> ������ ��Ȳ, ã�⵵ ���� (0.1%)
// �޸� ����
// - �߸��� ĳ���� << 
// - ���� �����÷ο� int arr[100]; -> arr[101] ��� -> �߸��� �ּҰ� ��� 
// - Use-After-Free �����ϰ� �ִ� �ּҰ��� �����Ǿ��µ��� �� �ּҸ� ��� �߸� �ǵ帲

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
	// nullüũ
	if (p == nullptr)
		return;
	p->_hp = 10;
}

int main()
{
	Player* p = FindPlayer(100);
	// 100 id �÷��̾ ��ã�Ƽ� nullptr�� ����	
	// p->_hp = 100;
	Test(nullptr);


	// ���� �����÷ο�(����÷ο�)
	short hp = 30000;

	while (true)
	{
		// short�� ���� �ʰ� -> �÷��̾ ���� �޾Ҵµ� �׾����
		hp += 100;
	}

}