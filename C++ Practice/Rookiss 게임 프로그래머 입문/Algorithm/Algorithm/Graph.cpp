#include <iostream>
using namespace std;
#include <vector>

// 그래프 - [현실 세계의 사물이나 추상적이 개념]간의 [연결 관계]를 표현
// 정점(Vertex) : 데이터를 표현 (사물, 개념 등)
// 간선(Edge) : 정점들을 연결하는데 사용
// 가중치 그래프(지하철 노선도) , 방향 그래프(일방통행 or 두사람의 호감도)

// 트리를 만들었던 방식
void CreateGraph_1()
{
	struct Vertex
	{
		// int data;
		vector<Vertex*> edges;
	};
	// vector<int> v2(10, -1);		// 10개짜리 모든 초기값은 -1인 벡터
	// vector<int> v3{ 1,2,3,4,5,6,7 };
	// v.reserve(6);	<- capacity
	vector<Vertex> v(6);	// resize(6)을 동시에 한 것

	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[3]);
	v[1].edges.push_back(&v[0]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);
	v[3].edges.push_back(&v[4]);
	v[5].edges.push_back(&v[4]);

	// Q) 0번->3번이 연결되어 있나요?
	bool connected = false;

	int size = v[0].edges.size();
	for (int i = 0; i < size; i++)
	{
		Vertex* vertex = v[0].edges[i];
		if (vertex == &v[3])
			connected = true;
	}
}

// 인접 리스트 : 실제 연결된 애들'만' 넣어준다.
void CreateGraph_2()
{
	struct Vertex
	{
		int data;
	};

	vector<Vertex> v(6);

	vector<vector<int>> adjacent;
	adjacent.resize(6);
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	// Q) 0번->3번 연결되어 있나요?
	bool connected = false;

	int size = adjacent[0].size();
	for (int i = 0; i < size; i++)
	{
		int vertex = adjacent[0][i];
		if (vertex == 3)
			connected = true;
	}

}

// 인접 행렬
void CreateGraph_3()
{
	struct Vertex
	{
		int data;
	};

	vector<Vertex> v(6);
	// 연결된 목록을 행렬로 관리
	// [X][O][X][O][X][X]
	// [O][X][O][O][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][O][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][O][X]

	// adjacent[from][to] ?
	// 행렬을 이용한 그래프 표현
	// 메모리 소모 심하지만, 빠른 접근
	vector<vector<bool>> adjacent(6, vector<bool> (6, false));
	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	// Q) 0번 -> 3번 연결되어 있나요?
	bool connected = adjacent[0][3];

	// 가중치 그래프
	vector<vector<int>> adjacent2 =
	{
		{-1, 15, -1, 35, -1, -1},
		{15, -1, +5, 10, -1, -1},
		{-1, +5, -1, -1, -1, -1},
		{35, 10, -1, -1, +5, -1},
		{-1, -1, -1, +5, -1, +5},
		{-1, -1, -1, -1, +5, -1},
	};
}


int main()
{
	vector<int> v;
}