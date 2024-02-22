#pragma once

// ���赵 (�÷��̾�, ����, GameRoom, Lobby, etc....)
class Player
{
public:
	// ������(constructor)
	// ����ڰ� �������� ������ �⺻ �����ڰ� ������
	// ����ڰ� �����ڸ� �ϳ��� �����ϸ� �⺻ �����ڰ� �������� ����
	Player();

	//���� ������
	Player(const Player& other);

	// ��Ÿ ������
	Player(int hp, int attack, int defence);
	// �Ҹ���(destructor)
	~Player();

	// ��� �Լ�
	void Attack();
	void Dead();
	void HealMe(int value);

public:
	// ��� ���� (_hp, m_hp, mHp ���� �����ǿ� ���缭)
	int m_hp;
	int m_attack;
	int m_defence;
};