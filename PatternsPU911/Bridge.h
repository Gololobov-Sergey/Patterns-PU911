#pragma once
#include<string>
#include<iostream>


using namespace std;

class ILanguage
{
public:
	virtual void build() = 0;
	virtual void execute() = 0;
};

class CPPLanguage : public ILanguage
{
public:
	void build() override
	{
		cout << "С помощью компилятора c++ компилируем программу в бинарный код" << endl;
	}
	void execute() override
	{
		cout << "Запускаем исполняемый файл" << endl;
	}
};

class HTMLLanguage : public ILanguage
{
public:
	void build() override
	{
		cout << "Пишет код в текстовом редакторе" << endl;
	}
	void execute() override
	{
		cout << "Запускает страницу в браузере" << endl;
	}
};

class Programmer
{
protected:
	ILanguage* language;
public:
	Programmer(ILanguage* lang) :language(lang) {}
	void setLenguage(ILanguage* lang)
	{
		language = lang;
	}
	virtual void doWork()
	{
		language->build();
		language->execute();
	}
	virtual void getSalary() = 0;
};

class FreelanceProgrammer : public Programmer
{
public:
	FreelanceProgrammer(ILanguage* lang):Programmer(lang){}
	void getSalary() override
	{
		cout << "Получаем оплату за выполненный заказ" << endl;
	}
};

class OfficeProgrammer : public Programmer
{
public:
	OfficeProgrammer(ILanguage* lang) :Programmer(lang) {}
	void getSalary() override
	{
		cout << "Получаем зарплату в конце месяца" << endl;
	}
};

//Programmer* freelancer = new FreelanceProgrammer(new CPPLanguage);
//freelancer->doWork();
//freelancer->getSalary();
//cout << endl;
//
//freelancer->setLenguage(new HTMLLanguage);
//freelancer->doWork();
//freelancer->getSalary();
//cout << endl;
//
//Programmer* officeprogrammer = new OfficeProgrammer(new HTMLLanguage);
//officeprogrammer->doWork();
//officeprogrammer->getSalary();