#pragma once



class Player
{
public:
	Player();
	Player(int hp);

	// 부모 클래스는 소멸자에 virtual필요
	virtual ~Player();

	void PrintInfo();

	void AddHp(int value);
	bool IsDead();

	int GetAttackDamage();

	void OnDamaged(Player* attacker);

public:

	int _hp;
	int _maxHp;
	int _attack;
};

