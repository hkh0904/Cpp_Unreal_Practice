#include <iostream>
// #include "List.h"
#include "Array.h"
#include "Vector.h"

int main()
{
	// 동적배열(배열) vs 연결리스트
	// 대부분은 동적배열 사용 -> 빠름
	// 연결리스트를 활용하는 경우

	// [					zone					]
	// 대기열인데 중간의 누군가가 빠질 수 있어야할때
	// [일감][일감][일감]<->[일감]<->[일감][일감][일감]

	Vector v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	int a = v[1];
}