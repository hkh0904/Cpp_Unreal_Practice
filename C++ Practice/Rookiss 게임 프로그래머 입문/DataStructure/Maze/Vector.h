#pragma once
#pragma once
#include <assert.h>

// 동적 배열
class Vector
{
	using T = int;

public:
	explicit Vector()
	{
	}

	~Vector()
	{
		if (_buffer)
			delete[] _buffer;
	}

	void clear()
	{
		// capacity는 줄어들지않음, size속 데이터만 초기화
		if (_buffer)
		{
			delete[] _buffer;
			_buffer = new T[_capacity];
		}
		_size = 0;
	}


	// 가장 중요한 기능
	void push_back(const T& data)
	{
		// 동적배열 -> capacity가 이미 full이라면?
		if (_size == _capacity)
		{
			// 증설작업
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}
		// 데이터 저장
		_buffer[_size] = data;

		// 데이터 개수 증가
		_size++;
	}

	void pop_back()
	{
		// TODO : 소멸
		_size--;
	}

	T& back()
	{
		return _buffer[_size - 1];
	}

	void reserve(int capacity)
	{
		if (_capacity >= capacity)
			return;

		_capacity = capacity;

		T* newData = new T[_capacity];

		for (int i = 0; i < _size; i++)
			newData[i] = _buffer[i];

		if (_buffer)
			delete[] _buffer;

		_buffer = newData;
	}


	T& operator[](int index)
	{
		// 클래스로 만들때 장점 -> 유효범위 체크등을 추가 가능

		// assert == 조건이 만족하지 않으면 바로 크래시 발생시킴
		assert(index >= 0 && index < _size);
		return _buffer[index];
	}

	// capacity = 할당받은 영역, size = 현재 사용중인 크기
	int size() { return _size; }
	int capacity() { return _capacity; }

private:
	T*		_buffer = nullptr;
	int		_size = 0;
	int		_capacity = 0;
};

