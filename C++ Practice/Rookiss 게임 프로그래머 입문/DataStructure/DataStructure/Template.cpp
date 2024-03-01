#include <iostream>
using namespace std;

// 함수 템플릿 > 특수화
// 템플릿은 구현부까지 전부 헤더에 만들자

// 조커카드 1개
template<typename T>
void Print(T a)
{
	cout << a << endl;
}

// 특정 타입에서는 다르게 동작하도록 만들 수 있다.
template<>
void Print(int a)
{
	cout << "int" << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}


// 클래스 템플릿
template<typename T>
class RandomBox
{
public:
	T GetRandomData()
	{
		int index = rand() % 100;
		return data[index];
	}
public:
	T data[100];
};

template<>
class RandomBox<int>
{
public:
	int GetRandomData()
	{
		int index = rand() % 100;
		return data[index];
	}
public:
	int data[100];
};



int main()
{
	Print(1);
	Print(3.14f, "check");
	Print("Hello Template");

	RandomBox<int> rb1;
	rb1.GetRandomData();
	RandomBox<float> rb2;
}