#include <iostream>
using namespace std;

// MMO RPG ���� 1��, ���� 50��

// - ���� ����
// - �޸� ����

// ���� �Ҵ� : �ǽð����� ��û�� �ؼ� �޸𸮸� �Ҵ�޾� ����Ѵ�.

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
	// �Ʒ��� ���� ������ ����� �� �ִ� ���ø޸� �ʰ�
	// Monster monsters[100 * 10000];

	// C���� ����ϴ� ���
	// malloc() �� ���� �޸� ��û + free �� �޸� ��ȯ -> ������ �Ҹ��ڸ� ȣ������ ����
	/*void* ptr = malloc(1000);

	Monster* m = (Monster*)ptr;
	m->_hp = 100;

	free(ptr);*/

	// C++���� ���Ǵ� ���
	// new + delete 

	Monster* m1 = new Monster();
	m1->_hp = 100;
	// new ���Ŀ� delete�� �������������� �޸� ������ crash������ �ִ�.

	Player* player = new Player();

	player->_target = m1;

	delete m1;
	delete player;

	// nullüũ�� �� �ض�
	Player* chkPlayer = FindPlayer(0);
	if (player != nullptr)
	{

	}

	// ?? 1) ũ���� 2) �׳� �ȴ�? -> �׳� ����ȴ�.
	// new delete�� ��¥ �ǽð����� �����ϴ°� �ƴ� -> ���������δ� ��������
	// Use-After-Free
	// �����ϴ� ��� -> nullptr
	m1 = nullptr;

	// �Ʒ�ó�� �ٸ����� ����Ų�ٸ� �� ������ �ȳ�������
	player->_target->_hp = 100;
	// m1->_hp = 200;

}