#include <iostream>
using namespace std;

// Vector/List -> Tree -> Graph -> BFS -> Dijikstra -> A* (PQ)

void Func(int a)
{
	if (a == 0)
		return;

	cout << a << endl;
	Func(a - 1);
}

int Factorial(int n)
{
	if (n <= 1)
		return 1;

	return n * Factorial(n - 1);
}

// 유클리드 알고리즘
// a > b
// GCD(1071, 1029)
// = GCD(1029, 1071%1029 = 42)
// = GCD(42, 1029%42 = 21)
// = GCD(21, 0) = 21
int Gcd(int a, int b)
{
	if (b == 0)
		return a;

	return Gcd(b, a % b);
}


int main()
{
	Func(5);
	cout << Gcd(1071, 1029) << endl;
}