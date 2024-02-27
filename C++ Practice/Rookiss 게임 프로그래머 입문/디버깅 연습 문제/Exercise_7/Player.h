#pragma once



class Player
{
public:
	Player();
	Player(int hp);

	// �θ� Ŭ������ �Ҹ��ڿ� virtual�ʿ�
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

