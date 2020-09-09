#pragma once
#include<string>
#include<iostream>


using namespace std;

class Strategy
{
public:
	virtual float move(int len) = 0;
};

class OnFootStrategy : public Strategy
{
	int speed = 3;
public:
	float move(int len) override
	{
		cout << "Выбран режим - пешком" << endl;
		return (float)len / speed;
	}
};

class OnBusStrategy : public Strategy
{
	int speed = 40;
public:
	float move(int len) override
	{
		cout << "Выбран режим - маршрутка" << endl;
		return (float)len / speed;
	}
};

class OnAutoStrategy : public Strategy
{
	int speed = 60;
public:
	float move(int len) override
	{
		cout << "Выбран режим - автомобиль" << endl;
		return (float)len / speed;
	}
};


class Navigator
{
	Strategy* strategy;
public:
	void setStrategy(Strategy* st)
	{
		strategy = st;
	}
	void getTime(int len)
	{
		float t = strategy->move(len);
		cout << "Расчётное время в пути " << t << " ч." << endl;
	}
};

//Navigator* navi = new Navigator;
//navi->setStrategy(new OnBusStrategy);
//navi->getTime(45);
//
//
//Strategy* strategy = nullptr;
//int len;
//cout << "Введите растояние: ";
//cin >> len;
//int i;
//cout << "Введите вариант поездки 1-Пешком, 2-Маршрутка, 3-Автомобиль: ";
//cin >> i;
//switch (i)
//{
//case 1:
//	strategy = new OnFootStrategy;
//	break;
//case 2:
//	strategy = new OnBusStrategy;
//	break;
//case 3:
//	strategy = new OnAutoStrategy;
//	break;
//default:
//	break;
//}
//if (strategy)
//{
//	navi->setStrategy(strategy);
//	navi->getTime(len);
//}