#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// find	<<
// find_if <<
// count_if <<
// all_of
// any_of
// none_of
// for_each <<
// remove
// remove_if <<

int main()
{
	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		int n = rand() % 100;
		v.push_back(n);
	}

	// Q1) 특정 숫자가 있는지?
	{
		int number = 50;
		//bool found = false;
		// vector<int>::iterator it;
		/*for (auto it = v.begin(); it != v.end(); it++)
		{
			int value = *it;
			if (value == number)
			{
				found = true;
				break;
			}
		}*/
		// 위와 성능적 이슈는X, 가독성이 상승
		auto it = std::find(v.begin(), v.end(), number);
		if (it == v.end())
		{
			cout << "못찾음" << endl;
		}
		else
		{
			cout << "찾음" << endl;
		}
	}

	// Q2) 11로 나뉘는 숫자가 있는지?
	{
		int div = 11;
		vector<int>::iterator it;
		for (it = v.begin(); it != v.end(); it++)
		{
			int value = *it;
			if (value % div == 0)
			{
				break;
			}
		}

		// lamda식을 배우면 더 간결해짐
		struct CanDivBy11
		{
			bool operator()(int n)
			{
				return n % 11 == 0;
			}
		};

		auto it2 = std::find_if(v.begin(), v.end(), CanDivBy11());
	}

	// Q3) 홀수인 숫자 갯수는?
	{
		int count = 0;

		for (auto it = v.begin(); it != v.end(); it++)
		{
			if (*it % 2 != 0)
			{
				count++;
			}
		}

		struct IsOdd
		{
			bool operator()(int n)
			{
				return n % 2 != 0;
			}
		};

		int n = std::count_if(v.begin(), v.end(), IsOdd());

		// 모든 데이터가 홀수입니까?
		bool b1 = std::all_of(v.begin(), v.end(), IsOdd());
		// 홀수인 데이터가 하나라도 있습니까?
		bool b2 = std::any_of(v.begin(), v.end(), IsOdd());
		// 모든 데이터가 홀수가 아닙니까?
		bool b3 = std::none_of(v.begin(), v.end(), IsOdd());
	}

	// Q4) 벡터에 있는 모든 숫자들에 3을 곱해주세요
	{
		for (int i = 0; i < v.size(); i++)
		{
			v[i] *= 3;
		}

		struct MultiplyBy3
		{
			void operator()(int& n)
			{
				n *= 3;
			}
		};

		std::for_each(v.begin(), v.end(), MultiplyBy3());
	}

	// Q5) 홀수인 데이터를 일괄 삭제
	{
		v = { 1, 4, 3, 5, 8, 2 };

		/*for (auto it = v.begin(); it != v.end();)
		{
			if (*it % 2 != 0)
				it = v.erase(it);
			else
				it++;
		}*/

		struct IsOdd
		{
			bool operator()(int n)
			{
				return n % 2 != 0;
			}
		};

		auto it = std::remove_if(v.begin(), v.end(), IsOdd());

		v.erase(it, v.end());
	}
	
}