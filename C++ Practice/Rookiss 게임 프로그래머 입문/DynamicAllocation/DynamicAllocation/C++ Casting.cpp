#include <iostream>
using namespace std;

// ĳ���� 4�ѻ�
// static_cast  << �߿�
// dynamic_cast  << �߿�
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
	// static_cast : Ÿ�� ��Ģ�� ���纼 �� ������� ĳ���ø� ������ش�
	// 1) int <-> float
	// 2) Player* -> Knight*

	int hp = 100;
	int maxHp = 200;
	float ratio = static_cast<float>(hp) / maxHp;

	Knight* k = new Knight();
	Player* p = k;
	Knight* k2 = static_cast<Knight*>(p);

	// dynamic_cast : ��� ���迡���� ���� ��ȯ
	// �������� Ȱ���ϴ� ��� (virtual)
	// RTTI (RunTime Type Information)
	Archer* a = new Archer();
	Player* p = a;
	Knight* k3 = dynamic_cast<Knight*>(p);	// C# as
	if (k2 != nullptr)
	{
		// ��� �¾ҳ�?
	}

	// const_cast -> ����� ���� ��ǻ� ����.
	const char* name = "Rookiss";
	char* name2 = const_cast<char*>(name);

	// reinterpret_cast
	// �����ϰ�, ������ ����
	// re-interpret �ٽ� �����ϴ�? �ٽ� �����ϴ�?
	// ������ -> ���� ������� �ٸ� �����ͷ� ��ȯ
	Dog* dog = reinterpret_cast<Dog*>(k);
	 

}