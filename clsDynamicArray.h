#pragma once
#include<iostream>

using namespace std;

template<class T>
class clsDynamicArray
{
private:
	int _Size;
	T* _TempArray;

	

public:
	
	T* OriginalArray;
	
	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
		{
			Size = 0;
		}

		_Size = Size;

		OriginalArray = new T[_Size];
	}
	
	~clsDynamicArray()
	{
		delete[] OriginalArray;
	}

	bool SetItem(int Index, T Value)
	{
		if (Index >= _Size || Index < 0)
		{
			return false;
		}

		OriginalArray[Index] = Value;
		return true;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	void Print()
	{
		cout << "\n";

		for (int i = 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << "  ";
		}

		cout << "\n";
	}
	
	void Resize(int Size)
	{
		if (Size < 0)
		{
			Size = 0;
		}

		_TempArray = new T[Size];

		if (Size < _Size)
		{
			_Size = Size;
		}

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		delete[]OriginalArray;
		OriginalArray = _TempArray;
	}

	T GetItem(int Index)
	{
		/*if (Item <= _Size && Item > 0)
		{
			return OriginalArray[Item - 1];
		}
		return 0;*/
		
		return OriginalArray[Index];
	}

	void Reverse()
	{
		_TempArray = new T[_Size];
		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[_Size - i - 1];
		}

		delete[]OriginalArray;
		OriginalArray = _TempArray;
	}

	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[]OriginalArray;
		OriginalArray = _TempArray;
	}
	
	void DeleteItemAt(int Index)
	{
		_TempArray = new T[_Size];
		int j = 0;
		bool Flag = false;
		for (int i = 0; i < _Size; i++)
		{
			if (Index != i)
			{
				_TempArray[j++] = OriginalArray[i];
			}
			else
			{
				Flag = true;
			}
		}
		if (Flag)
		{
			_Size -= 1;
		}

		delete[]OriginalArray;
		OriginalArray = _TempArray;

	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	int Found(T Item)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == Item)
			{
				return i;
			}
		}

		return -1;
	}

	bool DeleteItem(T Item)
	{
		int Index = Found(Item);
		if (Index == -1)
		{
			return false;
		}
		
		DeleteItemAt(Index);
		return true;
	}

	bool InsertAt(int Index, T Value)
	{
		if (Index > _Size || Index < 0)
		{
			return false;
		}

		_Size++;
		_TempArray = new T[_Size];

		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_TempArray[Index] = Value;

		for (int i = Index+1; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i-1];
		}

		delete[]OriginalArray;
		OriginalArray = _TempArray;
		return true;

	}

	void InsertAtBegininng(T Value)
	{
		InsertAt(0, Value);
	}

	void InsertAtEnd(T Value)
	{
		/*_Size++;
		Resize(_Size);
		OriginalArray[_Size - 1] = Value;*/
		InsertAt(_Size, Value);
	}

	void InsertAfter(int Index, T Value)
	{
		if (Index >= _Size)
			InsertAt(_Size - 1, Value);
		else
			InsertAt(Index + 1 , Value);

	}

	void InsertBefor(int Index, T Value)
	{
		if (Index < 1)
			InsertAt(0, Value);
		else
			InsertAt(Index-1, Value);
	}

	bool UpdateItem(int Index, T Value)
	{
		if (Index < 0 || Index >= _Size)
		{
			return false;
		}

		for (int i = 0; i < _Size; i++)
		{
			if (i == Index)
			{
				OriginalArray[i] = Value;
				return true;
			}
		}
		return true;
	}
};



//void Resize(int Size)
//{
//	if (Size < 0)
//	{
//		Size = 0;
//	}
//
//	TempArray = new T[_Size];
//	CopyArrayItems(OriginalArray, TempArray);
//	delete[]OriginalArray;
//
//
//	_Size = Size;
//	OriginalArray = new T[_Size];
//
//
//	CopyArrayItems(TempArray, OriginalArray);
//
//	delete[]TempArray;
//
//}
// 
//void CopyArrayItems(T*& Orginal, T*& Temp)
//{
//	for (int i = 0; i < _Size; i++)
//	{
//		Temp[i] = Orginal[i];
//	}
//}