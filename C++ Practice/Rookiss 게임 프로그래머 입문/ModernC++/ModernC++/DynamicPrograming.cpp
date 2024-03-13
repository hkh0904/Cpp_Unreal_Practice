#include <iostream>
using namespace std;
#include <Windows.h>

// 메모이제이션 (memoization)
int cache[50][50];

int combination(int n, int r)
{
	// 기저 사례 (예외 사례)
	if (r == 0 || n == r)
		return 1;

	// 이미 답을 구한 적 있으면 바로 반환
	int& ret = cache[n][r];
	if (ret != -1)
		return ret;

	return ret = combination(n - 1, r - 1) + combination(n - 1, r);
}

// ENCHANT

// +0 집행검
// 무기 강화 주문서 -> +1 +2 +3 중 하나

// +9 집행검 뜨는 경우의 수는?
// ex) +1 +2 +3 +4 ... +9
// ex) +3 +6 +9
// es) +1 +3 +4 ... +9

int N = 9;
int eCache[100];

// [+num]부터 시작해서 [+N]까지 가는 경우의 수
int Enchant(int num)
{
	// 기저 사례
	if (num > N)
		return 0;
	if (num == N)
		return 1;

	// 캐시
	int& ret = eCache[num];
	if (ret != -1)
		return ret;

	// 적용
	return ret = Enchant(num + 1) + Enchant(num + 2) + Enchant(num + 3);
}



int main()
{
	::memset(cache, -1, sizeof(cache));

	__int64 start = GetTickCount64();
	int lotto = combination(45, 6);
	__int64 end = GetTickCount64();

	cout << end - start << "ms" << endl;

	::memset(eCache, -1, sizeof(eCache));
	int ret = Enchant(0);
	cout << ret << endl;
}