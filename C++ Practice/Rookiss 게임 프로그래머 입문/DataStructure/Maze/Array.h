#pragma once
#include <assert.h>

// 배열
class Array
{
	using T = int;

public:
	explicit Array(int capacity = 100) : _capacity(capacity)
	{
		_buffer = new T[capacity];
	}

	~Array()
	{
		delete[] _buffer;
	}

	void push_back(const T& data)
	{
		// TODO
		if (_size == _capacity)
			return;

		_buffer[_size] = data;
		_size++;
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

