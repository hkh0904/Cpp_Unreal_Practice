#include <iostream>
using namespace std;
#include <queue>


// 함수 객체
// 함수 포인터의 단점
// 시그니처가 안맞으면 사용 불가능
// 상태를 가질 수 없음

class Functor
{
public:
	void AddValue(int value)
	{
		_value += value;
	}

	void operator()()
	{
		cout << "Functor Test" << endl;
		cout << _value << endl;
	}

	void operator()(int n)
	{
		cout << "Functor Test" << endl;
		_value += n;
		cout << _value << endl;
	}

public:
	int _value = 0;
};

struct AddStruct
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

template<typename T>
int DoSometing(int a, int b, T func)
{
	return func(a, b);
}


class Job
{
public:
	Job() { }
	virtual ~Job() { }
};

class MoveJob : public Job
{
public:
	MoveJob(int x, int y) : x(x), y(y) { }

	void operator()()
	{
		cout << "Player Move" << endl;
	}

public:
	int x;
	int y;
};

class AttackJob : public Job
{

};

int main()
{
	/*Functor Func;
	Func(5);

	AddStruct add;
	DoSometing(10, 20, add);

	priority_queue<int, vector<int>, greater<int>> pq;*/



	// 클라 : (10, 20) 좌표로 이동할래
	MoveJob* MJob = new MoveJob(10, 20);
	AttackJob* AJob = new AttackJob();
	//
	// ...
	queue<Job*>;
	(*MJob)();

}