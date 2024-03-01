#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	// CalculatePath_RightHand();
	CalculatePath_BFS();
	// CalculatePath_AStar();
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;

	_sumTick += deltaTick;

	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;
		// 이동하는 코드
		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}

void Player::CalculatePath_RightHand()
{
	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);

	// 목적지
	Pos dest = _board->GetExitPos();

	_dir;	// 내가 바라보는 방향
	pos;	// 현재 좌표

	// 내가 바라보는 방향 기준 앞에 있는 좌표?
	Pos front[4] =
	{
		Pos(-1, 0),	// UP
		Pos(0, -1),	// LEFT
		Pos(1, 0),	// DOWN
		Pos(0, 1)	// RIGHT
	};

	//  next = pos + front[_dir];

	// 오른쪽 방향 90도 회전
	// _dir = (_dir - 1) % DIR_COUNT;
	// 왼쪽 방향 90도 회전
	// 	_dir = (_dir + 1) % DIR_COUNT;

	// 목적지 찾을 때까지
	while (pos != dest)
	{
		// 1. 현재 바라보는 방향 기준으로, 오른쪽으로 갈 수 있는지 확인
		int32 newDir = (_dir - 1) % DIR_COUNT;	//?
		if (CanGo(pos + front[newDir]))
		{
			// 오른쪽 방향으로 90도 회전
			_dir = newDir;
			// 앞으로 한 보 전진
			pos += front[_dir];
			// 좌표 기록
			_path.push_back(pos);
		}
		// 2. 현재 바라보는 방향을 기준으로 전진할 수 있는지 확인
		else if (CanGo(pos + front[_dir]))
		{
			// 앞으로 한 보 전진
			pos += front[_dir];
			// 좌표 기록
			_path.push_back(pos);
		}
		else
		{
			// 왼쪽 방향으로 90도 회전
			_dir = (_dir + 1) % DIR_COUNT;
		}
	}
}

void Player::CalculatePath_BFS()
{
	Pos pos = _pos;
	Pos dest = _board->GetExitPos();	// 목적지

	Pos front[4] =
	{
		Pos(-1, 0),	// UP
		Pos(0, -1),	// LEFT
		Pos(1, 0),	// DOWN
		Pos(0, 1)	// RIGHT
	};

	const int32 size = _board->GetSize();
	vector<vector<bool>> discovered(size, vector<bool>(size, false));

	// extra)
	// parent[y][x] = pos -> (y, x)는 Pos에 의해 발견되었다.
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	queue<Pos> q;
	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos.y][pos.x] = pos;

	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		// 목적지 도착
		if (pos == dest)
			break;

		for (int32 dir = 0; dir < DIR_COUNT; dir++)
		{
			Pos nextPos = pos + front[dir];
			// 갈 수 있는 지역은 맞는지 확인
			if (CanGo(nextPos) == false)
				continue;
			// 이미 다른 경로에 의해 발견한 지역인지 확인
			if (discovered[nextPos.y][nextPos.x])
				continue;

			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;
			parent[nextPos.y][nextPos.x] = pos;
		}
	}

	_path.clear();
	pos = dest;

	while (true)
	{
		_path.push_back(pos);

		if (pos == parent[pos.y][pos.x])
			break;

		pos = parent[pos.y][pos.x];
	}

	vector<Pos> temp(_path.size());
	for (int i = 0; i < _path.size(); i++)
		temp[i] = _path[_path.size() - 1 - i];

	_path = temp;

	// std::reverse(_path.begin(), _path.end());

}


// BFS, 다익스트라는 목적지의 개념이 없음!
// 스타크래프트처럼 안개처럼?

// 채점
// - 입구에서부터 얼마나 떨어져 있는지?
// - 출구에서부터 얼마나 떨어져 있는지?

struct PQNode
{
	PQNode(int32 f, int32 g, Pos pos) : f(f), g(g), pos(pos) { }

	bool operator<(const PQNode& other) const { return f < other.f; }
	bool operator>(const PQNode& other) const { return f > other.f; }


	int32 f;	// f = g + h
	int32 g;
	Pos pos;
};

void Player::CalculatePath_AStar()
{
	// F = G + H
	// F = 최종점수 (작을수록 좋음)
	// G = 시작점에서 해당 좌표까지 이동하는데 드는 비용
	// H = 목적지에서 해당 좌표까지 이동하는데 드는 비용
	Pos start = _pos;
	Pos dest = _board->GetExitPos();	// 목적지

	Pos front[] =
	{
		Pos(-1, 0),	// UP
		Pos(0, -1),	// LEFT
		Pos(1, 0),	// DOWN
		Pos(0, 1),	// RIGHT
		Pos(-1, -1),	// UP_LEFT
		Pos(1, -1),	// DOWN_LEFT
		Pos(1, 1),	// DOWN_RIGHT
		Pos(-1, 1),	// UP_RIGHT
	};

	int32 cost[] =
	{
		10,
		10,
		10,
		10,
		14,
		14,
		14,
		14
	};

	const int32 size = _board->GetSize();
	
	// best[y][x] -> 지금까지 (y, x)에 대한 가장 좋은 비용 (작을수록 좋음)
	vector<vector<int32>> best(size, vector<int32>(size, INT32_MAX));

	// ClosedList -> closed[y][x] -> (y, x)에 방문을 했는지 여부
	// Option) 사실 best만으로 판별 가능
	vector<vector<bool>> closed(size, vector<bool>(size, false));

	// 부모 추적 용도
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	// 1) 예약 시스템 구현
	// 2) 뒤늦게 더 좋은 경로가 [발견]될 수 있음 -> 예외처리!

	// OpenList : 지금까지 [발견]된 목록 (방문 X)
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;

	// 초기값 세팅
	{
		int32 g = 0;
		int32 h = 10 * (abs(dest.y - start.y) + abs(dest.x - start.x));

		pq.push(PQNode(g + h, g, start));
		best[start.y][start.x] = g + h;
		parent[start.y][start.x] = start;
	}

	while (pq.empty() == false)
	{
		// 제일 좋은 후보를 찾는다
		PQNode node = pq.top();
		pq.pop();

		// 동일한 좌표를 여러 경로로 찾아서
		// 더 빠른 경로로 인해서 이미 방문(closed) 된 경우 스킵
		if (closed[node.pos.y][node.pos.x])
			continue;
		// 기껏 등록했더니 나보다 더 우수한 후보가 있다?
		if (best[node.pos.y][node.pos.x] < node.f)
			continue;

		// 방문
		closed[node.pos.y][node.pos.x] = true;

		// 목적지에 도착했으면 바로 종료
		if (node.pos == dest)
			break;

		for (int32 dir = 0; dir < 8; dir++)
		{
			Pos nextPos = node.pos + front[dir];
			// 갈 수 있는 지역은 맞는지 확인
			if (CanGo(nextPos) == false)
				continue;
			if (closed[nextPos.y][nextPos.x])
				continue;

			int32 g = node.g + cost[dir];
			int32 h = 10 * (abs(dest.y - nextPos.y) + abs(dest.x - nextPos.x));

			// 다른 경로에서 더 빠른 길을 찾았으면 스킵
			if (best[nextPos.y][nextPos.x] <= g + h)
				continue;

			// 예약 진행 -> 예약되더라도 언제든 스킵될 수 있음 (새로운 best경로)
			best[nextPos.y][nextPos.x] = g + h;
			pq.push(PQNode(g + h, g, nextPos));
			parent[nextPos.y][nextPos.x] = node.pos;
		}
	}

	_path.clear();
	Pos pos = dest;

	while (true)
	{
		_path.push_back(pos);

		if (pos == parent[pos.y][pos.x])
			break;

		pos = parent[pos.y][pos.x];
	}

	//vector<Pos> temp(_path.size());
	//for (int i = 0; i < _path.size(); i++)
	//	temp[i] = _path[_path.size() - 1 - i];

	//_path = temp;

	std::reverse(_path.begin(), _path.end());

}
