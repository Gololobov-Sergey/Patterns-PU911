#pragma once

#include<string>
#include<iostream>


using namespace std;

namespace Adapter {

	//Target
	class ITransport
	{
	public:
		virtual void drive() = 0;
	};


	class Car: public ITransport
	{
	public:
		void drive()
		{
			cout << "������ ���� �� ������" << endl;
		}
	};

	//Client
	class Driver
	{
	public:
		void travel(ITransport* transport)
		{
			transport->drive();
		}
	};

	//Adaptee
	class Camel
	{
	public:
		void move()
		{
			cout << "������� ��� �� �������" << endl;
		}
	};


	//Adapter
	class CamelToTransport : public ITransport
	{
		Camel* camel;
	public:
		CamelToTransport(Camel* c) :camel(c) {}
		void drive() override
		{
			camel->move();
		}
		
	};
}

//Adapter::Car* car = new Adapter::Car;
//Adapter::Driver* driver = new Adapter::Driver;
//driver->travel(car);
//
//Adapter::Camel* camel = new Adapter::Camel;
//Adapter::ITransport* camelTransport = new Adapter::CamelToTransport(camel);
//driver->travel(camelTransport);