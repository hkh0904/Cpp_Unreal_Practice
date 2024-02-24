#include <iostream>
using namespace std;

// 객체지향 (Object Oriented Programming)
// 데이터 + 로직

// OOP 3대 요소
// - 상속성
// - 은닉성
// - 다형성

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


// Is-A vs Has-A 를 고려해 상속을 사용
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
	
	// 포인터를 사용하면 Player로 간주를 하겠다
	Player* p1 = &k1;
	Knight* p2 = (Knight*)p1;

	Player* p2 = &m1;
	
	Fight(&k1, &m1);

}