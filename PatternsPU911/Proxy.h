#pragma once
#include<string>
#include<iostream>
#include<map>

using namespace std;

class IPages
{
public:
	virtual string getPage(int key) = 0;
};

class DataBase : public IPages
{
	map<int, string> base;
public:
	DataBase()
	{
		base[1] = "Page 1";
		base[2] = "Page 2";
		base[3] = "Page 3";
		base[4] = "Page 4";
		base[5] = "Page 5";
	}
	string getPage(int key) override
	{
		if (base.count(key))
			return base[key];
		else
			return "no page";
	}
};

class DataBaseProxy : public IPages
{
	map<int, string> cash;
	DataBase* base;
public:
	string getPage(int key) override
	{
		if (cash.count(key))
		{
			cout << "Взято из кэша" << endl;
			return cash[key];
		}
		else
		{
			base = new DataBase;
			string page = base->getPage(key);
			cash[key] = page;
			cout << "Взято из базы" << endl;
			delete base;
			return page;
		}
	}
};

//DataBaseProxy* dbproxy = new DataBaseProxy;
//int i = 1;
//while (i)
//{
//	cout << "Страница: ";
//	cin >> i;
//	cout << dbproxy->getPage(i) << endl;
//}