#pragma once
#include<string>
#include<iostream>


using namespace std;


class HouseBuilder
{
protected:
	virtual void buildWall() = 0;
	virtual void buildDoor() = 0;
	virtual void buildWindows(int count) = 0;
	virtual void buildRoof() = 0;
	virtual void hookBuildPool() = 0;
	
public:
	void buildHouse(int wind)
	{
		buildWall();
		buildDoor();
		buildWindows(wind);
		hookBuildPool();
		buildRoof();
	}
	virtual string getResult() = 0;
};

class StandartHouse : public HouseBuilder
{
	string house = "";
public:
	void buildWall() override
	{
		house += "������� �����\n";
	}
	void buildDoor() override
	{
		house += "������� �����\n";
	}
	void buildWindows(int count) override
	{
		house += "������� ���� - ";
		char buff[10];
		_itoa(count, buff, 10);
		house += buff;
		house += " ��\n";
	}
	virtual void buildRoof()override
	{
		house += "������� �����\n";
	}
	virtual void hookBuildPool() override
	{
		
	}
	string getResult() { return house; }
};

class SuperPuperHouse : public HouseBuilder
{
	string house = "";
public:
	void buildWall() override
	{
		house += "�������� �����\n";
	}
	void buildDoor() override
	{
		house += "�������� ������\n";
	}
	void buildWindows(int count) override
	{
		house += "������� ���� - ";
		char buff[10];
		_itoa(count, buff, 10);
		house += buff;
		house += " ��\n";
	}
	virtual void buildRoof()override
	{
		house += "������������� �����\n";
	}
	virtual void hookBuildPool() override
	{
		house += "������� �� 500 �\n";
	}
	string getResult() { return house; }
};


//HouseBuilder* house1 = new SuperPuperHouse;
//house1->buildHouse(10);
//cout << house1->getResult() << endl;
//
//HouseBuilder* house2 = new StandartHouse;
//house2->buildHouse(4);
//cout << house2->getResult() << endl;