#include <iostream>

using namespace std;

// [타입] [이름];


int main()
{
	// 별찍기
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	// 구구단
	for (int i = 2; i < 10; i++)
	{
		printf("===== %d단 =====\n", i);
		for (int j = 1; j < 10; j++)
			cout << i << " * " << j << " = " << (i * j) << endl;
	}

	// 간단한 전투
	int round = 1;
	int hp = 100; // 몬스터HP
	int damage = 25; // 플레이어 데미지

	while (true)
	{
		hp -= damage;
		if (hp < 0)
			hp = 0;

		cout << "Round: " << round << ", 몬스터 체력: " << hp << endl;

		if (hp == 0)
		{
			cout << "몬스터 처치!" << endl;
			break;
		}

		if (round == 5)
		{
			cout << "GameOver, 몬스터 처치 실패!" << endl;
			break;
		}

		round++;
	}

	// 가위-바위-보
	const int SCISSORS = 0;
	const int ROCK = 1;
	const int PAPER = 2;

	// 열거형으로 관리하기도 함
	enum ENUM_GBB
	{
		GBB_SCISSORS = 0,
		GBB_ROCK = 1,
		GBB_PAPER = 2
	};

	srand(time(0));

	while (true)
	{
		cout << "가위(0) 바위(1) 보(2) 골라주세요!" << endl;
		cout << ">";

		// 사용자
		int value;
		cin >> value;

		// 컴퓨터
		int computerValue = rand() % 3;

		if (value == SCISSORS)
		{
			switch (computerValue)
			{
				case SCISSORS:
					cout << "가위(Player) vs 가위(Computer) : Draw" << endl;
					break;
				case ROCK:
					cout << "가위(Player) vs 바위(Computer) : Computer WIN" << endl;
					break;
				case PAPER:
					cout << "가위(Player) vs 보(Computer) : Player WIN" << endl;
					break;
			}
		}
		else if (value == ROCK)
		{
			switch (computerValue)
			{
				case SCISSORS:
					cout << "바위(Player) vs 가위(Computer) : Player WIN" << endl;
					break;
				case ROCK:
					cout << "바위(Player) vs 바위(Computer) : Draw" << endl;
					break;
				case PAPER:
					cout << "바위(Player) vs 보(Computer) : Computer WIN" << endl;
					break;
			}
		}
		else if (value == PAPER)
		{
			switch (computerValue)
			{
				case SCISSORS:
					cout << "보(Player) vs 가위(Computer) : Computer WIN" << endl;
					break;
				case ROCK:
					cout << "보(Player) vs 바위(Computer) : Player WIN" << endl;
					break;
				case PAPER:
					cout << "보(Player) vs 보(Computer) : Draw" << endl;
					break;
			}
		}

		else
		{
			cout << "잘못된 Value 입력, 게임을 종료합니다." << endl;
			break;
		}

	}

}