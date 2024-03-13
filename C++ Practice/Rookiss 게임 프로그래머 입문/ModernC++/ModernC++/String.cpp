#include <iostream>
using namespace std;

int main()
{
	std::string str = "Rookiss";
	std::string str2 = "Rookiss";

	// 1) 비교
	if (str == str2)
	{	}

	// 2) 복사
	string str3;
	str3 = str;

	// 3) 추가 ()
	// str.append("1234");
	str += "1234";

	// 4) 찾기
	auto c = str.find("Roo");
	if (c == std::string::npos)
	{
		cout << "not found";
	}

	// 5) 교체
	string chatStr = "Fuck !!";
	string findStr = "Fuck";
	string replaceStr = "****";

	chatStr.replace(chatStr.find(findStr), findStr.length(), replaceStr);

	string str4 = str.substr(0, 3);

	const char* name = str.c_str();

}