#pragma once

// 설계도 (플레이어, 몬스터, GameRoom, Lobby, etc....)
class Player
{
public:
	// 생성자(constructor)
	// 사용자가 정의하지 않으면 기본 생성자가 생성됨
	// 사용자가 생성자를 하나라도 정의하면 기본 생성자가 생성되지 않음
	Player();

	//복사 생성자
	Player(const Player& other);

	// 기타 생성자
	Player(int hp, int attack, int defence);
	// 소멸자(destructor)
	~Player();

	// 멤버 함수
	void Attack();
	void Dead();
	void HealMe(int value);

public:
	// 멤버 변수 (_hp, m_hp, mHp 팀의 컨벤션에 맞춰서)
	int m_hp;
	int m_attack;
	int m_defence;
};