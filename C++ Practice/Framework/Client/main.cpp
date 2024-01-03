//// #이 붙은 코드는 전처리기(코드 실행전 수행)
//// iostream이라는 파일을 현재 위치에서 사용하겠다
//#include <iostream>
//using namespace std;
//
//// 진입점함수
//// 여러 함수 중, 무조건 main이라는 함수를 가장 먼저 호출한다.
//int main(void)
//{
//	// 변수 : 무언가 저장하는 공간
//	// 할당할 크기를 지정, 뭘 저장할거야 라는걸 지정해야함
//	// int : 4byte 정수 음수 양수 다 저장
//	// Number : 변수의 이름, 메모리에 이름을 붙인것, 
//	// 그 공간(메모리)을 계속 불러내 사용하기 위해 필요
//	int Number;
//	Number = 4;
//
//	// 컴파일러의 기능 : 번역 + 전달(명령) + 결과파일(.exe) 저장 = 실행
//	// cout == consol output (iostream)
//	// << 출력연산자. 오른쪽 데이터(Hello World)를 왼쪽의 기능으로 수행(cout)
//	// << 출력연산자 가장앞의cout. endl를 출력한다! endl == "\n" 로 이해
//	cout << "Hello World" << Number << endl;
//}

// ===================================================


# include <iostream>
using namespace std;

int main(void)
{
	int				iData;

	iData = 10;

	iData = iData + 10;

	// 한번에 여러변수 선언하더라도 아래처럼 비슷한 카테고리로만 묶는게 좋다
	int				iPlayerHp = 100, iPlayerAtt = 5, iPlayerDef = 3;
	int				iMonsterHp = 100, iMonsterAtt = 3, iMonsterDef = 2;

	//int				iMonsterHp;
	//int				iMonsterDef;

	//int				iPlayerAtt;

	//iMonsterHp = 100;
	//iMonsterDef = 10;
	//iPlayerAtt = 20;

	//iMonsterHp = iMonsterHp + (iMonsterDef - iPlayerAtt);


	//cout << iMonsterHp << endl;

	//// 변수 할당할 때 초기화한다!!
	//int				iData1 = 0;

	//cout << iData1 << endl;

	//int				iData2 = 10, iData3 = 20;

}