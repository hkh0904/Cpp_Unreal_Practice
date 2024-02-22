#include <iostream>
using namespace std;

// ���м� Data hiding (ĸ��ȭ encapsulation)

// �ڵ���
// - �ڵ�/���/����/��/���⼱/�ֹ���
// ������ ���忡�� ��� : �ڵ�/���/��
// ���� �Ǵ� ��� : ����/���⼱/�ֹ���

// ���� ������
// public(������), private(������->������ �Լ� ���ο����� ��밡��), protected(��ȣ�޴�->��ӹ��� �ڼյ� ��밡��)

class Car
{
public:
	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}
	void TurnKey()
	{
		// ...
		PutFuellneEngin();
		// ...
	}

protected:
	void Disassemble() {}	// ���� ���ؽ�Ų��(?)
	void PutFuellneEngin() {}
	void ConnectCircuit() {}

public:
	// �ڵ�
	// ���
	// ����
	// ��
	// ���⼱
};

// ��� ���� ������ : ���� �������� �θ���� ������ ��� ��������?
// public : ������ ��� -> �״�� �����ش� (��κ��� public�� ���)
// protected : ��ȣ�޴� ���? �� �ڼյ鿡�Ը� �����ش�. (public -> protected�� ������)
// private : �������� �ܺ��� (���Ŀ� ������ �� public, protected -> private�� ������)
class SuperCar : public Car
{
public:
	void Test()
	{
		MoveHandle();
		// protected�� �����߱� ������ ��ӹ��� �ڽĵ� ��밡��
		Disassemble();
	}
};

class Knight
{
public:
	void SetHp(int hp)
	// 1. �̷��� hp�� �ǵ帮�� �κ��� �Լ��� �����θ� braek�� �ɾ� ��� hp�� �ǵ帮���� ���� ã�� �� ����
	{
		m_hp = hp;
		// 2. hp�� �����Ƿ��� �ش� �Լ��� ������ ���ľ��ϹǷ� hp�� ������ ������Ǿ�� �ϴ� ���۵��� �� ����� �� ����
		if (m_hp <= 50)
		{
			// TODO
		}
	}

	int GetHp()
	{
		return m_hp;
	}

private:
	int m_hp = 100;
};

int main()
{
	Car Car1;

	Knight k1;
	// �̷��� �ܺο��� �ƹ��� ��ġ�°� ������ �� ���ɼ��� ũ��
	// k1.m_hp = 200;

	k1.SetHp(100);
}