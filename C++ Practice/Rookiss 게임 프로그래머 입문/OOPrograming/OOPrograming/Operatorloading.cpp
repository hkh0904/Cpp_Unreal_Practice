#include <iostream>
using namespace std;

// ������ �����ε�

// ��� ������ �Լ� ����
// - a op b ���¿��� ������ �������� ����
 
// ���� ������ �Լ� ����
// - a op b ���¶��, a/b ��θ� ������ �Լ��� �ǿ����ڷ� ���

class Pos
{
public:
	Pos operator+(const Pos& b)
	{
		Pos pos;
		pos.x = x + b.x;
		pos.y = y + b.y;
		return pos;
	}

	Pos operator+(int b)
	{
		Pos pos;
		pos.x = x + b;
		pos.y = y + b;
		return pos;
	}

	bool operator==(const Pos& b)
	{
		return x == b.x && y == b.y;
	}

	// ���� ������
	Pos& operator=(int b)
	{
		x = b;
		y = b;
		return *this;
	}

public:
	int x = 0;
	int y = 0;
};

Pos operator+(int a, const Pos& b)
{
	Pos pos;
	pos.x = a + b.x;
	pos.y = a + b.y;
	return pos;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = a + b;

	Pos pos1;
	Pos pos2;

	Pos pos3 = pos1 + pos2;
	Pos pos4 = 10 + pos1;

	// ����� ���ÿ� ���� �����ϴ� ���� ������ �ڵ带 ���� �̷����
	// ���� �����ڸ� ����ϴ� ���� �ƴ�   ex) Pos pos5 = 10;
	// �̰��� �������� ������ �Լ� �տ� explicit�� �ٿ��־� ���� ���� ex) explicit Pos(int a) { }
	// ���� �����ڸ� ����Ϸ��� ������ �� �ٽ� ���Կ����ڸ� ������־����
	// �� ��쿡�� ���Կ����ڸ� �������� �ʾҴٸ� ������ �ڵ�� �� �� ������ ����
	// ex) Pos pos5;	pos5 = 10;


}