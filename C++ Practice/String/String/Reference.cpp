#include <iostream>
using namespace std;

struct StatInfo
{
	int hp;
	int att;
	int def;
};

// 1) 값(복사) 전달 방식
void PrintByCopy(StatInfo player)
{
	cout << "===================" << endl;
	cout << "HP : " << player.hp << endl;
	cout << "ATT : " << player.att << endl;
	cout << "DEF : " << player.def << endl;
	cout << "===================" << endl;
}

// 2) 주소 전달 방식
void PrintByPointer(StatInfo* player)
{
	cout << "===================" << endl;
	cout << "HP : " << player->hp << endl;
	cout << "ATT : " << player->att << endl;
	cout << "DEF : " << player->def << endl;
	cout << "===================" << endl;
}

// 3) 참조 전달 방식
# define OUT // 이런 컨벤션도 있다.
// const StatInfo& player로 수정을 막는 방법도있다.
void PrintByRef(OUT StatInfo& player)
{
	cout << "===================" << endl;
	cout << "HP : " << player.hp << endl;
	cout << "ATT : " << player.att << endl;
	cout << "DEF : " << player.def << endl;
	cout << "===================" << endl;
}


int main()
{
	StatInfo player = { 100, 10, 1 };
	PrintByCopy(player);

	// 포인터
	// 1) 원본을 건드리고 싶을때 (원격)
	// 2) 복사 비용 X, null포인터를 사용 가능
	StatInfo* ptr = nullptr;
	PrintByPointer(&player);

	// 참조
	// pointer랑 비슷함
	// 내부에서 건드릴 일이 없을때 복사 비용을 줄이기위해 사용
	// pointer처럼 &player를 입력하는게 아니라서 ref인지 아닌지 모를수있음
	PrintByRef(OUT player);
}