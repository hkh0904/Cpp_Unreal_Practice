#include <iostream>
using namespace std;
#include "Item.h"
#include "Inventory.h"

// [시스템] 몬스터를 잡을 때, 아이템을 떨군다
Item* DropItem()
{
    if (rand() % 2 == 0)
    {
        Weapon* weapon = new Weapon();
        return weapon;
    }
    else
    {
        Armor* armor = new Armor();
        return armor;
    }
}


int main()
{
    srand((unsigned)time(0));

    for (int i = 0; i < 100; i++)
    {
        // 몬스터 처치
        Item* item = DropItem();
        item->PrintInfo();

        if (Inventory::GetInstance()->AddItem(item))
        {
            cout << "Added Item to Inventory" << endl;
        }
        else
        {
            cout << "Failed to add Item" << endl;
            delete item;
        }
        //// 무기라면 TODO, 방어구라면 TODO 하려면
        //ItemType itemType = item->GetItemType();
        //if (itemType == IT_Weapon)
        //{
        //    // item 클래스로 취급하던 포인터를 weapon을 가리키도록 설정
        //    Weapon* weapon = (Weapon*)item;
        //    weapon->GetDamage();
        //}
        //else if (itemType == IT_Armor)
        //{
        //    Armor* armor = (Armor*)item;
        //    armor->GetDefence();
        //}
    }

    // PK 당해서 랜덤으로 일부 아이템 드랍
    for (int i = 0; i < 20; i++)
    {
        int randIndex = rand() % MAX_SLOT;
        Item* item = Inventory::GetInstance()->GetItemAtSlot(randIndex);
        if (item && Inventory::GetInstance()->RemoveItem(item))
        {
            cout << "Removed Item" << endl;
        }
    }

}