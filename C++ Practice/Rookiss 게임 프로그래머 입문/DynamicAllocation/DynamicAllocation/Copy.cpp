#include <iostream>
using namespace std;

// ���� ���� vs ���� ����
class Pet
{
public:
	Pet() { cout << "Pet()" << endl; }
	~Pet() { cout << "~Pet()" << endl; }

	Pet(const Pet& pet) { cout << "Pet(const Pet&)" << endl; }
};


class Knight
{
public:
	Knight()
	{
		_pet = new Pet();
	}

	~Knight()
	{
		delete _pet;
	}

	Knight(const Knight& k)
	{
		_hp = k._hp;
		// ���� �����Ҵ��� �ؾ� ���� ����
		_pet = new Pet(*(k._pet));
	}

public:
	int _hp = 100;
	// �����ͷ� ���������� �����ϸ�
	// k1, k2����Ʈ�� ������ ���� �����Եȴ�.
	// �� ����� �ϳ��� �Ҹ��ϴ� ���� �Ҹ��ڿ��� ���� �Ҹ��Ű��?
	// ������ ��簡 �Ҹ��ؼ� ���� �Ҹ��Ϸ������� -> �̹� ���� �Ҹ�Ǿ�����..
		
	// ���� �����͸� ����Ű�� �������� 
	Pet* _pet;
};


int main()
{
	Knight k1;
	k1._hp = 200;

	Knight k2(k1); // == Knight k2 = k1; (���� �������� ����)

	Knight k3;	// �⺻ ������
	k3 = k1		// ���� ������

}