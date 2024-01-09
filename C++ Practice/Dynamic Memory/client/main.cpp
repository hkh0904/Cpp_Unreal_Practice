#include <iostream>

using namespace std;


//int main(void)
//{
//	int iData;
//	/* 동적할당 */
//	// 메모리의 할당 시점과 삭제시점을 내가 직접 통제하고 싶다.
//
//	float* pInt = new float;
//
//	*pInt = 10;
//
//	cout << *pInt << endl;
//
//	/* delete 뒤에는 삭제하고자하는 공간의 주소가 온다. */
//	delete pInt;
//
//	// 삭제된 공간에 접근하는거 위험
//	// 삭제한 공간을 초기화하는 습관을 들이자
//	pInt = nullptr;
//	cout << *pInt << endl;
//
//}


//int main()
//{
//	int			iArray[3] = { 0 };
//
//	int*		pArray = new int[3];
//
//	pArray[0] = 10;
//	cout << *(pArray + 0) << endl;
//
//	pArray[1] = 20;
//	cout << *(pArray + 1) << endl;
//
//	// 배열로 선언시 삭제할때 [] 선언해주기
//	delete [] pArray;
//	pArray = nullptr;
//
//}


int main()
{
	// new선언시 int뒤에 () 붙여주면 초기화가능
	int*	 pInt = new int(2);


	cout << *pInt << endl;

	delete pInt;
	pInt = nullptr;

}