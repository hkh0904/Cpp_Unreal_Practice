#include <iostream>
using namespace std;


int main(void)
{
	/* 배열 : 같은 타입의 변수를 여러개 선언하고 싶을 때 */

	//int iData0, iData1, 
	//bool isData2;

	/* 배열에서 초기화하지 않은 부분은 전부 0으로 초기화됨 */
	int iData[3] = { 0, 1, 2 };
	float fData[3] = { 1.0f, 1.5f, 2.f };

	/* 배열의 각 메모리 영역에 접근할 때에는 0부터 시작하는 인덱스로 접근한다 */
	for (int i = 0; i < 3; ++i)
	{
		// iData[i] == *(iData + i)
		cout << "배열[i] : " << iData[i] << endl;
		cout << "포인터(+i) : " << *(iData + i) << endl;
	}

	/* const사용하면 배열의 범위에 변수를 넣을 수 있다. */
	/* const는 선언 후 값이 바뀔 수 없음 */
	const int	iSize = 5;

	int iData_A[iSize] = { 0 };

	// 2차원배열

	/* 3개의 연속적인 데이터를 2그룹으로 선언한 것과 같다. */
	int iArray[2][3] = { {0, 1, 2}, {3, 4, 5} };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << iArray[i][j] << ", ";
		}
		cout << endl;
	}


}