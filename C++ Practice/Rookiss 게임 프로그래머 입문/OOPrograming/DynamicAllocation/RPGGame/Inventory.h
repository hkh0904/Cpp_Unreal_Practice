#pragma once
#include "Item.h"

enum
{
	MAX_SLOT = 100
};

class Inventory
{
public:
	Inventory();
	~Inventory();

	bool AddItem(Item* item);
	// 슬롯번호? 아이템 포인터? 뭘받아 제거할지 고려
	bool RemoveItem(Item* item);
	Item* GetItemAtSlot(int slot);

	// 메모리 정리
	void Clear();

	static Inventory* GetInstance();

private:
	int FindEmptySlot();
	int FindItemSlot(Item* item);

private:
	// Item _items[MAX_SLOT]과는 차이가 크다
	Item* _items[MAX_SLOT];
	int _itemCount = 0;

	static Inventory* s_instance;
};

