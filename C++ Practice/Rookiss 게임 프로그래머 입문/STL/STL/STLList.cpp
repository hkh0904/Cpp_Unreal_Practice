#include <iostream>
using namespace std;
#include <list>
#include "List.h"

int main()
{
	// size (resize) - 실제 데이터 크기 / capacity 개념은 없음
	// 삽입/삭제
	// 시작 0(1), 끝 0(1), 중간 0(1) << 위치를 기억하고 있을 때
	// push_front 0(1), push_back 0(1), front 0(1), back 0(1)

	list<int> li{ 1,2,3,4,5 };

	li.insert(li.end(), 1);
	li.insert(li.end(), 2);
	list<int>::iterator it = li.insert(li.end(), 3);
	li.insert(li.end(), 4);
	li.insert(li.end(), 5);
	
	// li.insert(it, 100);
	li.erase(it);

	{
		list<int> li{ 1,2,3,4,5 };

		list<int>::iterator it;
		for (it = li.begin(); it != li.end();)
		{
			int value = *it;
			if (value % 2 == 0)
				it = li.erase(it);
			else
				it++;
		}
	}


	{
		// 직접 구현한 iterator
		List<int> li;
		li.AddAtTail(10);
		li.AddAtTail(20);
		li.AddAtTail(30);

		for (List<int>::iterator it = li.begin(); it != li.end(); it++)
		{
			int value = *it;
			cout << value << endl;
		}
	}

}