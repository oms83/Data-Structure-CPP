

#include <iostream>
#include"clsQueueLine.h"

using namespace std;
int main()
{
    system("cls");
    clsQueueLine PayBillsQueue("A0", 5);
    clsQueueLine SubstractionQueue("B0", 10);
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.PrintInfo();
    PayBillsQueue.PrintTicketsLineLTR();
    PayBillsQueue.PrintTicketsLineRTL();
    PayBillsQueue.PrintAllTickets();
    PayBillsQueue.ServeNextClient();
    PayBillsQueue.ServeNextClient();
    PayBillsQueue.PrintInfo();

    SubstractionQueue.IssueTicket();
    SubstractionQueue.IssueTicket();
    SubstractionQueue.IssueTicket();
    SubstractionQueue.PrintInfo();
    SubstractionQueue.PrintAllTickets();


    system("pause>0");
}


//clsMyString S1;
//
//cout << "\nS1 = " << S1.Value;
//S1.Value = "OMER1";
//cout << "\nS1 = " << S1.Value;
//S1.Value = "OMER2";
//cout << "\nS1 = " << S1.Value;
//S1.Value = "OMER3";
//cout << "\nS1 = " << S1.Value;
//
//
//cout << "\n\n\n---- Undo ----\n\n";
//S1.Undo();
//cout << "\nS1 = " << S1.Value;
//S1.Undo();
//cout << "\nS1 = " << S1.Value;
//S1.Undo();
//cout << "\nS1 = " << S1.Value;
//
//
//
//cout << "\n\n\n---- Redo ----\n\n";
//S1.Redo();
//cout << "\nS1 = " << S1.Value;
//S1.Redo();
//cout << "\nS1 = " << S1.Value;
//S1.Redo();
//cout << "\nS1 = " << S1.Value;


/*clsMyStackArr<int>MyStack;

    MyStack.push(10);
    MyStack.push(20);
    MyStack.push(30);
    MyStack.push(40);

    MyStack.Print();

    MyStack.InsertAfter(3, 50);
    MyStack.InsertAtBack(60);
    MyStack.InsertAtFront(0);
    
    MyStack.Print();

    cout << "\nFront: " << MyStack.Top() << endl;
    cout << "\nBack: " << MyStack.Bottom() << endl;
    cout << "\nSize: " << MyStack.Size() << endl;
    cout << "\nGet Item: " << MyStack.GetItem(1) << endl;

    MyStack.Reverse();
    MyStack.Print();

    MyStack.UpdateItem(2, 90);
    MyStack.pop();
    MyStack.Print();*/