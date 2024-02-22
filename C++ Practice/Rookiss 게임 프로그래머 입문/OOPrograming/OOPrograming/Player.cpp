#include <iostream>
using namespace std;
#include "Player.h"

Player::Player()
{
	m_hp = 0;
	m_attack = 0;
	m_defence = 0;
	cout << "Player()" << endl;
}

Player::Player(const Player& other)
{
	m_hp = other.m_hp;
	m_attack = other.m_attack;
	m_defence = other.m_defence;
	cout << "Player()" << endl;
}

Player::Player(int hp, int attack, int defence)
{
	m_hp = hp;
	m_attack = attack;
	m_defence = defence;
	cout << "Player()" << endl;
}

Player::~Player()
{
	cout << "~Player()" << endl;
}

void Player::Attack()
{
	cout << "Attack : " << m_attack << endl;
}

void Player::Dead()
{
	cout << "Dead" << endl;
}

void Player::HealMe(int value)
{
	m_hp += 10;
}