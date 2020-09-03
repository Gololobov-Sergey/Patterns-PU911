#pragma once
#include<string>
#include<iostream>


using namespace std;

class TextEditor
{
public:
	void createCode()
	{
		cout << "Написание кода" << endl;
	}
	void save()
	{
		cout << "Сохранение кода" << endl;
	}
};

class Compiller
{
public:
	void compile()
	{
		cout << "Компиляция приложения" << endl;
	}
};

class Debager
{
public:
	void execute()
	{
		cout << "Включение режима отладки" << endl;
	}
	void finish()
	{
		cout << "Завершение работы приложения" << endl;
	}
};

class VisualStudioFacade
{
	TextEditor* te;
	Compiller* comp;
	Debager* deb;

public:
	VisualStudioFacade()
	{
		te = new TextEditor;
		comp = new Compiller;
		deb = new Debager;
	}
	void start()
	{
		te->createCode();
		te->save();
		comp->compile();
		deb->execute();
	}
	void stop()
	{
		deb->finish();
	}
};

//VisualStudioFacade* vs2019 = new VisualStudioFacade;
//vs2019->start();
//vs2019->stop();