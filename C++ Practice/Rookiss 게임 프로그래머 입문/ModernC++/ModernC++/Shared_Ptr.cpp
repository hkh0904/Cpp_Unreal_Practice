#include <iostream>
using namespace std;


class Knight
{
public:
	
	void Attack()
	{
		//if (_target)
		//	_target->_hp -= _damage;

		if (_target.expired() == false)
		{
			shared_ptr<Knight> spr = _target.lock();
		}

	}

public:
	int _hp = 100;
	int _damage = 10;
	// shared_ptr의 사이클을 보완하기 위함
	// refcount에는 영향x, weakRefCount로 별도로 관리	
	weak_ptr<Knight> _target;
};

template<typename T>
class Wrapper
{
public:
	Wrapper(T* ptr) : _ptr(ptr) {}
	~Wrapper()
	{
		if (_ptr)
			delete _ptr;
	}

public:
	T* _ptr;
};

class RefCountBlock
{
public:
	int _refCount = 1;
};

template<typename T>
class SharedPtr
{
public:
	SharedPtr() {}
	SharedPtr(T* ptr) : _ptr(ptr) 
	{
		if (ptr)
		{
			_block = new RefCountBlock();
			cout << "RefCount: " << _block->_refCount << endl;
		}
	}

	SharedPtr(const SharedPtr& other) : _ptr(other._ptr), _block(other._block)
	{
		if (_ptr)
		{
			_block->_refCount--;

			if (_block->_refCount == 0)
			{
				delete _ptr;
				delete _block;
				cout << "Delete Date" << endl;
			}
		}
	}

	void operator=(const SharedPtr & other)
	{
		_ptr = other._ptr;
		_block = other._block;

		if (_ptr)
			_block->_refCount++;
	}

	~SharedPtr()
	{
		if (_ptr)
		{
			_block->_refCount--;
		}
	}

public:
	T* _ptr = nullptr;
	RefCountBlock* _block = nullptr;
};



int main()
{
	{
		Wrapper<Knight> w(new Knight);
	}

	// 일반 포인터 사용
	{
		Knight* k1 = new Knight();
		Knight* k2 = new Knight();

		// k1->_target = k2;
		// k2를 타겟으로 참조하고 있는 k1이 있음에도 k2가 지워짐
		delete k2;

		k1->Attack();
	} 

	// shared_ptr
	// weak_ptr
	// delete를 하지 않아도 아무도 참조를 하지않게되면 그때 삭제된다
	{
		shared_ptr<Knight> k1(new Knight());	// refCount 1
		shared_ptr<Knight> k2(new Knight());	// refCount 1

		// 서로 참조하는 경우 서로 놔주지않아서 메모리 릭 발생
		// 예방하려면 weak_ptr함께 사용
		k1->_target = k2;
		k2->_target = k1;
	}

	// unique_ptr
	{
		// 복사 생성자, 복사 연산자가 다 막혀있다.
		unique_ptr<Knight> k(new Knight());

		// 유일하게 이동으로 가능
		unique_ptr<Knight> k2 = std::move(k);
	}
}