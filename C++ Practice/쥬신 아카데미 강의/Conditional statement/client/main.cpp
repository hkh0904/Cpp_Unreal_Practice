
#include <iostream>
using namespace std;

//int main(void)
//{
//	/* 조건문 */
//	/* bool타입으로 결과를 판단 가능한 무언가(조건식) */
//
//	int		iData = 11;
//
//	if (100 < iData)
//	{
//		cout << "True" << endl;
//	}
//	else if (10 < iData <= 100)
//	{
//		cout << "11~100" << endl;
//	}
//	else 
//	{
//		cout << "False" << endl;
//	}
//}

//int main(void)
//{
//	// switch -case 조건문
//
//	int		iData = 10;
//
//	//switch (iData)
//	//{
//	//case 0:
//	//	// 수행을 해야 할 기능
//	//	cout << "0입니다..." << endl;
//	//	break;	// break 없다면 아래의 모든 case를 실행함
//
//	//case 5: [[__fallthrough]];
//	//case 7: [[__fallthrough]];
//	//case 10: [[__fallthrough]];
//	//case 100:
//	//	cout << "100입니다..." << endl;
//	//	break;
//	//}
//
//	switch (int iData_A = 10; iData)
//	{
//		case 0:
//			iData_A = 20;
//			cout << "0입니다.." << endl;
//			break;
//
//		case 5:
//			cout << "5입니다.." << endl;
//			break;
//
//		default:
//			cout << "0이나 5가 아닌 값입니다." << endl;
//			break;
//	}
//	
//	if (int iData_A = 10; iData)
//	{
//		cout << "왜 나는 안되지" << endl;
//	}
//
//}


// ====================================================
//
//int main(void)
//{
//	// 반복문
//	// (초기값, 조건, 증감)
//
//	int		i, j, k, l = 0;
//
//	for (i = 0; i < 5; ++i)
//	{
//		cout << i << endl;
//	}
//
//	cout << "완료되었습니다." << endl;
//
//}


int main(void)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << "출력" << endl;
		}
	}

	cout << "끝" << endl;

	int		iNumX = 4;
	int		iNumY = 2;

	int		iResult = iNumX * iNumY;

	for (int i = 0; i < iResult; ++i)
	{
		// 만나는 순간 바로 반복문 종료
		break;
	}

	for (int i = 0; i < iNumY; ++i)
	{
		for (int j = 0; j < iNumX; ++j)
		{
			// 만나는 순간 현재의 반복을 멈추고 다음 반복으로 이어감
			continue;
		}
	}

	// while문

	int i = 0;

	//while (i < 5)
	//{
	//	++i; // 반복문 내에서 증감

	//	if (i == 2)
	//	{
	//		continue;
	//	}

	//	if (i == 4)
	//	{
	//		break;
	//	}

	//	cout << i << endl;
	//}

	//// 게임 만들때 자주 생성하는 의도적인 무한루프
	//while (true)
	//{
	//	++i;
	//	cout << i << endl;

	//	// if 유저가 종료키를 누르면?
	//	if (i == 100)
	//	{
	//		break;
	//	}

	//}

	// 무조건 do 내 코드 1번은 수행 후 while
	do
	{
		cout << i << endl;
		++i;
	} while (i < 5)


}
