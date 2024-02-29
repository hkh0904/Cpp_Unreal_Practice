#include <iostream>
using namespace std;
#include <vector>

// DFS (depth first search)
// DFS = 재귀함수 (끝까지 탐색 후 돌아오기) = 스택

struct Vertex
{
	// int data
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

vector<bool> visited;

void CreateGraph()
{
	vertices.resize(6);

	// 인접 리스트
	/*adjacent = vector<vector<int>>(6);
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };*/

	// 인접 행렬
	adjacent = vector<vector<int>>
	{
		{0, 1, 0, 1, 0, 0},
		{1, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0}
	};
}

void Dfs(int here)
{
	// 방문 체크
	visited[here] = true;
	cout << "Visited : " << here << endl;

	// 인접한 길을 다 체크 (인접리스트 버전)
	// 시간복잡도 O(V+E) - V:Verter, E:Edge
	/*for (int i = 0; i < adjacent[here].size(); i++)
	{
		int there = adjacent[here][i];
		if (visited[there] == false)
			Dfs(there);
	}*/

	// 인접 행렬 버전
	// 시간복잡도 O(V^2)
	for (int there = 0; there < 6; there++)
	{
		// 길은 있는지
		if (adjacent[here][there] == 0)
			continue;
		
		// 아직 방문하지 않은 곳에 한해서 방문
		if (visited[there] == false)
			Dfs(there);
	}
}

// 그래프라면 모든 점이 연결되있는지 확인할 수 없기때문에
void DfsAll()
{
	visited = vector<bool>(6, false);

	for (int i = 0; i < 6; i++)
		if (visited[i] == false)
			Dfs(i);
}


int main()
{
	CreateGraph();

	visited = vector<bool>(6, false);
	DfsAll();
}