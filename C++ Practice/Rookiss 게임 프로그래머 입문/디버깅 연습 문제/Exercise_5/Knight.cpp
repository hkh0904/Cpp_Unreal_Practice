#include "Knight.h"
#include <iostream>
using namespace std;

// [사양서] 기본값 Hp=100, Attack=10
Knight::Knight() : _hp(100), _maxHp(100), _attack(10)
{

}

Knight::Knight(int hp) : _hp(hp), _maxHp(hp), _attack(10)
{

}

Knight::~Knight()
{

}

void Knight::AddHp(int value)
{
	_hp += value;
	if (_hp < 0)
		_hp = 0;
	if (_hp > _maxHp)
		_hp = _maxHp;
}

bool Knight::IsDead()
{
	return (_hp <= 0);
}

int Knight::GetAttackDamage()
{
	// hp가 0이하라면(이미 죽었다면) 바로 return하는 조건 추가
	if (_hp <= 0)
		return 0;
	// hp 50% 이하 => maxHp / hp가 2 이상
	int damage = _attack;

	//int ratio = _maxHp / _hp;
	//// 50% 이하가 되려면 일단 >=이 맞다
	//if (ratio >= 2)
	//	damage *= 2;

	// _hp는 0이될수 있으니까 퍼센트로 계산
	int percentage = _hp / _maxHp * 100;
	if (percentage <= 50)
		damage *= 2;

	return damage;
}

void Knight::PrintInfo()
{
	cout << "HP: " << _hp << endl;
	cout << "ATT: " << _attack << endl;
}