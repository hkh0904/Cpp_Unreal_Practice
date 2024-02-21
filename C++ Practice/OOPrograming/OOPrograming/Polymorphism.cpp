#include <iostream>
using namespace std;

// ������ << polymorphism (poly + morphism)

// �����ε�(overloading) = �Լ� �̸��� ����
// �������̵�(overriding) = �θ� Ŭ������ �Լ��� �ڽ� Ŭ�������� ������

// �߻� Ŭ����
class Player
{
public:
	// ���� �Լ� -> ���� �Լ� ���̺��� ������ (vftable -> virtual function table)
	// .vftable [ �ּ�1 | �ּ�2 | �ּ�3 ]
	virtual void Move() { cout << "Player Move()" << endl; }

	virtual void OnDead() = 0;	// ���� ���� �Լ� (��ӹ��� �Լ����� �����ؾ���)
	// virtual void OnDead() abstract;

public:
	int m_hp;
};

class Knight : public Player
{
public:
	// �����Լ������� ����� ������ ���� �˷��ִ� ����
	virtual void Move() override { cout << "Knight Move()" << endl; }
	// ���� �����Լ��� ���������� ������ ���� �߻�
	virtual void OnDead() override { cout << "Dead()" << endl; }
};

// ���ε�(Binding) = ���´�
// - ���� ���ε� (static binding = ������ ���� ����)
// - ���� ���ε� (dynamic binding = ���� ���� ����
void MovePlayer(Player* player)
{
	player->Move();
	player->OnDead();
}

int main()
{
	Knight k1;
	MovePlayer(&k1);
}