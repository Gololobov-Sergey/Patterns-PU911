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
#include"ChainOfResponsibility.h"
#include"Command.h"
#include"Mediator.h"
#include"Strategy.h"
#include"Observer.h"
#include"Memento.h"

using namespace std;



int main()
{
	setlocale(0, "");

	Hero* hero = new Hero;
	hero->shoot();
	hero->shoot();
	hero->shoot();
	hero->shoot();
	GameHistory* gh = new GameHistory;
	gh->history.push(hero->saveMemento());
	hero->shoot(); 
	hero->shoot(); 
	hero->shoot();
	hero->restoreMemento(gh->history.top());
	hero->shoot(); 
	hero->shoot(); 
	hero->shoot();
	hero->shoot();
	hero->shoot();
	hero->shoot();
	hero->shoot();
	hero->shoot();
	hero->shoot();

	system("pause");
}