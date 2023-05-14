#pragma once
#include<iostream>
#include"clsDynamicArray.h"

using namespace std;

template <class T>
class clsMyQueueArr
{
protected:
	clsDynamicArray<T> _MyArr;

public:

	void push(T Value)
	{
		_MyArr.InsertAtBegininng(Value);
	}

	void pop()
	{
		_MyArr.DeleteLastItem();
	}

	T Front()
	{
		return _MyArr.GetItem(0);
	}

	int Size()
	{
		return _MyArr.Size();
	}

	T Back()
	{
		return _MyArr.GetItem(Size() - 1);
	}

	bool IsEmpty()
	{
		return _MyArr.IsEmpty();
	}

	void Print()
	{
		_MyArr.Print();
	}

	void Reverse()
	{
		_MyArr.Reverse();
	}

	void UpdateItem(int Index, T Value)
	{
		_MyArr.UpdateItem(Index, Value);
	}

	void InsertAfter(int Index, T Value)
	{
		_MyArr.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value)
	{
		_MyArr.InsertAtBegininng(Value);
	}

	void InsertAtBack(T Value)
	{
		_MyArr.InsertAtEnd(Value);
	}

	void Clear()
	{
		_MyArr.Clear();
	}

	T GetItem(int Item)
	{
		return _MyArr.GetItem(Item);
	}

};

