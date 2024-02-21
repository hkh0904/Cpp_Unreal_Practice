#include <iostream>
using namespace std;

// ��ü���� (Object Oriented Programming)
// ������ + ����

// OOP 3�� ���
// - ��Ӽ�
// - ���м�
// - ������

// GameObject
// - Creature
// -- Player, Monster, Npc, Pet
// - Projectile
// -- Arrow, Fireball
// - Env

// Item
// - Weapon
// -- Sword, Bow, Lance
// - Armor
// -- Helmet, Boots, Armor, Glove
// - Consumable
// -- Potion, Scroll

enum PLAYER_TYPE
{
	PT_KNIHGT = 1,
	PT_ARCHER = 2,
	PT_MAGE = 3,
};


// Is-A vs Has-A �� ����� ����� ���
class Player
{
public:
	void Move() {}
	void Attack() {}
	void Die() {}

public:
	int m_type;
	int m_hp;
	int m_attack;
	int m_defence;
};

class Knight : public Player
{
public:

public:
	// Inventory*
	int  m_stamina; 
};

class Archer : public Player
{
public:

public:
	int m_arrowCount;  
};

class Mage : public Player
{
public:

public:
	int m_mp;
};

void Fight(Player* p1, Player* p2)
{
	p1->m_hp -= p2->m_attack;
}


int main()
{
	Knight k1;
	
	Mage m1;
	
	// �����͸� ����ϸ� Player�� ���ָ� �ϰڴ�
	Player* p1 = &k1;
	Knight* p2 = (Knight*)p1;

	Player* p2 = &m1;
	
	Fight(&k1, &m1);

}