#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

enum class ItemType
{
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable
};

enum class Rarity
{
	Common,
	Rare,
	Unique
};

class Item
{
public:
	Item() { }
	Item(int itemId, Rarity rarity, ItemType type) : _itemId(itemId), _rarity(rarity), _type(type) { }

public:
	int _itemId = 0;
	Rarity _rarity = Rarity::Common;
	ItemType _type = ItemType::None;
};

class Knight
{
public:
	auto MakeResetHpJob()
	{
		auto job = [=]()
		{
			_hp = 200;
		};

		return job;
	}

public:
	int _hp = 100;
};


int main()
{
	vector<Item> v;
	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
	v.push_back(Item(2, Rarity::Common, ItemType::Armor));
	v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));

	{
		struct IsWantedItem
		{

		};

		// lambda
		// [](){}
		auto isUniqueLambda = [](Item& item) {return item._rarity == Rarity::Unique; };

		std::find_if(v.begin(), v.end(), isUniqueLambda);
		// std::find_if(v.begin(), v.end(), [](Item& item) {return item._rarity == Rarity::Unique; });

		int wantedId = 2;
		// 기본 캡쳐모드
		// = 복사, & 참조

		// 단일 변수마다 캡처 모드 사용 가능
		std::find_if(v.begin(), v.end(), [&wantedId](Item& item) {return item._itemId == wantedId; });


	}

	Knight* k = new Knight();
	k->_hp = 100;

	auto job = k->MakeResetHpJob();

	delete k;

	job();

}