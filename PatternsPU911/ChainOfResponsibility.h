#pragma once
#include<string>
#include<iostream>


using namespace std;

class Handler
{
public:
	virtual void sendPayment(int sum) = 0;
	virtual Handler* setHandler(Handler* h) = 0;
};

class Client : public Handler
{
	Handler* nextHandler = nullptr;
public:
	Client() {}
	Client(Handler* nh) :nextHandler(nh) {}
	Handler* setHandler(Handler* h)
	{
		nextHandler = h;
		return nextHandler;
	}
	void sendPayment(int sum)
	{
		if (nextHandler)
			nextHandler->sendPayment(sum);
	}
};

class EconomistHandler : public Handler
{
	Handler* nextHandler = nullptr;
public:
	EconomistHandler(){}
	EconomistHandler(Handler* nh):nextHandler(nh) {}
	Handler* setHandler(Handler* h)
	{
		nextHandler = h;
		return nextHandler;
	}
	void sendPayment(int sum) override
	{
		if (sum > 1000)
		{
			if (nextHandler)
				nextHandler->sendPayment(sum);
		}
		else
		{
			cout << "Платёж проведён экономистом" << endl;
		}
	}
}; 

class BuhgalterHandler : public Handler
{
	Handler* nextHandler = nullptr;
public:
	BuhgalterHandler(){}
	BuhgalterHandler(Handler* nh) :nextHandler(nh) {}
	Handler* setHandler(Handler* h)
	{
		nextHandler = h;
		return nextHandler;
	}
	void sendPayment(int sum) override
	{
		if (sum > 5000)
		{
			if (nextHandler)
				nextHandler->sendPayment(sum);
		}
		else
		{
			cout << "Платёж проведён бухгалтером" << endl;
		}
	}
};

class DirectorHandler : public Handler
{
	Handler* nextHandler = nullptr;
public:
	DirectorHandler(){}
	DirectorHandler(Handler* nh) :nextHandler(nh) {}
	Handler* setHandler(Handler* h)
	{
		nextHandler = h;
		return nextHandler;
	}
	void sendPayment(int sum) override
	{
		if (sum > 10000)
		{
			if (nextHandler)
				nextHandler->sendPayment(sum);
			else
				cout << "Нужет совет директоров, а у нас его нет! Платёж проведён не будет" << endl;
		}
		else
		{
			cout << "Платёж проведён директором" << endl;
		}
	}
};

	//Client* client = new Client(new EconomistHandler(new BuhgalterHandler(new DirectorHandler())));

	/*Client* client = new Client;
	client->
		setHandler(new EconomistHandler)->
		setHandler(new BuhgalterHandler)->
		setHandler(new DirectorHandler);

	client->sendPayment(1200);*/