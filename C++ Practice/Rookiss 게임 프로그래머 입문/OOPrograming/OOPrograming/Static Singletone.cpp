#include <iostream>
using namespace std;

// struct vs class
// ���� ��������� ���������� ������ ���� �� �⺻������
// struct�� public / class�� private��

// static
class marine
{
public:
	// Ư�� ���� ��ü�� ����
	void takedamage(int damage)
	{
		hp -= damage;
	}

	// Ư�� ���� ��ü�� ����
	static void setattack(int value)
	{
		// hp = 40;
		attack = value;
	}

public:
	// static���� �����ϸ� ��� ������ ��ü�� �ϳ��� �����͸� �ٶ󺸰� �ִ� ��
	// 100������ �����̾ 4byte �ϳ��� ������ �������� ��� ����

	// Ư�� ���� ��ü�� ����
	int hp;
	// Ư�� ���� ��ü�� �����ϴ�.
	static int attack;
};
 int marine::attack = 6;


 // static Ȱ��
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


// ������ ����
// - �̱���, ������, ������Ʈ, ...

// �̱��� Ȱ�� ���� : ���� �� 1���� �����ϰ� ��𼭵� ����� �� �ִ� [�Ŵ���] Ŭ����
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