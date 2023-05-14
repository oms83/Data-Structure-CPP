#pragma once
#include<iostream>
using namespace std;



template<class T>
class clsDblLinkedList
{
protected:
	int _Size = 0;

public:

	class Node
	{
	public:
		Node* Next;
		Node* Prev;
		T Value;
	};

	Node* Head = NULL;

	void InserAtBeginning(T Value)
	{
		Node* NewNode = new Node();

		NewNode->Value = Value;
		NewNode->Next = Head;
		NewNode->Prev = NULL;

		if (Head != NULL)
		{
			Head->Prev = NewNode;
		}

		Head = NewNode;

		_Size++;
	}

	void InsertAtEnd(T Value)
	{
		Node* NewNode = new Node();

		NewNode->Value = Value;
		NewNode->Next = NULL;

		if (Head == NULL)
		{
			NewNode->Prev = NULL;
			Head = NewNode;
		}
		else
		{
			Node* Current = Head;

			while (Current->Next != NULL)
			{
				Current = Current->Next;
			}

			Current->Next = NewNode;
			NewNode->Prev = Current;
		}

		_Size++;

	}

	Node* Find(T Value)
	{
		Node* Current = Head;

		while (Current != NULL)
		{
			if (Current->Value == Value)
			{
				return Current;
			}

			Current = Current->Next;
		}


		return NULL;
	}

	void InsertAfter(Node*& PrevNode, T Value)
	{
		if (PrevNode == NULL)
		{
			return;
		}

		Node* NewNode = new Node();

		NewNode->Next = PrevNode->Next;
		NewNode->Value = Value;
		NewNode->Prev = PrevNode;

		if (PrevNode->Next != NULL)
		{
			PrevNode->Next->Prev = NewNode;
		}

		PrevNode->Next = NewNode;
		_Size++;

	}

	void Delete(Node*& NodeToDelete)
	{
		if (NodeToDelete == NULL || Head == NULL)
		{
			return;
		}

		if (NodeToDelete == Head)
		{
			Head = NodeToDelete->Next;
		}

		if (NodeToDelete->Next != NULL)
		{
			NodeToDelete->Next->Prev = NodeToDelete->Prev;
		}

		if (NodeToDelete->Prev != NULL)
		{
			NodeToDelete->Prev->Next = NodeToDelete->Next;
		}

		delete NodeToDelete;
		_Size--;
	}

	void Delete(T Value)
	{
		if (Head == NULL)
		{
			return;
		}
		Node* Current = Head;

		if (Head->Value == Value)
		{
			Current->Prev = NULL;
			Head = Current->Next;
			delete Current;

		}
		else
		{
			while (Current->Value != Value && Current != NULL)
			{
				Current = Current->Next;
			}

			if (Current->Next == NULL)
			{
				Current->Prev->Next = NULL;

			}
			else
			{
				Current->Prev->Next = Current->Next;
				Current->Next->Prev = Current->Prev;
			}
			delete Current;
		}

		_Size--;
	}

	void DeleteFirstNode()
	{
		Node* Current = Head;
		if (Head == NULL)
		{
			return;
		}

		Head = Current->Next;
		if (Head != NULL)
		{
			Head->Prev = NULL;
		}
		delete Current;
		_Size--;
	}

	void DeleteLastNode()
	{
		Node* Current = Head;

		if (Head == NULL)
		{
			return;
		}

		if (Current->Next == NULL)
		{
			Head = NULL;
			delete Current;
		}
		else
		{
			while (Current->Next != NULL)
			{
				Current = Current->Next;
			}

			Current->Prev->Next = NULL;
			delete Current;
		}
		

		_Size--;
	}

	void PrintList()
	{
		Node* Current = Head;
		cout << "NULL";
		while (Current != NULL)
		{
			cout << " <-> " << Current->Value;
			Current = Current->Next;
		}
		cout << " <-> NULL";
	}

	void PrintNodeDetails(Node* Current)
	{

		if (Current->Prev != NULL)
			cout << Current->Prev->Value;
		else
			cout << "NULL";

		cout << " <--> " << Current->Value << " <--> ";

		if (Current->Next != NULL)
			cout << Current->Next->Value << "\n";
		else
			cout << "NULL";
	}

	void PrintListDetails()
	{
		Node* Current = Head;
		cout << "\n\n";
		while (Current != NULL)
		{
			PrintNodeDetails(Current);
			Current = Current->Next;
		}
	}

	int Size()
	{
		// This solution [  O of 1  O(1)  ]
		// The other solution [  O of n O(n)  ]
		return _Size;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		Node* Current = Head;
		Node* Temp = nullptr;

		while (Current != NULL)
		{
			Temp = Current->Prev;
			Current->Prev = Current->Next;
			Current->Next = Temp;
			Current = Current->Prev;
		}
		if (Temp != nullptr)
		{
			Head = Temp->Prev;
		}
	}

	Node* GetNode(int Index)
	{
		Node* Current = Head;

		if (Head == NULL || _Size < Index || Index < 0)
		{
			return NULL;
		}
		
		for (int i = 0; i < Index; i++)
		{
			Current = Current->Next;
		}

		return Current;
	}

	T GetItem(int Item)
	{
		Node* N1 = GetNode(Item);
		return N1 == NULL ? NULL : N1->Value;
	}

	bool UpdateItem(int Index, T Value)
	{
		Node* N1 = GetNode(Index);
		if (N1 != NULL)
		{
			N1->Value = Value;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool InsertAfter(int Index, T Value)
	{
		Node* N1 = GetNode(Index);

		if (N1 != NULL)
		{
			InsertAfter(N1, Value);
			return true;
		}
		else
		{
			return false;
		}

	}
};

