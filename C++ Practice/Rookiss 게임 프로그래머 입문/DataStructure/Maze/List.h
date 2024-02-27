#pragma once
#include <iostream>
using namespace std;

// LinkedList 연결리스트

class Node
{
	// typedef int T;  <- 옛날문법
	using T = int;
public:
	Node(int data) : data(data), prev(nullptr), next(nullptr) { }

public:
	T		data;
	Node*	prev;
	Node*	next;
};

class List
{
public:
	List()
	{
		_head = new Node(0);
		_tail = new Node(0);
		_head->next = _tail;
		_tail->prev = _head;
	}

	~List()
	{
		Node* node = _head;
		while (node)
		{
			Node* deleteNode = node;
			// 다음 노드로 넘어감
			// Node* nextNode = node->next;랑 동일
			node = node->next;
			delete deleteNode;
		}
	}

	// [dummy]<->[1]<->[2]<->[3]<->[dummy] 더미노드 활용
	// [head]						[tail]
	Node* GetNode(int index)
	{
		Node* node = _head->next;
		if (node == _tail)
			return nullptr;
		
		for (int i = 0; i < index; i++)
		{
			if (node == _tail->prev)
				return nullptr;

			node = node->next;
		}

		return node;
	}

	void Print()
	{
		Node* node = _head->next;
		while (node != _tail)
		{
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
	}

	Node* AddAtHead(int data)
	{
		Node* node = new Node(data);
		Node* nextNode = _head->next;

		nextNode->prev = node;
		node->next = nextNode;
		node->prev = _head;
		_head->next = node;

		return node;
	}

	Node* AddAtTail(int data)
	{
		Node* node = new Node(data);
		Node* prevNode = _tail->prev;

		prevNode->next = node;
		node->prev = prevNode;
		node->next = _tail;
		_tail->prev = node;

		return node;
	}

	Node* Insert(Node* posNode, int data)
	{
		Node* node = new Node(data);
		Node* prevNode = posNode->prev;

		prevNode->next = node;
		node->prev = prevNode;
		node->next = posNode;
		posNode->prev = node;

		return node;
	}

	Node* Remove(Node* node)
	{
		Node* prevNode = node->prev;
		Node* nextNode = node->next;

		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete node;
		node = nullptr;

		return nextNode;
	}

private:
	Node* _head = nullptr;
	Node* _tail = nullptr;

	 
};

