
#include <iostream>
using namespace std;

//int main(void)
// 산술연산
//{
//	// c++ 연산자
//	// 산술연산자 (+, -, *, /, %, ++, --)
//	// 부울연산자 bool타입으로 결과를 가지는 연산자들 (부정, 논리, 관계)
//	// 비트단위 논리연산자
//	// 배정연산자 (=, +=, -=, *=, /=)
//	// 접근연산자 (구조체, 클래스 ., ->, *)
//
//	// 모든 연산자는 결과값을 가진다
//	// 1. 산술연산자 (+, -, *, /, %, ++, --)
//	int		iData_A = 10;
//	int		iData_B = 20;
//
//	// 연산자 우선순위 (*, /, +, -)
//
//	cout << iData_A * iData_B << endl;
//
//	int iResult = iData_A * iData_B;
//
//	cout << iResult << endl;
//
//	// 단항연산자로도 활용할 수 있다
//	int		iData_C = 10;
//
//	cout << -iData_C << endl;
//	cout << iData_C << endl;
//
//	// 두 변수 모두 int이기 때문에 0.5가 아닌 0이 나옴
//	iResult = iData_A / iData_B;
//	cout << iResult << endl;
//
//	float	fData_A = 10.f;
//	float	fData_B = 20.f;
//
//	cout << fData_A / fData_B << endl;
//
//
//	// % 나머지연산, 실수타입에 대해서는 연산할 수 없다 (오로지 정수)
//
//	iData_A = 7;
//	iData_B = 2;
//
//	cout << iData_A % iData_B << endl;
//
//	// 부울연산자 bool타입(0또는 1) 으로 결과를 가지는 연산자들 (부정, 논리, 관계)
//	// 관계연산자( <, >, <=, >=, ==, != )
//
//
//	cout << (iData_A > iData_B) << endl;
//	
//	// ! (not) 부정연산자 단항연산자
//	// !연산자 오른쪽에 있는 데이터가 true라면 결과를 false로 보내줌
//	// !연산자 오른쪽에 있는 데이터가 false(0)라면 결과를 true로 보내줌
//	
//	iData_B = 10;
//
//	cout << !iData_B << endl;
//	cout << not iData_B << endl;
//
//
//}

// =================================================

//int main(void)
//{
//	// 논리연산자 (and, or)
//
//	int		iData_A = 10;
//	int		iData_B = 0;
//	int		iData_C = 20;
//
//	// and(&&) : 그리고, 이항연산자
//	// 좌변의 데이터가 true고 우변의 데이터도 true면 결과로 true를 리턴
//
//	// ex) 몬스터가 hp가 언제 달아야하는가?
//	// 몬스터가 Player의 공격에 피격되었다(true) && 몬스터의 hp가 만약 0보다 크다면(true)
//	cout << (iData_A && iData_B) << endl;
//
//	// or(||) : 또는(이거나), 이항연산자
//	// 좌변과 우변 중 단 하나라도 true라면 결과를 true로 리턴한다
//
//	// ex) 플레이어가 죽는경우
//	// 플레이어의 hp가 0보다 작거나 같아지면 || 플레이어가 혹여나 높은 곳에서 떨어지면
//	cout << (iData_A || iData_B) << endl;
//
//
//	// &&연산에서 앞의 인자가 false라서 이미 false이거나, ||연산에서 앞의 인자가 true라서 이미 true일땐 뒤의 연산을 수행하지 않음
//	// 때문에 가벼운 연산을 앞에 두는게 유리함
//	cout << (iData_A && (iData_B = iData_C)) << endl;
//}

// ================================================================

#include <bitset>
//int main(void)
//{
//	// 비트단위논리연산자
//	// and 연산 (&), or 연산 (|), xor연산 (^)
//	// bool값을 반환하지 않고 숫자를 반환
//	// 비트 자리수마다 and나 or연산 수행
//
//
//	// and연산 (&),검사의 용도 : 특정 비트에 0이 들어가있는지 검사하는 용도
//	char		Data_A = 0b00000011;
//	char		Data_B = 0b00000010;
//
//	cout << bitset<8>(Data_A & Data_B) << endl;	// 2
//
//	/* 게임을 만드는데 플레이어를 게임내에서 동작하도록 만들고 싶다 */
//	/* 플레이어에게 여러 상태가 필요하다 */
//	/* 만약 내가  
//	1. 비트 단위별로 마음껏 0, 1을 대입할수 있고
//	2. 1을 꺼낼 수 있고, 0을 대입할 수 있고,
//	3. 어떤 비트에 0인지 1인지 검사할 수 있다면? */
//	bool		isAttack;
//	bool		isDefeat;
//	bool		isRun;
//	bool		isIdle;
//
//	// or 연산 (|) : 비트 단위별로 마음껏 1을 대입할 수 있다.
//
//	Data_A = 0b00000001;
//	Data_B = 0b00000010;
//
//	Data_A = Data_A | Data_B;
//
//	cout << bitset<8>(Data_A) << endl;
//
//	// xor 연산 (^) : 1을 꺼내고, 0으로 대입해줌
//	// 두개의 비트가 서로 다를때 1, 서로 같다면 0을 리턴한다.
//	Data_A = 0b00000111;
//	Data_B = 0b00000010;
//
//	Data_A = Data_A ^ Data_B;
//
//	cout << bitset<8>(Data_A) << endl;
//
//	// ~ 단항연산자, 비트가 전부 반전
//	Data_A = 0b00001111;
//	cout << bitset<8>(~Data_A) << endl;
//
//	// >>, << 쉬프트 연산자, (왼쪽,오른쪽으로) 비트를 한칸씩 이동시킴
//	Data_A = 0b11111111;
//
//	// 왼쪽으로 밀면 가장 뒤 빈칸에 0이 채워짐
//	Data_A = Data_A << 1;
//	cout << bitset<8>(Data_A) << endl;
//
//	// 오른쪽으로 밀면 가장 앞 칸에 기존 부호비트 값이 유지됨
//	// unsigned라면 0이 채워짐
//	Data_A = Data_A >> 1;
//	cout << bitset<8>(Data_A) << endl;
//
//	// 쉬프트 연산은 어떻게 활용할 수 있을까?
//	/* 색상을 가지고 있는 변수가 있다. */
//	unsigned int	iColor = 50;
//
//	/* >> 1 == iColor / 2 한것과 같다 */
//	// >> 값 -> 오른쪽으로 민다. == 나누기 연산의 거듭제곱
//	// 비트 한칸 미는게 각 자리 비트마다 연산하는거보다 훨씬 빠르다
//	cout << (iColor >> 1) << endl;
//
//	/* << 1 == iColor * 2 한것과 같다 */
//	cout << (iColor << 1) << endl;
//
//}

// ==============================

int main(void) {
	// 배정 연산자 : = 
	int		iData_A = 10;
	int		iData_B = 20;

	//iData_A = iData_B;

	// 복합배정연산자 : +=, -=, *=, /=, &=, |=

	iData_A -= iData_B;

	cout << iData_A << endl;

	int		iData_C = 10;

	// 게임에서 콤보, FPS 같은거 보여줄 때 사용
	//iData_C += 1 == iData_C++ (후치연산)
	iData_C--;

	// 아래처럼 사용하면 값을 출력 후 --연산
	cout << iData_C-- << endl;
	cout << --iData_C << endl;

}