#include <iostream>
using namespace std;


class Knight
{};

int main()
{
	// C++03
	// C++11 (Modern C++) -> auto, lamda

	// auto
	// - 장점 : 타이핑이 빠름 ex) vector<int>::iterator it = v.begin();  ->  auto it = v.begin();
	// - 단점 : 가독성(다 auto면 봤을때 알기 힘듬)


	{
		int a = 3;
		float b = 3.14f;
		double c = 1.23;
		Knight* d = new Knight;
		const char* e = "Rookiss";
	}

	{
		auto a = 3;
		auto b = 3.14f;
		auto c = 1.23;
		auto d = new Knight;
		auto e = "Rookiss";

		// auto는 일종의 조커카드
		// 형식 영역 (type deduction)
		// -> 말이 되게 잘 맞춤 (추론)

		int& ref = a;
		const int cst = a;

		// 주의! auto는 const,  &는 떼고 추론한다.
		auto& ref2 = ref;
		const auto cst2 = cst;
	}
	
}