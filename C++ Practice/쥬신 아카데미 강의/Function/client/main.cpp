#include <iostream>
using namespace std;

/* 함수 */
// 반환값의 타입, 함수의 이름(인자값)
//
//int Sum(int iDataA, int iDataB)
//{
//	return iDataA + iDataB;
//}
//
//void Print(void)
//{
//	cout << "입력값이 없어도 함수" << endl;
//	cout << "리턴값이 없어도 괜찮다" << endl;
//}
//
//int main(void)
//{
//	int sumA = 5, sumB = 8;
//
//
//	cout << Sum(sumA, sumB) << endl;
//
//	Print();
//
//}
//
///* 인자로 전달받은 변수의 값을 10배 증가시킨다. */
//
//void Change(int iData)
//{
//	iData = iData * 10;
//}
//
///* void함수로 선언할때 전달받은 변수에 접근하기 위해 포인터 사용 */
//void Change1(int *pData)
//{
//	*pData = *pData * 10;
//}
//
//void Change2(int& rData)
//{
//	rData = rData * 10;
//}
//
//int main()
//{
//	int iData = 10;
//
//	/* call by value */
//	Change(iData);
//
//	cout << "call by value : " << iData << endl;
//
//	iData = 10;
//	/* call by address */
//	Change1(&iData);
//
//	cout << "call by address : " << iData << endl;
//
//	iData = 10;
//	/* call by reference */
//	Change2(iData);
//
//	cout << "call by reference : " << iData << endl;
//
//}


// =============================================================

/* 같은 이름의 함수를 중복정의하려면 함수의 인자가 서로 달라야한다. */

/* 함수 원형 */
void Test(float iData);
void Test(int iData);

int main()
{
	/* 디폴트 인자를 가진 함수, 함수 오버로딩 */

	/* 함수 오버로딩 : 같은 이름의 함수를 여러개 정의하는 방식 */
	Test(10);

}


void Test(float iData)
{
	cout << "위에 함수가 호출" << endl;
}

void Test(int iData)
{
	cout << "아래 함수가 호출" << endl;
}