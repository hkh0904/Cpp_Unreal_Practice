#include <iostream>
using namespace std;

// 연산자 오버로딩

// 멤버 연산자 함수 버전
// - a op b 형태에서 왼쪽을 기준으로 실행
 
// 전역 연산자 함수 버전
// - a op b 형태라면, a/b 모두를 연산자 함수의 피연산자로 사용

class Pos
{
public:
	Pos operator+(const Pos& b)
	{
		Pos pos;
		pos.x = x + b.x;
		pos.y = y + b.y;
		return pos;
	}

	Pos operator+(int b)
	{
		Pos pos;
		pos.x = x + b;
		pos.y = y + b;
		return pos;
	}

	bool operator==(const Pos& b)
	{
		return x == b.x && y == b.y;
	}

	// 대입 연산자
	Pos& operator=(int b)
	{
		x = b;
		y = b;
		return *this;
	}

public:
	int x = 0;
	int y = 0;
};

Pos operator+(int a, const Pos& b)
{
	Pos pos;
	pos.x = a + b.x;
	pos.y = a + b.y;
	return pos;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = a + b;

	Pos pos1;
	Pos pos2;

	Pos pos3 = pos1 + pos2;
	Pos pos4 = 10 + pos1;

	// 선언과 동시에 값을 대입하는 것은 생성자 코드를 통해 이루어짐
	// 대입 연산자를 사용하는 것이 아님   ex) Pos pos5 = 10;
	// 이것을 막으려면 생성자 함수 앞에 explicit을 붙여주어 예방 가능 ex) explicit Pos(int a) { }
	// 대입 연산자를 사용하려면 선언한 후 다시 대입연산자를 사용해주어야함
	// 이 경우에도 대입연산자를 정의하지 않았다면 생성자 코드로 갈 수 있음에 주의
	// ex) Pos pos5;	pos5 = 10;


}