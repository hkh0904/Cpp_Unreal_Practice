#include <iostream>
using namespace std;

class Player
{
public:

};

class Knight : public Player
{
public:

};

class Dog
{
public:
};



int main()
{
	// C ��Ÿ�� ĳ����

	// �� Ÿ�� ��ȯ
	// Ư¡) �ǹ̸� �����ϱ� ���ؼ� ���� ��ü�� �ٸ� ��Ʈ�� �籸��
	{
		int a = 123456789;
		float b = (float)a;
		int c = 0;
	}
	// ���� Ÿ�� ��ȯ
	{
		int a = 123456789;
		float b = (float&)a;
		int c = 0;
	}
	// ������ ��ȯ (�ǹ̰� 100% ��ġ)
	{
		int a = 123456789;
		__int64 b = (__int64)a;
		int c = 0;
	}
	// �Ͻ���
	{
		int a = 123456789;
		float b = a;
		int c = 0;
	}

	Knight* k = new Knight;

	Dog* dog = (Dog*)k;

}