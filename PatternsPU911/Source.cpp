#include<iostream>
#include"FactoryMethod.h"
#include"AbstractFactory.h"
#include"Builder.h"
#include"Singleton.h"
#include"Prototype.h"
#include"Decorator.h"
#include"Adapter.h"
#include"Bridge.h"
#include"Composit.h"
#include"Facade.h"
#include"Flyweight.h"
#include"Proxy.h"
#include"State.h"

using namespace std;



int main()
{
	setlocale(0, "");

	Water* water = new Water(new SolidWaterState);
	water->heat();
	water->heat();
	water->heat();
	water->heat();
	water->frost();
	water->frost();
	water->frost();
	water->frost();


	system("pause");
}