#include "Player.h"
#include "Helper.h"
#include "RoguelikeMap.h"

bool canMove = true;
int GPlayerX = 2;
int GPlayerY = 2;

void MovePlayer(int x, int y)
{
	// 범위 체크
	if (x < 0 || x >= MAP_SIZE)
		return;
	if (y < 0 || y >= MAP_SIZE)
		return;
	// 벽 체크
	int index = y * MAP_SIZE + x;
	if (GMap1D[index] == 1)
		return;

	if (GMap2D[y][x] == 1)
		return;


	// 기존 위치 정리
	{
		int index = GPlayerY * MAP_SIZE + GPlayerX;
		GMap1D[index] = 0;

		GMap2D[GPlayerY][GPlayerX] = 0;
	}

	// 새 위치 이동
	GPlayerX = x;
	GPlayerY = y;
	{
		int index = GPlayerY * MAP_SIZE + GPlayerX;
		GMap1D[index] = 2;

		GMap2D[GPlayerY][GPlayerX] = 2;
	}
}

void HandleMove()
{
	// 키보드를 떼고 있으면, 다음번엔 움직일 수 있다.
	// 한번에 한칸만 이동가능하다
	if (GMoveDir == MD_NONE)
	{
		canMove = true;
		return;
	}
	if (canMove != true)
		return;

	canMove = false;

	if (GMoveDir == MD_LEFT)
	{
		MovePlayer(GPlayerX - 1, GPlayerY);
	}
	else if (GMoveDir == MD_RIGHT)
	{
		MovePlayer(GPlayerX + 1, GPlayerY);
	}
	else if (GMoveDir == MD_UP)
	{
		MovePlayer(GPlayerX, GPlayerY - 1);
	}
	else if (GMoveDir == MD_DOWN)
	{
		MovePlayer(GPlayerX, GPlayerY + 1);
	}
}