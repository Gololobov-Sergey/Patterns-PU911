#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class HeroMemento;

class Hero
{
	int patrons = 10;
	int hp = 100;
public:
	void shoot()
	{
		if (patrons > 0)
		{
			cout << "��������� �������" << endl;
			cout << "�������� " << --patrons << " ��������" << endl;
		}
		else
		{
			cout << "�������� ������ ���" << endl;
		}
	}
	HeroMemento* saveMemento();

	void restoreMemento(HeroMemento* memento);

};

class HeroMemento
{
	int patrons = 10;
	int hp = 100;
public:
	HeroMemento(int p, int hp) :patrons(p), hp(hp) {};
	int getPatrons() { return patrons; }
	int getHP() { return hp; }
};

class GameHistory
{
public:
	stack<HeroMemento*> history;
};

HeroMemento* Hero::saveMemento()
{
	cout << "���������� ����: �������� " << patrons << ", ����� " << hp << endl;
	return new HeroMemento(patrons, hp);
}

void Hero::restoreMemento(HeroMemento* memento)
{
	this->patrons = memento->getPatrons();
	this->hp = memento->getHP();
	cout << "������������� ����: �������� " << patrons << ", ����� " << hp << endl;
}


//Hero* hero = new Hero;
//hero->shoot();
//hero->shoot();
//hero->shoot();
//hero->shoot();
//GameHistory* gh = new GameHistory;
//gh->history.push(hero->saveMemento());
//hero->shoot();
//hero->shoot();
//hero->shoot();
//hero->restoreMemento(gh->history.top());
//hero->shoot();
//hero->shoot();
//hero->shoot();
//hero->shoot();
//hero->shoot();
//hero->shoot();
//hero->shoot();
//hero->shoot();
//hero->shoot();
