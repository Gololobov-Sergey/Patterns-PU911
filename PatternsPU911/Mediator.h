#pragma once
#include<string>
#include<iostream>


using namespace std;

class Colleague;

class Mediator
{
public:
	virtual void send(string msg, Colleague* collegue) = 0;
};

class Colleague
{
protected:
	Mediator* mediator;
public:
	Colleague(Mediator* mediator) :mediator(mediator) {}
	virtual void send(string msg)
	{
		mediator->send(msg, this);
	}
	virtual void notify(string msg) = 0;
};

class CustomerCollegue : public Colleague
{
public:
	CustomerCollegue(Mediator* md): Colleague(md){}
	void notify(string msg) override
	{
		cout << "Сообщение заказчику: " << msg << endl;
	}
};

class ProgrammerCollegue : public Colleague
{
public:
	ProgrammerCollegue(Mediator* md) : Colleague(md) {}
	void notify(string msg) override
	{
		cout << "Сообщение программисту: " << msg << endl;
	}
};

class TesterCollegue : public Colleague
{
public:
	TesterCollegue(Mediator* md) : Colleague(md) {}
	void notify(string msg) override
	{
		cout << "Сообщение тестировщику: " << msg << endl;
	}
};

class ManagerMediator : public Mediator
{
public:
	Colleague* customer;
	Colleague* programmer;
	Colleague* tester;
	void send(string msg, Colleague* collegue) override
	{
		if (collegue == customer)
			programmer->notify(msg);
		else if (collegue == programmer)
			tester->notify(msg);
		else if (collegue == tester)
			customer->notify(msg);
	}
};

//ManagerMediator* manager = new ManagerMediator;
//Colleague* customer = new CustomerCollegue(manager);
//Colleague* programmer = new ProgrammerCollegue(manager);
//Colleague* tester = new TesterCollegue(manager);
//manager->customer = customer;
//manager->programmer = programmer;
//manager->tester = tester;
//
//customer->send("Есть заказ, надо сделать программу");
//programmer->send("Программа готова, нужно протестировать");
//tester->send("Программа протестирована, готова к продаже");