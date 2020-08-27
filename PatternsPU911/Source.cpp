#include<iostream>
#include"FactoryMethod.h"
#include"AbstractFactory.h"

using namespace std;

int main()
{
	setlocale(0, "");

	Car* car1 = new Car;
	CarConfigurator* config = new CarConfigurator;
	config->setConfiguration(new SportCar);
	config->configurate(car1);
	car1->print();
	cout << endl;
	
	Car* car2 = new Car;
	config->setConfiguration(new BMW);
	config->configurate(car2);
	car2->print();

	system("pause");
}