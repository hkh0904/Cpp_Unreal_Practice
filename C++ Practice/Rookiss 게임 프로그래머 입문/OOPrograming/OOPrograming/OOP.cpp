#include <iostream>
using namespace std;
#include "Player.h"

// ��ü���� (Object Oriented Programming)
// ������ + ����

int main()
{
	// ��ü (instance)
	Player k1;
	Player k2(200, 20, 4);

	// ���� ������
	Player k3(k2);

	k1.m_hp = 100;
	k1.m_attack = 10;
	k1.m_defence = 10;

	k1.Attack();
	k2.Attack();
	k3.Attack();

}