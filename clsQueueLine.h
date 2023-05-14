#pragma once
#include<iostream>
#include<queue> 
#include<iomanip>

#include"clsDate.h"
#include"clsTime.h"

using namespace std;

class clsQueueLine
{
private:
	
	struct stIssueTicket
	{
		string DTime;
		string Prefix;
		short WaitingClient;
		short ServedTime;
	};

	stIssueTicket MyTickets;

	queue <stIssueTicket> MyQueue;

	string _Prefix;
	short _ServedTime;
	short _NumberOfClients = 0;

	void _PrintTicketsRecord(stIssueTicket Ticket)
	{
		cout << "\n" << setw(33) << "" << Ticket.Prefix;
		cout << "\n\n" << setw(26) << "" << Ticket.DTime;
		cout << "\n" << setw(26) << "" << "Waiting Clients : " << Ticket.WaitingClient;
		cout << "\n" << setw(28) << "" << "Served Time In ";
		cout << "\n" << setw(30) << "" << Ticket.ServedTime << " Minutes";
	}

public:

	clsQueueLine(string Prefix, short ServedTime)
	{
		_Prefix = Prefix;
		_ServedTime = ServedTime;
	}

	void SetServedTime(short ServedTime)
	{
		_ServedTime = ServedTime;
	}
	
	short GetServedTime()
	{
		return _ServedTime;
	}
	
	void SetPrefix(string Prefix)
	{
		_Prefix = Prefix;
	}

	string GetPrefix()
	{
		return _Prefix;
	}
	
	__declspec(property(get = GetPrefix, put = SetPrefix))string Prefix;
	__declspec(property(get = GetServedTime, put = SetServedTime))short ServedTime;

	void PrintInfo()
	{
		cout << "\n" << setw(20) << "" << "______________________________\n";
		cout << setw(30) << "" << "Queue Info";
		cout << "\n" << setw(20) << "" << "______________________________\n";

		cout << "\n" << setw(22) << "" << "Prefix          : " << Prefix;
		cout << "\n" << setw(22) << "" << "Total Tickets   : " << _NumberOfClients;
		cout << "\n" << setw(22) << "" << "Served Clients  : " << _NumberOfClients - MyQueue.size();
		cout << "\n" << setw(22) << "" << "Waiting Clients : " << MyQueue.size();
		cout << "\n" << setw(20) << "" << "______________________________\n\n\n";
	}

	void IssueTicket()
	{
		_NumberOfClients++;

		string NowTime = clsDate::DateToString(clsDate::clsDate()) + " - " + clsTime::StringTime(clsTime());
		
		MyTickets.DTime = NowTime;
		MyTickets.Prefix = Prefix + to_string(_NumberOfClients);
		MyTickets.ServedTime = MyQueue.size() * ServedTime;
		MyTickets.WaitingClient = MyQueue.size();

		MyQueue.push(MyTickets);
	}

	void PrintAllTickets()
	{
		queue<stIssueTicket> TempQueue = MyQueue;

		while (!TempQueue.empty())
		{
			cout << "\n" << setw(20) << "" << "______________________________\n";
			cout << setw(30) << "" << "Client Info";
			cout << "\n" << setw(20) << "" << "______________________________\n";
			_PrintTicketsRecord(TempQueue.front());
			TempQueue.pop();
			cout << "\n" << setw(20) << "" << "______________________________\n\n\n\n";
		}
	}

	void PrintTicketsLineRTL()
	{
		queue<stIssueTicket> TempQueue = MyQueue;

		cout << setw(16) << "" << "Tickets: ";
		while (!TempQueue.empty())
		{
			cout << TempQueue.front().Prefix << " <-- ";
			TempQueue.pop();
		}

		cout << endl;
	}

	void PrintTicketsLineLTR()
	{
		queue<stIssueTicket> TempQueue = MyQueue;

		cout << setw(16) << "" << "Tickets: ";
		while (!TempQueue.empty())
		{
			cout << TempQueue.back().Prefix << " --> ";
			TempQueue.pop();
		}

		cout << endl;
	}

	void ServeNextClient()
	{
		MyQueue.pop();
	}
};



//#pragma once
//
//#include <iostream>
//#include "clsDate.h"
//#include "clsTime.h"
//#include "queue"
//#include "stack"
//
//using namespace std;
//
//class clsQueueLine
//{
//
//private:
//
//    short _TotalTickets = 0;
//    short _AverageServeTime = 0;
//    string _Prefix = "";
//
//    class clsTicket
//    {
//    private:
//
//        short _Number = 0;
//        string _Prefix;
//        string _TicketTime;
//        short _WaitingClients = 0;
//        short _AverageServeTime = 0;
//        short _ExpectedServeTime = 0;
//
//    public:
//        clsTicket(string Prefix, short Number, short WaitingClients, short AverageServeTime)
//        {
//
//            _Number = Number;
//            _TicketTime = clsDate::DateToString(clsDate::clsDate()) + " - " + clsTime::StringTime(clsTime());
//            _Prefix = Prefix;
//            _WaitingClients = WaitingClients;
//            _AverageServeTime = AverageServeTime;
//        }
//
//        string Prefix()
//        {
//            return _Prefix;
//
//        }
//        short Number()
//        {
//            return _Number;
//        }
//
//        string FullNumber()
//        {
//            return _Prefix + to_string(_Number);
//        }
//
//        string TicketTime()
//        {
//            return _TicketTime;
//        }
//
//        short WaitingClients()
//        {
//            return _WaitingClients;
//        }
//
//        short ExpectedServeTime()
//        {
//            return _AverageServeTime * _WaitingClients;
//        }
//
//        void Print()
//        {
//            cout << "\n\t\t\t  _______________________\n";
//            cout << "\n\t\t\t\t    " << FullNumber();
//            cout << "\n\n\t\t\t    " << _TicketTime;
//            cout << "\n\t\t\t    Wating Clients = " << _WaitingClients;
//            cout << "\n\t\t\t      Serve Time In";
//            cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
//            cout << "\n\t\t\t  _______________________\n";
//
//
//        }
//    };
//
//public:
//
//    queue <clsTicket> QueueLine;
//
//    clsQueueLine(string Prefix, short AverageServeTime)
//    {
//        _Prefix = Prefix;
//        _TotalTickets = 0;
//        _AverageServeTime = AverageServeTime;
//    }
//
//
//
//    void IssueTicket()
//    {
//        _TotalTickets++;
//        clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(), _AverageServeTime);
//        QueueLine.push(Ticket);
//
//    }
//
//    int WaitingClients()
//    {
//        return QueueLine.size();
//
//    }
//
//
//    string WhoIsNext()
//    {
//        if (QueueLine.empty())
//            return "No Clients Left.";
//        else
//            return QueueLine.front().FullNumber();
//
//    }
//
//    bool ServeNextClient()
//    {
//        if (QueueLine.empty())
//            return false;
//
//
//        QueueLine.pop();
//
//        return true;
//
//    }
//
//    short ServedClients()
//    {
//        return _TotalTickets - WaitingClients();
//    }
//
//    void PrintInfo()
//    {
//        cout << "\n\t\t\t _________________________\n";
//        cout << "\n\t\t\t\tQueue Info";
//        cout << "\n\t\t\t _________________________\n";
//        cout << "\n\t\t\t    Prefix   = " << _Prefix;
//        cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
//        cout << "\n\t\t\t    Served Clients  = " << ServedClients();
//        cout << "\n\t\t\t    Wating Clients  = " << WaitingClients(); ;
//        cout << "\n\t\t\t _________________________\n";
//        cout << "\n";
//
//    }
//
//    void PrintTicketsLineRTL()
//    {
//
//        if (QueueLine.empty())
//            cout << "\n\t\tTickets: No Tickets.";
//        else
//            cout << "\n\t\tTickets: ";
//
//        //we copy the queue in order not to lose the original
//        queue <clsTicket> TempQueueLine = QueueLine;
//
//
//        while (!TempQueueLine.empty())
//        {
//            clsTicket Ticket = TempQueueLine.front();
//
//            cout << " " << Ticket.FullNumber() << " <-- ";
//
//            TempQueueLine.pop();
//        }
//
//        cout << "\n";
//
//    }
//
//    void PrintTicketsLineLTR()
//    {
//        if (QueueLine.empty())
//            cout << "\n\t\tTickets: No Tickets.";
//        else
//            cout << "\n\t\tTickets: ";
//
//        //we copy the queue in order not to lose the original
//        queue <clsTicket> TempQueueLine = QueueLine;
//        stack <clsTicket> TempStackLine;
//
//        while (!TempQueueLine.empty())
//        {
//            TempStackLine.push(TempQueueLine.front());
//            TempQueueLine.pop();
//        }
//
//        while (!TempStackLine.empty())
//        {
//            clsTicket Ticket = TempStackLine.top();
//
//            cout << " " << Ticket.FullNumber() << " --> ";
//
//            TempStackLine.pop();
//        }
//        cout << "\n";
//    }
//
//
//    void PrintAllTickets()
//    {
//
//        cout << "\n\n\t\t\t       ---Tickets---";
//
//        if (QueueLine.empty())
//            cout << "\n\n\t\t\t     ---No Tickets---\n";
//
//        //we copy the queue in order not to lose the original
//        queue <clsTicket> TempQueueLine = QueueLine;
//
//
//        while (!TempQueueLine.empty())
//        {
//            TempQueueLine.front().Print();
//            TempQueueLine.pop();
//        }
//
//    }
//
//
//};