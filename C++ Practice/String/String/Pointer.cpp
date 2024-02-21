#include <iostream>
using namespace std;

struct StatInfo
{
	int hp;
	int att;
	int def;
};

// ���ø޸𸮿��� �������� �����ؼ� ����ϱ⶧����
// ������ ������ �޸𸮼��ذ� ���� �� �ִ� ���
StatInfo CreatePlayer()
{
	StatInfo info;

	cout << "�÷��̾� ����" << endl;

	info.hp = 100;
	info.att = 10;
	info.def = 2;

	return info;

}

// �������� ��ġ�� ���� ���������Ϳ� ���� �����ϱ� ������ �޸� ���ذ� ����
// �����͸� ����� ������ �����ϴ� ��ŭ ���ǰ� �ʿ���
void CreateMonster(StatInfo* info)
{
	cout << "���� ����" << endl;

	// (*info).hp == info->hp ���� ������ ������
	(*info).hp = 40;
	info->att = 8;
	info->def = 1;
}

void Battle(StatInfo* player, StatInfo* monster)
{
	while (true)
	{
		int damage = player->att - monster->def;
		if (damage < 0)
			damage = 0;

		monster->hp -= damage;
		if (monster->hp < 0)
			monster->hp = 0;

		cout << "���� HP : " << monster->hp << endl;

		if (monster->hp == 0)
			return;

		damage = monster->att - player->def;
		if (damage < 0)
			damage = 0;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		cout << "�÷��̾� HP : " << player->hp << endl;

		if (player->hp == 0)
			return;
	}
}


int main()
{
	StatInfo player;
	player = CreatePlayer();

	StatInfo monster;
	CreateMonster(&monster);

	Battle(&player, &monster);
}