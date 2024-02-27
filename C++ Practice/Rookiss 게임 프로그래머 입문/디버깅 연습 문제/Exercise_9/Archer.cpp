#include "Archer.h"
#include "Pet.h"

Archer::Archer(Pet* pet) : _pet(pet)
{
	
}

Archer::Archer(int hp) : Player(hp)
{
}

Archer::~Archer()
{
	// 즐거웠다 내 펫 :(
	if (_pet != nullptr)
		delete _pet;
}

void Archer::AddHp(int value)
{
	Player::AddHp(value);

	// 죽었으면 펫도 날린다
	if (IsDead())
	{
		delete _pet;
		// 삭제하면 nullptr로 초기화해주는 습관들이기
		_pet = nullptr;
	}
}
