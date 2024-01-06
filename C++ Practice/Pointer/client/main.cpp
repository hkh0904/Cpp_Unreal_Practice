#include <iostream>
using namespace std;

//int main(void)
//{
//	/* 포인터형 변수 */
//	/* 메모리 주소를 가질 수 있는 변수 */
//
//	int			iData = 10;
//	/* 할당한 변수의 가장 앞 주소를 가진다. */
//	/* 할당하는 변수의 byte를 알기위해 int*, float* 식으로 변수 타입을 선언해야함 */
//	int*		pData = &iData;
//
//	float		fData = 10.1f;
//	float*		pData_f = &fData;
//
//	*pData = 100;
//
//	cout << iData << endl;
//	cout << *pData << endl;
//
//	int *pData_A = nullptr, *pData_B = nullptr;		// 당장 pointer에 주소를 배정하지 않을때, 또한 여러 포인터를 동시에 할당할때
//
//	pData_A = &iData;
//
//}

// ==================================================

//int main(void)
//{
//	//// void 포인터 (모든 타입의 주소를 저장할 수 있다)
//	int			iData = 10;
//
//	////int*		pData = &iData; // (4byte)
//
//
//	//double		Data = 10.1234;
//
//	//void*		pData = &Data;
//	///* 첫주소에 해당하는 공간에 접근은 성공, 이 첫주소부터 어디까지 사용하는지가 불명확 */
//	//cout << *static_cast<double*>(pData) << endl;
//
//	/* 실제 이 주소에 해당하는 공간에 접근할 시, 반드시 저장하고 있는 변수타입의 포인터로 형변환을 하여야한다. */
//	/* *static_cast<(변수타입)*> */
//
//
//	/* 몬스터를 만든다. 몬스터의 초기 hp(int) */
//	/* 카메라를 만든다. 카메라의 속도를 셋팅(float) */
//	/* Create(void *pData) */
//
//
//	/* void 이중포인터 */
//	/* 이중포인터 : 포인터형 변수의 주소를 가진다. */
//	void**		ppData = nullptr;
//
//	//int*		pData = &iData;
//
//	void*		pData = &iData;
//
//	/* void** = void*형의 주소만 저장할 수 있는 이중 포인터형 변수다. */
//	/* void** = 다른 타입의 포인터형의 주소는 저장할 수 없다. */
//	ppData = &pData; 
//
//	*ppData = &iData;
//
//	cout << *static_cast<int*>(*ppData) << endl;
//
//	/* 포인터형 변수의 크기 */
//	/* 16bit os : 2byte */
//	/* 32bit os : 4byte */
//	/* 64bit os : 8byte */
//}

// ============================================================

int main(void)
{
	// 참조 : Reference

	int		iData = 10;

	/* iData라는 변수에 rData라는 새로운 이름을 지어준거라고 이해하기 */
	/* 하지만 사실 새로운 메모리 추가할당을 하기한다. */
	/* 참조자 : 반드시 선언과 동시에 어떤 공간을 참조할 수 있도록 해야한다. */
	/* 임시공간을 참조할 수 없다. (리터럴 상수 ex) rData = 3; ) */
	int&	rData = iData;

	int* pData = &iData;

	rData = 50;

	cout << "iData : " << iData << endl;
	cout << "rData : " << rData << endl;
	cout << "*pData : " << *pData << endl;
}