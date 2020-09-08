#pragma once
#include<string>
#include<iostream>
#include<Windows.h>
using namespace std;


class TV
{
public:
	void on()
	{
		cout << "TV on" << endl;
	}
	void off()
	{
		cout << "TV off" << endl;
	}
};

class ICommand
{
public:
	virtual void execute() = 0;
};

class TVComandON : public ICommand
{
	TV* tv;
public:
	TVComandON(TV* tv) :tv(tv) {}
	void execute() override
	{
		tv->on();
	}
};

class TVComandOff : public ICommand
{
	TV* tv;
public:
	TVComandOff(TV* tv) :tv(tv) {}
	void execute() override
	{
		tv->off();
	}
};
class Pult
{
	vector<ICommand*> command;
public:
	Pult(int num) { command.resize(num); }
	void setCommand(int num, ICommand* comm)
	{
		command[num] = comm;
	}
	void pressButton(int num)
	{
		command[num]->execute();
	}
};

class Multivarka
{
public:
	void start(int t)
	{
		cout << "Готовим еду" << endl;
		for (size_t i = 0; i < t; i++)
		{
			cout << ".";
			Sleep(1000);
		}
		cout << endl;
	}
	void stop()
	{
		cout << "Еда готова" << endl;
	}
};

class MVCommand : public ICommand
{
	Multivarka* mv;
	int t;
public:
	MVCommand(Multivarka* mv, int t):mv(mv), t(t){}
	void execute()override
	{
		mv->start(t);
		mv->stop();
	}
};

//TV* tv = new TV;
//
//Pult* pult = new Pult(3);
//
//pult->setCommand(0, new TVComandOff(tv));
//
//pult->setCommand(1, new TVComandON(tv));
//
//
//Multivarka* mv = new Multivarka;
//pult->setCommand(2, new MVCommand(mv, 7));
//pult->pressButton(2);