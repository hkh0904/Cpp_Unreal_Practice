#pragma once
#include "Enums.h"

// Item
// - Weapon
// - Armor
// - Consumable

// **********************
//			Item
// **********************

class Item
{
protected:
	// Item();		// 기본 생성자
	Item(ItemType itemType);
public:
	// 부모클래스의 소멸자에 virtual 꼭 붙여야한다.
	// 붙이지 않으면 무슨일이 일어날까? - 메모리 누수가 일어날 수 있다
	virtual ~Item();

public:
	virtual void PrintInfo();
	ItemType GetItemType() { return _itemType; }

protected:
	int _itemId = 0;
	int _itemCount = 0;
	ItemRarity _rarity = IR_Normal;
	ItemType _itemType = IT_None;
};

// **********************
//		    Weapon
// **********************

class Weapon : public Item
{
public:
	Weapon();
	virtual ~Weapon();

	virtual void PrintInfo() override;


	void SetDamage(int damage) { _damage = damage; }
	int GetDamage() { return _damage; }

private:
	int _damage = 0;
};

// **********************
//		    Armor
// **********************

class Armor : public Item
{
public:
	Armor();
	virtual ~Armor();

	virtual void PrintInfo() override;

	void SetDefence(int defence) { _defence = defence; }
	int GetDefence() { return _defence; }

private:
	int _defence = 0;
};
