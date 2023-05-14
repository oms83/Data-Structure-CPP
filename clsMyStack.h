#pragma once
#include<iostream>
#include"clsMyQueue.h"
using namespace std;

template<class T>

class clsMyStack : public clsMyQueue<T>
{
public:

	void push(T Value)
	{
		clsMyQueue <T>::_MyList.InserAtBeginning(Value);
	}

	void pop()
	{
		clsMyQueue <T>::_MyList.DeleteFirstNode();
	}

	int Size()
	{
		return clsMyQueue<T>::Size();
	}

	T Bottom()
	{
		return clsMyQueue<T>::Front();
	}

	T Top()
	{
		return clsMyQueue<T>::Back();
	}

	bool IsEmpty()
	{
		return clsMyQueue<T>::IsEmpty();

	}
	void Print()
	{
		clsMyQueue<T>::Print();
	}

	void Reverse()
	{
		clsMyQueue<T>::Reverse();
	}

	void UpdateItem(int Index, T Value)
	{
		clsMyQueue<T>::UpdateItem(Index, Value);
	}

	void InsertAfter(int Index, T Value)
	{
		clsMyQueue<T>::InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value)
	{
		clsMyQueue<T>::push(Value);
	}

	void InsertAtBack(T Value)
	{
		clsMyQueue<T>::InsertAtBack(Value);
	}

	void Clear()
	{
		clsMyQueue<T>::Clear();
	}

	T GetItem(int Item)
	{
		return clsMyQueue<T>::GetItem(Item);
	}
};

