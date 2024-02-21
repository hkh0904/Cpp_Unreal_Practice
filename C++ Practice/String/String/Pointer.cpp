#include <iostream>
using namespace std;

struct StatInfo
{
	int hp;
	int att;
	int def;
};

// 스택메모리에서 복사한후 리턴해서 사용하기때문에
// 문제는 없지만 메모리손해가 있을 수 있는 방법
StatInfo CreatePlayer()
{
	StatInfo info;

	cout << "플레이어 생성" << endl;

	info.hp = 100;
	info.att = 10;
	info.def = 2;

	return info;

}

// 포인터의 위치로 가서 원본데이터에 직접 접촉하기 때문에 메모리 손해가 없음
// 포인터를 사용해 원본을 수정하는 만큼 주의가 필요함
void CreateMonster(StatInfo* info)
{
	cout << "몬스터 생성" << endl;

	// (*info).hp == info->hp 둘이 완전히 동일함
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

		cout << "몬스터 HP : " << monster->hp << endl;

		if (monster->hp == 0)
			return;

		damage = monster->att - player->def;
		if (damage < 0)
			damage = 0;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		cout << "플레이어 HP : " << player->hp << endl;

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