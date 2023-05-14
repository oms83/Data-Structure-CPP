#pragma once
#include<iostream>
#include"clsDblLinkedList.h"

using namespace std;

template<class T>
class clsMyQueue
{

protected:
	clsDblLinkedList<T> _MyList; // Composition Concept

public:

	void push(T Value)
	{
		_MyList.InserAtBeginning(Value);
	}

	void pop()
	{
		_MyList.DeleteLastNode();
	}

	int Size()
	{
		return _MyList.Size();
	}

	T Front()
	{
		return _MyList.GetItem(0);
	}

	T Back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	void Print()
	{
		_MyList.PrintList();
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void UpdateItem(int Index, T Value)
	{
		_MyList.UpdateItem(Index, Value);
	}

	void InsertAfter(int Index, T Value)
	{
		_MyList.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value)
	{
		_MyList.InserAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void Clear()
	{
		_MyList.Clear();
	}

	T GetItem(int Item)
	{
		return _MyList.GetItem(Item);
	}
};

