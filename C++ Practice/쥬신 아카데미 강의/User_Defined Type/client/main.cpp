#include <iostream>
#include <bitset>
using namespace std;

//// 이건 전역변수가 아닌 그냥 정의 (공간을 할당하지 않음)
//// 이 구조체가 이런 타입을 가질거다
//struct tDataSet // 타입의 이름
//{
//	int		iData;
//	float	fData;
//	double	Data;
//};
//
//struct tStatus
//{
//	int		iAtt, iDef, iHp, iMp;
//};
//
//void Output_Status(const tStatus& State);
//void Output_Status(const tStatus* State);
//
//void Output_Status(int iAtt, int iDef, int iHp, int iMp)
//{
//	cout << "공격력 : " << iAtt << endl;
//	cout << "방어력 : " << iDef << endl;
//	cout << "생명력 : " << iHp << endl;
//	cout << "정신력 : " << iMp << endl;
//}
//
//
//int main()
//{
//	/* 사용자 정의 타입 <-> 원시적인 데이터 타입 */
//	// 구조체, 공용체, 클래스
//	// 구조체 : 제가 타입을 만든다.
//	// 왜? : 여러개의 다양한 타입을 하나 묶어서 사용하기 위해
//
//	/* tDataSet이름의 새로운 타입을 정의한 것이다. */
//
//
//
//	tDataSet		DataSet;
//
//	DataSet.iData = 10;
//	DataSet.fData = 10.123f;
//	DataSet.Data = 10.12345;
//
//	//cout << DataSet.iData << endl;
//	//cout << DataSet.fData << endl;
//	//cout << DataSet.Data << endl;
//
//	tStatus		PlayerState;
//	
//	PlayerState.iAtt = 10;
//	PlayerState.iDef = 5;
//	PlayerState.iHp = 100;
//	PlayerState.iMp = 50;
//
//	Output_Status(&PlayerState);
//
//	tStatus*	pPlayerState = new tStatus;
//
//	pPlayerState->iAtt = 100;
//	pPlayerState->iDef = 50;
//	pPlayerState->iHp = 1000;
//	pPlayerState->iMp = 500;
//
//	Output_Status(pPlayerState); 
//
//	delete pPlayerState;
//	pPlayerState = nullptr;
//
//}
//
//void Output_Status(const tStatus* pState)
//{
//	cout << "공격력 : " << pState->iAtt << endl;
//	cout << "방어력 : " << pState->iDef << endl;
//	cout << "생명력 : " << pState->iHp << endl;
//	cout << "정신력 : " << pState->iMp << endl;
//}
//
//
//void Output_Status(const tStatus& State)
//{
//	cout << "공격력 : " << State.iAtt << endl;
//	cout << "방어력 : " << State.iDef << endl;
//	cout << "생명력 : " << State.iHp << endl;
//	cout << "정신력 : " << State.iMp << endl;
//}


struct tagTest
{
	int		iData_A;
	bool	bData_B;
}; // g_DataSet 처럼 바로 변수 선언가능;
//
//typedef struct tagCharacterStatus
//{
//	int		iAtt;
//	int		iDef;
//	bool	isPlayer;
//	bool	isMonster;
//	int		iHp;		// 두 변수 추가해도 24byte할당
//	short	nDummy;		// 더미 선언해서 빈공간없이 할당하는 방법도있음
//	double	iExp;
//} Status;

struct
{
	int		iAtt;
	int		iHp;
	bool	isPlayer;
} Test;

// 비트구조체
typedef struct
{
	/*short	nAtt : 8;
	short	nDef : 8;*/

	bool	isAtt : 1;
	bool	isRun : 1;
	bool	isJump : 1;
	bool	isWalk : 1;
	bool	isAtt1 : 1;
	bool	isRun1 : 1;
	bool	isJump1 : 1;
	bool	isWalk1 : 1;

	// 게임구현시 색깔에서도 사용
	//unsigned int	iRed : 8;
	//unsigned int	iGreen : 8;
	//unsigned int	iBlue : 8;
	//unsigned int	iAlpha : 8;

}Status;


int main(void)
{
	Test.iAtt = 10;

	//tagCharacterStatus		Test;
	//Status					Test1;

	// 64bit환경에서는 8byte씩 접근해서 변수를 읽어온다.
	// 구조체는 구조체 내의 가장 큰 type을 fadding byte로 사용함
	// ex) int, int, bool 이라면 (4,4,4(1)) = 12, 접근은 3번
	// CPU가 메모리에 접근하는 횟수를 줄이기위해서 24byte가 할당됨
	// 첫번째, 두번째 접근 8byte = int, int (4,4)
	// 세번째 접근 8byte = bool (1)
	// 네번째 접근 8byte = double (8)
	cout << sizeof(Status) << endl;		// 24byte

	Status		State;

	/*State.nAtt = 0xff;
	State.nDef = 0x11;

	cout << bitset<8>(State.nAtt) << endl;
	cout << bitset<8>(State.nDef) << endl;*/

	State.isAtt = 0b1;

}