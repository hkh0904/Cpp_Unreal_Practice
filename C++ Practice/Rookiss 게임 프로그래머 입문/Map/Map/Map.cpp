#include <iostream>
using namespace std;
#include <vector>
#include <map>

class Player
{
public:
	Player() : _id(0) {}
	Player(int id) : _id(id) {}

	int _id = 0;
};

template<typename T, typename U>
struct Pair
{
	T first;
	U second;
};

template<typename T, typename U>
auto MakePair(T first, U second)
{
	return std::pair<T, U>(first, second);
}


int main()
{
	vector<Player*> v;
	v.push_back(new Player(100));
	v.push_back(new Player(200));
	v.push_back(new Player(300));
	v.push_back(new Player(400));
	v.push_back(new Player(500));

	// C++ vector = C# List
	// C++ hash_map = C# Dictionary

	// (key, value)
	map<int, Player*> m;

	// 추가
	// 찾기
	// 삭제
	// 순회?

	Pair<int, Player*> p;
	/*int key = pair.first;
	Player* value = pair.second;*/

	// std::pair<int, Player*> p;

	for (Player* player : v)
	{
		MakePair(player->_id, player);

		// m.insert(pair<int, Player*>(key, data));
		m.insert(make_pair(player->_id, player));
	}

	auto it = m.find(300);	// 0(logN)
	auto whoami = *it;

	if (it != m.end())
	{
		int key = it->first;
		Player* value = it->second;
		cout << "찾음" << endl;
	}
	else
	{
		cout << "없음" << endl;
	}

	m.erase(it);		// 찾아서 삭제
	m.erase(200);		// key값으로 삭제

	// 순회? 큰 이점은 없다. 벡터가 좀더 좋음
	for (auto it = m.begin(); it != m.end(); it++)
	{
		int key = it->first;
		Player* p = it->second;
	}

	// 없는 키값을 넣어버리면?
	// C++ STL vs UE TMap
	// C++ STL -> 갖고 오되, 없으면 기본값으로 추가
	// UE -> 크래쉬
	Player* p = m[100];

}