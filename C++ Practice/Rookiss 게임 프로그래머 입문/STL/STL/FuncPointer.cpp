#include <iostream>
using namespace std;


void Print()
{
	cout << "Hello World" << endl;
}

int Add(int a, int b)
{
	return a + b;
}

// 콜백 함수
// ex) UI를 눌렀을 때 어떤 함수가 실행되게끔
// ex) 클라에 입장했을때 서버에서 어떤 행동을 하도록 (온라인게임)
// ex) 특정키를 누르면 무엇인가 일어나야한다

// '행동' 자체를 인자로 넘기고 싶을 때
using FuncPtr = int(*)(int a, int b);

int DoSometing(int a, int b, FuncPtr func)
{
	return func(a, b);
}

//===============================================

class Item
{
public:

public:
	int _itemId = 0;
	int _rarity = 0;
	int _ownerId = 0;
};

using ItemSelectorType = bool(*)(Item* item);

Item* FindItem(Item items[], int itemCount, ItemSelectorType selector)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		if (selector(item))
			return item;
	}
	return nullptr;
}

bool IsRare(Item* item)
{
	return item->_rarity == 1;
}


// 멤버함수의 포인터
class Test
{
public:
	void PrintTest() {}
};

// 함수 포인터 -> 함수의 실행 시기를 늦출수 있다.(서버에서 사용)
// 클라 -> 나 10번 유저 공격할래
// 클라2 -> 나 10, 20 좌표로 이동할래
// .......................

int main()
{
	using DataType = int;


	// void(*FuncPtrType)();
	using FuncPtrType = void(*)();

	FuncPtrType ptr = &Print;

	DoSometing(10, 20, &Add);
	DoSometing(10, 20, [](int a, int b) {return a - b; });

	Item items[10];
	items[3]._rarity = 1;	// Rare

	FindItem(items, 10, IsRare);

	// 멤버함수 포인터
	using MemFuncPtrType = void(Test::*)();

	MemFuncPtrType funcPtr = &Test::PrintTest;

	Test t;
	(t.*funcPtr)();

	Test* t2 = &t;
	(t2->*funcPtr)();

}