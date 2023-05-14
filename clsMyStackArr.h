#pragma once
#include<iostream>
#include"clsMyQueueArr.h"

using namespace std;

template <class T>

class clsMyStackArr : public clsMyQueueArr <T>
{

public:

	void push(T Value)
	{
		
		clsMyQueueArr <T>::_MyArr.InsertAtEnd(Value);
	}

	void pop()
	{
		clsMyQueueArr <T>::_MyArr.DeleteFirstItem();
	}

	int Size()
	{
		return clsMyQueueArr<T>::Size();
	}

	T Bottom()
	{
		return clsMyQueueArr<T>::Front();
	}

	T Top()
	{
		return clsMyQueueArr<T>::Back();
	}

	bool IsEmpty()
	{
		return clsMyQueueArr<T>::IsEmpty();

	}
	void Print()
	{
		clsMyQueueArr<T>::Print();
	}

	void Reverse()
	{
		clsMyQueueArr<T>::Reverse();
	}

	void UpdateItem(int Index, T Value)
	{
		clsMyQueueArr<T>::UpdateItem(Index, Value);
	}

	void InsertAfter(int Index, T Value)
	{
		clsMyQueueArr<T>::InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value)
	{
		clsMyQueueArr<T>::push(Value);
	}

	void InsertAtBack(T Value)
	{
		clsMyQueueArr<T>::InsertAtBack(Value);
	}

	void Clear()
	{
		clsMyQueueArr<T>::Clear();
	}

	T GetItem(int Item)
	{
		return clsMyQueueArr<T>::GetItem(Item);
	}
};

