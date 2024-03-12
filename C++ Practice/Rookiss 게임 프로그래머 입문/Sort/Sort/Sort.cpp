#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <concurrent_priority_queue.h>
#include <algorithm>

// BubbleSort -> O(N^2)
void BubbleSort(vector<int>& v)
{
	const int n = v.size();

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (v[j] > v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
				// swap(v[j], v[j + 1]);
			}
		}
	}
}

// SelectionSort -> O(N^2)
void SelectionSort(vector<int>& v)
{
	const int n = v.size();

	for (int i = 0; i < n - 1; i++)
	{
		int bestIdx = i;

		for (int j = i + 1; j < n; j++)
		{
			if (v[j] < v[bestIdx])
				bestIdx = j;
		}
		if (i != bestIdx)
			swap(v[i], v[bestIdx]);
	}
}

// HeapSort(우선순위 큐 활용) -> O(N logN)
void HeapSort(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<int>> pq;

	// O(N logN)
	for (int num : v)
		pq.push(num);

	v.clear();

	// O(N logN)
	while (pq.empty() == false)
	{
		v.push_back(pq.top());	// O(1)
		pq.pop();	// O(LogN)
	}

}

// 병합 정렬 (MergeSort) -> O(N logN)
// 분할 정복(Divide and Conquer)
// - 분할(Divide)	문제를 더 단순하게 분할한다
// - 정복(Conquer)	분할된 문제를 해결
// - 결합(Combine)	결과를 취합하여 마무리
// [3][K][J][7][2][4][8][9]			<< 8개*1
// [3][K][J][7] [2][4][8][9]		<< 4개*2
// [3][K] [J][7] [2][4] [8][9]		<< 2개*4
// [3] [K] [J] [7] [2] [4] [8] [9]	<< 1개*8
// [3][K] [7][J] [2][4] [8][9]		<< 2개*4
// [3][7][J][K] [2][4][8][9]		<< 4개*2

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;

	vector<int> temp;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (v[leftIdx] <= v[rightIdx])
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
		else
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}

	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
		v[left + i] = temp[i];
}

void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);

	MergeResult(v, left, mid, right);
}

int Partition(vector<int>& v, int left, int right)
{
	int pivot = v[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (low <= right && pivot >= v[low])
			low++;

		while (high >= left + 1 && pivot <= v[high])
			high--;

		if (low < high)
			swap(v[low], v[high]);
	}

	swap(v[left], v[high]);
	return high;
}

// QuickSort	-> O(N logN) 평균적 경우, 최악의 경우는 O(N^2)
void QuickSort(vector<int>& v, int left, int right)
{
	if (left > right)
		return;

	int pivot = Partition(v, left, right);
	QuickSort(v, left, pivot - 1);
	QuickSort(v, pivot + 1, right);
}

int main()
{
	vector<int> v{ 1, 5, 3, 4, 2 };

	// std::sort(v.begin(), v.end());
	// BubbleSort(v);
	// SelectionSort(v);
	// HeapSort(v);
	// MergeSort(v, 0, v.size() - 1);
	QuickSort(v, 0, v.size() - 1);

}