#include <iostream>
using namespace std;

int main()
{
	// 1) ASCII 코드 -> 영어만 고려
	char ch = 'A';
	//  7bit (0~127)
	
	// 2) ANSI
	// ASCII + 각국 언어별로 128
	// CP949(한국어)

	// 3) 유니코드 (동일 번호 = 동일한 문자 = 동일한 유니코드)
	// 인코딩 (utf8, utf16)
	// -utf-8 : 영어(1), 한국어/중국어(3)
	// -utf-16 : 영어(2), 한국(2), 중국어(2)


	setlocale(LC_ALL, "");
	cout << "LC_ALL: " << setlocale(LC_ALL, NULL) << endl;

	// CP949
	const char* test = "aaa루키스";
	cout << test << endl;

	//
	auto test2 = u8"aaa루키스입니다.";
	setlocale(LC_ALL, "en_US.UTF-8");
	cout << test2 << endl;

	auto test3 = u"aaa루키스입니다.";
	setlocale(LC_ALL, "en_US.UTF-16");
	cout << test3 << endl;

}