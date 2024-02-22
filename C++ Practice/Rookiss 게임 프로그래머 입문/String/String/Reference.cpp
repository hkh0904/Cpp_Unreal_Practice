#include <iostream>
using namespace std;

struct StatInfo
{
	int hp;
	int att;
	int def;
};

// 1) ��(����) ���� ���
void PrintByCopy(StatInfo player)
{
	cout << "===================" << endl;
	cout << "HP : " << player.hp << endl;
	cout << "ATT : " << player.att << endl;
	cout << "DEF : " << player.def << endl;
	cout << "===================" << endl;
}

// 2) �ּ� ���� ���
void PrintByPointer(StatInfo* player)
{
	cout << "===================" << endl;
	cout << "HP : " << player->hp << endl;
	cout << "ATT : " << player->att << endl;
	cout << "DEF : " << player->def << endl;
	cout << "===================" << endl;
}

// 3) ���� ���� ���
# define OUT // �̷� �����ǵ� �ִ�.
// const StatInfo& player�� ������ ���� ������ִ�.
void PrintByRef(OUT StatInfo& player)
{
	cout << "===================" << endl;
	cout << "HP : " << player.hp << endl;
	cout << "ATT : " << player.att << endl;
	cout << "DEF : " << player.def << endl;
	cout << "===================" << endl;
}


int main()
{
	StatInfo player = { 100, 10, 1 };
	PrintByCopy(player);

	// ������
	// 1) ������ �ǵ帮�� ������ (����)
	// 2) ���� ��� X, null�����͸� ��� ����
	StatInfo* ptr = nullptr;
	PrintByPointer(&player);

	// ����
	// pointer�� �����
	// ���ο��� �ǵ帱 ���� ������ ���� ����� ���̱����� ���
	// pointeró�� &player�� �Է��ϴ°� �ƴ϶� ref���� �ƴ��� �𸦼�����
	PrintByRef(OUT player);
}