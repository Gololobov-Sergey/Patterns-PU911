#pragma once

#include<string>
#include<iostream>

using namespace std;

class Component
{
public:
	virtual string toString() const = 0;
};


class Engine : public Component
{

};

class Transmission : public Component
{

};

class BodyType :public Component
{

};

class DiselEngine : public Engine
{
	string toString() const override
	{
		return "Disel Engin";
	}
};

class FuelEngine : public Engine
{
	string toString() const override
	{
		return "Fuel Engin";
	}
};

class GasEngine : public Engine
{
	string toString() const override
	{
		return "Gas Engin";
	}
};

class MechanicTransmission : public Transmission
{
	string toString() const override
	{
		return "Mechanic Transmission";
	}
};

class AutomaticTransmission : public Transmission
{
	string toString() const override
	{
		return "Automatic Transmission";
	}
};

class RobotTransmission : public Transmission
{
	string toString() const override
	{
		return "Robot Transmission";
	}
};

class SedanBodyType : public BodyType
{
	string toString() const override
	{
		return "Sedan BodyType";
	}
};

class CrossoverBodyType : public BodyType
{
	string toString() const override
	{
		return "Crossover BodyType";
	}
};

class UniversalBodyType : public BodyType
{
	string toString() const override
	{
		return "Universal BodyType";
	}
};

class Car
{
	Engine* engine = nullptr;
	Transmission* transmission = nullptr;
	BodyType* bodytype = nullptr;
	string name;
public:
	Car() {}
	virtual ~Car()
	{
		if (engine)
			delete engine;
		if (transmission)
			delete transmission;
		if (bodytype)
			delete bodytype;
	}
	void setEngine(Engine* en) { engine = en; }
	void setTransmission(Transmission* tr) { transmission = tr; }
	void setBodyType(BodyType* bt) { bodytype = bt; }
	void setName(string n) { name = n; }
	Engine* getEngine() { return engine; }
	Transmission* getTransmission() { return transmission; }
	BodyType* getBodyType() { return bodytype; }
	void print()
	{
		cout << "Name Configuration: " << name << endl;
		cout << "Engine: " << engine->toString() << endl;
		cout << "Transmission: " << transmission->toString() << endl;
		cout << "BodyType: " << bodytype->toString() << endl;
	}
};

class ICarFactory
{
public:
	virtual Engine* createEngine() = 0;
	virtual Transmission* createTransmission() = 0;
	virtual BodyType* createBodyType() = 0;
	virtual string createName() = 0;
};

class SportCar : public ICarFactory
{
public:
	Engine* createEngine() { return new FuelEngine; }
	Transmission* createTransmission() { return new RobotTransmission; }
	BodyType* createBodyType() { return new SedanBodyType; }
	string createName() { return "SportCar"; }
};

class BMW : public ICarFactory
{
public:
	Engine* createEngine() { return new GasEngine; }
	Transmission* createTransmission() { return new AutomaticTransmission; }
	BodyType* createBodyType() { return new CrossoverBodyType; }
	string createName() { return "BMW"; }
};


class CarConfigurator
{
	ICarFactory* factory = nullptr;
public:
	~CarConfigurator()
	{
		if (factory)
			delete factory;
	}
	void setConfiguration(ICarFactory* f) { factory = f; }
	void configurate(Car* car)
	{
		car->setName(factory->createName());
		car->setEngine(factory->createEngine());
		car->setTransmission(factory->createTransmission());
		car->setBodyType(factory->createBodyType());
	}
};


//Car* car1 = new Car;
//CarConfigurator* config = new CarConfigurator;
//config->setConfiguration(new SportCar);
//config->configurate(car1);
//car1->print();
//cout << endl;
//
//Car* car2 = new Car;
//config->setConfiguration(new BMW);
//config->configurate(car2);
//car2->print();