#include <iostream>
using namespace std;

class Player
{
public:
	Player()
	{
		cout << "Player()" << endl;
	}
	virtual ~Player()
	{
		cout << "~Player()" << endl;
	}
};

class Pet { };

class Archer : public Player
{
public:
	Archer()
	{
		_pet = new Pet();
		cout << "Archer()" << endl;
	}

	virtual ~Archer()
	{
		cout << "~Archer()" << endl;
		delete _pet;
	}

private:
	// Pet _pet ���� �����ϸ� archer�� pet�� �޸𸮸� ���� �ٿ��� �ٴѴ�
	Pet* _pet;
};


int main()
{
	// �ڽ� Ŭ������ �θ� Ŭ������ ������ �� -> �ڽ��� �Ҹ��ڰ� ������� ����
	// �����Լ� -> � Ÿ���� �����͸� ����Ű�� �ֵ� ������ ������ Ÿ�Կ� ���� �ش��ϴ� Ÿ���� �Լ��� ȣ��
	// �� �θ�Ŭ������ �Ҹ��ڸ� �����Լ��� �����ؾ� �ڽ��� �Ҹ��ڵ� �� �����ؼ� �޸� ������ ���� �� ���� (�ڽ� Ŭ�������� �Ҹ��ڶ�� virtual ���̴� ����)
	// ���� �ڽ�Ŭ������ �Ҹ��ڿ� �޸𸮸� �����ϴ� �ڵ尡 �����Ǿ��־��ٸ� �޸� ������ ����ؼ� �ȵɼ� �ִ�.
	
	// ������ ȣ��
	// Archer* archer = new Archer();
	Player* archer = new Archer();

	// �Ҹ��� ȣ��
	delete archer;
	archer = nullptr;
}