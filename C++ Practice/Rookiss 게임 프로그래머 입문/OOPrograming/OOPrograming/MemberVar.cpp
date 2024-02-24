#include <iostream>
using namespace std;

class Player
{
public:
	Player()
	{
		cout << "Player()" << endl;
	}
	~Player()
	{
		cout << "~Player()" << endl;
	}
};

class Inventory
{
public:
	Inventory()
	{
		cout << "Inventory()" << endl;
	}
	~Inventory()
	{
		cout << "~Inventory()" << endl;
	}

public:
	int m_a = 0;
};

class Knight : public Player
{
public:
	Knight() : m_hp(0), m_inventory()
	/*
	  선처리 영역
	  Player()
	  m_Inventroy = Inventory()
	*/
	{
		cout << "Knight()" << endl;
	}
	~Knight()
	{
		cout << "~Knight()" << endl;
	}

public:
	int m_hp;
	Inventory m_inventory;
};


int main()
{
	// C# Knight k1 = new Knight();
	// C++ Knight* k1 = new Knight();

	Knight k1;
}