#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <unordered_map>

// 살을 내주고 뼈를 취한다
// 메모리를 팔아서 (CPU)성능을 얻겠다!

// 1~999
// [1][2][3][4]...[999]

// 키를 알면 빠르게 찾을 수 있다 0(1)

// Hash 기법
// 보안
// id : rookiss / pw : 1234@ -> hash값으로 변환해 저장 (단방향 변환)
// hash값에서 -> pw로는 변환 불가


int main()
{
	// hash_map
	// 데이터 서칭시 시간복잡도 0(1)
	unordered_map<int, int> um;
	
	//추가, 찾기, 삭제, 순회 -> map이랑 유사함

	um.insert(make_pair(10, 100));

	um[20] = 200;

	auto findIt = um.find(10);
	if (findIt != um.end())
	{
		cout << "찾음" << endl;
	}
	else
	{
		cout << "없음" << endl;
	}

	um.erase(10);
	// um.erase(findIt);

	for (auto it = um.begin(); it != um.end(); it++)
	{
		int key = it->first;
		int value = it->second;
	}

}