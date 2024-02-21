#include <iostream>
using namespace std;
#include "Player.h"

// 객체지향 (Object Oriented Programming)
// 데이터 + 로직

int main()
{
	// 객체 (instance)
	Player k1;
	Player k2(200, 20, 4);

	// 복사 생성자
	Player k3(k2);

	k1.m_hp = 100;
	k1.m_attack = 10;
	k1.m_defence = 10;

	k1.Attack();
	k2.Attack();
	k3.Attack();

}