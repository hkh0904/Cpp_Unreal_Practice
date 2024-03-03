#include <iostream>
using namespace std;
#include <vector>


int main()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	// size (resize) - 실제 데이터 크기
	// capacity (reserve) - 실제 할당된 공간
	// 삽입/삭제
	// 시작 0(N), 중간 0(N), 끝 0(1)
	// push_back, front, back
	// v.remove(10)?

	v.reserve(10);

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	int a = v.front();	// 0(1)
	int b = v.back();	// 0(1)

	// 임의 접근 v[i]	0(1)
	v[2] = 100;
	// v.push_front() 느려서 STL에서 구현하지않음


	// 추가, 삭제, 순회, 검색

	const int size = v.size();
	for (int i = 0; i < size; i++)
	{
		// 순회
	}

	// 초기화
	vector<int> v1(5);
	vector<int> v2(5, -1);
	vector<int> v3{ 1, 2, 3, 4, 5 };

	vector<int> v4 = v3;
	v4[0] = 100;		// 원본도 바뀔까? x 복사된 v4만 바뀜

	v3.clear();		// size? capacity?
	cout << v3.size() << endl;		// 0
	cout << v3.capacity() << endl;	// 5 -> size(데이터)만 초기화 capacity(할당된 크기)는 유지됨

	// iterator ? 반복자 포인터?
	{
		vector<int> v{ 1, 2, 3, 4, 5 };

		int* ptr = &v[0];
		int* ptrEnd = &v[4] + 1;
		
		while (ptr != ptrEnd)
		{
			cout << *ptr << endl;
			ptr++;
		}
	}

	{
		vector<int> v{ 1, 2, 3, 4, 5 };

		vector<int>::iterator it;

		// 순회
		for (it = v.begin(); it != v.end(); it++)
		{
			int data = *it;
			if (data == 3)
			{
				// 찾음
				break;
			}
			cout << data << endl;
		}

		if (it != v.end())
		{
			cout << "찾음" << endl;
			v.erase(it);
		}
	}

	{
		vector<int> v{ 1, 2, 3, 4, 5 };

		vector<int>::iterator it;

		// 순회하면서 삭제
		for (it = v.begin(); it != v.end(); it++)
		{
			int value = *it;

			if (value % 2 == 0)
				it = v.erase(it);
			else
				it++;
		}
	}

}