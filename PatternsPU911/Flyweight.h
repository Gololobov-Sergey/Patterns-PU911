#pragma once
#include<string>
#include<iostream>
#include<map>

using namespace std;


class House
{
protected:
	int floor;
public:
	virtual void build(float latitude, float longitude) = 0;
};

class PanelHouse : public House
{
public:
	PanelHouse() { floor = 9; }
	void build(float latitude, float longitude) override
	{
		cout << "Построен панельный дом из " << floor << " этажей, координаты: "
			<< latitude << "* широты и " << longitude << "* долготы" << endl;
	}
};

class BrickHouse : public House
{
public:
	BrickHouse() { floor = 5; }
	void build(float latitude, float longitude) override
	{
		cout << "Построен кипичный дом из " << floor << " этажей, координаты: "
			<< latitude << "* широты и " << longitude << "* долготы" << endl;
	}
};

class HouseFactory
{
	map<string, House*> houses;

public:
	HouseFactory()
	{
		houses["Panel"] = new PanelHouse;
		houses["Brick"] = new BrickHouse;
	}

	House* getHouse(string key)
	{
		if (houses.count(key))
			return houses[key];
		else
			return nullptr;
	}
};


//float latitude = 50.3, longitude = 30.6;
//
//HouseFactory* houseFactory = new HouseFactory;
//
//for (size_t i = 0; i < 10; i++)
//{
//	House* panelHouse = houseFactory->getHouse("Panel");
//	if (panelHouse != nullptr)
//		panelHouse->build(latitude, longitude);
//	latitude += 0.2;
//	longitude += 0.3;
//}
//
//for (size_t i = 0; i < 10; i++)
//{
//	House* bricklHouse = houseFactory->getHouse("Brick");
//	if (bricklHouse != nullptr)
//		bricklHouse->build(latitude, longitude);
//	latitude += 0.2;
//	longitude += 0.3;
//}