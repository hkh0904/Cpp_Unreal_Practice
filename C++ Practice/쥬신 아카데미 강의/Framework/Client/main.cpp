/* Hello c++
// #이 붙은 코드는 전처리기(코드 실행전 수행)
// iostream이라는 파일을 현재 위치에서 사용하겠다
#include <iostream>
using namespace std;

// 진입점함수
// 여러 함수 중, 무조건 main이라는 함수를 가장 먼저 호출한다.
int main(void)
{
	// 변수 : 무언가 저장하는 공간
	// 할당할 크기를 지정, 뭘 저장할거야 라는걸 지정해야함
	// int : 4byte 정수 음수 양수 다 저장
	// Number : 변수의 이름, 메모리에 이름을 붙인것, 
	// 그 공간(메모리)을 계속 불러내 사용하기 위해 필요
	int Number;
	Number = 4;

	// 컴파일러의 기능 : 번역 + 전달(명령) + 결과파일(.exe) 저장 = 실행
	// cout == consol output (iostream)
	// << 출력연산자. 오른쪽 데이터(Hello World)를 왼쪽의 기능으로 수행(cout)
	// << 출력연산자 가장앞의cout. endl를 출력한다! endl == "\n" 로 이해
	cout << "Hello World" << Number << endl;
}
*/

// ===================================================

/* // 변수
# include <iostream>
using namespace std;

int main(void)
{
	int				idata;

	idata = 10;

	idata = idata + 10;

	// 한번에 여러변수 선언하더라도 아래처럼 비슷한 카테고리로만 묶는게 좋다
	int				iplayerhp = 100, iplayeratt = 5, iplayerdef = 3;
	int				imonsterhp = 100, imonsteratt = 3, imonsterdef = 2;

	//int				imonsterhp;
	//int				imonsterdef;

	//int				iplayeratt;

	//imonsterhp = 100;
	//imonsterdef = 10;
	//iplayeratt = 20;

	//imonsterhp = imonsterhp + (imonsterdef - iplayeratt);


	//cout << imonsterhp << endl;

	//// 변수 할당할 때 초기화한다!!
	//int				idata1 = 0;

	//cout << idata1 << endl;

	//int				idata2 = 10, idata3 = 20;

}
*/


// ========================================================

# include <iostream>
# include <stdint.h>
using namespace std;

int main(void)
{
	// 리터럴 상수, 변수의 타입
	// 리터럴 상수 == 10

	//int		iData = 10;
	//int		iData1 = 10;

	// 변수의 타입 integer == 정수를 저장할 수 있는 타입, 4byte
	// int 변수의 타입 (몇 바이트나 메모리를 예약할건지 + 이 메모리 공간에 어떤값을 보관할건지)


	// 1. 크기가 다른 숫자를 저장할 수 있는 여러개의 타입
	// 2. 크기가 다르다면 저장할 수 있는 숫자의 크기가 다름
	// char (1byte == 8bit, 255)
	// short (2byte == 16bit, 65535)
	// int (4byte == 32bit, 약 42억)
	// long (4byte == 32bit, 약 42억)	운영체제에 따라 8bit (Linux, Mac)
	// long long (8byte == 64bit, 엄청큰수)
	signed char		iData = 7;		// 00000111 로 저장됨
	short			iData1 = 7;
	int				iData2 = 7;
	long			iData3 = 7l;
	unsigned long iData5 = 7ul;
	long long		iData4 = 7;

	// signed (기호(-)가 있다.) 가장 앞비트를 부호비트로 사용, 1이면 (-)
	// unsigned (기호(-)가 없다.)
	// signed로 선언시 같은 타입의 변수라도 표현할 수 있는 숫자 크기가 달라짐
	// char 일때 unsigned = 0 ~ 255, signed라면 -128 ~ 127

	// char, signed char, unsigned char 은 전부 다름
	// char 은 문자를 사용하기 위해 사용된다

	// 어떤 플랫폼에서든 항상 고정된 사이즈를 보장하는 정수를 저장하는 변수 타입을 쓰고싶다.
	// int8_t, uint8_t (1byte)
	// int16_t, uint16_t (2byte)
	// int32_t, uint32_t (3byte)
	// int64_t, uint64_t (4byte)


	// 실수형 데이터.
	// float(4byte : 소수점자리수 7자리까지는), double(8byte : 소수점자리수 14 ~ 15자리수 까지는), long double(16byte)
	// float -> 1bit == MSB, 8bit == 지수, 23bit == 가수(데이터)
	float		fData = 10.12f;		// float형을 사용시 f를 붙여줘야 float형으로 인식함
	double		dData = 10.12;
	long double ldData = 10.12l;

	// 실수를 저장할때 부동소수점의 방식 (단점 : 정확한 데이터를 저장하지 못하는 경우)
	float		fData = 1.0f;		// 1.0000000001f 이런 오차 발생가능성

	// fData == 1.0f 같다고 비교는 위험함 -> (fData <= 1.0f or fData >= 1.0f)

	// 1byte (0 or 1) => (false or true)
	bool		bTest = true;

	bTest = false;

}